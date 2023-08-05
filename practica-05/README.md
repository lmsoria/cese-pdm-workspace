# Práctica 05

## Objetivo
Implementar un módulo de software sencillo para trabajar con la UART. 

## Punto 1
Implementar un módulo de software en un archivos fuente `API_uart.c` con su correspondiente archivo de cabecera `API_uart.h` y ubicarlos en el proyecto dentro de  las carpetas `/drivers/API/src` y `/drivers/API/inc`, respectivamente.

En `API_uart.h` se deben ubicar los prototipos de las funciones públicas:

```
bool_t uartInit();
void uartSendString(uint8_t * pstring);
void uartSendStringSize(uint8_t * pstring, uint16_t size);
void uartReceiveStringSize(uint8_t * pstring, uint16_t size);
```
En `API_uart.c` se deben ubicar los prototipos de las funciones privadas y la implementación de todas las funciones de módulo, privadas y públicas.

### Consideraciones para la implementación:
1. `uartInit()` debe realizar toda la inicialización de la UART.  Adicionalmente, debe imprimir por la terminal serie un mensaje con sus parámetros de configuración. La función devuelve:

    * `true` si la inicialización es exitosa.
    * `false` si la inicialización no es exitosa.
2. `uartSendString(uint8_t *pstring)` recibe un puntero a un string que se desea enviar por la UART completo (hasta el caracter `\0`) y debe utilizar la función de la HAL `HAL_UART_Transmit(...)` para transmitir el string.
3. `uartSendStringSize(uint8_t * pstring, uint16_t size)` recibe un puntero a un string que se desea enviar por la UART y un entero con la cantidad de caracteres que debe enviar. La función debe utilizar `HAL_UART_Transmit(...)` para transmitir el string.

## Punto 2
Sobre el ejercicio de la [práctica 04 (parte 2)](https://github.com/lmsoria/cese-pdm-workspace/tree/main/practica-04-parte-2), implementar un programa que utilice el módulo de uart para informar al usuario cuando se producen los flancos ascendente y descendente.

## Notas del autor
* El proyecto fue creado teniendo como base la placa NUCLEO-F413ZH.
* No se agregó la librería de BSP.
* Para el manejo de los LEDs de decidió crear una API básica que puede consultarse en [`drivers/API/inc/API_leds.h`](https://github.com/lmsoria/cese-pdm-workspace/blob/main/practica-05/Drivers/API/inc/API_leds.h)
* Para el manejo del botón se decidió crear una API básica que puede consultarse en [`drivers/API/inc/API_button.h`](https://github.com/lmsoria/cese-pdm-workspace/blob/main/practica-05/Drivers/API/inc/API_button.h)
* Para evitar duplicar la definicion de `bool_t` se optó por crear un header común llamado [`API_types.h`](https://github.com/lmsoria/cese-pdm-workspace/blob/main/practica-05/Drivers/API/inc/API_types.h) donde se encuentran todas las definiciones de tipos de datos custom.
* Se decidió modificar la forma de `debounce_fsm_init()` para que acepte un puntero a una estructura custom que a su vez contiene punteros a funciones: `typedef void (*button_callback_t)(void)`. De esta forma, desde `main.c` se pueden crear los handlers adecuados (y desacoplados de la lógica interna de la FSM) para procesar ambos eventos triggereados por la FSM.