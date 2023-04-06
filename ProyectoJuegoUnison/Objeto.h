#pragma once
#ifndef OBJETO_H
#define OBJETO_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <string>

//Esta clase unicamente la utilizo para usarla como clase padre
class Objeto
{
public:
	Objeto(std::string ruta);
	~Objeto();
	int x;
	int y;
	ALLEGRO_BITMAP* sprite;

	void action();
};
#endif // !1


