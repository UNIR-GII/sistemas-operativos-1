#include <stdio.h>  // Necesario para las funciones de entrada/salida, como printf y scanf.
#include <unistd.h> // Necesario para las funciones fork() y sleep().
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h> // Añadido para asegurar la definición de pid_t

int main () {
    int valor;
    // Solicita al usuario un número entero.
    printf("Escribe un número entero: ");
    scanf("%i", &valor);

    // Informa al usuario sobre el comportamiento esperado de los procesos padre e hijo.
    printf("El proceso padre escribirá cada %f segundos el mensaje, un total de %i veces.\n", (float)valor, valor);
    printf("El proceso hijo escribirá cada %f segundos el mensaje, un total de %i veces.\n", (float)valor/3, valor*2);

    pid_t PID = fork(); // Crea el proceso hijo.
    
    if (PID == 0) {
        // Este bloque se ejecuta solo en el proceso hijo.
        for (int i = 0; i < valor * 2; i++) {
            printf("Hola, soy tu hijo (%i)\n", getpid());
            sleep(valor / 3); // Hace que el proceso hijo duerma un tercio del valor especificado por el usuario.
        }
    } else if (PID > 0) {
        // Este bloque se ejecuta solo en el proceso padre.
        for (int i = 0; i < valor; i++) {
            printf("Hola, soy tu padre (%i)\n", getpid());
            sleep(valor); // Hace que el proceso padre duerma el valor completo especificado por el usuario.
        }
    } else {
        // Se ejecuta si hubo un error al crear el proceso hijo.
        printf("Hubo un problema en la creación del proceso hijo\n");
    }
    return 0;
}
