# Práctica 03

## Objetivo
Implementar un módulo de software para trabajar con retardos no bloqueantes a partir de las funciones creadas en la práctica 02.

## Punto 1
Crear un nuevo proyecto como copia del proyecto realizado para la práctica 02.

Crear una carpeta **API** dentro de la carpeta `Drivers` en la estructura de directorios del nuevo proyecto. Crear dentro de la carpeta `API` subcarpetas `src` e `inc`.

Encapsular las funciones necesarias para usar retardos no bloqueantes en un archivo fuente `API_delay.c` con su correspondiente archivo de cabecera `API_delay.h`, y ubicar estos archivos en la carpeta `API` creada.

En `API_delay.h` se deben ubicar los prototipos de funciones y declaraciones:
```
typedef uint32_t tick_t; // Qué biblioteca se debe incluir para que esto compile?
typedef bool bool_t;	  // Qué biblioteca se debe incluir para que esto compile?
typedef struct{
   tick_t startTime;
   tick_t duration;
   bool_t running;
} delay_t;
void delayInit( delay_t * delay, tick_t duration );
bool_t delayRead( delay_t * delay );
void delayWrite( delay_t * delay, tick_t duration );
```

En `API_delay.c` se debe ubicar la implementación de todas las funciones.

**NOTA:** cuando se agregan carpetas a un proyecto de eclipse se deben incluir en el *include path* para que se incluya su contenido en la compilación. Se debe hacer clic derecho sobre la carpeta con los archivos de encabezamiento y seleccionar la opción `add/remove include path`.

## Punto 2
Implementar un programa que utilice retardos no bloqueantes y haga titilar en forma periódica e independiente los tres leds de la placa NUCLEO-F413ZH de acuerdo a una secuencia predeterminada como en la [práctica 01](https://github.com/lmsoria/cese-pdm-workspace/tree/main/practica-01).

Cada led debe permanecer encendido 200 ms. No debe encenderse más de un led simultáneamente en ningún momento.

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

(Buen momento para encapsular estos LEDs dentro de una `API_leds`, no?)