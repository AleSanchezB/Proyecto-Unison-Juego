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
		int cantidadPapaya = 0, int cantidadRemolacha = 0, ALLEGRO_FONT* font = al_load_font("assets/fonts/Minecraft.ttf", 20, 0));
	~Mochila();

	int getcantidadObjetos();
	int getcantidadTomates();
	int getcantidadCalabaza();
	int getcantidadZanahoria();
	int getcantidadBerenjena();
	int getcantidadEjotes();
	int getcantidadMaiz();
	int getcantidadPapa();
	int getcantidadPapaya();
	int getcantidadRemolacha();


	int verificarObjectoSeleccionado();

	void setcantidadObjetos(int cantidadObjetos);
	void setcantidadTomates(int cantidadTomates);
	void setcantidadCalabaza(int cantidadCalabaza);
	void setcantidadZanahoria(int cantidadZanahoria);
	void setcantidadBerenjena(int cantidadBerenjena);
	void setcantidadEjotes(int cantidadEjotes);
	void setcantidadMaiz(int cantidadMaiz);
	void setcantidadPapa(int cantidadPapa);
	void setcantidadPapaya(int cantidadPapaya);
	void setcantidadRemolacha(int cantidadRemolacha);

	void action(int escena);
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
	int cantidadBerenjena;
	int cantidadEjotes;
	int cantidadMaiz;
	int cantidadPapa;
	int cantidadPapaya;
	int cantidadRemolacha;


	int casillaSelect;
	int Monedas;

	ALLEGRO_BITMAP* barraHerramientas;
	ALLEGRO_BITMAP* seleccionHerramienta;
	ALLEGRO_FONT* font;

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