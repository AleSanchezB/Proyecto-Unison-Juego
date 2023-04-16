#pragma once
#ifndef MOCHILA_H
#define MOCHILA_H
#include <list>
#include <allegro5/allegro_font.h>
#include "TipoCultivos.h"

class Mochila
{
public:
	Mochila(int cantidadObjetos, int cantidadTomates, int cantidadCalabaza, int cantidadZanahoria, ALLEGRO_FONT* font = al_load_font("assets/fonts/Minecraft.ttf", 20, 0));
	~Mochila();

	int getcantidadObjetos();
	int getcantidadTomates();
	int getcantidadCalabaza();
	int getcantidadZanahoria();
	int verificarObjectoSeleccionado();

	void setcantidadObjetos(int cantidadObjetos);
	void setcantidadTomates(int cantidadTomates);
	void setcantidadCalabaza(int cantidadCalabaza);
	void setcantidadZanahoria(int cantidadZanahoria);
	void action();
	void cambiarCasilla(int casillaSelect);
	void quitarCultivo(int tipo);

	bool verificacionMochila();
	bool verificarCantidadCultivos(int tipo);
	bool verificarCantidadCultivosGuardados(int tipo, int cantidad);
	bool verificarMochilaLlena(int cantidad);

	void setMonedas(int monedas);
	int getMonedas();
private:
	int capacidadMochila;
	int cantidadObjetos;
	int cantidadTomates;
	int cantidadCalabaza;
	int cantidadZanahoria;
	int casillaSelect;
	int Monedas;

	ALLEGRO_BITMAP* barraHerramientas;
	ALLEGRO_BITMAP* seleccionHerramienta;
	ALLEGRO_BITMAP* tom;
	ALLEGRO_BITMAP* cal;
	ALLEGRO_BITMAP* zana;
	ALLEGRO_FONT* font;
};
#endif // !MOCHILA_H