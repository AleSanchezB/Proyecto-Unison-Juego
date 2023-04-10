#pragma once
#ifndef BOTON_H
#define BOTON_H
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
#include <string>
class Boton
{
public:
	Boton(std::string ruta, float x, float y, float w, float h);
	~Boton();
	float x;
	float y;
	float w;
	float h;
	ALLEGRO_BITMAP* sprite;
	void action();
private:

};
#endif // BOTON_H


