CXXFLAGS_DEBUG = -std=c++17 -O0 -g3

CXXFLAGS_RELEASE = -std=c++17 -O3

CXXFLAGS_WARNINGS = -Wall -Wextra -Wpedantic -Werror

CXXFLAGS_SANITIZE = 

CXXFLAGS_ALLEGRO = -I C:\mingw64\include -L C:\mingw64\lib -lallegro_image -lallegro_ttf -lallegro_font -lallegro_primitives -lallegro

CXX = g++

OBJECTS = ProyectoJuegoUnison/Boton.o \
	ProyectoJuegoUnison/DibujarFondo.o \
	ProyectoJuegoUnison/InitMap.o \
	ProyectoJuegoUnison/MainGame.o \
	ProyectoJuegoUnison/Mochila.o \
	ProyectoJuegoUnison/Objeto.o \
	ProyectoJuegoUnison/Player.o \
	ProyectoJuegoUnison/SubmenuOptions.o \
	ProyectoJuegoUnison/TiempoDia.o \
	ProyectoJuegoUnison/Tienda.o \
	ProyectoJuegoUnison/TiposCultivos.o \
	ProyectoJuegoUnison/sonidos.o

build: agromania-debug

agromania: CXXFLAGS = $(CXXFLAGS_RELEASE) $(CXXFLAGS_ALLEGRO)
agromania: ProyectoJuegoUnison\main.cpp $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^

agromania-debug: CXXFLAGS = $(CXXFLAGS_DEBUG) $(CXXFLAGS_WARNINGS) $(CXXFLAGS_SANITIZE) $(CXXFLAGS_ALLEGRO)
agromania-debug: ProyectoJuegoUnison\main.cpp $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^

%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) $< -o $@

clean:
	rm -f ProyectoJuegoUnison\*.o

init: compile_flags.txt

compile_flags.txt: Makefile
	echo "-xc++"  > compile_flags.txt
	echo $(CXXFLAGS_DEBUG) | tr " " "\n" >> compile_flags.txt
	echo $(CXXFLAGS_WARNINGS) | tr " " "\n" >> compile_flags.txt
	echo $(CXXFLAGS_ALLEGRO) | tr " " "\n" >> compile_flags.txt
