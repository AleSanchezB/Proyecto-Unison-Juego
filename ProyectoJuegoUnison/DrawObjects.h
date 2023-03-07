#pragma once
#include <allegro5/allegro_image.h>
#include <allegro5/allegro.h>

using namespace std;

class DrawObjects
{
public:
	DrawObjects();
	~DrawObjects();
	void Animate(float SpritePosX, float SpritePosY, float movimientoX, float movimientoY, float xCoordsFondos, float yJug);
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
void DrawObjects::Animate(float SpritePosX, float SpritePosY, float movimientoX, float movimientoY, float xCoordsFondos, float yJug) {
	//al_clear_to_color(al_map_rgb_f(254, 254, 254));
	al_draw_bitmap_region(player, SpritePosX, SpritePosY, movimientoX, movimientoY, xCoordsFondos, yJug, NULL);
}
void DrawObjects::initImg() {
	al_init();
	al_init_image_addon();
	player = al_load_bitmap("assets/IdleTam/Sprites Players/characters/Walk_run Player.png");
}