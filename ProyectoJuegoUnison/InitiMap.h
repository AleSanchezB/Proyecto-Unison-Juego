#ifndef INIMAP_H
#define INIMAP_H
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <string>

#include "Player.h"
#include "DibujarFondo.h"
#include "Tienda.h"

class GameRun
{
public:
	GameRun();
	~GameRun();
	ALLEGRO_TIMER* timer;
	bool running;
private:

	enum{NORMAL, NORMALSELE};
	//VARIABLES ALLEGRO
	ALLEGRO_DISPLAY* displayGame;
	ALLEGRO_EVENT_QUEUE* queue;
	ALLEGRO_BITMAP* ESCENAS[3];
	ALLEGRO_EVENT event;
	ALLEGRO_SAMPLE* A_actual;
	ALLEGRO_SAMPLE_INSTANCE* ambientacion;
	
	ALLEGRO_BITMAP* iconDisplay;
	ALLEGRO_BITMAP* Ajustes[4];
	
	//CONSTANTES
	const int width = 1280;
	const int height = 720;
	const float FPS = 90.0;

	//VARIABLES
	int mouseX, mouseY;
	int sonido;
	int w;
	int h;
	int volumen;

	bool draw = true;

	//funciones
	void initGame();
	void ColocarMusica();
	void setVolumen(int volumen);
	int getVolumen();
};
extern Background* background;
extern Player* player;
#endif // !1