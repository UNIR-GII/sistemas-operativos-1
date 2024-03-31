#include <unistd.h>
#include <pthread.h>
#include <stdio.h>

#define ERROR_THREAD "No se ha podido crear un nuevo hilo\\n"
#define N_VECES 5

int variable = 2;

// Rutina que ejecuta cada hilo
void *thread_routine(void* arg) {
    int incremento = *((int*)arg);
    for (int i = 0; i < N_VECES; i++) {
        printf("%s LA VARIABLE GLOBAL\\n", (incremento > 0) ? "INCREMENTANDO" : "DECREMENTANDO");
        variable += incremento;
        sleep(1);
    }
    printf("El valor final de la variable para este hilo es: %i\\n", variable);
    return NULL;
}

int main(int argc, char *argv[]) {
    pthread_t thread1, thread2;
    int incremento = 1;
    int decremento = -1;

    if (0 != pthread_create(&thread1, NULL, thread_routine, &decremento)) {
        printf(ERROR_THREAD);
        return -1; // No se ha podido crear el thread
    }

    if (0 != pthread_create(&thread2, NULL, thread_routine, &incremento)) {
        printf(ERROR_THREAD);
        return -1; // No se ha podido crear el thread
    }

    pthread_join(thread1, NULL); // Esperamos que el hilo 1 finalice
    pthread_join(thread2, NULL); // Esperamos que el hilo 2 finalice

    return 0;
}