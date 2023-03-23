#ifndef INIMAP_H
#define INIMAP_H
#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <windows.h>
#include "DrawObjects.h"
#include "controlesCultivos.h"
#include <string>
#include <chrono>

using namespace std;

class Mapa1
{
public:
	Mapa1();
	~Mapa1();
	void setMonedas(int monedas);

private:
	//VARIABLES ALLEGRO
	ALLEGRO_DISPLAY* displayGame;
	ALLEGRO_EVENT_QUEUE* queue;
	ALLEGRO_BITMAP* ESCENAS[3];
	ALLEGRO_TIMER* _timer;
	ALLEGRO_EVENT event;
	DrawObjects drawPlayer;

	//CONSTANTES
	const int width = 1280;
	const int height = 720;

	//VARIABLES
	bool running;
	int mouseX, mouseY;
	int Monedas;
	int i;

	float alpha = 1.0;
	float x = 0;
	float y = 0;
	float scale = 1.0;

	//funciones
	void init();
	void initRoom();
	int getMonedas();
	void DibujarGradualmente();

	//VARIABLES FPS
	int fps = 0;
	int frame_count = 0;
	double frame_time = 0;
};
#endif // !1