<img width=100% src="https://capsule-render.vercel.app/api?type=waving&color=00bfbf&height=120&section=header"/>
<h1 align="center"><img align="center" style="border-radius: 100%;" src="https://moodle.embarcatech.cepedi.org.br/pluginfile.php/1/theme_moove/logo/1733422525/Group%20658.png" width="300px;" alt=""><br>Animation BitDogLab</h1>

<h3 align="center">
   Para consolidar a compreensão dos conceitos relacionados ao uso de interrupções no microcontrolador RP2040 e explorar as funcionalidades da placa de desenvolvimento BitDogLab, propõe-se a seguinte tarefa prática. 
</h3>

<h4 align="center">
	✅  Concluído ✅
</h4>

---

Tabela de conteúdos
=================
<!--ts-->
   * [Sobre o projeto](#-sobre-o-projeto)
   * [Layout Repositorio Github](#-layout-repositorio-github)
   * [Funcionalidades](#-Funcionalidades)
   * [Como executar o projeto](#-como-executar-o-projeto)
   * [Imagens do Projeto](#-imagens-do-projeto)
     * [Imagem](#-projeto-na-extensão-wokwi-simulator-no-visual-studio)
     * [Vídeo](#-video-do-projeto)
   * [Tecnologias](#-tecnologias)
     * [Websites](#-websites)
     * [Utilitários](#user-content-server--nodejs----typescript)
   * [Contribuidores](#-contribuidores)
   * [Licença](#-licença)
<!--te-->

---

## 💻 Sobre o projeto

Com o emprego da função add_repeating_timer_ms(), presente na ferramenta Pico SDK, projete um semáforo com temporização de 3 segundos para cada alteração de sinal. O fluxograma simplificado de atuação do semáforo.

Projeto desenvolvido durante o curso de Formação Básica em Software Embarcado oferecido pela [Embarcatech](https://embarcatech.softex.br).
A Formação Básica em Software Embarcado da Embarcatech é um programa de capacitação profissional técnica destinado a alunos de nível superior e técnico em Tecnologias da Informação e Comunicação (TIC) e áreas correlatas, focado em tecnologias de Sistemas Embarcados.

---

## 🎨 Layout Repositorio Github
<i>
temporizador_periodico

- .vscode/&emsp;&emsp;&emsp;&emsp;# Arquivos .json
  - c_cpp_properties.json
  - cmake-kits.json
  - extensions.json
  - launch.json
  - settings.json
  - tasks.json

- assets/&emsp;&emsp;&emsp;&emsp;# Midias do Projeto
  - image/
    - diagram.png
  - video/
    - demonstration.mp4

- include/&emsp;&emsp;&emsp;&emsp;# includes do projeto
  - buttons.h
  - led_red.h
  - matriz_led.h
  - sprites.h

- lib/&emsp;&emsp;&emsp;&emsp;# bibliotecas do projeto
  - ws2812.pio
    
- src/&emsp;&emsp;&emsp;&emsp;# códigos do projeto
  - buttons.c
  - led_red.c
  - matriz_led.c
  - sprites.c

- .gitattributes

- .gitignore

- CMakeLists.txt

- diagram.json&emsp;&emsp;&emsp;&emsp;# Arquivo Wokwi do BitDogLab

- LICENSE

- pico_sdk_import.cmake

- README.md

- temporizador_periodico.c&emsp;&emsp;&emsp;&emsp;# Código principal do projeto

- wokwi.toml
</i>

---

## ⚙️ Funcionalidades
- Teclas Funcionais:
  - 1) O acionamento dos LEDs (sinais do semáforo) deve iniciar na cor vermelha, conforme orientação presente na Figura 1, alterando para amarela e, em seguida, verde.
  - 2) O temporizador deve ser ajustado para um atraso de 3 segundos (3.000ms).
  - 3) A mudança de estado dos LEDs deve ser implementa na função de call-back do temporizador, a exemplo da rotina trabalhada na aula síncrona - repeating_timer_callback().
  - 4) A rotina principal, presente no interior da estrutura de repetição while, deve imprimir algum tipo de informação a cada segundo (1.000 ms) - a mensagem enviada pela porta serial fica a critério do discente.
  - 5) Com o emprego da Ferramenta Educacional BitDogLab, faça um experimento com o código deste exercício utilizando o LED RGB – GPIOs 11, 12 e 13.


---

## 🚀 Como executar o projeto

💡Siga as instruções abaixo para configurar, compilar e executar o programa.

### Pré-requisitos

Antes de começar, você vai precisar ter instalado em sua máquina as seguintes ferramentas:
  - Sistema operacional Linux, macOS ou Windows (com suporte a Makefile).
  - [Git](https://git-scm.com) (Opcional, mas recomendado),
  - [GCC compilador](https://gcc.gnu.org)
  - [Biblioteca Pico-Sdk](https://github.com/raspberrypi/pico-sdk.git) (OBS: Necessário caso queira modificar o projeto)

Além disto é bom ter um editor para trabalhar com o código como [VSCode](https://code.visualstudio.com/) com a extensão [Raspberry](https://marketplace.visualstudio.com/items?itemName=raspberry-pi.raspberry-pi-pico)  e usar o simulador web [Wokwi](https://wokwi.com) (ou a extensão do Vscode [Wokwi Simulator](https://marketplace.visualstudio.com/items?itemName=Wokwi.wokwi-vscode))

### 🎲 Dowload do Projeto

#### Dowload do Projeto no Desktop
- Opção 1:
  - Abra o terminal de comando Git Bash 
  - Clone o repositório do GitHub com o comando:
```
$ git clone https://github.com/ferreiramateusalencar/temporizador_periodico.git
```
- Opção 2:
  - No repósitorio [Animation-BitDogLab](https://github.com/ferreiramateusalencar/temporizador_periodico) aperte o Botão <i><>code</i>
  - Aperte a opção <i>Dowload ZIP</i>


### 🎲 Rodando a Animação no Wokwi

#### Wokwi Web
- Entre no navegador e digite [Wokwi.com]()
- Faça Upload dos Arquivos <i>diagram.json</i>
- Faça upload do aquivo temporizador_periodico <i>temporizador_periodico.c</i> e da pasta <i>src/</i>

#### Extensão Wokwi
- Abra o Visual Studio
- Na aba da extensão [Raspberry Pi Pico](https://marketplace.visualstudio.com/items?itemName=raspberry-pi.raspberry-pi-pico), aperte para Importar o projeto
- Compile o projeto
- crie um arquivo (caso não tenha no projeto) <i>wokwi.toml</i> e digite o código:
```
[wokwi]
version = 1
firmware = 'build/temporizador_periodico.hex'
elf = 'build/temporizador_periodico.elf'
```
- Abra o arquivo <i>diagram.json</i>


### 🎲 Rodando as Animações na placa BitdogLab

#### Placa BitDogLab
- Através de um cabo USB conecte a placa ao seu Disposito
- Aperte o Botão Bootsel e Reset 

#### VsCode Studio
- Abra o Visual Studio
- Na aba da extensão [Raspberry Pi Pico](https://marketplace.visualstudio.com/items?itemName=raspberry-pi.raspberry-pi-pico), aperte para Importar o projeto
- Compile o projeto
- Entre na pasta <i>build/</i>
- Cole o arquivo <i>temporizador_periodico.uf2</i> no armazenamento placa BitDog
<br>

---

## 🎥 Imagens do Projeto

### 💿 Diagrama Visual do Projeto
<p align="center"><img width="700" height="400" src="https://github.com/ferreiramateusalencar/temporizador_periodico/blob/main/assets/image/diagram.png"></p>

### 💿 Video do Projeto na Extensão Wokwi



https://github.com/user-attachments/assets/1cb5ff3f-3bc1-4b1f-a468-651a5e83f5a7





- Dowload HD video completo: https://github.com/ferreiramateusalencar/temporizador_periodico/blob/main/assets/video/demonstration.mp4

---

## 🛠 Tecnologias

As seguintes ferramentas foram usadas na construção do projeto:

#### **Websites**
-   **[Visual Studio code](https://code.visualstudio.com)**
-   **[Github](https://github.com)**
-   **[Wokwi Web](https://gcc.gnu.org)**


#### **Utilitários**

-   Editor:  **[Visual Studio Code](https://code.visualstudio.com/)**  → Extensions:  **[C/C++](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools), [C/C++ Compile Run](https://marketplace.visualstudio.com/items?itemName=danielpinto8zz6.c-cpp-compile-run), [Raspberry Pi Pico](https://marketplace.visualstudio.com/items?itemName=raspberry-pi.raspberry-pi-pico) e [Wokwi Simulator](https://marketplace.visualstudio.com/items?itemName=Wokwi.wokwi-vscode)**
-   **[Git](https://git-scm.com)**


---

## 👨‍💻 Membro

GRUPO 1, SUBGRUPO 3 da Embarcatech <br/>
Mentor: MANOEL MESSIAS DA SILVA JUNIOR

<table>
  <tr>
    <td align="center"><img style="border-radius: 50%;" src="https://avatars.githubusercontent.com/u/86336670?v=4" width="100px;"/><br/><a href="https://github.com/ferreiramateusalencar">Mateus A. Ferreira<a/><br/><br/><a href="https://github.com/ferreiramateusalencar/Conversor-de-Unidades-C" title="Líder">🌐</a></td>
  </tr>
</table>
      
---

## 📄 Licença

Este projeto está sob a licença do discente Mateus Alencar ferreira, da Formação Básica em Software Embarcado da Embarcatech - Veja o arquivo <a href="https://github.com/ferreiramateusalencar/temporizador_periodico/blob/main/LICENSE">License.md<a/>

<img width=100% src="https://capsule-render.vercel.app/api?type=waving&color=00bfbf&height=120&section=footer"/>
