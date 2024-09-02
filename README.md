# Coloración de Grafos: Fronteras de Sudamérica

Este proyecto implementa una solución al problema de coloración de grafos, aplicándolo a un mapa de Sudamérica. Utiliza una tabla hash personalizada para representar el grafo de países y sus fronteras.

## El Problema de Coloración de Grafos

La coloración de grafos es un problema clásico en teoría de grafos y ciencias de la computación. El objetivo es asignar colores a los vértices de un grafo de tal manera que no haya dos vértices adyacentes (conectados por una arista) que tengan el mismo color, usando el menor número posible de colores.

### Aplicación a las Fronteras de Sudamérica

En el contexto de este proyecto, aplicamos la coloración de grafos al mapa de Sudamérica:

- Cada país es un vértice en el grafo.
- Las fronteras entre países son las aristas del grafo.
- El objetivo es "pintar" cada país de tal manera que ningún par de países vecinos tenga el mismo color.

Este problema tiene aplicaciones prácticas en cartografía, asignación de frecuencias en telecomunicaciones, y programación de horarios, entre otros.

## Solución Implementada

Nuestro enfoque para resolver este problema incluye:

1. **Representación del Grafo**: 
   - Utilizamos una tabla hash personalizada para almacenar los países y sus conexiones.
   - Cada país (vértice) se representa como un objeto `Pais` con nombre, capital y moneda.

2. **Algoritmo de Coloración**:
   - Implementamos un algoritmo voraz (greedy) para la coloración.
   - Para cada país, asignamos el primer color disponible que no haya sido usado por ningún país vecino.
   - Utilizamos un conjunto fijo de colores: Rojo, Verde, Azul y Amarillo.

3. **Manejo de Adyacencias**:
   - Las fronteras entre países se representan como relaciones de adyacencia en el grafo.
   - Usamos la estructura de la tabla hash para almacenar y recuperar eficientemente esta información.

## Características del Proyecto

- Implementación de una tabla hash personalizada
- Representación de países con nombre, capital y moneda
- Grafo de países de Sudamérica con sus fronteras
- Algoritmo de coloración de grafos
- Visualización de resultados con colores en la terminal

## Estructura del Proyecto

- `Pais.h` y `Pais.cpp`: Definición e implementación de la clase Pais
- `Nodo.h` y `Nodo.cpp`: Definición e implementación de la clase Nodo para la tabla hash
- `HashTable.h` y `HashTable.cpp`: Implementación de la tabla hash
- `Grafo.h` y `Grafo.cpp`: Implementación del grafo utilizando la tabla hash
- `main.cpp`: Programa principal que demuestra la funcionalidad
- `Makefile`: Para compilar el proyecto

## Compilación y Ejecución

Para compilar el proyecto:

```
make
```

Para ejecutar el programa:

```
./sudamerica
```

## Ejemplo de Salida

El programa mostrará:
1. Una lista de países de Sudamérica con sus capitales, monedas y colores asignados.
2. Las fronteras de cada país.

La salida estará coloreada según el color asignado a cada país.

## Limpieza

Para limpiar los archivos objeto y el ejecutable:

```
make clean
```

## Notas y Limitaciones

- Este proyecto es una demostración educativa y puede no reflejar con total precisión las fronteras o datos actuales de los países de Sudamérica.
- El algoritmo implementado no garantiza usar el mínimo número de colores posible (conocido como el número cromático del grafo), pero asegura una coloración válida.
- En la práctica, cuatro colores son suficientes para colorear cualquier mapa planar (Teorema de los cuatro colores), lo cual se aplica a mapas geográficos reales.

## Posibles Extensiones

- Implementar algoritmos más avanzados de coloración de grafos.
- Añadir una interfaz gráfica para visualizar el mapa coloreado.
- Extender el proyecto para manejar mapas de otras regiones o del mundo entero.

## Requisitos del Sistema

- Compilador de C++ que soporte C++11 o superior
- Make (para usar el Makefile)
- Terminal que soporte colores ANSI (para la visualización de colores)

Este proyecto demuestra la aplicación práctica de conceptos de estructuras de datos (tablas hash, grafos) y algoritmos (coloración de grafos) en un contexto geográfico real.
