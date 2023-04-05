#ifndef INIMAP_H
#define INIMAP_H
#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <windows.h>
#include <string>
#include <chrono>
#include <list>

#include "Objeto.h"
#include "Player.h"
#include "TipoCultivos.h"
#include "DrawObjects.h"
#include "controlesCultivos.h"

std::list<Cultivo*>cultivos;
class GameRun
{
public:
	GameRun();
	~GameRun();

private:
	//VARIABLES ALLEGRO
	ALLEGRO_DISPLAY* displayGame;
	ALLEGRO_EVENT_QUEUE* queue;
	ALLEGRO_BITMAP* ESCENAS[3];
	ALLEGRO_TIMER* _timer;
	ALLEGRO_EVENT event;

	//CONSTANTES
	const int width = 1280;
	const int height = 720;

	//VARIABLES
	bool running;
	int mouseX, mouseY;
	int i;

	float alpha = 1.0;
	float scale = 1.0;

	//funciones
	void initGame();
	void DibujarGradualmente();
};
#endif // !1