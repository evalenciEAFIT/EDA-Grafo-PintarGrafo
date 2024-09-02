#include "HashTable.h"
#include <iostream>  // Para operaciones de entrada/salida

// Constructor: Inicializa la tabla hash con punteros nulos
HashTable::HashTable() : table(TABLE_SIZE, nullptr) {}

// Destructor: Libera la memoria de todos los nodos en la tabla hash
HashTable::~HashTable() {
    for (Nodo* head : table) {
        while (head) {
            Nodo* temp = head;
            head = head->getNext();
            delete temp;
        }
    }
}

// Función hash: Implementa un algoritmo simple de hashing
int HashTable::hash(const std::string& key) const {
    int hash = 0;
    for (char c : key) {
        hash = (hash * 31 + c) % TABLE_SIZE;  // Fórmula de hash
    }
    return hash;
}

// Inserta un nuevo país en la tabla hash
void HashTable::insert(const Pais& pais) {
    int index = hash(pais.getNombre());
    Nodo* newNodo = new Nodo(pais);
    
    if (!table[index]) {
        table[index] = newNodo;  // Si el bucket está vacío, inserta directamente
    } else {
        newNodo->setNext(table[index]);  // Si no, inserta al principio de la lista
        table[index] = newNodo;
    }
}

// Busca un país por nombre y devuelve sus datos
bool HashTable::get(const std::string& nombre, Pais& pais) const {
    int index = hash(nombre);
    Nodo* current = table[index];
    
    while (current) {
        if (current->getPais().getNombre() == nombre) {
            pais = current->getPais();
            return true;  // País encontrado
        }
        current = current->getNext();
    }
    return false;  // País no encontrado
}

// Elimina un país de la tabla hash por nombre
bool HashTable::remove(const std::string& nombre) {
    int index = hash(nombre);
    Nodo* current = table[index];
    Nodo* prev = nullptr;
    
    while (current) {
        if (current->getPais().getNombre() == nombre) {
            if (prev) {
                prev->setNext(current->getNext());
            } else {
                table[index] = current->getNext();
            }
            delete current;
            return true;  // País eliminado
        }
        prev = current;
        current = current->getNext();
    }
    return false;  // País no encontrado
}

// Imprime todos los países en la tabla hash
void HashTable::printAll() const {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        Nodo* current = table[i];
        if (current) {
            std::cout << "Bucket " << i << ":" << std::endl;
            while (current) {
                std::cout << "  " << current->getPais() << std::endl;
                current = current->getNext();
            }
        }
    }
}