# Exercise 7 (solución tema 3 ejercicio 7)

Este código en C crea un proceso hijo a partir de un proceso padre y realiza acciones diferentes en cada proceso, basado en un valor entero proporcionado por el usuario. Aquí está una explicación línea por línea:

```c
#include <unistd.h>
#include <stdio.h>
```
Incluye las cabeceras necesarias para las funciones que se usarán: `unistd.h` para `fork()` y `sleep()`, y `stdio.h` para `printf()` y `scanf()`.

```c
int main () {
```
Define la función principal `main`.

```c
    int valor;
    printf ("Escribe un número entero: ");
    scanf ("%i", &valor);
```
Declara una variable `valor` para almacenar un número entero. Luego solicita al usuario que introduzca este número y lo lee desde la entrada estándar.

```c
    printf ("El proceso padre escribirá cada %f segundos el mensaje, un total de %i veces.\n",(float)valor, valor);
    printf ("El proceso hijo escribirá cada %f segundos el mensaje, un total de %i veces.\n",(float)valor/3, valor*2);
```
Imprime información sobre cómo se comportarán el proceso padre y el proceso hijo basado en el valor introducido.

```c
    pid_t PID = fork(); // Creación del proceso hijo
```
Crea un nuevo proceso (el proceso hijo) duplicando el proceso actual (el proceso padre). `fork()` retorna `0` al proceso hijo, y al proceso padre le retorna el PID (identificador de proceso) del hijo.

```c
    if (PID == 0) {
```
Verifica si el código se está ejecutando en el proceso hijo (`fork()` retorna `0` al hijo).

```c
        for (int i=0; i<valor*2; i++) {
            printf ("Hola, soy tu hijo (%i)\n", getpid());
            sleep (valor/3);
        }
```
En el proceso hijo, entra en un bucle que se repite `valor*2` veces, imprimiendo un mensaje y luego "durmiendo" un tercio del `valor` segundos en cada iteración.

```c
    } else if (PID > 0) {
```
Verifica si el código se está ejecutando en el proceso padre (`fork()` retorna el PID del hijo, que es un número positivo, al padre).

```c
        for (int i=0; i<valor; i++) {
            printf ("Hola, soy tu padre (%i)\n", getpid());
            sleep (valor);
        }
```
En el proceso padre, entra en un bucle que se repite `valor` veces, imprimiendo un mensaje y luego "durmiendo" `valor` segundos en cada iteración.

```c
    } else {
        printf ("Hubo un problema en la creación del proceso hijo\n");
    }
```
Cubre el caso de error en la creación del proceso hijo (`fork()` retorna `-1` si falla).

```c
    return 0;
}
```
Finaliza la función `main` con un valor de retorno de `0`, indicando una terminación exitosa del programa.

Este programa demuestra la creación y gestión de procesos en C, utilizando la llamada al sistema `fork()` para crear un proceso hijo que ejecuta un comportamiento diferente del proceso padre, basado en un valor especificado por el usuario.


