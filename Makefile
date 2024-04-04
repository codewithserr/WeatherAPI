# Definición de variables
CXX = g++
CXXFLAGS = -std=c++11 -Wall -IInclude
SRC_DIR = src
OBJ_DIR = obj

# Lista de archivos fuente y objetos
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))

# Nombre del ejecutable
TARGET = weather_app

# Regla de construcción del ejecutable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Regla de construcción de los objetos
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Regla de limpieza
clean:
	$(RM) $(TARGET) $(OBJS)

# Regla phony para prevenir conflictos con archivos llamados "clean" o "all"
.PHONY: clean
