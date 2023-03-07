#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <windows.h>
#include "DrawObjects.h"
#include "controlesCultivos.h"
#include <string>
#include <chrono>
#include "GuardarDatos.h"

using namespace std;

class Mapa1
{
public:
	Mapa1();
	~Mapa1();
	void setMonedas(int monedas);

private:
	//VARIABLES ALLEGRO
	ALLEGRO_BITMAP* player;
	ALLEGRO_BITMAP* ESCENA3;
	ALLEGRO_BITMAP* ESCENA1;
	ALLEGRO_BITMAP* ESCENA2;
	ALLEGRO_BITMAP* ESTATS[3];
	ALLEGRO_DISPLAY* displayGame;
	ALLEGRO_EVENT_QUEUE* queue;
	ALLEGRO_FONT* font;
	ALLEGRO_TIMER* _timer;
	DrawObjects drawPlayer;
	ControlarCultivos controlsCultivos;

	//CONSTANTES
	const int width = 1280;
	const int height = 720;

	//VARIABLES
	float speedPlayer = 2;
	int xJugador = 640;
	int yJugador = 400;
	int xCoordsFondos = 1280;
	bool running, active = false;
	int mouseX, mouseY;
	int direccion = 0, SpritePosX = 0, SpritePosY = 0, corriendo = 0;
	int PlayRefresh = 0;
	int Monedas;

	//funciones
	void init();
	void initRoom();
	void loadImg();
	void move(ALLEGRO_KEYBOARD_STATE keystate);
	void drawBackground(int i);
	int getMonedas();
	DatosJuego datosJuego;

	//DIRECCIONES
	enum { DOWNW, RIGHTW, UPW, LEFTW };
	//VARIABLES FPS
	int fps = 0;
	int frame_count = 0;
	double frame_time = 0;
};

Mapa1::Mapa1()
{
	ObtenerDatos();
	al_init();
	al_init_image_addon();
	al_install_keyboard();
	al_init_font_addon();
	al_init_ttf_addon();
	init();
	initRoom();
}
Mapa1::~Mapa1()
{
	
	al_destroy_bitmap(player);
	al_destroy_display(displayGame);
	al_destroy_timer(_timer);
	al_uninstall_keyboard();
	al_destroy_font(font);
}
void Mapa1::loadImg()
{
	font = al_load_font("assets/fonts/Minecraft.ttf", 20, 0);
	ESTATS[0] = al_load_bitmap("assets/fondos/Objetos/OPCIONES.png");
	ESTATS[1] = al_load_bitmap("assets/fondos/Objetos/CUANDO PRESIONA CONFI.png");
	ESCENA1 = al_load_bitmap("assets/fondos/EscenasInicio/ESCENA1.png");
	ESCENA2 = al_load_bitmap("assets/fondos/EscenasInicio/ESCENA2.png");
	player = al_load_bitmap("assets/IdleTam/Sprites Players/characters/Walk_run Player.png");
	assert(player != NULL);
	assert(ESCENA1 != NULL);
	assert(ESCENA2 != NULL);
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
		if (event.type == ALLEGRO_EVENT_MOUSE_AXES) {
			if (event.mouse.x >= 18 && event.mouse.x <= 73 && event.mouse.y >= 0 && event.mouse.y <= 53) drawBackground(1);
		}
		else drawBackground(0);
	}
}
void Mapa1::drawBackground(int i) {
	al_clear_to_color(al_map_rgb_f(254, 254, 254));
	al_draw_bitmap(ESCENA2, xCoordsFondos, 0, 0);
	al_draw_bitmap(ESCENA1, xCoordsFondos - 1280, 0, 0);
	al_draw_bitmap(ESTATS[i], 18, 10, 0);
	al_draw_text(font, al_map_rgb(255, 255, 255), 10, 10, ALLEGRO_ALIGN_LEFT, ("xjugador: " + to_string(xJugador)).c_str());
	al_draw_text(font, al_map_rgb(255, 255, 255), 10, 30, ALLEGRO_ALIGN_LEFT, ("yjugador: " + to_string(yJugador)).c_str());
	al_draw_text(font, al_map_rgb(255, 255, 255), 10, 50, ALLEGRO_ALIGN_LEFT, ("xFondo: " + to_string(xCoordsFondos)).c_str());
	al_draw_text(font, al_map_rgb(255, 255, 255), 1030, 33, 0, (to_string(datosJuego.dinero).c_str()));
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
			direccion = UPW + corriendo;
		}
		else if (al_key_down(&keystate, ALLEGRO_KEY_S)) {
			yJugador += speedPlayer;
			direccion = DOWNW + corriendo;
		}
		else if (al_key_down(&keystate, ALLEGRO_KEY_D)) {
			xJugador += speedPlayer;
			direccion = RIGHTW + corriendo;
		}
		else if (al_key_down(&keystate, ALLEGRO_KEY_A)) {
			xJugador -= speedPlayer;
			direccion = LEFTW + corriendo;
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

void Mapa1::setMonedas(int monedas)
{
	this->Monedas = monedas;
}

int Mapa1::getMonedas()
{
	return Monedas;
}