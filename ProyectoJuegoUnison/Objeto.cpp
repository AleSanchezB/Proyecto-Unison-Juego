#include "Objeto.h"

Objeto::Objeto(std::string ruta)
{
	this->sprite = al_load_bitmap(ruta.c_str());
	this->x = 0;
	this->y = 0;
}
Objeto::~Objeto()
{
	al_destroy_bitmap(this->sprite);
}

void Objeto::action()
{
	const int spriteW = al_get_bitmap_width(sprite);
	const int spriteH = al_get_bitmap_height(sprite);
	al_draw_bitmap(this->sprite, spriteW, spriteH, 0);
}