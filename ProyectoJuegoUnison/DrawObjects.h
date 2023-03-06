#pragma once
#include <allegro5/allegro_image.h>
#include <allegro5/allegro.h>

using namespace std;

class DrawObjects
{
public:
	DrawObjects();
	~DrawObjects();
	void draw(int xJugador, int yJugador);
	void initImg();

private:
	ALLEGRO_BITMAP* player;	
	
};

DrawObjects::DrawObjects()
{
	al_init();
	al_init_image_addon();
	player = al_load_bitmap("assets/IdleTam/frame01.png");
}

DrawObjects::~DrawObjects()
{
}
void DrawObjects::draw(int xJugador, int yJugador) {
	//al_clear_to_color(al_map_rgb_f(254, 254, 254));
	al_draw_bitmap(player, xJugador, yJugador, 0);
}
void DrawObjects::initImg() {
	al_init();
	al_init_image_addon();
	player = al_load_bitmap("assets/Sprites Players/NO SE USARA/PNG/IdleTam/frame01.png");
}
