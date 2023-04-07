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


void Cultivo::action(int escena)
{
	try
	{
		for (std::list<Cultivo*>::iterator it = cultivos.begin(); it != cultivos.end(); it++)
		{
			Cultivo* other = *it;
			//std::cout << other->sx << '\n';
			other->aux++;
			if (other->aux >= 90)
			{
				other->Crecer(other);
				other->aux = 0;
			}
			if (escena == 1)
				al_draw_bitmap_region(other->sprite, other->sx, other->sy, 40, other->sh, other->x, other->y, 0);
		}
	}
	catch (const std::exception&)
	{
		std::cout << "Error en action cultivos" << std::endl;
	}
}

void Cultivo::Crecer(Cultivo* other)
{
	int resta = (int)(al_current_time() - other->T_Plantacion) % 7;
	std::cout << resta << " resta" << '\n';
	if (resta == 0 && other->estado != other->COSECHABLE) {
		other->estado++;
		//other->sh += 34;
		other->sx += 40;
		std::cout << other->sx << " sx dentro de crecer\n";
	}
}