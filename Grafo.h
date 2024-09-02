#ifndef GRAFO_H
#define GRAFO_H

#include "HashTable.h"  // Para usar la clase HashTable como estructura de almacenamiento
#include <vector>       // Para almacenar los vértices y colores
#include <string>       // Para manejar nombres de vértices y colores

class Grafo {
private:
    HashTable listaAdyacencia;  // Tabla hash para almacenar la lista de adyacencia
    std::vector<std::string> vertices;  // Vector para mantener el orden de los vértices

public:
    // Constructor: Inicializa un grafo vacío
    Grafo();

    // Agrega un nuevo país (vértice) al grafo
    void agregarVertice(const Pais& pais);

    // Agrega una frontera (arista) entre dos países
    void agregarArista(const std::string& origen, const std::string& destino);

    // Obtiene los países fronterizos (vértices adyacentes) a un país dado
    std::vector<std::string> obtenerAdyacentes(const std::string& vertice) const;

    // Obtiene todos los países (vértices) del grafo
    std::vector<std::string> obtenerVertices() const;

    // Implementa el algoritmo de coloración del grafo
    std::vector<std::string> colorearGrafo() const;

    // Obtiene los datos de un país específico
    Pais obtenerPais(const std::string& nombre) const;
};

#endif