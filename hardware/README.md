# Videogame Portátil com STM32F103C8Tx (Blue Pill)

## Sumário
- [1. Introdução](#1-introdução)
- [2. Objetivos do Projeto](#2-objetivos-do-projeto)
  - [2.1 Objetivo Geral](#21-objetivo-geral)
  - [2.2 Objetivos Específicos](#22-objetivos-específicos)
- [3. Visão Geral do Sistema](#3-visão-geral-do-sistema)
  - [3.1 Arquitetura Geral](#31-arquitetura-geral)
  - [3.2 Fluxo de Funcionamento](#32-fluxo-de-funcionamento)
- [4. Escolha dos Componentes](#4-escolha-dos-componentes)
  - [4.1 Microcontrolador – STM32F103C8T6](#41-microcontrolador--stm32f103c8t6-blue-pill)
  - [4.2 Display – Nokia 5110 (PCD8544)](#42-display--nokia-5110-pcd8544)
  - [4.3 Armazenamento – Cartão SD](#43-armazenamento--cartão-sd-modo-spi)
  - [4.4 Interface de Entrada – Botões Táteis](#44-interface-de-entrada--botões-táteis)
  - [4.5 Áudio – Buzzer Passivo](#45-áudio--buzzer-passivo)
- [5. Projeto do Esquemático](#5-projeto-do-esquemático)
- [6. Definição de Pinout](#6-definição-de-pinout)
- [7. Projeto da PCB](#7-projeto-da-pcb)
- [8. Visualização 3D e Montagem](#8-visualização-3d-e-montagem)
- [9. Conclusão](#9-conclusão)
- [10. Referências](#10-referências)

---

## 1. Introdução
Este documento apresenta a **documentação técnica do hardware** de um videogame portátil desenvolvido com foco educacional e experimental, baseado no microcontrolador **STM32F103C8T6 (Blue Pill)**. O objetivo principal desta documentação é **descrever, justificar e analisar as decisões de projeto de hardware**, desde a escolha dos componentes até o esquemático elétrico e o layout final da PCB.

O projeto foi concebido para integrar conceitos de eletrônica digital, sistemas embarcados e boas práticas de projeto de placas de circuito impresso, priorizando simplicidade, modularidade e confiabilidade elétrica.

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
O sistema é composto pelos seguintes blocos principais:
- Microcontrolador STM32F103 (unidade de processamento)
- Display gráfico monocromático
- Interface de entrada por botões
- Armazenamento externo via cartão SD
- Circuito de áudio simples (buzzer)
- Circuito de alimentação em 3,3 V

Todos os blocos são integrados em uma única placa de circuito impresso, visando reduzir conexões externas e melhorar a confiabilidade do sistema.

### 3.2 Fluxo de Funcionamento
O funcionamento básico do hardware segue a seguinte sequência:
1. Alimentação do sistema e estabilização da tensão
2. Inicialização do microcontrolador
3. Ativação dos periféricos conectados ao barramento SPI
4. Leitura das entradas de usuário
5. Atualização do display e acionamento do áudio conforme necessário

---

## 4. Escolha dos Componentes

### 4.1 Microcontrolador – STM32F103C8T6 (Blue Pill)
O STM32F103C8T6 foi escolhido por apresentar um **equilíbrio adequado entre desempenho, custo e disponibilidade**. O núcleo ARM Cortex-M3 operando a até 72 MHz fornece capacidade suficiente para controle de display gráfico, leitura de entradas e execução de lógica de jogos simples.

Principais características relevantes:
- Arquitetura ARM Cortex-M3
- Frequência de operação até 72 MHz
- Interface SPI, timers e GPIOs em quantidade adequada
- Alimentação em 3,3 V
- Ampla documentação e comunidade ativa

A escolha do módulo Blue Pill, em vez do microcontrolador discreto, reduz a complexidade inicial do projeto, facilita depuração e permite foco no desenvolvimento do restante do hardware.

---

### 4.2 Display – Nokia 5110 (PCD8544)
O display Nokia 5110 foi selecionado por sua **simplicidade de interface e baixo consumo de energia**. Com resolução de 84x48 pixels monocromáticos, atende aos requisitos gráficos do projeto sem demandar grande quantidade de memória ou processamento.

Características que justificam a escolha:
- Interface SPI simples
- Baixo consumo de corrente
- Boa legibilidade
- Ampla utilização em projetos educacionais

---

### 4.3 Armazenamento – Cartão SD (Modo SPI)
O uso de cartão SD em modo SPI foi adotado por oferecer **alta capacidade de armazenamento com baixa complexidade de hardware**. O cartão é utilizado para dados persistentes, como configurações e estados simples de jogo.

---

### 4.4 Interface de Entrada – Botões Táteis
A interface de entrada é composta por botões tácteis individuais conectados diretamente aos GPIOs do microcontrolador, priorizando simplicidade e confiabilidade elétrica.

---

### 4.5 Áudio – Buzzer Passivo
O buzzer passivo foi selecionado para permitir geração de áudio simples por meio de PWM, utilizando timers internos do STM32, possibilitando variação de tons e efeitos sonoros.

---

## 5. Projeto do Esquemático

---

## 6. Definição de Pinout

---

## 7. Projeto da PCB

---

## 8. Visualização 3D e Montagem

---

## 9. Conclusão

---

## 10. Referências
