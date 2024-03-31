# Ejercicio 10: Modificación de Variables Globales desde Dos Hilos

## Descripción

El objetivo de este ejercicio es demostrar la manipulación de una variable global desde dos hilos diferentes en un programa C. Uno de los hilos incrementará el valor de la variable global, mientras que el otro la decrementará. Ambas operaciones se realizarán un número determinado de veces, definido por una constante global.

## Requerimientos

- Crear dos hilos diferentes.
- Desde el primer hilo, decrementar el valor de una variable entera global en una unidad cada segundo.
- Desde el segundo hilo, incrementar el valor de la misma variable global en una unidad cada segundo.
- Realizar el proceso de incremento y decremento el número de veces definido en una constante global (por ejemplo, 5 veces).
- Imprimir el valor final de la variable global después de las operaciones realizadas por cada hilo.

## Nota

Este ejercicio es una excelente oportunidad para entender cómo trabajar con hilos en C y cómo gestionar el acceso a variables globales desde múltiples hilos, lo cual es crucial para el desarrollo de software concurrente.
