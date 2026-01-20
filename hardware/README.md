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
<div align="center">
<br><figure align="center">
  <div> 
    <img src="../documentação/assets/OIP.png" width="333" label="Figura 1 - STM32F103C8T6 MCU">
    <img src="../documentação/assets/STM32F103C8T6_Blue_Pill-1.jpg" width="500">
  </div>
</figure><br>
<div align="center">
  <figcaption>
    <b>Figura 1</b> – Microcontrolador STM32F103C8T6 e sua Dev Board (Blue Pill)
  </figcaption>
</div><br>
</div>


O STM32F103C8T6 foi escolhido por oferecer um equilíbrio adequado entre desempenho, custo e disponibilidade. O núcleo ARM Cortex-M3 operando a até 72 MHz é suficiente para aplicações gráficas simples, leitura de entradas e controle de periféricos.

A utilização do módulo Blue Pill reduz a complexidade do projeto, facilita testes e depuração e permite foco no desenvolvimento do restante do hardware.

### 4.2 Display – Nokia 5110 (PCD8544)

<br><div align="center">
  <figure>
      <img src="../documentação/assets/img58.jpg" style="transform: rotate(180deg); width: 300px;">
  </figure><br>
</div><br>

<div align="center">
  <figcaption>
    <b>Figura 2</b> – Display LCD Nokia 5110
  </figcaption>
</div><br>

O display Nokia 5110 foi selecionado por sua simplicidade de interface, baixo consumo de energia e ampla documentação disponível. Sua resolução de 84x48 pixels é adequada para jogos 2D simples e menus gráficos.

### 4.3 Armazenamento – Cartão SD (Modo SPI)

<br><div align="center">
  <figure>
      <img src="../documentação/assets/img7.jpg" width="300">
  </figure><br>
</div><br>

<div align="center">
  <figcaption>
    <b>Figura 3</b> – Módulo Micro Cartão SD
  </figcaption>
</div><br>

O cartão SD operando em modo SPI oferece alta capacidade de armazenamento com baixa complexidade de hardware. Ele é utilizado para armazenamento de dados persistentes como estados de jogos e configurações.


### 4.4 Interface de Entrada – Botões Táteis
Os botões táteis foram escolhidos por sua robustez, simplicidade elétrica e fácil integração com GPIOs do microcontrolador. O tratamento de debounce é realizado via software.



### 4.5 Áudio – Buzzer Passivo
O buzzer passivo permite geração de áudio por PWM, utilizando timers internos do STM32. Essa abordagem oferece flexibilidade sonora com baixo custo e simplicidade de hardware.

---

## 5. Projeto do Esquemático

O esquemático elétrico do videogame portátil foi desenvolvido com foco em simplicidade, robustez elétrica e boas práticas de projeto para sistemas embarcados. A organização do circuito segue uma divisão funcional clara, permitindo fácil compreensão, manutenção e futuras modificações.

<figure align="center">
  <img src="../documentação/assets/ProtoGame-schematic-v1_page-0001.jpg" width="1000">
  <figcaption>
    <b>Figura 4</b> – Esquemático elétrico versão v1
  </figcaption>
</figure>

<p align="center">
  <a href="ProtoGame/ProtoGame-schematic-v1.pdf">Esquemático elétrico completo (PDF)</a>
</p>

---

### 5.1 Circuito de Alimentação

O sistema foi projetado para operar integralmente em **3,3 V**, tensão compatível com o microcontrolador STM32F103C8T6 e com todos os periféricos utilizados. A alimentação principal é fornecida por uma bateria, cuja tensão é regulada por um regulador linear **AMS1117-3.3**.

O regulador AMS1117 foi escolhido por sua ampla disponibilidade e facilidade de aplicação, sendo adequado para projetos educacionais e protótipos funcionais. Apesar de sua eficiência inferior quando comparado a reguladores chaveados, seu uso é justificado pelo consumo moderado do sistema e pela simplicidade do circuito.

Na entrada e na saída do regulador são utilizados capacitores de filtragem, conforme recomendado pelo fabricante, garantindo estabilidade da tensão e evitando oscilações indesejadas.

---

### 5.2 Capacitores Bulk e Filtragem de Baixa Frequência

O capacitor **bulk** de maior valor (47 µF) foi inserido na linha de alimentação principal com o objetivo de absorver variações lentas de corrente e fornecer energia instantânea durante picos de consumo, especialmente durante inicialização do sistema e acesso ao cartão SD.

Além do capacitor bulk principal, capacitores adicionais de **4,7 µF** são distribuídos próximos a blocos específicos do circuito, atuando como suporte local de energia. Essa abordagem reduz quedas momentâneas de tensão e melhora a estabilidade global da alimentação.

O uso combinado de capacitores de diferentes valores cria um efeito de filtragem em larga faixa de frequência, aumentando a confiabilidade do sistema.

---

### 5.3 Desacoplamento do Microcontrolador e Periféricos

Cada circuito integrado presente no projeto possui capacitores cerâmicos de **100 nF** posicionados o mais próximo possível de seus pinos de alimentação. Esses capacitores atuam como desacoplamento de alta frequência, reduzindo ruídos gerados por comutações internas e interferências no barramento de alimentação.

O microcontrolador STM32F103C8T6 possui múltiplos pinos de alimentação (VDD e VDDA), sendo essencial o desacoplamento individual de cada domínio. O domínio analógico (VDDA) recebe atenção especial, garantindo menor interferência em funções sensíveis internas do microcontrolador.

Essa prática evita resets espúrios, falhas de comunicação SPI e comportamentos instáveis durante operação contínua.

---

### 5.4 Comunicação SPI

A comunicação SPI é utilizada para interface com o display gráfico Nokia 5110 e com o módulo de cartão SD. Ambos os dispositivos compartilham as linhas de clock (SCK) e dados (MOSI e MISO), utilizando sinais de **Chip Select independentes** para controle de acesso.

Foram adicionados resistores em série nas linhas de clock e dados, próximos ao microcontrolador, com a finalidade de reduzir efeitos de ringing, overshoot e reflexões em trilhas mais longas. Essa técnica melhora significativamente a integridade do sinal, especialmente no acesso ao cartão SD, que é mais sensível a ruídos.

Resistores de pull-up nos sinais de Chip Select garantem que os dispositivos permaneçam desabilitados durante a inicialização do sistema.

---

### 5.5 Interface com o Display LCD

O display Nokia 5110 utiliza o barramento SPI para comunicação de dados e comandos, além de sinais adicionais de controle como **Reset** e **Data/Command**. Esses sinais são controlados diretamente por GPIOs do microcontrolador.

A alimentação do display é feita em 3,3 V, eliminando a necessidade de conversores de nível lógico. O controle do backlight é realizado por meio de um pino dedicado, permitindo economia de energia quando o display não está em uso.

A escolha desse display contribui para um circuito simples, de baixo consumo e fácil integração.

---

### 5.6 Interface com o Cartão SD

O cartão SD é operado em **modo SPI**, reduzindo significativamente a complexidade do hardware quando comparado ao modo SD nativo. Essa abordagem é suficiente para leitura e escrita de dados de pequeno volume, como estados de jogos e configurações.

Capacitores de desacoplamento dedicados são utilizados próximos ao módulo SD, devido aos picos de corrente característicos durante operações de escrita. Essa decisão é fundamental para evitar falhas intermitentes de comunicação.

---

### 5.7 Interface de Entrada – Botões

Os botões táteis são conectados diretamente aos pinos GPIO do microcontrolador, utilizando resistores de polarização de **10 kΩ** para garantir níveis lógicos definidos quando não acionados. Essa configuração evita estados flutuantes e simplifica o circuito.

O tratamento de debounce é realizado via software, reduzindo a quantidade de componentes externos e mantendo o esquemático mais enxuto.

---

### 5.8 Circuito de Áudio

O circuito de áudio é composto por um buzzer passivo acionado por um pino de timer do STM32F103, permitindo geração de sinais PWM em diferentes frequências. Essa abordagem possibilita a criação de efeitos sonoros simples, adequados para um videogame portátil.

A escolha do buzzer passivo oferece maior flexibilidade sonora em comparação a buzzers ativos, mantendo baixo custo e simplicidade de implementação.

---

## 6. Bill of Materials (BoM)

A Bill of Materials apresenta todos os componentes utilizados no projeto, sendo essencial para reprodução do hardware, aquisição de peças e validação do circuito.

<div align="center">

<a id="tab-bom"></a>

**Tabela 2** – Bill of Materials (BoM).

| Referência | Qtd | Valor / Modelo | Função |
|:----------|:---:|----------------|--------|
| BT1 | 1 | Battery | Alimentação do sistema |
| BZ1 | 1 | Buzzer | Saída de áudio |
| C1–C2, C4–C6, C9 | 6 | 100 nF | Desacoplamento |
| C3 | 1 | 47 µF | Capacitor bulk |
| C7–C8 | 2 | 4.7 µF | Filtragem local |
| J1 | 1 | SD Card Module | Armazenamento |
| LCD_Nokia1 | 1 | Nokia 5110 | Display gráfico |
| R1–R11 | 11 | 10 kΩ | Pull-up / Pull-down |
| SW1 | 1 | SW_DPST_x2 | Chave geral |
| SW2–SW10 | 9 | SW_MEC_5E | Botões |
| U1 | 1 | STM32F103C8T6 | Microcontrolador |
| U2 | 1 | AMS1117-3.3 | Regulador 3,3 V |


</div>

---

## 6. Definição de Pinout



<br><div align="center">
  <figure>
      <img src="../documentação/assets/IMG-20251220-WA0038.jpg" width="400">
  </figure><br>
</div><br>

<div align="center">
  <figcaption>
    <b>Figura 5</b> – IOC MCU Pinout
  </figcaption>
</div><br>

### 6.1 Tabela de Pinout


<br><div align="center">

<a id="tab-pinout"></a>

**Tabela 1** – Mapeamento de pinos do STM32F103C8T6.
  
| Pino | Nome (MCU) | Função |
|:-----:|:------------:|:--------|
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

</div><br>


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
