# Exercise 7 (alternativa creada con GPT)

Este código en C demuestra cómo crear un proceso hijo desde un proceso padre y ejecutar diferentes acciones en cada uno de ellos, basándose en un número entero proporcionado por el usuario. A continuación, se detalla el propósito de cada parte del código:

```c
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
```
Incluye las bibliotecas necesarias para las funciones de entrada/salida, manejo de procesos, y terminación de programas.

```c
int main() {
```
Define la función principal del programa.

```c
    int n;
    printf("Por favor, introduce un número entero: ");
    scanf("%d", &n);
```
Solicita al usuario un número entero `n`, que determinará la cantidad de veces que el padre imprimirá un mensaje y el tiempo de espera entre mensajes.

```c
    pid_t pid = fork();
```
Crea un proceso hijo duplicando el proceso actual (el proceso padre). `fork()` retorna `0` al proceso hijo y el PID del hijo al proceso padre.

```c
    if (pid == -1) {
```
Comprueba si hubo un error al crear el proceso hijo.

```c
        perror("fork failed");
        exit(EXIT_FAILURE);
```
Imprime un mensaje de error y termina el programa si no se pudo crear el proceso hijo.

```c
    } else if (pid == 0) {
```
Sección del código que solo ejecutará el proceso hijo.

```c
        for (int i = 0; i < 2 * n; i++) {
            printf("Hola, soy tu hijo (PID: %d)\n", getpid());
            if (i % 2 == 1) {
                sleep(n / 3);
            }
        }
```
El proceso hijo imprime un mensaje el doble de veces que el valor `n` introducido por el usuario. Después de cada par de impresiones, espera un tercio del valor de `n` segundos.

```c
    } else {
```
Sección del código que solo ejecutará el proceso padre.

```c
        for (int i = 0; i < n; i++) {
            printf("Hola, soy tu padre (PID: %d)\n", getpid());
            sleep(n);
        }
        wait(NULL); // Esperar a que el proceso hijo termine
    }
```
El proceso padre imprime un mensaje `n` veces, con un intervalo de espera de `n` segundos entre cada impresión. Después de completar sus impresiones, espera a que el proceso hijo termine su ejecución.

```c
    return 0;
}
```
Termina la función `main` con un valor de retorno `0`, indicando que el programa se ejecutó exitosamente.

Este programa es un ejemplo de cómo utilizar la función `fork()` para crear procesos hijos en C, y cómo los procesos padre e hijo pueden ejecutar diferentes secciones de código simultáneamente, así como la importancia de sincronizar el final de estos procesos usando `wait()`.