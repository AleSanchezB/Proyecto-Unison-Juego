#ifndef INIMAP_H
#define INIMAP_H
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include "Player.h"
#include "DibujarFondo.h"
#include "Comprador.h"

class GameRun
{
public:
	GameRun();
	~GameRun();
	ALLEGRO_TIMER* timer;
	bool running;
private:
	//VARIABLES ALLEGRO
	ALLEGRO_DISPLAY* displayGame;
	ALLEGRO_EVENT_QUEUE* queue;
	ALLEGRO_BITMAP* ESCENAS[3];
	ALLEGRO_EVENT event;
	ALLEGRO_SAMPLE* A_actual;
	ALLEGRO_SAMPLE_INSTANCE* ambientacion;
	ALLEGRO_BITMAP* iconDisplay;
	//CONSTANTES
	const int width = 1280;
	const int height = 720;
	const float FPS = 90.0;

	//VARIABLES
	
	int mouseX, mouseY;
	int i;
	float alpha = 1.0;
	float scale = 1.0;
	bool draw = true;

	//funciones
	void initGame();
	void ColocarMusica();

	int w;
	int h;
	ALLEGRO_DISPLAY_MODE disp_data;
};
extern Background* background;
extern Player* player;
#endif // !1