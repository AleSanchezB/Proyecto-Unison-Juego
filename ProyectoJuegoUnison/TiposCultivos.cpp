#include "TipoCultivos.h"
Cultivo* matrizCultivos[8];
Cultivo::Cultivo(int x, int y, int tipo, int T_Creado) : Objeto(ruta)
{
	this->tipo = tipo;
	switch (tipo)
	{
	case 0: //tomate
		this->ruta = "assets/Plants/tomate sprites.png";
		break;
	case 1: //calabaza
		this->ruta = "assets/Plants/calabaza sprites.png";
		break;
	case 2: //zanahoria
		this->ruta = "assets/Plants/zanahoria sprites.png";
		break;
	default:
		break;
	}
	this->sprite = al_load_bitmap(ruta.c_str());
	this->sx = 0;
	this->sy = 0;
	this->sw = 45;
	this->sh = 36;
	this->x = x;
	this->y = y;
	this->T_Plantacion = T_Creado;
}

Cultivo::~Cultivo()
{
}


void Cultivo::action(int escena)
{
	try
	{
		for (int i = 0; i < 8; i++)
		{
			if (matrizCultivos[i] != NULL)
			{
				Cultivo* other = matrizCultivos[i];
				other->aux++;
				if (other->aux >= 90 && other->estado != other->COSECHABLE)
				{
					other->Crecer(other);
					other->aux = 0;
				}
				al_draw_bitmap_region(other->sprite, other->sx, other->sy, other->sw, other->sh, other->x, other->y, 0);
			}

		}
	}
	catch (const std::exception&)
	{
		std::cout << "Error en action cultivos" << std::endl;
	}
}

void Cultivo::Crecer(Cultivo* other)
{
	/*int resta = (int)(al_current_time() - other->T_Plantacion) % 7;
	if (resta == 0)
	{
		other->estado++;
		other->sy += 36;
	}*/
	float tiempo_actual = al_get_time();
	srand(time(NULL)); // semilla para generar números aleatorios
	float tiempo_crecimiento_aleatorio = (rand() % 61 + 180); // Entre 3 y 4 minutos en segundos
	float tiempo_transcurrido = tiempo_actual - other->T_Plantacion;
	std::cout << "tiempo_actual: " << tiempo_actual << "\n tiempo_crecimiento_aleatorio: " 
		<< tiempo_crecimiento_aleatorio << "\n tiempo_transcurrido: " << tiempo_transcurrido << "\n ";
	if (tiempo_transcurrido >= tiempo_crecimiento_aleatorio) {
		other->estado++;
		other->sy += 36;
		other->T_Plantacion = tiempo_actual;
	}
}