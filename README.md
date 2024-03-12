# Monitor Cardíaco Arduino - Complemento HeartCare

Este programa Arduino monitora a frequência cardíaca com sensor de pulso e display LCD I2C.

## Componentes
- Arduino
- Sensor de Pulso
- LCD I2C
- LED (opcional)
- Fios

## Bibliotecas
- Wire.h
- LiquidCrystal_I2C.h

## Instruções
1. Sensor de pulso: Pino A0.
2. LED (opcional): Pino 13.
3. LCD I2C: Pinos I2C do Arduino.

## Visão Geral
- Inicialização de variáveis, pinos e LCD.
- Detecção de pulso por interrupção.
- Atualização do monitor serial e do LCD ao detectar batimentos cardíacos.

## Funções Principais
- `configurarInterrupcao()`
- `saidaSerial()`
- `saidaSerialQuandoBatimentoAcontece()`
- `monitorSerialArduinoVisual()`
- `enviarDadosParaSerial()`

## Uso
1. Conecte os componentes.
2. Carregue o código na placa Arduino.
3. Abra o monitor serial para visualizar os dados.
4. O LCD exibirá informações sobre os batimentos cardíacos.

## Circuito
![Foto 1](https://raw.githubusercontent.com/DSantosxTech/sensor-de-batimentos/main/github/galeria%20(1).jpeg)
![Foto 2](https://raw.githubusercontent.com/DSantosxTech/sensor-de-batimentos/main/github/galeria%20(2).jpeg)
![Circuito Diagrama](https://raw.githubusercontent.com/DSantosxTech/sensor-de-batimentos/main/github/Circuito%20Diagrama.png)


## Tecnologias e Linguagens
<div style="display: inline_block">
  <img src="https://cdn.jsdelivr.net/gh/devicons/devicon@latest/icons/arduino/arduino-original-wordmark.svg" height="50" width="60"/>
  <img src="https://cdn.jsdelivr.net/gh/devicons/devicon@latest/icons/cplusplus/cplusplus-original.svg" height="50" width="60"/>
</div>

## Referências e documentações
| **[C++](https://en.cppreference.com/w/)**
## Vídeo Demonstrativo 
[Assista](https://youtube.com/shorts/XUnM2_iGVNA?si=ZwaqqHhv3dkJSGIT)

## Tutorial
[Aprenda](https://youtu.be/x_fcC0qvXmI?si=grnr9d38WYIHxS77)