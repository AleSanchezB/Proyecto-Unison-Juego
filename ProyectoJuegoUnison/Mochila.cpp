#include "Mochila.h"

Mochila::Mochila(int cantidadObjetos, int cantidadTomates, int cantidadCalabaza, int cantidadZanahoria)
{
	this->cantidadObjetos = cantidadObjetos;
	this->cantidadTomates = cantidadTomates;
	this->cantidadCalabaza = cantidadCalabaza;
	this->cantidadZanahoria = cantidadZanahoria;

	for (int i = 0; i < cantidadTomates; i++)
	{
		cantTomates.push_back(new Cultivo("assets/Plants/tomate sprites.png",0,0,0));
	}

	for (int i = 0; i < cantidadCalabaza; i++)
	{
		cantCalabazas.push_back(new Cultivo("assets/Plants/calabaza sprites.png", 0, 0, 1));
	}

	for (int i = 0; i < cantidadZanahoria; i++)
	{
		cantZanahorias.push_back(new Cultivo("assets/Plants/zanahoria sprites.png", 0, 0, 2));
	}
	barraHerramientas = al_load_bitmap("assets/fondos/Objetos/barraHerramientas.png");
	seleccionHerramienta = al_load_bitmap("assets/fondos/Objetos/seleccionHerramienta.png");
	tom = al_load_bitmap("assets/Plants/tomate item.png");
	cal = al_load_bitmap("assets/Plants/calabaza item.png");
	zana = al_load_bitmap("assets/Plants/zanahoria item.png");
}

void Mochila::setcantidadObjetos(int cantidadObjetos)
{
	this->cantidadObjetos = cantidadObjetos;
}

void Mochila::setcantidadTomates(int cantidadTomates)
{
	if (cantidadTomates < getcantidadTomates()) cantTomates.pop_back();
	else cantTomates.push_back(new Cultivo("assets/Plants/tomate sprites.png", 0, 0, 0));
	this->cantidadTomates = cantidadTomates;
}

void Mochila::setcantidadCalabaza(int cantidadCalabaza)
{
	if (cantidadCalabaza < getcantidadCalabaza()) cantCalabazas.pop_back();
	else cantCalabazas.push_back(new Cultivo("assets/Plants/calabaza sprites.png", 0, 0, 1));
	this->cantidadCalabaza = cantidadCalabaza;
}

void Mochila::setcantidadZanahoria(int cantidadZanahoria)
{
	if (cantidadZanahoria < getcantidadZanahoria()) cantZanahorias.pop_back();
	else cantZanahorias.push_back(new Cultivo("assets/Plants/zanahoria sprites.png", 0, 0, 2));
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

void Mochila::action(ALLEGRO_FONT *font)
{
	/*for (std::list<Cultivo*>::iterator it = cantTomates.begin(); it != cantTomates.end(); it++)
	{
		Cultivo* other = *it;
		al_draw_bitmap(other->sprite, 50, 50, 0);
	}
	for (std::list<Cultivo*>::iterator it = cantCalabazas.begin(); it != cantCalabazas.end(); it++)
	{
		Cultivo* other = *it;
		al_draw_bitmap(other->sprite, 100, 100, 0);
	}
	for (std::list<Cultivo*>::iterator it = cantZanahorias.begin(); it != cantZanahorias.end(); it++)
	{
		Cultivo* other = *it;
		al_draw_bitmap(other->sprite, 150, 150, 0);
	}*/
	al_draw_bitmap(barraHerramientas, 530, 658, 0);
	al_draw_bitmap(seleccionHerramienta, 538 + 42 * 0, 663, 0);
	al_draw_bitmap(tom, 548, 669, 0);
	al_draw_bitmap(cal, 589, 669, 0);
	al_draw_bitmap(zana, 635, 669, 0);
	al_draw_text(font, al_map_rgb(255, 255, 255), 572, 690, ALLEGRO_ALIGN_LEFT, std::to_string(cantidadTomates).c_str());
	al_draw_text(font, al_map_rgb(255, 255, 255), 572+42, 690, ALLEGRO_ALIGN_LEFT, std::to_string(cantidadCalabaza).c_str());
	al_draw_text(font, al_map_rgb(255, 255, 255), 572+42*2, 690, ALLEGRO_ALIGN_LEFT, std::to_string(cantidadZanahoria).c_str());
}