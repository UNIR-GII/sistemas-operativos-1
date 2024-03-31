#include <unistd.h>
#include <pthread.h>
#include <stdio.h>

#define ERROR_THREAD1 "No se ha podido crear un nuevo hilo\n"

void *thread_routine(void* arg) {
    int n_veces = *((int*)arg);
    for (int i = 0; i < n_veces; i++) {
        printf("Imprimiendo %i de %i mensajes desde el proceso: %i\n", i + 1, n_veces, getpid());
        sleep(n_veces); // El hilo se duerme "n_veces" segundos para simular trabajo.
    }
}

int main(int argc, char *argv[]) {
    pthread_t thread1, thread2;
    int VAL;
    printf("Introduzca un número natural: ");
    scanf("%i", &VAL);
    
    int n_veces_1 = VAL, n_veces_2 = VAL * 2;

    // Creación del primer hilo. Si falla, termina el programa.
    if (0 != pthread_create(&thread1, NULL, thread_routine, &n_veces_1)) {
        printf(ERROR_THREAD1);
        return -1;
    }
    
    // Creación del segundo hilo. Si falla, termina el programa.
    if (0 != pthread_create(&thread2, NULL, thread_routine, &n_veces_2)) {
        printf(ERROR_THREAD1);
        return -1;
    }
    
    pthread_join(thread1, NULL); // Espera a que el primer hilo finalice.
    pthread_join(thread2, NULL); // Espera a que el segundo hilo finalice.
    
    return 0;
}
