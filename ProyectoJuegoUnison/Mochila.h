#pragma once
#ifndef MOCHILA_H
#define MOCHILA_H
#include <list>
#include <allegro5/allegro_font.h>
#include "TipoCultivos.h"

class Mochila
{
public:
	/*template<typename Tomate, typename Calabaza, typename Zanahoria>
	Mochila(int cantidadObjetos, Tomate cantTomates, Calabaza cantCalabaza, Zanahoria cantZanahoria);*/
	Mochila(int cantidadObjetos, int cantidadTomates, int cantidadCalabaza, int cantidadZanahoria);
	~Mochila();
	void setcantidadObjetos(int cantidadObjetos);
	void setcantidadTomates(int cantidadTomates);
	void setcantidadCalabaza(int cantidadCalabaza);
	void setcantidadZanahoria(int cantidadZanahoria);

	int getcantidadObjetos();
	int getcantidadTomates();
	int getcantidadCalabaza();
	int getcantidadZanahoria();
	std::list<Cultivo*>cantTomates;
	std::list<Cultivo*>cantCalabazas;
	std::list<Cultivo*>cantZanahorias;
	void action(ALLEGRO_FONT* font);
private:
	int cantidadObjetos;
	int cantidadTomates;
	int cantidadCalabaza;
	int cantidadZanahoria;

	ALLEGRO_BITMAP* barraHerramientas;
	ALLEGRO_BITMAP* seleccionHerramienta;
	ALLEGRO_BITMAP* tom;
	ALLEGRO_BITMAP* cal;
	ALLEGRO_BITMAP* zana;
};
#endif // !MOCHILA_H