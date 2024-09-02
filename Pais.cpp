#include "Pais.h"

// Constructor: Inicializa un país con su nombre, capital y moneda
Pais::Pais(const std::string& n, const std::string& c, const std::string& m)
    : nombre(n), capital(c), moneda(m) {}

// Getters: Devuelven los atributos del país
std::string Pais::getNombre() const { return nombre; }
std::string Pais::getCapital() const { return capital; }
std::string Pais::getMoneda() const { return moneda; }
const std::vector<std::string>& Pais::getFronteras() const { return fronteras; }

// Setters: Modifican los atributos del país
void Pais::setCapital(const std::string& c) { capital = c; }
void Pais::setMoneda(const std::string& m) { moneda = m; }

// Añade un país fronterizo a la lista de fronteras
void Pais::addFrontera(const std::string& f) { fronteras.push_back(f); }

// Sobrecarga del operador << para imprimir objetos Pais
std::ostream& operator<<(std::ostream& os, const Pais& pais) {
    os << "País: " << pais.nombre 
       << ", Capital: " << pais.capital 
       << ", Moneda: " << pais.moneda;
    return os;
}