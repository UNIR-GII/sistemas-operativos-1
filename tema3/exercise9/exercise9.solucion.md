
# Ejercicio 9: Modificación de Variables Globales desde Dos Procesos

## Enunciado

Escribe un programa en C tal que desde un proceso padre se cree un proceso hijo.
Desde el proceso padre, cada segundo, debe decrementarse el valor de una variable
entera global en una unidad. Desde el proceso hijo, cada segundo, debe
incrementarse el valor de una variable global en una unidad. Ambos procesos de
incremento y decremento deben realizarse el mismo número de veces definido en
una constante global (por ejemplo, 5 veces). Finalmente, cada proceso debe imprimir
el valor que contiene almacenada la variable entera global que ha estado
manipulando.

## Código en C

```c
#include <unistd.h>
#include <stdio.h>

#define N_ITERACIONES 5
int n = 2;

int main () {
    pid_t PID = fork(); // Creación del proceso hijo
    
    if (PID == 0) {
        // Proceso hijo
        for (int i=0; i<N_ITERACIONES; i++) {
            printf ("SUMANDO EN EL PROCESO HIJO (%i)
", getpid());
            n++;
            sleep(1);
        }
        printf ("El valor final de n para el proceso hijo es: %i
", n);
    } else if (PID > 0) {
        // Proceso padre
        for (int i=0; i<N_ITERACIONES; i++) {
            printf ("RESTANDO EN EL PROCESO PADRE (%i)
", getpid());
            n--;
            sleep(1);
        }
        printf ("El valor final de n para el proceso padre es: %i
", n);
    } else {
        // Error en la creación del proceso hijo
        printf ("Hubo un problema en la creación del proceso hijo
");
    }
    
    return 0;
}
```

## Documentación del Script

- `#include <unistd.h>`: Incluye funciones para llamadas al sistema como `fork()` y `sleep()`.
- `#include <stdio.h>`: Permite el uso de funciones de entrada/salida, como `printf` y `scanf`.
- `#define N_ITERACIONES 5`: Define una constante para el número de iteraciones que realizarán ambos procesos.
- `int n = 2;`: Declara e inicializa una variable global que ambos procesos modificarán.

### `int main()`
Función principal donde se ejecuta el programa.

- `pid_t PID = fork();`: Crea un proceso hijo duplicando el proceso actual. `fork()` devuelve `0` al proceso hijo y el PID del proceso hijo al proceso padre.
- `if (PID == 0) { ... }`: Bloque de código que solo ejecuta el proceso hijo.
    - `for (int i=0; i<N_ITERACIONES; i++) { ... }`: Bucle que se repite `N_ITERACIONES` veces. Cada iteración, el proceso hijo incrementa `n` y espera 1 segundo.
- `else if (PID > 0) { ... }`: Bloque de código que solo ejecuta el proceso padre.
    - Como en el proceso hijo, este bucle se repite `N_ITERACIONES` veces, pero en cada iteración, el proceso padre decrementa `n`.
- `else { ... }`: Se ejecuta si hubo un error al crear el proceso hijo, imprimiendo un mensaje de error.
- `return 0;`: Indica que el programa terminó exitosamente.
