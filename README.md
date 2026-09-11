# Análisis y Diseño de Algoritmos (AyDA) — Trabajos Prácticos

Repositorio académico que compila las implementaciones, resoluciones analíticas y análisis de complejidad correspondientes a las técnicas de **Divide y Conquista (D&C)** y **Programación Dinámica (PD)**, cursadas en el 2do año de Ingeniería de Sistemas.

---

## 📌 Índice de Contenidos

1. [Estructura del Proyecto](#-estructura-del-proyecto)
2. [Técnicas Implementadas](#-técnicas-implementadas)
   * [Divide y Conquista](#1-divide-y-conquista-dc)
   * [Programación Dinámica](#2-programación-dinámica-pd)
3. [Comparativa Conceptual](#-comparativa-conceptual-dc-vs-pd)
4. [Requisitos y Configuración](#-requisitos-y-configuración)
5. [Compilación y Ejecución](#-compilación-y-ejecución)
6. [Buenas Prácticas Aplicadas](#-buenas-prácticas-aplicadas)

---

## 📂 Estructura del Proyecto

El repositorio consolida los módulos desarrollados durante la cursada dentro de un único árbol de directorios:

```text
ayda-algoritmos/
├── .gitignore
├── README.md
├── divide-y-conquista/
│   └── src/
│       └── algorithms/
│           ├── MergeSort.java
│           ├── QuickSort.java
│           ├── BinarySearch.java
│           ├── ClosestPair.java
│           └── MatrixMultiplicationStrassen.java
└── programacion-dinamica/
    └── src/
        └── algorithms/
            ├── Knapsack01.java          # Mochila 0/1 (Memoización y Tabulación)
            ├── LCS.java                 # Longest Common Subsequence
            ├── MatrixChainMultiplication.java
            ├── CoinChange.java          # Problema del cambio de monedas
            └── Fibonacci.java           # Comparativa Recursivo vs DP
```
## 🧠 Técnicas Implementadas

### 1. Divide y Conquista (D&C)

Estrategia basada en tres pasos fundamentales:

* **Dividir:** Fragmentar el problema original en subproblemas independientes del mismo tipo de menor tamaño.
* **Conquistar:** Resolver los subproblemas recursivamente. Si el subproblema es suficientemente pequeño (caso base), resolverlo directamente.
* **Combinar:** Integrar las soluciones de los subproblemas para construir la solución del problema global.
* **Cálculo de Complejidad:** Resolución de recurrencias mediante el **Teorema Maestro**:

$$T(n) = a \cdot T\left(\frac{n}{b}\right) + f(n)$$



donde $a \ge 1$, $b > 1$, y $f(n)$ representa el costo de división y combinación.
* **Algoritmos implementados:**
* **MergeSort:** Ordenamiento estable por mezcla ($O(n \log n)$ temporal, $O(n)$ espacial).
* **QuickSort:** Partición in-place con selección de pivote ($O(n \log n)$ promedio, $O(n^2)$ peor caso).
* **Búsqueda Binaria:** Reducción logarítmica sobre arreglos ordenados ($O(\log n)$).
* **Par de Puntos más Cercanos:** Optimización geométrica sobre plano 2D de $O(n^2)$ a $O(n \log n)$.



---

### 2. Programación Dinámica (PD)

Técnica aplicable a problemas de optimización que cumplen dos propiedades esenciales:

* **Subestructura Óptima:** La solución óptima del problema global contiene las soluciones óptimas de sus subproblemas.
* **Solapamiento de Subproblemas:** El algoritmo recursivo ingenuo resuelve las mismas instancias de subproblemas repetidamente.
* **Enfoques utilizados:**
* **Top-Down (Memoización):** Mantiene la estructura recursiva natural y almacena en una tabla auxiliar (lookup table) el resultado de cada subproblema resuelto.
* **Bottom-Up (Tabulación):** Resuelve iterativamente desde los casos base más pequeños, rellenando una matriz/vector hasta alcanzar el estado objetivo; optimiza la sobrecarga de la pila de llamadas (*call stack*).


* **Algoritmos implementados:**
* **Problema de la Mochila 0/1 (*0/1 Knapsack*):** Selección de elementos indivisibles para maximizar valor sin exceder capacidad. Complejidad pseudo-polinomial $O(n \cdot W)$.
* **Subsecuencia Común Más Larga (*LCS*):** Alineación de cadenas y cálculo de distancias de edición ($O(n \cdot m)$).
* **Cambio de Monedas (*Coin Change*):** Minimización de la cantidad de monedas necesarias para alcanzar un valor dado.



---

## ⚖️ Comparativa Conceptual: D&C vs. PD

| Criterio | Divide y Conquista | Programación Dinámica |
| --- | --- | --- |
| **Naturaleza de Subproblemas** | Desconexos / Independientes | Solapados (se repiten) |
| **Estructura típica** | Recursión pura | Tabulación iterativa o Recursión + Memo |
| **Almacenamiento auxiliar** | Mínimo ($O(\log n)$ de pila) | Requerido (vectores / matrices de estados) |
| **Ecuación representativa** | Teorema Maestro / Árbol de recurrencia | Ecuación de Bellman / Recurrencia de estados |

---

## 🛠️ Requisitos y Configuración

* **JDK:** Java Development Kit 17 o superior.
* **IDE recomendado:** IntelliJ IDEA (Community o Ultimate).
* **Control de versiones:** Git.

---

## 🚀 Compilación y Ejecución

### Desde IntelliJ IDEA

1. Abrir la carpeta raíz `ayda-algoritmos/` (**File > Open**).
2. Marcar los directorios `src` de cada subcarpeta como fuentes si el IDE no los reconoce:
* Clic derecho en `divide-y-conquista/src` > **Mark Directory as** > **Sources Root**.
* Clic derecho en `programacion-dinamica/src` > **Mark Directory as** > **Sources Root**.


3. Navegar hasta cualquier clase con método `main` (por ejemplo, `Knapsack01.java`) y ejecutar con `Shift + F10` (o `Ctrl + Shift + R`).

### Desde la Terminal (CLI)

Compilar y ejecutar una clase particular (ej. `MergeSort`):

```bash
# Compilar desde la raíz del módulo
cd divide-y-conquista/src
javac algorithms/MergeSort.java

# Ejecutar
java algorithms.MergeSort

```

---

## 📐 Buenas Prácticas Aplicadas

* **Separación de Responsabilidades:** Lógica algorítmica desacoplada de la interfaz de entrada/salida (I/O).
* **Medición de Complejidad Experimental:** Inclusión de benchmarks de tiempo de CPU (`System.nanoTime()`) frente a variaciones de tamaño de entrada ($n$) para contrastar con las cotas asintóticas teóricas ($O, \Omega, \Theta$).
* **Higiene de Repositorio:** Filtrado estricto mediante `.gitignore` para excluir metadatos de entorno (`.idea/`, `*.iml`), binarios compilados (`.class`) y directorios de salida (`out/`, `build/`, `target/`).

