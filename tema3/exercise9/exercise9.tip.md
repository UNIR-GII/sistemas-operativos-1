
# Consejos para Resolver el Ejercicio 9 en C

Este documento provee las herramientas y conocimientos necesarios para resolver el ejercicio de modificación de variables globales desde dos procesos en C, sin entregar la solución completa. La meta es que el estudiante pueda ensamblar todas las piezas por sí mismo.

## Conceptos Clave

- **Procesos**: Entiende qué son y cómo se crean los procesos en C utilizando la función `fork()`.
- **Variables Globales**: Aprende a definir y utilizar variables globales en C.
- **Control de Flujo**: Familiarízate con las estructuras de control de flujo como bucles `for` y condicionales `if-else`.
- **Tiempo de Espera**: Usa la función `sleep()` para hacer que tu programa espere por un número determinado de segundos.

## Herramientas y Funciones

- `fork()`: Crea un nuevo proceso. El proceso hijo recibe un retorno `0`, mientras que el padre recibe el PID (Process ID) del hijo.
  - **Documentación**: Busca la documentación de `fork()` para entender mejor cómo usarla.

- `sleep(seconds)`: Hace que el proceso espere durante un número especificado de segundos.
  - **Ejemplo**: `sleep(1);` hace que el proceso espere 1 segundo.

- `printf()` y `scanf()`: Para imprimir en consola y recibir entrada del usuario, respectivamente.

- Variables Globales: Declara una variable global fuera de cualquier función para que pueda ser accedida por todas las funciones del archivo.
  - **Ejemplo**: `int n = 2;`

- Constantes: Utiliza `#define` para definir valores constantes que no cambien durante la ejecución del programa.
  - **Ejemplo**: `#define N_ITERACIONES 5`

## Estructura Básica del Programa

1. **Incluye las Cabeceras Necesarias**
   - `#include <unistd.h>`
   - `#include <stdio.h>`

2. **Define Variables Globales y Constantes**
   - Por ejemplo, el número de iteraciones y la variable global a modificar.

3. **Función Principal `main()`**
   - Utiliza `fork()` para crear un proceso hijo.
   - Usa estructuras de control para diferenciar entre el proceso hijo y el padre.
   - Implementa bucles `for` para realizar las modificaciones a la variable global en ambos procesos.

4. **Implementación de `fork()`**
   - Recuerda verificar el valor retornado por `fork()` para determinar si el código se está ejecutando en el proceso padre, hijo, o si hubo un error.

5. **Modificación Condicional de la Variable Global**
   - Basado en si el código se ejecuta en el proceso hijo o padre, incrementa o decrementa la variable global.

6. **Impresión del Resultado**
   - Cada proceso debe imprimir el valor final de la variable global después de realizar sus modificaciones.

## Recomendaciones

- Experimenta con diferentes valores y observa cómo afectan al resultado del programa.
- Investiga cada una de las funciones y keywords para entender profundamente su funcionamiento y propósito.

Al ensamblar el código con estos consejos y componentes, estarás creando un programa que demuestra la creación y manipulación de procesos en C, así como la gestión de variables globales entre ellos.
