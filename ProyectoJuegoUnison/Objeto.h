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
	ALLEGRO_BITMAP* sprite;
	
	int x;
	int y;

	void action();
};
#endif // !1


