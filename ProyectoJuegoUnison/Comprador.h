#pragma once
#ifndef COMPRADOR_H
#define COMPRADO_H
#include <allegro5/allegro5.h>
#include <allegro5/bitmap.h>
#include <string>
#include <Windows.h>
#include "DrawObjects.h"

class Comprador
{
public:
	Comprador();
	~Comprador();
	void Menu();
	void animtaion(int tipo);

private:
	ALLEGRO_BITMAP* menu[37];
	ALLEGRO_BITMAP* coins;
	Background* backgroud;
	int aux;
	int animacion_y;
	int animacion_x;
};

#endif // !COMPRADOR_H


