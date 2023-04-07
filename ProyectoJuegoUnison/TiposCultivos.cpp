#include "TipoCultivos.h"
std::list<Cultivo*> cultivos;
Cultivo::Cultivo(std::string ruta, int x, int y, int tipo,int T_Creado) : Objeto(ruta)
{
	std::cout << "Se creó" << std::endl;
	this->sprite = al_load_bitmap(ruta.c_str());
	this->x = x;
	this->y = y;
	this-> T_Plantacion= T_Creado;
	switch (tipo)
	{
	case 0: //tomate
		this->sx = 0;
		this->sy = 0;

		this->sw = 40.0;
		this->sh = 34.0;
		break;
	case 1: //calabaza
		this->sx = 0;
		this->sy = 0;

		this->sw = 40.0;
		this->sh = 34.0;
		break;
	case 2: //zanahoria
		this->sx = 0;
		this->sy = 0;

		this->sw = 40.0;
		this->sh = 34.0;
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

void Cultivo::Crecer(float T_Actual)
{
	int resta = (int)(T_Actual - T_Plantacion)%7;
	std::cout << resta<<'\n';
	if (resta==0 && estado != COSECHABLE) {
		estado++;
		sw += 40;
		sh += 34;
		al_draw_bitmap_region(this->sprite, sw, sh, 40, 34, this->x-40, this->y, 0);
	}
}