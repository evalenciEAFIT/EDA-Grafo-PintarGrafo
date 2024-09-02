#include "Grafo.h"
#include <algorithm>  // Para std::find y std::distance

Grafo::Grafo() {}

// Agrega un nuevo país (vértice) al grafo
void Grafo::agregarVertice(const Pais& pais) {
    if (std::find(vertices.begin(), vertices.end(), pais.getNombre()) == vertices.end()) {
        vertices.push_back(pais.getNombre());
        listaAdyacencia.insert(pais);
    }
}

// Agrega una frontera (arista) entre dos países
void Grafo::agregarArista(const std::string& origen, const std::string& destino) {
    Pais paisOrigen, paisDestino;
    if (listaAdyacencia.get(origen, paisOrigen) && listaAdyacencia.get(destino, paisDestino)) {
        paisOrigen.addFrontera(destino);
        paisDestino.addFrontera(origen);
        listaAdyacencia.insert(paisOrigen);
        listaAdyacencia.insert(paisDestino);
    }
}

// Obtiene los países fronterizos (vértices adyacentes) a un país dado
std::vector<std::string> Grafo::obtenerAdyacentes(const std::string& vertice) const {
    Pais pais;
    if (listaAdyacencia.get(vertice, pais)) {
        return pais.getFronteras();
    }
    return std::vector<std::string>();
}

// Obtiene todos los países (vértices) del grafo
std::vector<std::string> Grafo::obtenerVertices() const {
    return vertices;
}

// Implementa el algoritmo de coloración del grafo
std::vector<std::string> Grafo::colorearGrafo() const {
    std::vector<std::string> colores(vertices.size(), "");
    std::vector<std::string> listaColores = {"Rojo", "Verde", "Azul", "Amarillo"};

    for (size_t i = 0; i < vertices.size(); ++i) {
        std::vector<bool> coloresUsados(listaColores.size(), false);
        std::vector<std::string> adyacentes = obtenerAdyacentes(vertices[i]);

        // Marca los colores ya usados por los países vecinos
        for (const auto& adyacente : adyacentes) {
            auto it = std::find(vertices.begin(), vertices.end(), adyacente);
            if (it != vertices.end()) {
                size_t index = std::distance(vertices.begin(), it);
                if (!colores[index].empty()) {
                    auto colorIt = std::find(listaColores.begin(), listaColores.end(), colores[index]);
                    if (colorIt != listaColores.end()) {
                        coloresUsados[std::distance(listaColores.begin(), colorIt)] = true;
                    }
                }
            }
        }

        // Asigna el primer color disponible
        for (size_t j = 0; j < listaColores.size(); ++j) {
            if (!coloresUsados[j]) {
                colores[i] = listaColores[j];
                break;
            }
        }
    }

    return colores;
}

// Obtiene los datos de un país específico
Pais Grafo::obtenerPais(const std::string& nombre) const {
    Pais pais;
    listaAdyacencia.get(nombre, pais);
    return pais;
}