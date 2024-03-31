
# Guía para Resolver el Problema de Manipulación de Variables Globales desde Dos Hilos

## Palabras Clave en C y Linux

- `pthread_create`: Función para crear un nuevo hilo.
- `pthread_join`: Función que espera a que un hilo termine su ejecución.
- `sleep`: Función para hacer que el hilo actual duerma durante un número especificado de segundos.
- `printf`: Función para imprimir mensajes en la consola, útil para depuración y seguimiento del programa.
- `global variable`: Variable accesible en cualquier parte del programa.

## Consejos y Estrategias

1. **Definición de la Variable Global**: Asegúrate de definir correctamente la variable global fuera de cualquier función para que sea accesible desde cualquier hilo.
2. **Uso de `pthread_create`**: Familiarízate con los parámetros que necesita esta función, incluyendo la función que ejecutará el hilo y cualquier argumento que necesite pasar a esta función.
3. **Sincronización**: Aunque este ejercicio inicial no se enfoca en sincronización, es importante ser consciente de que el acceso concurrente a variables globales puede llevar a condiciones de carrera. Considera esto como una introducción a conceptos más avanzados como mutexes o semáforos.
4. **Implementación de la Lógica de Incremento y Decremento**: Piensa en cómo las operaciones de incremento y decremento afectarán la variable global y cómo puedes utilizar los argumentos pasados a `pthread_create` para diferenciar la operación que cada hilo debe realizar.
5. **Depuración**: Utiliza `printf` para imprimir el valor de la variable global después de cada modificación para hacer seguimiento de cómo cambia su valor a lo largo del tiempo.
6. **Finalización Correcta**: Asegúrate de que el programa principal espere a que ambos hilos terminen su ejecución usando `pthread_join` antes de terminar.

## Aprendizaje Esperado

Después de completar este ejercicio, deberías tener una mejor comprensión de cómo los hilos pueden interactuar con variables compartidas y la importancia de la sincronización para asegurar resultados consistentes en programas concurrentes.