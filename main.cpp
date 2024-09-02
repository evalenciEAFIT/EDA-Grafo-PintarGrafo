#include <iostream>   // Para entrada/salida estándar
#include <iomanip>    // Para formatear la salida (std::setw)
#include "Grafo.h"    // Incluye la definición de la clase Grafo

// Códigos ANSI para colores en la terminal
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define BLUE    "\033[34m"
#define YELLOW  "\033[33m"

// Función para convertir el nombre del color a su código ANSI correspondiente
std::string colorToAnsi(const std::string& color) {
    if (color == "Rojo") return RED;
    if (color == "Verde") return GREEN;
    if (color == "Azul") return BLUE;
    if (color == "Amarillo") return YELLOW;
    return RESET;
}

int main() {
    // Crear una instancia del grafo para representar Sudamérica
    Grafo sudamerica;

    // Agregar países (vértices) con su capital y moneda
    sudamerica.agregarVertice(Pais("Argentina", "Buenos Aires", "Peso argentino"));
    sudamerica.agregarVertice(Pais("Bolivia", "La Paz", "Boliviano"));
    sudamerica.agregarVertice(Pais("Brasil", "Brasilia", "Real brasileño"));
    sudamerica.agregarVertice(Pais("Chile", "Santiago", "Peso chileno"));
    sudamerica.agregarVertice(Pais("Colombia", "Bogotá", "Peso colombiano"));
    sudamerica.agregarVertice(Pais("Ecuador", "Quito", "Dólar estadounidense"));
    sudamerica.agregarVertice(Pais("Guyana", "Georgetown", "Dólar guyanés"));
    sudamerica.agregarVertice(Pais("Paraguay", "Asunción", "Guaraní"));
    sudamerica.agregarVertice(Pais("Perú", "Lima", "Sol"));
    sudamerica.agregarVertice(Pais("Surinam", "Paramaribo", "Dólar surinamés"));
    sudamerica.agregarVertice(Pais("Uruguay", "Montevideo", "Peso uruguayo"));
    sudamerica.agregarVertice(Pais("Venezuela", "Caracas", "Bolívar"));

    // Agregar fronteras (aristas)
    sudamerica.agregarArista("Argentina", "Bolivia");
    sudamerica.agregarArista("Argentina", "Brasil");
    sudamerica.agregarArista("Argentina", "Chile");
    sudamerica.agregarArista("Argentina", "Paraguay");
    sudamerica.agregarArista("Argentina", "Uruguay");
    sudamerica.agregarArista("Bolivia", "Brasil");
    sudamerica.agregarArista("Bolivia", "Chile");
    sudamerica.agregarArista("Bolivia", "Paraguay");
    sudamerica.agregarArista("Bolivia", "Perú");
    sudamerica.agregarArista("Brasil", "Colombia");
    sudamerica.agregarArista("Brasil", "Guyana");
    sudamerica.agregarArista("Brasil", "Paraguay");
    sudamerica.agregarArista("Brasil", "Perú");
    sudamerica.agregarArista("Brasil", "Surinam");
    sudamerica.agregarArista("Brasil", "Uruguay");
    sudamerica.agregarArista("Brasil", "Venezuela");
    sudamerica.agregarArista("Chile", "Perú");
    sudamerica.agregarArista("Colombia", "Ecuador");
    sudamerica.agregarArista("Colombia", "Perú");
    sudamerica.agregarArista("Colombia", "Venezuela");
    sudamerica.agregarArista("Ecuador", "Perú");
    sudamerica.agregarArista("Guyana", "Surinam");
    sudamerica.agregarArista("Guyana", "Venezuela");

    // Colorear el grafo
    std::vector<std::string> colores = sudamerica.colorearGrafo();

    // Mostrar los resultados
    std::cout << "Coloreado de países de Sudamérica:\n" << std::endl;
    auto vertices = sudamerica.obtenerVertices();
    for (size_t i = 0; i < vertices.size(); ++i) {
        Pais pais = sudamerica.obtenerPais(vertices[i]);
        std::string colorAnsi = colorToAnsi(colores[i]);
        
        std::cout << colorAnsi;
        std::cout << std::left << std::setw(15) << "País: " << pais.getNombre() << std::endl;
        std::cout << std::left << std::setw(15) << "Capital: " << pais.getCapital() << std::endl;
        std::cout << std::left << std::setw(15) << "Moneda: " << pais.getMoneda() << std::endl;
        std::cout << std::left << std::setw(15) << "Color: " << colores[i] << std::endl;
        std::cout << "Fronteras con: ";
        for (const auto& frontera : pais.getFronteras()) {
            std::cout << frontera << ", ";
        }
        std::cout << std::endl << std::endl;
        std::cout << RESET;
    }

    return 0;
}