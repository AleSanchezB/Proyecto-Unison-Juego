#pragma once
#ifndef COMPRADOR_H
#define COMPRADO_H
#include <allegro5/allegro5.h>
#include <allegro5/bitmap.h>
#include <string>
#include <Windows.h>
#include <cmath>
#define DX 4
#include "DrawObjects.h"
#include "InitiMap.h"
#include "Boton.h"
#include "Player.h"
#include "Mochila.h"

class Comprador
{
public:
	Comprador();
	~Comprador();
	void Menu(ALLEGRO_KEYBOARD_STATE keystate, ALLEGRO_EVENT_QUEUE* queue);
	void animacionMenu(int tipo);
	void animacionMonedas();
private:
	ALLEGRO_BITMAP* menu[37];
	ALLEGRO_BITMAP* coins;
	int animacion_y;
	int animacion_x;
	Boton* btnflechaArriba[4];
	Boton* btnflechaAbajo[4];
	Boton* btnSalir[2];
	Boton* btnVender[2];
	int CantVender;
	int TipoCultivo;
	int cantDig;
	int xVenta = 604;
	const int PRECIOTOM = 100;
	const int PRECIOZCALA = 200;
	const int PRECIOZANA = 300;
	void DibujarCantidadSelec();
	void AnimacionRevsera();
	void action(int btnCult = 0, int btnCant = 1, int btnCultB = 0, int btnCantB = 1, int btnExit = 0, int btnVen = 0);
	void DibujarElFondo(int i = 0);
	void VerificarVenta();
};

#endif // !COMPRADOR_H

