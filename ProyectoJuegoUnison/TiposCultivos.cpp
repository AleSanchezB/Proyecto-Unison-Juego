#include "TipoCultivos.h"
std::list<Cultivo*> cultivos;
Cultivo::Cultivo(std::string ruta, int x, int y, int tipo) : Objeto(ruta)
{
	std::cout << "Se creó" << std::endl;
	this->sprite = al_load_bitmap(ruta.c_str());
	this->x = x;
	this->y = y;

	switch (tipo)
	{
	case 0: //tomate
		this->sx = 0;
		this->sy = 0;

		this->sw = 35.0;
		this->sh = 34.0;
		break;
	case 1: //calabaza
		this->sx = 0;
		this->sy = 0;

		this->sw = 36.5;
		this->sh = 31.0;
		break;
	case 2: //zanahoria
		this->sx = 0;
		this->sy = 0;

		this->sw = 30.0;
		this->sh = 25.0;
		break;
	default:
		break;
	}
	
}

Cultivo::~Cultivo()
{
}

void Cultivo::action()
{
	try
	{
		for (std::list<Cultivo*>::iterator it = cultivos.begin(); it != cultivos.end(); it++)
		{
			Cultivo* other = *it;
			al_draw_bitmap_region(other->sprite, other->sx, other->sy, other->sw, other->sh, other->x, other->y, 0);
		}
	}
	catch (const std::exception&)
	{
		std::cout << "Error en action cultivos" << std::endl;
	}
}