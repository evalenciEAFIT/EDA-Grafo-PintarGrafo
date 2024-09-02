#include "Nodo.h"

// Constructor: Inicializa un nodo con un país y establece el siguiente como nullptr
Nodo::Nodo(const Pais& p) : pais(p), next(nullptr) {}

// Getter: Devuelve el país almacenado en el nodo
Pais Nodo::getPais() const { return pais; }

// Setter: Establece el país del nodo
void Nodo::setPais(const Pais& p) { pais = p; }

// Getter: Devuelve el puntero al siguiente nodo
Nodo* Nodo::getNext() const { return next; }

// Setter: Establece el puntero al siguiente nodo
void Nodo::setNext(Nodo* n) { next = n; }