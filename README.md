# Push Swap - 42 School Project

## Descripción del Proyecto

Este proyecto, llamado "push_swap", es parte del plan de estudios de la escuela 42. La tarea principal es implementar un algoritmo eficiente que organice una pila de números en orden ascendente utilizando dos pilas y un conjunto limitado de operaciones.

## Reglas y Operaciones

- Los números están representados por sus posiciones iniciales en la pila A.
- El programa debe mostrar una serie de instrucciones que, al ejecutarse, ordenarán la pila A.
- Se tienen dos pilas, A y B, y un conjunto limitado de operaciones permitidas.

## Operaciones Permitidas

| Operación | Descripción |
| --- | --- |
| `sa` | Swap A: Intercambia los dos primeros elementos de la pila A. |
| `sb` | Swap B: Intercambia los dos primeros elementos de la pila B. |
| `ss` | Swap Both: `sa` y `sb` al mismo tiempo. |
| `pa` | Push A: Mueve el primer elemento de B a la primera posición de A. |
| `pb` | Push B: Mueve el primer elemento de A a la primera posición de B. |
| `ra` | Rotate A: Rota hacia arriba todos los elementos de A. |
| `rb` | Rotate B: Rota hacia arriba todos los elementos de B. |
| `rr` | Rotate Both: `ra` y `rb` al mismo tiempo. |
| `rra` | Reverse Rotate A: Rota hacia abajo todos los elementos de A. |
| `rrb` | Reverse Rotate B: Rota hacia abajo todos los elementos de B. |
| `rrr` | Reverse Rotate Both: `rra` y `rrb` al mismo tiempo. |

Estas operaciones permitidas se utilizarán para crear un algoritmo eficiente que ordene la pila A.
