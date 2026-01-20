# Videogame Portátil com STM32F103 (Blue Pill)

## Sumário
- [1. Introdução](#1-introdução)
- [2. Objetivos do Projeto](#2-objetivos-do-projeto)
  - [2.1 Objetivo Geral](#21-objetivo-geral)
  - [2.2 Objetivos Específicos](#22-objetivos-específicos)
- [3. Visão Geral do Sistema](#3-visão-geral-do-sistema)
  - [3.1 Arquitetura Geral](#31-arquitetura-geral)
  - [3.2 Fluxo Geral de Operação](#32-fluxo-geral-de-operação)
- [4. Escolha dos Componentes](#4-escolha-dos-componentes)
  - [4.1 Microcontrolador – STM32F103C8T6 (Blue Pill)](#41-microcontrolador--stm32f103c8t6-blue-pill)
  - [4.2 Display – Nokia 5110 (PCD8544)](#42-display--nokia-5110-pcd8544)
  - [4.3 Armazenamento – Cartão SD (Modo SPI)](#43-armazenamento--cartão-sd-modo-spi)
  - [4.4 Interface de Entrada – Botões Táteis](#44-interface-de-entrada--botões-táteis)
  - [4.5 Áudio – Buzzer Passivo](#45-áudio--buzzer-passivo)
- [5. Projeto do Esquemático](#5-projeto-do-esquemático)
  - [5.1 Circuito de Alimentação](#51-circuito-de-alimentação)
  - [5.2 Desacoplamento do Microcontrolador e Periféricos](#52-desacoplamento-do-microcontrolador-e-periféricos)
  - [5.3 Comunicação SPI](#53-comunicação-spi)
  - [5.4 Interface com o Display](#54-interface-com-o-display)
  - [5.5 Interface com o Cartão SD](#55-interface-com-o-cartão-sd)
  - [5.6 Interface de Entrada (Botões)](#56-interface-de-entrada-botões)
  - [5.7 Circuito de Áudio](#57-circuito-de-áudio)
- [6. Definição de Pinout](#6-definição-de-pinout)
  - [6.1 Tabela de Pinout](#61-tabela-de-pinout)
  - [6.2 Justificativa do Pinout](#62-justificativa-do-pinout)
- [7. Projeto da PCB](#7-projeto-da-pcb)
  - [7.1 Considerações Gerais](#71-considerações-gerais)
  - [7.2 Primeira Versão da PCB](#72-primeira-versão-da-pcb)
  - [7.3 Segunda Versão da PCB](#73-segunda-versão-da-pcb)
  - [7.4 Análise do Layout Final](#74-análise-do-layout-final)
- [8. Visualização 3D e Montagem](#8-visualização-3d-e-montagem)
  - [8.1 Modelo 3D da PCB](#81-modelo-3d-da-pcb)
  - [8.2 Considerações de Montagem](#82-considerações-de-montagem)
- [9. Conclusão](#9-conclusão)
- [10. Referências](#10-referências)

---

## 1. Introdução
Este documento apresenta a **documentação técnica do hardware** de um videogame portátil desenvolvido com foco educacional e experimental, baseado no microcontrolador **STM32F103C8T6 (Blue Pill)**. O objetivo principal desta documentação é **descrever, justificar e analisar as decisões de projeto de hardware**, desde a escolha dos componentes até o esquemático elétrico e o layout final da PCB.

O projeto foi concebido para integrar conceitos de eletrônica digital, sistemas embarcados e boas práticas de projeto de placas de circuito impresso, priorizando simplicidade, modularidade e confiabilidade elétrica. Questões relacionadas a firmware são abordadas apenas quando necessárias para justificar decisões de hardware.

---

## 2. Objetivos do Projeto

### 2.1 Objetivo Geral
Desenvolver e documentar o **hardware de um videogame portátil**, incluindo esquemático elétrico e PCB, utilizando componentes amplamente disponíveis e de baixo custo, garantindo funcionamento estável e possibilidade de expansão futura.

### 2.2 Objetivos Específicos
- Selecionar um microcontrolador adequado para aplicações gráficas simples e controle de periféricos  
- Projetar um circuito de alimentação estável em 3,3 V  
- Implementar comunicação SPI confiável para display gráfico e cartão SD  
- Desenvolver uma interface física com botões e sinalização sonora  
- Aplicar boas práticas de desacoplamento, filtragem e layout de PCB  

---

## 3. Visão Geral do Sistema

### 3.1 Arquitetura Geral
O sistema é composto pelos seguintes blocos funcionais:
- Unidade de processamento baseada no STM32F103  
- Interface de usuário composta por display gráfico, botões e buzzer  
- Sistema de armazenamento removível via cartão SD  
- Circuito de alimentação em 3,3 V  

### 3.2 Fluxo Geral de Operação
1. Energização do circuito e estabilização da alimentação  
2. Inicialização do microcontrolador  
3. Configuração dos periféricos SPI  
4. Leitura das entradas do usuário  
5. Atualização do display e geração de áudio  

---

## 4. Escolha dos Componentes

### 4.1 Microcontrolador – STM32F103C8T6 (Blue Pill)
O STM32F103C8T6 foi escolhido por oferecer um equilíbrio adequado entre desempenho, custo e disponibilidade. O núcleo ARM Cortex-M3 operando a até 72 MHz é suficiente para aplicações gráficas simples, leitura de entradas e controle de periféricos.

A utilização do módulo Blue Pill reduz a complexidade do projeto, facilita testes e depuração e permite foco no desenvolvimento do restante do hardware.

---

### 4.2 Display – Nokia 5110 (PCD8544)
O display Nokia 5110 foi selecionado por sua simplicidade de interface, baixo consumo de energia e ampla documentação disponível. Sua resolução de 84x48 pixels é adequada para jogos 2D simples e menus gráficos.

---

### 4.3 Armazenamento – Cartão SD (Modo SPI)
O cartão SD operando em modo SPI oferece alta capacidade de armazenamento com baixa complexidade de hardware. Ele é utilizado para armazenamento de dados persistentes como estados de jogos e configurações.

---

### 4.4 Interface de Entrada – Botões Táteis
Os botões táteis foram escolhidos por sua robustez, simplicidade elétrica e fácil integração com GPIOs do microcontrolador. O tratamento de debounce é realizado via software.

---

### 4.5 Áudio – Buzzer Passivo
O buzzer passivo permite geração de áudio por PWM, utilizando timers internos do STM32. Essa abordagem oferece flexibilidade sonora com baixo custo e simplicidade de hardware.

---

## 5. Projeto do Esquemático



[Esquemático elétrico completo](hardware/ProtoGame/ProtoGame-schematic-v1.pdf)


### 5.1 Circuito de Alimentação
O sistema opera integralmente em 3,3 V. Capacitores de bulk e cerâmicos são utilizados para garantir estabilidade da tensão e filtragem de ruídos.

### 5.2 Desacoplamento do Microcontrolador e Periféricos
Cada CI possui capacitores de desacoplamento próximos aos pinos de alimentação, reduzindo ruídos e garantindo operação confiável.

### 5.3 Comunicação SPI
O barramento SPI é compartilhado entre display e cartão SD, utilizando sinais de Chip Select independentes e resistores em série para integridade de sinal.

### 5.4 Interface com o Display
O display utiliza SPI e sinais adicionais de controle, conectados diretamente aos GPIOs do STM32.

### 5.5 Interface com o Cartão SD
O cartão SD opera em modo SPI, com capacitores dedicados para suportar picos de corrente.

### 5.6 Interface de Entrada (Botões)
Os botões são conectados diretamente aos GPIOs, com resistores de polarização e debounce via software.

### 5.7 Circuito de Áudio
O buzzer passivo é acionado por PWM, permitindo geração de tons variados.

---

## 6. Definição de Pinout

### 6.1 Tabela de Pinout

| Pino | Nome (MCU) | Função |
|-----:|------------|--------|
| 1 | VBAT | Alimentação de bateria |
| 5 | PD0 | Cristal externo (OSC_IN) |
| 6 | PD1 | Cristal externo (OSC_OUT) |
| 7 | NRST | Reset |
| 10 | PA0 | Reset do LCD |
| 11 | PA1 | LCD Data/Command |
| 13 | PA3 | CS do LCD |
| 14 | PA4 | CS do Cartão SD |
| 15 | PA5 | SPI1 SCK |
| 16 | PA6 | SPI1 MISO |
| 17 | PA7 | SPI1 MOSI |
| 18 | PB0 | Backlight do LCD |
| 29 | PA8 | Buzzer |
| 30–42 | PA9–PB6 | Botões |
| 34 | PA13 | SWDIO |
| 37 | PA14 | SWCLK |
| 44 | BOOT0 | Seleção de boot |

---

### 6.2 Justificativa do Pinout
O pinout foi definido priorizando o uso do SPI1, timers dedicados para PWM e pinos compatíveis com depuração SWD, garantindo organização e facilidade de manutenção.

---

## 7. Projeto da PCB

### 7.1 Considerações Gerais
A PCB foi projetada considerando dimensões compactas, trilhas curtas para SPI e bom plano de terra.

### 7.2 Primeira Versão da PCB
A primeira versão serviu como validação elétrica e identificação de limitações de layout.

### 7.3 Segunda Versão da PCB
A segunda versão incorporou melhorias de roteamento, ergonomia e posicionamento dos componentes.

### 7.4 Análise do Layout Final
O layout final apresenta melhor integridade de sinal, organização visual e facilidade de montagem.

---

## 8. Visualização 3D e Montagem

### 8.1 Modelo 3D da PCB
Modelos 3D foram gerados no KiCad para validação mecânica e visual.

### 8.2 Considerações de Montagem
O posicionamento dos componentes facilita acesso ao display, botões e cartão SD.

---

## 9. Conclusão
O projeto atinge os objetivos propostos, resultando em um hardware funcional, organizado e adequado para fins educacionais e experimentais.

---

## 10. Referências
- Datasheet STM32F103  
- Documentação do display PCD8544  
- Application Notes da STMicroelectronics  
- KiCad Documentation  
