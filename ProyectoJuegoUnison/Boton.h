#pragma once
#ifndef BOTON_H
#define BOTON_H
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
#include <string>
class Boton
{
public:
	Boton(std::string ruta, std::string btnPresionado, float x, float y, float w, float h);
	~Boton();

	float x;
	float y;	
	float w;
	float h;
	ALLEGRO_BITMAP* sprite[2];
	void action(int i);
private:

};
#endif // BOTON_H


