
#include <unistd.h>
#include <stdio.h>

#define N_ITERACIONES 5
int n = 2;

int main () {
    pid_t PID = fork(); // Creación del proceso hijo
    
    if (PID == 0) {
        // Proceso hijo
        for (int i=0; i<N_ITERACIONES; i++) {
            printf ("SUMANDO EN EL PROCESO HIJO (%i)\n", getpid());
            n++;
            sleep(1);
        }
        printf ("El valor final de n para el proceso hijo es: %i\n", n);
    } else if (PID > 0) {
        // Proceso padre
        for (int i=0; i<N_ITERACIONES; i++) {
            printf ("RESTANDO EN EL PROCESO PADRE (%i)\n", getpid());
            n--;
            sleep(1);
        }
        printf ("El valor final de n para el proceso padre es: %i\n", n);
    } else {
        // Error en la creación del proceso hijo
        printf ("Hubo un problema en la creación del proceso hijo\n");
    }
    
    return 0;
}
