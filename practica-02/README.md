# Práctica 02

## Objetivo
Implementar un módulo de software para trabajar con retardos no bloqueantes. 

## Punto 1
Implementar las funciones auxiliares necesarias para usar retardos no bloqueantes en un archivo fuente `main.c` con su correspondiente archivo de cabecera `main.h`.

En `main.h` se deben ubicar los prototipos de las siguientes funciones y las declaraciones:

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

En `main.c` se deben ubicar la implementación de todas las funciones.

### Consideraciones para la implementación:
1. `delayInit` debe cargar el valor de duración del retardo en la estructura, en el campo correspondiente. No debe iniciar el conteo del retardo. Debe inicializar el flag `running` en `false`.
2. `delayRead` debe verificar el estado del flag `running`:
    * `false`, tomar marca del tiempo y cambiar `running` a `true`
    * `true`, hacer la cuenta para saber si el tiempo del retardo se cumplió o no (`marca_de_tiempo_actual - marca_de_tiempo_inicial >= duracion_del_retardo?`) 
    y devolver un valor booleano que indique si el tiempo se cumplió o no.
    * Cuando el tiempo se cumple debe cambiar el flag `running` a `false`.
3. `delayWrite` debe permitir cambiar el tiempo de duración de un delay existente.

**NOTA:** Para obtener una marca de tiempo se puede usar la función `HAL_GetTick()` que devuelve un valor que se incrementa cada 1ms y que se puede usar como base de tiempo.

## Punto 2
Implementar un programa que utilice retardos no bloqueantes y  haga titilar en forma periódica e independiente los tres leds de la placa NUCLEO-F413ZH de la siguiente manera:
* `LED1`: 100 ms.
* `LED2`: 500 ms.
* `LED3`: 1000 ms.


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

Por otra parte, en `void delay_init(delay_t* const delay, const tick_t duration)` no se realizó la validación del argumento `duration` pues se configuró el proyecto para que incluya las flags de compilación `-Wall` y `-Wextra`. Lo ideal sería agregar `-Werror` tambien para que la comparación entre enteros con y sin signo arroje un error, pero al hacer eso aparecieron otros warnings (y por ende errores) correspondientes a la librería HAL de ST.