#pragma once
#include <allegro5/allegro_image.h>
#include <allegro5/allegro.h>
#include <string>

using namespace std;

class DrawObjects
{
public:
	DrawObjects();
	~DrawObjects();
	void Animate(float SpritePosX, float SpritePosY, float movimientoX, float movimientoY, float xCoordsFondos, float yJug);
	void initImg();
	void DrawBackgrounds(int i);
	void move(ALLEGRO_KEYBOARD_STATE keystate, ALLEGRO_EVENT_QUEUE* queue);
private:
	ALLEGRO_BITMAP* player;
	ALLEGRO_BITMAP* ESCENAS[3];
	ALLEGRO_BITMAP* ESTATS[3];
	ALLEGRO_FONT* font;
	enum { DOWNW, RIGHTW, UPW, LEFTW };
	float speedPlayer = 2;
	bool active = false;
	int direccion = 0, SpritePosX = 0, SpritePosY = 0, corriendo = 0;
	int PlayRefresh = 0;
	int xJugador = 640;
	int yJugador = 400;
	int xCoordsFondos = 1280;
};

DrawObjects::DrawObjects()
{
}

DrawObjects::~DrawObjects()
{
}

void DrawObjects::Animate(float SpritePosX, float SpritePosY, float movimientoX, float movimientoY, float xCoordsFondos, float yJug) {
	al_draw_bitmap_region(player, SpritePosX, SpritePosY, movimientoX, movimientoY, xCoordsFondos, yJug, NULL);
}
void DrawObjects::initImg() {
	al_init();
	al_init_image_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	font = al_load_font("assets/fonts/Minecraft.ttf", 20, 0);
	player = al_load_bitmap("assets/IdleTam/Sprites Players/characters/Walk_run Player.png");
	string rutaFondos, rutaIconos;
	for (int i = 1; i <= 2; i++)
	{
		rutaFondos = "assets/fondos/EscenasInicio/ESCENA" + to_string(i) + ".png";
		rutaIconos = "assets/fondos/Objetos/OPCIONES" + to_string(i) + ".png";
		ESCENAS[i] = al_load_bitmap(rutaFondos.c_str());
		ESTATS[i] = al_load_bitmap("assets/fondos/Objetos/OPCIONES.png");
	}
}
void DrawObjects::DrawBackgrounds(int i)
{
	al_clear_to_color(al_map_rgb_f(254, 254, 254));
	al_draw_bitmap(ESCENAS[2], xCoordsFondos, 0, 0);
	al_draw_bitmap(ESCENAS[1], xCoordsFondos - 1280, 0, 0);
	al_draw_bitmap(ESTATS[i], 18, 10, 0);
	//al_draw_text(font, al_map_rgb(255, 255, 255), 10, 10, ALLEGRO_ALIGN_LEFT, ("xjugador: " + to_string(xJugador)).c_str());
	//al_draw_text(font, al_map_rgb(255, 255, 255), 10, 30, ALLEGRO_ALIGN_LEFT, ("yjugador: " + to_string(yJugador)).c_str());
	//al_draw_text(font, al_map_rgb(255, 255, 255), 10, 50, ALLEGRO_ALIGN_LEFT, ("xFondo: " + to_string(xCoordsFondos)).c_str());
	//al_draw_text(font, al_map_rgb(255, 255, 255), 1030, 33, 0, (to_string(datosJuego.dinero).c_str()));
	Animate(SpritePosX, SpritePosY * 50, 33.0f, 51.0f, xJugador, yJugador);
	al_flip_display();
}

void DrawObjects::move(ALLEGRO_KEYBOARD_STATE keystate, ALLEGRO_EVENT_QUEUE* queue)
{
	al_get_keyboard_state(&keystate);
	ALLEGRO_EVENT events;
	al_wait_for_event(queue, &events);

	if (al_key_down(&keystate, ALLEGRO_KEY_F))
	{
		//obtengo las coords del puntero del mouse
		//controlsCultivos.plantarCultivo(keystate, queue);
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