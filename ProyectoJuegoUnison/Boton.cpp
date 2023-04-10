#include "Boton.h"

Boton::Boton(std::string btnSinPresionar, float x, float y, float w, float h)
{
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;

	this->sprite = al_load_bitmap(btnSinPresionar.c_str());
}
void Boton::action()
{
	al_draw_bitmap(this->sprite, this->x, this->y, 0);
}