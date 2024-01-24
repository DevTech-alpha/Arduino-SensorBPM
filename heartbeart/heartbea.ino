#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 12, 6);
int pinoSensorPulso = A0;
int pinoLED = 13;

volatile int BPM;
volatile int Sinal;
volatile int IBI = 600;
volatile boolean Pulso = false;
volatile boolean QS = false;
static boolean serialVisual = true;

volatile int taxa[10];
volatile unsigned long contadorAmostras = 0;
volatile unsigned long ultimoTempoBatimento = 0;
volatile int P = 512;
volatile int T = 512;
volatile int limiteSuperior = 525;
volatile int amplitude = 100;
volatile boolean primeiroBatimento = true;
volatile boolean segundoBatimento = false;

void setup() {
  Serial.begin(115200);
  configurarInterrupcao();
  lcd.begin();
}

void loop() {
  saidaSerial();

  if (QS == true) {
    saidaSerialQuandoBatimentoAcontece();
    QS = false;
  }

  delay(20);
}

void configurarInterrupcao() {
  TCCR2A = 0x02;
  TCCR2B = 0x06;
  OCR2A = 0X7C;
  TIMSK2 = 0x02;
  sei();
}

void saidaSerial() {
  if (serialVisual == true) {
    monitorSerialArduinoVisual('-', Sinal);
  } else {
    enviarDadosParaSerial('S', Sinal);
  }
}

void saidaSerialQuandoBatimentoAcontece() {
  if (serialVisual == true) {
    Serial.print("Heart Beat");
    Serial.print("BPM: ");
    Serial.println(BPM);
    lcd.setBacklight(HIGH);
    lcd.setCursor(0, 0);
    lcd.print(" Heart Beat ");
    lcd.setCursor(1, 1);
    lcd.print("BPM: ");
    lcd.setCursor(5, 1);
    lcd.print(BPM);
    delay(300);
    lcd.clear();
  } else {
    enviarDadosParaSerial('B', BPM);
    enviarDadosParaSerial('Q', IBI);
  }
}

void monitorSerialArduinoVisual(char simbolo, int dados) {
  const int sensorMinimo = 0;
  const int sensorMaximo = 1024;
  int leituraSensor = dados;
  int faixa = map(leituraSensor, sensorMinimo, sensorMaximo, 0, 11);
}

void enviarDadosParaSerial(char simbolo, int dados) {
  Serial.print(simbolo);
  Serial.println(dados);
}

ISR(TIMER2_COMPA_vect) {
  cli();
  Sinal = analogRead(pinoSensorPulso);
  contadorAmostras += 2;
  int N = contadorAmostras - ultimoTempoBatimento;

  if (Sinal < limiteSuperior && N > (IBI / 5) * 3) {
    if (Sinal < T) {
      T = Sinal;
    }
  }

  if (Sinal > limiteSuperior && Sinal > P) {
    P = Sinal;
  }

  if (N > 250) {
    if ((Sinal > limiteSuperior) && (Pulso == false) && (N > (IBI / 5) * 3)) {
      Pulso = true;
      digitalWrite(pinoLED, HIGH);
      IBI = contadorAmostras - ultimoTempoBatimento;
      ultimoTempoBatimento = contadorAmostras;

      if (segundoBatimento) {
        segundoBatimento = false;
        for (int i = 0; i <= 9; i++) {
          taxa[i] = IBI;
        }
      }

      if (primeiroBatimento) {
        primeiroBatimento = false;
        segundoBatimento = true;
        sei();
        return;
      }

      word totalCorrente = 0;

      for (int i = 0; i <= 8; i++) {
        taxa[i] = taxa[i + 1];
        totalCorrente += taxa[i];
      }

      taxa[9] = IBI;
      totalCorrente += taxa[9];
      totalCorrente /= 10;
      BPM = 60000 / totalCorrente;
      QS = true;
    }
  }

  if (Sinal < limiteSuperior && Pulso == true) {
    digitalWrite(pinoLED, LOW);
    Pulso = false;
    amplitude = P - T;
    limiteSuperior = amplitude / 2 + T;
    P = limiteSuperior;
    T = limiteSuperior;
  }

  if (N > 2500) {
    limiteSuperior = 512;
    P = 512;
    T = 512;
    ultimoTempoBatimento = contadorAmostras;
    primeiroBatimento = true;
    segundoBatimento = false;
  }

  sei();
}
