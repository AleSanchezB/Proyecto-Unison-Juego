#ifndef INIMAP_H
#define INIMAP_H
#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_audio.h>
#include <windows.h>
#include <string>
#include <chrono>
#include <list>

#include "Objeto.h"
#include "Player.h"
#include "TipoCultivos.h"
#include "DrawObjects.h"

class GameRun
{
public:
	GameRun();
	~GameRun();
	ALLEGRO_TIMER* timer;
private:
	//VARIABLES ALLEGRO
	ALLEGRO_DISPLAY* displayGame;
	ALLEGRO_EVENT_QUEUE* queue;
	ALLEGRO_BITMAP* ESCENAS[3];
	ALLEGRO_EVENT event;
	ALLEGRO_SAMPLE* A_actual;
	ALLEGRO_SAMPLE_INSTANCE* ambientacion;

	//CONSTANTES
	const int width = 1280;
	const int height = 720;
	const float FPS = 90.0;
	//VARIABLES
	bool running;
	int mouseX, mouseY;
	int i;

	float alpha = 1.0;
	float scale = 1.0;


	bool draw = true;
	//funciones
	void initGame();
	void DibujarGradualmente();
	void ColocarMusica();
};
#endif // !1