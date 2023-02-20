#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <windows.h>
#include "DrawObjects.h"

using namespace std;

class Mapa1
{
public:
	Mapa1();
	~Mapa1();

private:
	//VARIABLES ALLEGRO
	ALLEGRO_BITMAP* _player;
	ALLEGRO_BITMAP* FONDO;
	ALLEGRO_BITMAP* ESCENA1;
	ALLEGRO_BITMAP* ESCENA2;
	ALLEGRO_BITMAP* OBJETO;
	ALLEGRO_DISPLAY* display;
	ALLEGRO_EVENT_QUEUE* queue;
	ALLEGRO_FONT* font;
	ALLEGRO_TIMER* _timer;
	DrawObjects drawPlayer;

	//CONSTANTES
	float speedPlayer = 2;
	int screenWidth = GetSystemMetrics(SM_CXSCREEN);
	int screenHeight = GetSystemMetrics(SM_CYSCREEN);

	//VARIABLES
	int xJugador = 152;
	int yJugador = 217;
	int PlayerX = 1280, PlayerY = 0;
	bool running;
	int width;
	int height;

	//VARIABLES FPS
	int fps = 0;
	int frame_count = 0;
	double frame_time = 0;

	//funciones
	void init();
	void initRoom();
	void draw();
	void drawBackground(int xJugador, int yJugador);
	void destroyAl();
	void loadImg();
	void installAl();
	void move(ALLEGRO_KEYBOARD_STATE keystate);
};
Mapa1::Mapa1()
{
	width = 1280;
	height = 720;
	initRoom();
}
Mapa1::~Mapa1()
{
	al_destroy_bitmap(_player);
	al_destroy_display(display);
	al_destroy_timer(_timer);
	al_uninstall_keyboard();
	al_destroy_font(font);
}
void Mapa1::installAl() 
{
	al_init_image_addon();
	al_install_keyboard();
	al_init_font_addon();
	al_init_ttf_addon();

	
}
void Mapa1::loadImg()
{
	font = al_load_font("ASSETS/fonts/Minecraft.ttf", 20, 0);
	_player = al_load_bitmap("ASSETS/IdleTam/frame01.png");
	FONDO = al_load_bitmap("ASSETS/fondos/fondo2.png");
	ESCENA1 = al_load_bitmap("ASSETS/fondos/Escena1.png");
	ESCENA2 = al_load_bitmap("ASSETS/fondos/Escena2.png");
	OBJETO = al_load_bitmap("ASSETS/IdleTam/Wraith_03_Idle_001.png");
	assert(_player != NULL);
	assert(FONDO != NULL);
}
//inicializa y define las variables;
void Mapa1::init() 
{
	installAl();
	running = true;
	al_set_new_display_flags(ALLEGRO_RESIZABLE);
	display = al_create_display(width, height);
	al_set_window_title(display, "Juego version Beta");
	//al_set_window_constraints(display,200,200, width,height);
	
	queue = al_create_event_queue();
	_timer = al_create_timer(1.0 / 60);
	//xJugador = al_get_display_width(display) / 2;
	//yJugador = al_get_display_height(display) / 2;
	al_start_timer(_timer);
	al_register_event_source(queue, al_get_display_event_source(display));
	al_register_event_source(queue, al_get_keyboard_event_source());
	al_register_event_source(queue, al_get_timer_event_source(_timer));
	loadImg();
}
//dibuja
void Mapa1::draw() {
	al_clear_to_color(al_map_rgb_f(254, 254, 254));
	drawBackground(xJugador, yJugador);
	al_draw_bitmap(OBJETO, PlayerX, PlayerY, 0); //generarlo en otra funcion y tambien cuando lo tome
	al_draw_bitmap(_player, xJugador, yJugador, 0);
	al_draw_textf(font, al_map_rgb(189, 39, 7), 10, 10, 0, "FPS: %d", fps);
	al_draw_textf(font, al_map_rgb(189, 39, 7), 10, 30, 0, "x: %d", PlayerX);
	al_draw_textf(font, al_map_rgb(189, 39, 7), 10, 50, 0, "y: %d", PlayerY);
	al_draw_textf(font, al_map_rgb(189, 39, 7), 10, 70, 0, "xP: %d", xJugador);
	al_draw_textf(font, al_map_rgb(189, 39, 7), 10, 90, 0, "yP: %d", yJugador);
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


	if ((PlayerY <= 720 && PlayerY >= -720) && (PlayerX <= 1279.5 && PlayerX >= -1279.5)) 
	{
		if (al_key_down(&keystate, ALLEGRO_KEY_W)) yJugador -= 1.2*speedPlayer;
		if (al_key_down(&keystate, ALLEGRO_KEY_S)) yJugador += speedPlayer;
		if (al_key_down(&keystate, ALLEGRO_KEY_D)) PlayerX -= speedPlayer;
		if (al_key_down(&keystate, ALLEGRO_KEY_A)) PlayerX += speedPlayer;
		xJugador = 640;
		
	}
	else 
	{
		if (PlayerX > 1280) PlayerX -= speedPlayer -1;
		else if (PlayerX < -1280) PlayerX += speedPlayer - 1;

		if (xJugador <= 640 && xJugador >= 0 && PlayerX > 1279) 
		{
			if (al_key_down(&keystate, ALLEGRO_KEY_W)) yJugador -= speedPlayer;
			if (al_key_down(&keystate, ALLEGRO_KEY_S)) yJugador += speedPlayer;
			if (al_key_down(&keystate, ALLEGRO_KEY_D)) xJugador += speedPlayer;
			if (al_key_down(&keystate, ALLEGRO_KEY_A)) xJugador -= speedPlayer;

			if (xJugador > 640) PlayerX = 1279;
		}
		else if (xJugador >= 640 && xJugador <= 1280 && PlayerX < -1279) {
			if (al_key_down(&keystate, ALLEGRO_KEY_W)) yJugador -= speedPlayer;
			if (al_key_down(&keystate, ALLEGRO_KEY_S)) yJugador += speedPlayer;
			if (al_key_down(&keystate, ALLEGRO_KEY_D)) xJugador += speedPlayer;
			if (al_key_down(&keystate, ALLEGRO_KEY_A)) xJugador -= speedPlayer;

			if (xJugador < 640) PlayerX = -1279;
		}
	}
}
void Mapa1::initRoom()
{
	
	al_init();
	init();
	drawPlayer.initImg();
	while (running)
	{
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
		//draw();
		move(keystate);
		drawBackground(xJugador, yJugador);
	}
}
void Mapa1::destroyAl() {

}
void Mapa1::drawBackground(int xJugador, int yJugador) {
	
	
	al_clear_to_color(al_map_rgb_f(254, 254, 254));
	al_draw_bitmap(ESCENA2, PlayerX, PlayerY, 0);
	//al_draw_bitmap(FONDO, PlayerX, PlayerY + 720, 0);
	//al_draw_bitmap(FONDO, PlayerX, PlayerY - 720, 0);
	al_draw_bitmap(FONDO, PlayerX + 1280, PlayerY, 0);
	al_draw_bitmap(ESCENA1, PlayerX - 1280, PlayerY, 0);
	drawPlayer.draw(xJugador, yJugador);
	al_flip_display();
	//al_draw_bitmap(FONDO, PlayerX + 1280, PlayerY + 720, 0);
	//al_draw_bitmap(FONDO, PlayerX - 1280, PlayerY - 720, 0);
	//al_draw_bitmap(FONDO, PlayerX + 1280, PlayerY - 720, 0);
	//al_draw_bitmap(FONDO, PlayerX - 1280, PlayerY + 720, 0);
}