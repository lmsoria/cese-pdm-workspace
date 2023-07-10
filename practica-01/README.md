# Práctica 01

## Objetivo
Familiarizarse con el entorno de trabajo STM32CubeIDE + NUCLEO-F413ZH + firmware.

## Punto 1
Implementar un programa que genere una secuencia periódica con los leds de la placa NUCLEO-F413ZI.

La secuencia debe seguir el orden: `LED1`, `LED2`, `LED3`, `LED1`,... etc.
Cada led debe permanecer encendido 200 ms. y 200 ms apagado. No debe encenderse más de un led simultáneamente.

## Punto 2
Utilizar el pulsador azul (`USER_BUTTON`) para controlar cómo se recorre la secuencia de leds.  Cada vez que se presiona el pulsador se debe alternar el orden de la secuencia entre:
1. `LED1`, `LED2`, `LED3`, `LED1`, ... etc.
2. `LED1`, `LED3`, `LED2`, `LED1`, ... etc.

## Notas del autor
El proyecto fue creado teniendo como base la placa NUCLEO-F413ZH. No se agregó la librería de BSP. Es por ello que para controlar los LEDs se creó una estructura con la forma:
```
typedef struct
{
    GPIO_TypeDef* port;
    uint16_t pin;
} LedStruct;

```
Luego, los LEDs de la placa se declaran de la siguiente manera:
```
const LedStruct SEQUENCE_LEDS[LEDS_QTY] =
{
    {LD1_GPIO_Port, LD1_Pin},
    {LD2_GPIO_Port, LD2_Pin},
    {LD3_GPIO_Port, LD3_Pin}
};
```