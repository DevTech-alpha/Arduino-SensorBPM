# Monitor Cardíaco com Arduino - Complemento para o Aplicativo HeartCare

Este programa Arduino monitora a frequência cardíaca com um sensor de pulso e um display LCD I2C.

## Componentes Necessários
- Placa Arduino
- Sensor de Pulso
- LCD com suporte I2C
- LED (opcional)
- Fios

## Bibliotecas Requeridas
- Wire.h
- LiquidCrystal_I2C.h

## Instruções de Conexão
1. Sensor de pulso: Pino Analógico A0.
2. LED (opcional): Pino Digital 13.
3. LCD com suporte I2C: Conecte aos pinos I2C do Arduino.

## Visão Geral do Código
- Inicialização de variáveis, pinos e LCD.
- Configuração da detecção de pulso por interrupção.
- Atualização contínua do monitor serial e do LCD ao detectar batimentos cardíacos.

## Funções Principais
- `configurarInterrupcao()`: Configura a interrupção para detecção de pulso.
- `saidaSerial()`: Emite dados do sinal de pulso para o monitor serial.
- `saidaSerialQuandoBatimentoAcontece()`: Emite dados do batimento cardíaco para o monitor serial e atualiza o LCD.
- `monitorSerialArduinoVisual()`: Mapeia dados do sensor para uma faixa visual (não utilizado atualmente).
- `enviarDadosParaSerial()`: Envia dados para o monitor serial.

## Uso
1. Conecte os componentes conforme as instruções.
2. Carregue o código na placa Arduino.
3. Abra o monitor serial para visualizar os dados.
4. O LCD exibirá informações sobre os batimentos cardíacos.

## Circuito

![Foto 1](https://raw.githubusercontent.com/DSantosxTech/sensor-de-batimentos/main/github/galeria%20(1).jpeg)
![Foto 2](https://raw.githubusercontent.com/DSantosxTech/sensor-de-batimentos/main/github/galeria%20(2).jpeg)
![Circuito Diagrama](https://raw.githubusercontent.com/DSantosxTech/sensor-de-batimentos/main/github/Circuito%20Diagrama.png)

## Assista o funcionamento no vídeo abaixo:
[![Youtube](https://img.shields.io/badge/YouTube-%23FF0000.svg?style=for-the-badge&logo=YouTube&logoColor=white)](https://youtube.com/shorts/XUnM2_iGVNA?si=ZwaqqHhv3dkJSGIT)

## Aprenda como fazer assistindo o tutorial:
[![Youtube](https://img.shields.io/badge/YouTube-%23FF0000.svg?style=for-the-badge&logo=YouTube&logoColor=white)](https://youtu.be/x_fcC0qvXmI?si=grnr9d38WYIHxS77)