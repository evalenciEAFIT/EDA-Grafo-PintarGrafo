#ifndef NODO_H
#define NODO_H

#include "Pais.h"  // Incluimos la definición de la clase Pais

class Nodo {
private:
    Pais pais;   // El país almacenado en este nodo
    Nodo* next;  // Puntero al siguiente nodo en la lista enlazada

public:
    // Constructor: Inicializa un nodo con un país
    Nodo(const Pais& p);

    // Getters y setters
    Pais getPais() const;
    void setPais(const Pais& p);
    Nodo* getNext() const;
    void setNext(Nodo* n);
};

#endif