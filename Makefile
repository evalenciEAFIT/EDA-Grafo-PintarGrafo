# Compilador
CXX = g++

# Flags de compilación
CXXFLAGS = -std=c++11 -Wall -Wextra

# Nombre del ejecutable
TARGET = sudamerica

# Archivos fuente
SRCS = main.cpp Grafo.cpp HashTable.cpp Nodo.cpp Pais.cpp

# Archivos objeto generados a partir de los archivos fuente
OBJS = $(SRCS:.cpp=.o)

# Regla por defecto
all: $(TARGET)

# Regla para generar el ejecutable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Regla para generar los archivos objeto
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regla para limpiar los archivos generados
clean:
	rm -f $(OBJS) $(TARGET)

# Regla para recompilar todo
rebuild: clean all

# Indica que 'clean' y 'rebuild' no son archivos
.PHONY: all clean rebuild