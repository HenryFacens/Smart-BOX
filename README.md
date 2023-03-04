# Protótipo de Caixa Inteligente com Componentes Arduino e ESP-01

Este projeto consiste em um protótipo de caixa inteligente utilizando componentes Arduino e ESP-01. A comunicação entre os dispositivos é realizada através do protocolo MQTT, permitindo a integração com outros sistemas. Além disso, a caixa inteligente possui interação com o framework Django, que possibilita a criação de aplicações web e a visualização dos dados coletados pelos sensores.

## Componentes Utilizados

- Arduino Uno
- ESP-01
- Sensores de temperatura e umidade
- Ruido
- LCD
- Fonte de alimentação

## Funcionamento

Os sensores de temperatura e umidade coletam dados e enviam para o ESP-01 através do protocolo MQTT. O ESP-01, por sua vez, envia os dados para o Arduino Uno, que faz o controle do módulo relé responsável por ligar ou desligar um aparelho, como um ventilador, por exemplo.

Os dados coletados pelos sensores são armazenados em um banco de dados e podem ser visualizados através de uma aplicação web desenvolvida no framework Django.

Além disso, o protótipo utiliza o protocolo de rede LoRaWAN com autenticação over-the-air (OTAA), que permite a comunicação sem fio de longo alcance entre dispositivos.
