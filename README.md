# Push Swap - 42 School Project

## Descripción del Proyecto

Este proyecto, denominado "push_swap", es parte del plan de estudios de la escuela 42. La tarea principal es implementar un algoritmo eficiente que organice una pila de números en orden ascendente utilizando dos pilas y un conjunto limitado de operaciones.

## Reglas y Operaciones

- Los números están representados por sus posiciones iniciales en la pila A.
- El programa debe mostrar una serie de instrucciones que, al ejecutarse, ordenarán la pila A.
- Se tienen dos pilas, A y B, y un conjunto limitado de operaciones permitidas.

## Operaciones Permitidas

1. `sa`: swap a - intercambia los dos primeros elementos de la pila A.
2. `sb`: swap b - intercambia los dos primeros elementos de la pila B.
3. `ss`: `sa` y `sb` al mismo tiempo.
4. `pa`: push a - mueve el primer elemento de B a la primera posición de A.
5. `pb`: push b - mueve el primer elemento de A a la primera posición de B.
6. `ra`: rotate a - rota hacia arriba todos los elementos de A.
7. `rb`: rotate b - rota hacia arriba todos los elementos de B.
8. `rr`: `ra` y `rb` al mismo tiempo.
9. `rra`: reverse rotate a - rota hacia abajo todos los elementos de A.
10. `rrb`: reverse rotate b - rota hacia abajo todos los elementos de B.
11. `rrr`: `rra` y `rrb` al mismo tiempo.
