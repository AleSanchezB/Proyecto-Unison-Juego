#pragma once
#ifndef MOCHILA_H
#define MOCHILA_H
#include <list>
#include <allegro5/allegro_font.h>
#include "TipoCultivos.h"

class Mochila
{
public:
	Mochila(int cantidadObjetos = 0, int cantidadTomates = 0, int cantidadCalabaza = 0, int cantidadZanahoria = 0,
		int cantidadBerenjenas = 0, int cantidadEjotes = 0, int cantidadMaiz = 0, int cantidadPapa = 0,
		int cantidadPapaya = 0, int cantidadRemolacha = 0, int capacidadMochila = 10, int Monedas = 50,ALLEGRO_FONT* font = al_load_font("assets/fonts/Minecraft.ttf", 20, 0));
	~Mochila();

	int getCantidadTipoCultivo(int tipo);
	int getCantidadCultivos();
	int getEspacioMochila();
	int verificarObjectoSeleccionado();
	int getMonedas();

	void setEspacioMochila(int cantidad);
	void setCantidadTipoCultivos(int cantCultivo, int tipo);
	void setCantidadCultivos(int cant);
	void action(int escena);
	void cambiarCasilla(int casillaSelect);
	void quitarCultivo(int tipo);
	void setMonedas(int monedas);

	bool verificacionMochila();
	bool verificarCantidadCultivos(int tipo);
	bool verificarCantidadCultivosGuardados(int tipo, int cantidad);
	bool verificarMochilaLlena(int cantidad = 0);
	bool verificarCapacidadMochila(int cantidad = 0);
private:
	int capacidadMochila;
	int cantidadObjetos;
	int cantidadTomates;
	int cantidadCalabaza;
	int cantidadZanahoria;
	int cantidadBerenjena;
	int cantidadEjotes;
	int cantidadMaiz;
	int cantidadPapa;
	int cantidadPapaya;
	int cantidadRemolacha;
	int casillaSelect;
	int Monedas;

	ALLEGRO_FONT* font;

	ALLEGRO_BITMAP* barraHerramientas;
	ALLEGRO_BITMAP* seleccionHerramienta;
	ALLEGRO_BITMAP* mochila;
	ALLEGRO_BITMAP* tom;
	ALLEGRO_BITMAP* cal;
	ALLEGRO_BITMAP* zana;
	ALLEGRO_BITMAP* bere;
	ALLEGRO_BITMAP* ejo;
	ALLEGRO_BITMAP* maiz;
	ALLEGRO_BITMAP* papa;
	ALLEGRO_BITMAP* papaya;
	ALLEGRO_BITMAP* remo;
};
#endif // !MOCHILA_H