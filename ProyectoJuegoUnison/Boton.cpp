#include "Boton.h"

Boton::Boton(std::string btnSinPresionar, std::string btnPresionado, float x, float y, float w, float h)
{
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;

	this->sprite[0] = al_load_bitmap(btnSinPresionar.c_str());
	this->sprite[1] = al_load_bitmap(btnPresionado.c_str());
}
void Boton::action(int i)
{
	al_draw_bitmap(this->sprite[i], this->x, this->y, 0);
}