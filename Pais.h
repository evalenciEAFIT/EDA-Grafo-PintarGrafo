#ifndef PAIS_H
#define PAIS_H

#include <string>    // Para usar std::string
#include <vector>    // Para almacenar las fronteras
#include <iostream>  // Para la sobrecarga del operador <<

class Pais {
private:
    std::string nombre;                 // Nombre del país
    std::string capital;                // Capital del país
    std::string moneda;                 // Moneda del país
    std::vector<std::string> fronteras; // Lista de países fronterizos

public:
    // Constructor
    // Inicializa un país con su nombre, capital y moneda
    Pais(const std::string& n = "", const std::string& c = "", const std::string& m = "");

    // Getters
    std::string getNombre() const;
    std::string getCapital() const;
    std::string getMoneda() const;
    const std::vector<std::string>& getFronteras() const;

    // Setters
    void setCapital(const std::string& c);
    void setMoneda(const std::string& m);

    // Añade un país fronterizo
    void addFrontera(const std::string& f);

    // Sobrecarga del operador << para imprimir objetos Pais
    friend std::ostream& operator<<(std::ostream& os, const Pais& pais);
};

#endif