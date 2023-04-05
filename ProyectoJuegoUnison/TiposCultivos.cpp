#include "TipoCultivos.h"

Cultivo::Cultivo(std::string ruta, int x, int y, int tipo) : Objeto(ruta)
{
	this->sprite = al_load_bitmap(ruta.c_str());
	this->x = x;
	this->y = y;
	
}

Cultivo::~Cultivo()
{
}

void Cultivo::action()
{
	al_draw_bitmap(this->sprite, this->x, this->y, 0);
}