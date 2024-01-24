# Monitor de Frequência Cardíaca com Arduino

Este é um programa Arduino para um monitor de frequência cardíaca usando um sensor de pulso e um display LCD com comunicação I2C. A frequência cardíaca é medida com base no sinal do sensor de pulso, e os resultados são exibidos no visor LCD.

## Componentes Utilizados
- Placa Arduino
- Sensor de Pulso
- LCD com suporte I2C (com a biblioteca LiquidCrystal_I2C)
- LED (opcional)
- fios

## Bibliotecas Necessárias
- Wire.h
- LiquidCrystal_I2C.h

## Instruções de Conexão
1. Conecte o sensor de pulso ao Pino Analógico A0.
2. Conecte o LED ao Pino Digital 13 (opcional).
3. Conecte o LCD com suporte I2C aos pinos I2C no Arduino.

## Visão Geral do Código
- O programa inicializa as variáveis necessárias, os pinos e o LCD.
- A detecção de pulso baseada em interrupção é configurada para ler o sinal analógico do sensor de pulso.
- O loop principal emite continuamente dados para o monitor serial e atualiza o LCD quando um batimento cardíaco é detectado.

## Funções
- `configurarInterrupcao()`: Configura a interrupção para detecção de pulso.
- `saidaSerial()`: Emite dados do sinal de pulso para o monitor serial.
- `saidaSerialQuandoBatimentoAcontece()`: Emite dados do batimento cardíaco para o monitor serial e atualiza o LCD.
- `monitorSerialArduinoVisual()`: Mapeia dados do sensor para uma faixa visual (não utilizado atualmente).
- `enviarDadosParaSerial()`: Envia dados para o monitor serial.

## Rotina de Serviço de Interrupção (ISR)
- A ISR (`TIMER2_COMPA_vect`) lida com a detecção de pulso, calcula a frequência cardíaca e atualiza as variáveis necessárias.

## Uso
1. Conecte o sensor de pulso, LED e LCD ao Arduino conforme as instruções.
2. Carregue o código no Arduino usando a IDE Arduino.
3. Abra o monitor serial para visualizar os dados de pulso e frequência cardíaca.
4. O LCD exibirá informações sobre os batimentos cardíacos quando detectados.