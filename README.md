# Monitor Cardíaco com Arduino

Desenvolvemos um programa Arduino para monitorar a frequência cardíaca usando um sensor de pulso e um display LCD com comunicação I2C. A frequência cardíaca é medida através do sinal do sensor de pulso, sendo os resultados exibidos no LCD.

## Componentes Necessários
- Placa Arduino
- Sensor de Pulso
- LCD com suporte I2C (usando a biblioteca LiquidCrystal_I2C)
- LED (opcional)
- Fios

## Bibliotecas Requeridas
- Wire.h
- LiquidCrystal_I2C.h

## Instruções de Conexão
1. Conecte o sensor de pulso ao Pino Analógico A0.
2. Conecte o LED ao Pino Digital 13 (opcional).
3. Conecte o LCD com suporte I2C aos pinos I2C no Arduino.

## Visão Geral do Código
- O programa inicializa variáveis, pinos e o LCD.
- Configura a detecção de pulso baseada em interrupção para ler o sinal analógico do sensor.
- O loop principal emite dados continuamente para o monitor serial e atualiza o LCD ao detectar um batimento cardíaco.

## Funções Principais
- `configurarInterrupcao()`: Configura a interrupção para detecção de pulso.
- `saidaSerial()`: Emite dados do sinal de pulso para o monitor serial.
- `saidaSerialQuandoBatimentoAcontece()`: Emite dados do batimento cardíaco para o monitor serial e atualiza o LCD.
- `monitorSerialArduinoVisual()`: Mapeia dados do sensor para uma faixa visual (não utilizado atualmente).
- `enviarDadosParaSerial()`: Envia dados para o monitor serial.

## Rotina de Serviço de Interrupção (ISR)
- A ISR (`TIMER2_COMPA_vect`) lida com a detecção de pulso, calcula a frequência cardíaca e atualiza variáveis.

## Uso
1. Conecte sensor de pulso, LED e LCD ao Arduino conforme as instruções.
2. Carregue o código no Arduino usando a IDE Arduino.
3. Abra o monitor serial para visualizar dados de pulso e frequência cardíaca.
4. O LCD exibirá informações sobre batimentos cardíacos quando detectados.

## Circuito

![Foto 1](https://raw.githubusercontent.com/DSantosxTech/sensor-de-batimentos/main/github/galeria%20(1).jpeg)
![Foto 2](https://raw.githubusercontent.com/DSantosxTech/sensor-de-batimentos/main/github/galeria%20(2).jpeg)
![Circuito Diagrama](https://raw.githubusercontent.com/DSantosxTech/sensor-de-batimentos/main/github/Circuito%20Diagrama.png)

## Assista o funcionamento no vídeo abaixo:
[![Youtube](https://img.shields.io/badge/YouTube-%23FF0000.svg?style=for-the-badge&logo=YouTube&logoColor=white)](https://youtube.com/shorts/8-nIhp7vw5Y?si=Inq4S-i6j-86-ig-)

## Aprenda como fazer assistindo o tutorial:
[![Youtube](https://img.shields.io/badge/YouTube-%23FF0000.svg?style=for-the-badge&logo=YouTube&logoColor=white)](https://youtu.be/x_fcC0qvXmI?si=grnr9d38WYIHxS77)