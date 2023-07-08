# Programación de Microcontroladores - Workspace

**Autor:** Ing. Leandro Soria

**Kit de Desarrollo:** [NUCLEO-F413ZH](https://www.st.com/en/evaluation-tools/nucleo-f413zh.html)

## Descripción
El siguiente repositorio contiene todos los ejemplos y prácticas correspondientes al curso **Programación de Microcontroladores (PdM)**, en el marco del **Curso de Especialización en Sistemas Embebidos (CESE)** dictado por la Facultad de Ingeniería de la Universidad de Buenos Aires (FI-UBA)

## Instrucciones de Uso

### Importar workspace/proyectos
Este repositorio se trata de un workspace de STM32CubeIDE, asi que con clonar el repositorio y abrir el directorio como un workspace ya se debería reconocer la estructura del workspace con sus respectivos proyectos. En caso de que no aparezcan los mismos:

* `File` -> `Import...` -> `General` -> `Existing Projects into Workspace`
* `Select root directory:` -> (elegir carpeta del workspace aka directorio donde se clonó el repositorio)
* Seleccionar proyectos que aparezcan en el listado `Projects`
* Listo!

### Compilar proyectos
(TBD)

### Cargar el Firmware
(TBD)

## Proyectos disponibles
* `Ej0_blinky`: Version del repo original. Hace titilar el LED1 de la placa
* `Ej0_blinky_413ZH`: Version adaptada a la F413ZH.
* `Ej1_pushButton`: Version del repo original. Hace titilar el LED1 de la placa cuando se aprieta el User Button.
* `Ej1_pushButton_413ZH`: Version adaptada a la F413ZH.
* `Ej2_uart`: Version del repo original.
* `Ejercicio_delayNB_1`: Version del repo original.
* `practica-01`: [Descripción del problema](https://docs.google.com/document/d/1caB5n22QeaETAT2AJ_aeaYWFDyMaYfSJhRpApwApLzw/edit). 
* `practica-02`: [Descripción del problema](https://docs.google.com/document/d/173_tBdN7rIAfT5S-5lSsJWCGIJHKG1ay3VvMh4yfM58/edit). 
* `practica-03`: [Descripción del problema](https://docs.google.com/document/d/1o45cu4Y6-IP3PXC4nwgnLuBHyxaYz1LkqilcBYN1GCU/edit). 

## Links de Referencia
* [Programación de Microcontroladores - Sitio Oficial](https://sites.google.com/cursoscapse.com/pdm/material?authuser=0)
* [DS11581 - STM32F413xH Datasheet](https://www.st.com/resource/en/datasheet/stm32f413zh.pdf)
* [UM1725 - Description of STM32F4 HAL and low-layer drivers (PDF)](https://www.google.com/url?sa=t&rct=j&q=&esrc=s&source=web&cd=&ved=2ahUKEwio4pKV_ub_AhU2rZUCHVSeBiwQFnoECAsQAQ&url=https%3A%2F%2Fwww.st.com%2Fresource%2Fen%2Fuser_manual%2Fum1725-description-of-stm32f4-hal-and-lowlayer-drivers-stmicroelectronics.pdf&usg=AOvVaw21r2dLlr83WM6rfjwZ3NM-&opi=89978449)