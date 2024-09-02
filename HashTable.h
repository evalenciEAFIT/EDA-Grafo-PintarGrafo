#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <vector>  // Para usar std::vector como estructura de almacenamiento
#include "Nodo.h"  // Incluye la definición de la clase Nodo

class HashTable {
private:
    static const int TABLE_SIZE = 100;  // Tamaño fijo de la tabla hash
    std::vector<Nodo*> table;           // Vector de punteros a nodos

    // Función hash: Convierte una clave (string) en un índice de la tabla
    int hash(const std::string& key) const;

public:
    // Constructor: Inicializa la tabla hash
    HashTable();

    // Destructor: Libera la memoria de todos los nodos
    ~HashTable();

    // Inserta un nuevo país en la tabla hash
    void insert(const Pais& pais);

    // Busca un país por nombre y devuelve sus datos
    bool get(const std::string& nombre, Pais& pais) const;

    // Elimina un país de la tabla hash por nombre
    bool remove(const std::string& nombre);

    // Imprime todos los países en la tabla hash
    void printAll() const;
};

#endif