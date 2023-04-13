#include "Mochila.h"

Mochila::Mochila(int cantidadObjetos, int cantidadTomates, int cantidadCalabaza, int cantidadZanahoria, ALLEGRO_FONT * font)
{
	this->cantidadObjetos = cantidadObjetos;
	this->cantidadTomates = cantidadTomates;
	this->cantidadCalabaza = cantidadCalabaza;
	this->cantidadZanahoria = cantidadZanahoria;
	this->casillaSelect = 0;
	this->font = font;
	this->Monedas = 10;
	barraHerramientas = al_load_bitmap("assets/fondos/Objetos/barraHerramientas.png");
	seleccionHerramienta = al_load_bitmap("assets/fondos/Objetos/seleccionHerramienta.png");
	tom = al_load_bitmap("assets/Plants/tomate item.png");
	cal = al_load_bitmap("assets/Plants/calabaza item.png");
	zana = al_load_bitmap("assets/Plants/zanahoria item.png");
}
Mochila::~Mochila()
{
	al_destroy_font(font);
	al_destroy_bitmap(seleccionHerramienta);
	al_destroy_bitmap(barraHerramientas);
	al_destroy_bitmap(tom);
	al_destroy_bitmap(cal);
	al_destroy_bitmap(zana);
}
void Mochila::setcantidadObjetos(int cantidadObjetos)
{
	this->cantidadObjetos = cantidadObjetos;
}

void Mochila::setcantidadTomates(int cantidadTomates)
{
	this->cantidadTomates = cantidadTomates;
}

void Mochila::setcantidadCalabaza(int cantidadCalabaza)
{
	this->cantidadCalabaza = cantidadCalabaza;
}

void Mochila::setcantidadZanahoria(int cantidadZanahoria)
{
	this->cantidadZanahoria = cantidadZanahoria;
}

int Mochila::getcantidadTomates()
{
	return this->cantidadTomates;
}

int Mochila::getcantidadCalabaza()
{
	return this->cantidadCalabaza;
}

int Mochila::getcantidadZanahoria()
{
	return this->cantidadZanahoria;
}

int Mochila::getcantidadObjetos()
{
	return this->cantidadObjetos;
}

void Mochila::action()
{
	al_draw_bitmap(barraHerramientas, 530, 658, 0);
	al_draw_bitmap(seleccionHerramienta, 538 + 42 * casillaSelect, 663, 0);
	al_draw_bitmap(tom, 548, 669, 0);
	al_draw_bitmap(cal, 589, 669, 0);
	al_draw_bitmap(zana, 635, 669, 0);
	al_draw_text(font, al_map_rgb(255, 255, 255), 572, 690, ALLEGRO_ALIGN_LEFT, std::to_string(cantidadTomates).c_str());
	al_draw_text(font, al_map_rgb(255, 255, 255), 572+42, 690, ALLEGRO_ALIGN_LEFT, std::to_string(cantidadCalabaza).c_str());
	al_draw_text(font, al_map_rgb(255, 255, 255), 572+42*2, 690, ALLEGRO_ALIGN_LEFT, std::to_string(cantidadZanahoria).c_str());
}
void Mochila::cambiarCasilla(int casillaSelect)
{
	if (this->casillaSelect == 0 && casillaSelect < 0) this->casillaSelect = 4;
	else if(this->casillaSelect == 4 && casillaSelect > 1) this->casillaSelect = 0;
	else this->casillaSelect = casillaSelect;
}

int Mochila::verificarObjectoSeleccionado()
{
	return this->casillaSelect;
}
void Mochila::quitarCultivo(int tipo)
{
	switch (tipo)
	{
	case 0: //tomate
		setcantidadTomates(getcantidadTomates() - 1);
		break;
	case 1: //calabaza
		setcantidadCalabaza(getcantidadCalabaza() - 1);
		break;
	case 2: //zanahoria
		setcantidadZanahoria(getcantidadZanahoria() - 1);
		break;
	default:
		break;
	}
}
bool Mochila::verificarCantidadCultivos(int tipo)
{
	switch (tipo)
	{
	case 0:
		if (getcantidadTomates() > 0) return true;
		else return false;
	case 1:
		if (getcantidadCalabaza() > 0) return true;
		else return false;
	case 2:
		if (getcantidadZanahoria() > 0) return true;
		else
		{
			return false;
		}
	default:
		break;
	}
	return false;
}
bool Mochila::verificacionMochila()
{
	if (getcantidadObjetos() > 0) return true;
	return false;
}
void Mochila::setMonedas(int Monedas)
{
	this->Monedas = Monedas;
}

int Mochila::getMonedas()
{
	return this->Monedas = Monedas;
}

bool Mochila::verificarCantidadCultivosGuardados(int tipo, int cantidad)
{
	switch (tipo)
	{
	case 0:
		if (cantidad > 0 && cantidad <= getcantidadTomates()) return true;
		else return false;
	case 1:
		if (cantidad > 0 && cantidad <= getcantidadCalabaza()) return true;
		else return false;
	case 2:
		if (cantidad > 0 && cantidad <= getcantidadZanahoria()) return true;
		else
		{
			return false;
		}
	default:
		break;
	}
	return false;
}