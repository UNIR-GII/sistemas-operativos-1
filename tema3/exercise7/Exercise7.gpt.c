#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
    int n;
    printf("Por favor, introduce un número entero: ");
    scanf("%d", &n);

    pid_t pid = fork();

    if (pid == -1) {
        // Si pid es -1, significa que hubo un error al crear el proceso hijo
        perror("fork failed");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Código ejecutado por el proceso hijo
        for (int i = 0; i < 2 * n; i++) {
            printf("Hola, soy tu hijo (PID: %d)\n", getpid());
            if (i % 2 == 1) { // Esperar después de cada dos impresiones
                sleep(n / 3);
            }
        }
    } else {
        // Código ejecutado por el proceso padre
        for (int i = 0; i < n; i++) {
            printf("Hola, soy tu padre (PID: %d)\n", getpid());
            sleep(n); // Esperar n segundos entre cada impresión
        }
        wait(NULL); // Esperar a que el proceso hijo termine
    }

    return 0;
}
