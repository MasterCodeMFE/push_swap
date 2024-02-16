<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
</head>
<body>

<h1>Push Swap - Proyecto de la Escuela 42</h1>

<h2>Descripción del Proyecto</h2>

<p>Push Swap es un proyecto del plan de estudios de la escuela 42. El objetivo principal es implementar un algoritmo eficiente que organice una pila de números en orden ascendente utilizando dos pilas y un conjunto limitado de operaciones.</p>

<h2>Reglas y Operaciones</h2>

<ul>
  <li>Los números están representados por sus posiciones iniciales en la pila A.</li>
  <li>El programa debe mostrar una serie de instrucciones que, al ejecutarse, ordenarán la pila A.</li>
  <li>Se tienen dos pilas, A y B, y un conjunto limitado de operaciones permitidas.</li>
</ul>

<h2>Operaciones Permitidas</h2>

<table>
  <tr>
    <th>Operación</th>
    <th>Descripción</th>
  </tr>
  <tr>
    <td><code>sa</code></td>
    <td>Swap A: Intercambia los dos primeros elementos de la pila A.</td>
  </tr>
  <tr>
    <td><code>sb</code></td>
    <td>Swap B: Intercambia los dos primeros elementos de la pila B.</td>
  </tr>
  <tr>
    <td><code>ss</code></td>
    <td>Swap Both: <code>sa</code> y <code>sb</code> al mismo tiempo.</td>
  </tr>
  <tr>
    <td><code>pa</code></td>
    <td>Push A: Mueve el primer elemento de B a la primera posición de A.</td>
  </tr>
  <tr>
    <td><code>pb</code></td>
    <td>Push B: Mueve el primer elemento de A a la primera posición de B.</td>
  </tr>
  <tr>
    <td><code>ra</code></td>
    <td>Rotate A: Rota hacia arriba todos los elementos de A.</td>
  </tr>
  <tr>
    <td><code>rb</code></td>
    <td>Rotate B: Rota hacia arriba todos los elementos de B.</td>
  </tr>
  <tr>
    <td><code>rr</code></td>
    <td>Rotate Both: <code>ra</code> y <code>rb</code> al mismo tiempo.</td>
  </tr>
  <tr>
    <td><code>rra</code></td>
    <td>Reverse Rotate A: Rota hacia abajo todos los elementos de A.</td>
  </tr>
  <tr>
    <td><code>rrb</code></td>
    <td>Reverse Rotate B: Rota hacia abajo todos los elementos de B.</td>
  </tr>
  <tr>
    <td><code>rrr</code></td>
    <td>Reverse Rotate Both: <code>rra</code> y <code>rrb</code> al mismo tiempo.</td>
  </tr>
</table>

</body>
</html>
