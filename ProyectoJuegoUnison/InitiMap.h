#ifndef INIMAP_H
#define INIMAP_H
#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <thread>

#include "Player.h"
#include "DrawObjects.h"
#include "Comprador.h"

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
	const double TARGET_FPS = 1000000000 / FPS;
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
	void Update(ALLEGRO_KEYBOARD_STATE keystate, ALLEGRO_EVENT_QUEUE* queue);
	void Draw();
};
extern Background* background;
extern Player* player;
#endif // !1