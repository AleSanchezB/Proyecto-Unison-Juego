#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <windows.h>
#include "DrawObjects.h"
#include "controlesCultivos.h"
#include <string>

using namespace std;


class Mapa1
{
public:
	Mapa1();
	~Mapa1();

private:
	//VARIABLES ALLEGRO
	ALLEGRO_BITMAP* playerBitmapImg;
	ALLEGRO_BITMAP* ESCENA3;
	ALLEGRO_BITMAP* ESCENA1;
	ALLEGRO_BITMAP* ESCENA2;
	ALLEGRO_DISPLAY* displayGame;
	ALLEGRO_EVENT_QUEUE* queue;
	ALLEGRO_FONT* font;
	ALLEGRO_TIMER* _timer;
	DrawObjects drawPlayer;
	ControlarCultivos controlsCultivos;
	ALLEGRO_BITMAP* player;
	//CONSTANTES
	const int width = 1280;
	const int height = 720;

	//VARIABLES
	float speedPlayer = 2;
	int xJugador = 640;
	int yJugador = 400;
	int xCoordsFondos = 1280;
	bool running,active=false;
	int mouseX,mouseY;
	int direccion = 0, SpritePosX = 0,SpritePosY=0,corriendo=0;
	int PlayRefresh = 0;
	//DIRECCIONES
	enum {DOWNW,RIGHTW,UPW,LEFTW};
	//VARIABLES FPS
	int fps = 0;
	int frame_count = 0;
	double frame_time = 0;
	//funciones
	void init();
	void initRoom();
	void loadImg();
	void move(ALLEGRO_KEYBOARD_STATE keystate);
	void drawBackground();
	//void move(ALLEGRO_KEYBOARD_STATE keysta);

};
Mapa1::Mapa1()
{
	al_init_image_addon();
	al_install_keyboard();
	al_init_font_addon();
	al_init_ttf_addon();
	init();
	initRoom();
}
Mapa1::~Mapa1()
{
	al_init();
	al_destroy_bitmap(playerBitmapImg);
	al_destroy_display(displayGame);
	al_destroy_timer(_timer);
	al_uninstall_keyboard();
	al_destroy_font(font);
}
void Mapa1::loadImg()
{
	font = al_load_font("assets/fonts/Minecraft.ttf", 20, 0);
	playerBitmapImg = al_load_bitmap("assets/Sprites Players/NO SE USARA/PNG/IdleTam/frame01.png");
	ESCENA3 = al_load_bitmap("assets/fondos/fondo2.png");
	ESCENA1 = al_load_bitmap("assets/fondos/Escena1.png");
	ESCENA2 = al_load_bitmap("assets/fondos/Escena2.png");
	player = al_load_bitmap("assets/IdleTam/Sprites Players/characters/Walk_run Player.png");
	assert(playerBitmapImg != NULL);
	assert(ESCENA1 != NULL);
	assert(ESCENA2 != NULL);
	assert(ESCENA3 != NULL);
}
//inicializa y define las variables;
void Mapa1::init()
{
	running = true;

	al_set_new_display_flags(ALLEGRO_RESIZABLE);
	displayGame = al_create_display(width, height);
	al_set_window_title(displayGame, "Juego version Beta");
	
	queue = al_create_event_queue();
	_timer = al_create_timer(1.0 / 60);
	al_start_timer(_timer);
	al_register_event_source(queue, al_get_display_event_source(displayGame));
	al_register_event_source(queue, al_get_keyboard_event_source());
	al_register_event_source(queue, al_get_timer_event_source(_timer));
	loadImg();
}
void Mapa1::initRoom()
{
	drawPlayer.initImg();
	while (running)
	{
		drawBackground();
		ALLEGRO_EVENT event;
		al_wait_for_event(queue, &event);
		ALLEGRO_KEYBOARD_STATE keystate;
		al_get_keyboard_state(&keystate);

		if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			running = false;
		}

		if (event.type == ALLEGRO_EVENT_TIMER)
		{
		move(keystate);
		}
	}
}

void Mapa1::drawBackground() {
	al_clear_to_color(al_map_rgb_f(254, 254, 254));
	al_draw_bitmap(ESCENA2, xCoordsFondos, 0, 0);
	al_draw_bitmap(ESCENA3, xCoordsFondos + 1280, 0, 0);
	al_draw_bitmap(ESCENA1, xCoordsFondos - 1280, 0, 0);
	al_draw_text(font, al_map_rgb(255, 255, 255), 10, 10, ALLEGRO_ALIGN_LEFT, ("xjugador: " + to_string(xJugador)).c_str());
	al_draw_text(font, al_map_rgb(255, 255, 255), 10, 30, ALLEGRO_ALIGN_LEFT, ("yjugador: " + to_string(yJugador)).c_str());
	al_draw_text(font, al_map_rgb(255, 255, 255), 10, 50, ALLEGRO_ALIGN_LEFT, ("xFondo: " + to_string(xCoordsFondos)).c_str());
	al_draw_textf(font, al_map_rgb(189, 39, 7), 10, 90, 0, "FPS: %d", fps);
		drawPlayer.Animate(SpritePosX, SpritePosY * 50, 33.0f, 51.0f, xJugador, yJugador);
	al_flip_display();
}
void Mapa1::move(ALLEGRO_KEYBOARD_STATE keystate)
{
	al_get_keyboard_state(&keystate);
	ALLEGRO_EVENT events;
	al_wait_for_event(queue, &events);
	
	if (al_key_down(&keystate, ALLEGRO_KEY_F))
	{
		//obtengo las coords del puntero del mouse
		controlsCultivos.plantarCultivo(keystate, queue);
	}
	else 
	{
		active = true;
		if (al_key_down(&keystate, ALLEGRO_KEY_LSHIFT)) {
			speedPlayer = 4;
			corriendo = 4;
		}
		else {
			speedPlayer = 2;
			corriendo = 0;
		}
		if (al_key_down(&keystate, ALLEGRO_KEY_W)) {
			yJugador -= speedPlayer;
			direccion=UPW+corriendo;
		}
		else if (al_key_down(&keystate, ALLEGRO_KEY_S)) {
			yJugador += speedPlayer;
			direccion=DOWNW+corriendo;
		}
		else if (al_key_down(&keystate, ALLEGRO_KEY_D)) {
			xJugador += speedPlayer;
			direccion=RIGHTW+corriendo;
		}
		else if (al_key_down(&keystate, ALLEGRO_KEY_A)) {
			xJugador -= speedPlayer;
			direccion = LEFTW+corriendo;
		}
		else active = false;
		PlayRefresh++;
		if (PlayRefresh == 6) {
			if (SpritePosX >= 165) SpritePosX = 0;
			if (active) SpritePosX += 33;
			else SpritePosX = 0;
			SpritePosY = direccion;
			PlayRefresh = 0;
		}
	}
}