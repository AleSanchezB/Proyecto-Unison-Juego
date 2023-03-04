#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <windows.h>
#include "DrawObjects.h"
#include "playerMovement.h"
#include <string>

using namespace std;

class Mapa1;

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
	PlayerMovement playerMovement;

	//CONSTANTES
	const float speedPlayer = 2;
	const int width = 1280;
	const int height = 720;

	//VARIABLES
	int xJugador = 152;
	int yJugador = 217;
	int xCoordsFondos = 1280, PlayerY = 0;
	bool running;

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
	//void move(ALLEGRO_KEYBOARD_STATE keystate);
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
	_timer = al_create_timer(1.0 / 120);
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
			frame_count++;
			frame_time += al_get_timer_speed(_timer);
			if (frame_time >= 1.0) {
				fps = frame_count;
				frame_count = 0;
				frame_time = 0;
			}
		}
		move(keystate);
	}
}
void Mapa1::drawBackground() {
	al_clear_to_color(al_map_rgb_f(254, 254, 254));
	al_draw_bitmap(ESCENA2, xCoordsFondos, PlayerY, 0);
	al_draw_bitmap(ESCENA3, xCoordsFondos + 1280, PlayerY, 0);
	al_draw_bitmap(ESCENA1, xCoordsFondos - 1280, PlayerY, 0);
	al_draw_text(font, al_map_rgb(255, 255, 255), 10, 10, ALLEGRO_ALIGN_LEFT, ("xjugador: " + to_string(xJugador)).c_str());
	al_draw_text(font, al_map_rgb(255, 255, 255), 10, 30, ALLEGRO_ALIGN_LEFT, ("yjugador: " + to_string(yJugador)).c_str());
	al_draw_text(font, al_map_rgb(255, 255, 255), 10, 50, ALLEGRO_ALIGN_LEFT, ("xFondo: " + to_string(xCoordsFondos)).c_str());
	al_draw_textf(font, al_map_rgb(189, 39, 7), 10, 90, 0, "FPS: %d", fps);
	drawPlayer.draw(xJugador, yJugador);
	al_flip_display();
}
void Mapa1::move(ALLEGRO_KEYBOARD_STATE keystate)
{
	al_get_keyboard_state(&keystate);

	//colision con los marcos
	if (yJugador <= 0) yJugador = 1;
	else if (yJugador >= 620) yJugador = 619;
	else if (xJugador <= 0) xJugador = 1;
	else if (xJugador >= 1205) xJugador = 1204;

	if (xCoordsFondos <= 1279.5 && xCoordsFondos >= -1279.5)
	{
		if (al_key_down(&keystate, ALLEGRO_KEY_W)) yJugador -= speedPlayer;
		if (al_key_down(&keystate, ALLEGRO_KEY_S)) yJugador += speedPlayer;
		if (al_key_down(&keystate, ALLEGRO_KEY_D)) xCoordsFondos -= speedPlayer;
		if (al_key_down(&keystate, ALLEGRO_KEY_A)) xCoordsFondos += speedPlayer;
		xJugador = 640;

	}
	else
	{
		if (xCoordsFondos > 1280) xCoordsFondos -= speedPlayer - 1;
		else if (xCoordsFondos < -1280) xCoordsFondos += speedPlayer - 1;

		if (xJugador <= 640 && xJugador >= 0 && xCoordsFondos > 1279)
		{
			if (al_key_down(&keystate, ALLEGRO_KEY_W)) yJugador -= speedPlayer;
			if (al_key_down(&keystate, ALLEGRO_KEY_S)) yJugador += speedPlayer;
			if (al_key_down(&keystate, ALLEGRO_KEY_D)) xJugador += speedPlayer;
			if (al_key_down(&keystate, ALLEGRO_KEY_A)) xJugador -= speedPlayer;

			if (xJugador > 640) xCoordsFondos = 1279;
		}
		else if (xJugador >= 640 && xJugador <= 1280 && xCoordsFondos < -1279) {
			if (al_key_down(&keystate, ALLEGRO_KEY_W)) yJugador -= speedPlayer;
			if (al_key_down(&keystate, ALLEGRO_KEY_S)) yJugador += speedPlayer;
			if (al_key_down(&keystate, ALLEGRO_KEY_D)) xJugador += speedPlayer;
			if (al_key_down(&keystate, ALLEGRO_KEY_A)) xJugador -= speedPlayer;

			if (xJugador < 640) xCoordsFondos = -1279;
		}
	}
}