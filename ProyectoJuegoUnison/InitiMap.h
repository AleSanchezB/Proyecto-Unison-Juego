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
	ControlarCultivos controlsCultivos;

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

Mapa1::Mapa1()
{
	al_init();
	al_init_image_addon();
	al_install_mouse();
	al_install_keyboard();
	al_init_font_addon();
	al_init_ttf_addon();
	init();
	initRoom();
}
Mapa1::~Mapa1()
{
	al_destroy_display(displayGame);
	al_destroy_timer(_timer);
	al_uninstall_keyboard();
}

//inicializa y define las variables;
void Mapa1::init()
{
	running = true;
	al_set_new_display_flags(ALLEGRO_RESIZABLE);

	displayGame = al_create_display(width, height);
	al_set_window_title(displayGame, "Juego version Beta");

	//cola de eventos
	queue = al_create_event_queue();

	//Timer e incio del timer
	_timer = al_create_timer(1.0 / 120);
	al_start_timer(_timer);

	//Registro de eventos
	al_register_event_source(queue, al_get_display_event_source(displayGame));
	al_register_event_source(queue, al_get_keyboard_event_source());
	al_register_event_source(queue, al_get_timer_event_source(_timer));
	al_register_event_source(queue, al_get_mouse_event_source());

}
void Mapa1::initRoom()
{
	drawPlayer.initImg();
	while (running)
	{
		al_wait_for_event(queue, &event);
		ALLEGRO_KEYBOARD_STATE keystate;
		al_get_keyboard_state(&keystate);

		if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			running = false;
		}
		if (event.type == ALLEGRO_EVENT_TIMER)
		{
			drawPlayer.move(keystate, queue);
		}
		drawPlayer.DrawBackgrounds();

		if (event.type == ALLEGRO_EVENT_MOUSE_AXES) {
			if (event.mouse.x >= 18 && event.mouse.x <= 73 && event.mouse.y >= 0 && event.mouse.y <= 53) i = 1;
			else i = 0;
		}
		drawPlayer.drawPlayerAnimation();
		drawPlayer.drawOptions(i, Monedas);
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

void Mapa1::DibujarGradualmente()
{
	al_clear_to_color(al_map_rgb(0, 0, 0));
	//al_draw_tinted_bitmap(ESCENA1, al_map_rgba_f(1.0, 1.0, 1.0, alpha), 0, 0, 0);
	al_draw_rectangle(0, 0, 1280, 720, al_map_rgba_f(0, 0, 0, 0), NULL);
	//al_draw_tinted_bitmap(ESCENA2, al_map_rgba_f(1.0, 1.0, 1.0, 1.0 - alpha), 0, 0, 0);

	// Cambiar gradualmente el nivel de opacidad de las imágenes
	alpha -= 0.01;
	if (alpha <= 0) {
		alpha = 1.0;
		//ALLEGRO_BITMAP* temp = ESCENA1;
		//ESCENA1 = ESCENA2;
		//ESCENA2 = temp;
	}

	// Actualizar la pantalla
	al_flip_display();
}