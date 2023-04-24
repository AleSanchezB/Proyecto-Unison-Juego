#pragma once
#ifndef TIENDA_H
#define TIENDA_H
#include <allegro5/allegro5.h>
#include <allegro5/bitmap.h>
#include <string>
#include <cmath>
#include <ctime>
#include <random>
#define DX 4
#include "Boton.h"
#include "InitiMap.h"

class Tienda
{
public:
	Tienda();
	~Tienda();

	void MenuVenderCultivos(ALLEGRO_KEYBOARD_STATE keystate, ALLEGRO_EVENT_QUEUE* queue);
	void MenuComprarCultivos(ALLEGRO_KEYBOARD_STATE keystate, ALLEGRO_EVENT_QUEUE* queue);
	void animacionMenu(int tipo);
	void animacionMonedas();
	void animacionDinero(int Pago);
	void GenerarVendibles();
	void GenerarComprables();
	std::string cultivos[9] = {
		".- Tomates  . . . . . . . . . . . . . . . . . . . . . . . . . . . . $100",
		".- Calabazas  . . . . . . . . . . . . . . . . . . . . . . . . . . . $150",
		".- Zanahorias . . . . . . . . . . . . . . . . . . . . . . . . . . . $150",
		"-. Berenjenas . . . . . . . . . . . . . . . . . . . . . . . . . . . $200",
		"-. Ejotes . . . . . . . . . . . . . . . . . . . . . . . . . . . . . $180",
		"-. Maiz . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . $250",
		"-. Papa  . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .$250",
		"-. Papaya  . . . . . . . . . . . . . . . . . . . . . . . . . . . . .$200",
		"-. Remolacha  . . . . . . . . . . . . . . . . . . . . . . . . . . . $200",
	};
	std::string MensajeVendibles[3];
	std::string MensajeComprables[3];

	int vendibles[3] = { 0 ,0 ,0 };
	int comprables[3] = { 0 ,0 ,0 };

private:
	ALLEGRO_BITMAP* menu[37];
	ALLEGRO_BITMAP* coins;
	ALLEGRO_FONT* font;

	int animacion_y;
	int animacion_x;
	int MenuImg;
	int CantVender;
	int CantComprar;
	int TipoCultivo;
	int cantDig;
	int xVenta = 604;

	Boton* btnflechaArriba[4];
	Boton* btnflechaAbajo[4];
	Boton* btnSalir[2];
	Boton* botones[4];

	const int precios[9] = { 100, 150, 150, 200, 180, 250, 250, 200, 200 };

	void DibujarCantidadSelec();
	void AnimacionReversa();
	void action(int btnCult = 0, int btnCant = 1, int btnCultB = 0, int btnCantB = 1, int btnExit = 0, int btnVen = 0);
	void DibujarFondo();
	bool VerificarVenta();
	bool VerificarCompra();
	void Sleep(int segundos);
	void DibujarPrecios();
};

#endif // !COMPRADOR_H