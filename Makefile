appname := weather_app
CXX := g++
CXXFLAGS := -Wall -g
srcdir := src
includedir := Include
objdir := obj

# Obtener la lista de archivos de código fuente en la carpeta src/
srcfiles := $(wildcard $(srcdir)/*.cpp)

# Agregar main.cpp a la lista de archivos fuente
srcfiles += main.cpp

# Generar la lista de objetos correspondientes a los archivos fuente
objects := $(patsubst $(srcdir)/%.cpp, $(objdir)/%.o, $(filter-out main.cpp, $(srcfiles)))
objects += $(patsubst %.cpp, $(objdir)/%.o, $(filter main.cpp, $(srcfiles)))

# Rutas de inclusión
CPPFLAGS := -I$(includedir)

# Reglas
all: $(appname)

$(appname): $(objects)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $(appname) $(objects) $(LDLIBS)

# Regla para generar los archivos de dependencias
depend: .depend

.depend: $(srcfiles)
	rm -f ./.depend
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -MM $^>>./.depend;

clean:
	rm -rf $(objdir) $(appname)

dist-clean: clean
	rm -f *~ .depend

# Crear la carpeta obj/ si no existe
$(objdir):
	mkdir -p $(objdir)

# Regla para compilar los archivos fuente y generar los archivos objeto
$(objdir)/%.o: $(srcdir)/%.cpp | $(objdir)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c -o $@ $<

$(objdir)/main.o: main.cpp | $(objdir)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c -o $@ $<

# Incluye el archivo de dependencias si existe
ifneq ($(wildcard ./.depend),)
include .depend
endif
