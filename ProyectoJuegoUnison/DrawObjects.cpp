#include "DrawObjects.h"
#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <string>
#include "GuardarDatos.h"
#include "controlesCultivos.h"
#include "TipoCultivos.h"
#include"sonidos.h"

DrawObjects::DrawObjects()
{
}

DrawObjects::~DrawObjects()
{
	al_destroy_bitmap(player);
	for (int i = 0; i < 2; i++)
	{
		std::string rutaFondos = "assets/fondos/EscenasInicio/ESCENA" + std::to_string(i) + ".png";
		std::string rutaIconos = "assets/fondos/Objetos/OPCIONES" + std::to_string(i) + ".png";
		al_destroy_bitmap(ESCENAS[i]);
		std::cout << std::endl << rutaFondos << std::endl << rutaIconos << std::endl;
		assert(ESCENAS[i] != NULL);
	}
}

void DrawObjects::Animate(float SpritePosX, float SpritePosY, float movimientoX, float movimientoY, float xCoordsFondos, float yJug) {
	al_draw_bitmap_region(player, SpritePosX, SpritePosY, movimientoX, movimientoY, xCoordsFondos, yJug, NULL);
}
void DrawObjects::initImg() {
	al_init();
	al_init_image_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	al_install_audio();
	font = al_load_font("assets/fonts/Minecraft.ttf", 20, 0);
	player = al_load_bitmap("assets/IdleTam/Sprites Players/characters/Walk_run Player.png");
	std::string rutaFondos, rutaIconos;
	for (int i = 0; i < 2; i++)
	{
		rutaFondos = "assets/fondos/EscenasInicio/ESCENA0" + std::to_string(i) + ".png";
		rutaIconos = "assets/fondos/Objetos/OPCIONES0" + std::to_string(i) + ".png";
		ESCENAS[i] = al_load_bitmap(rutaFondos.c_str());
		OPCIONES[i] = al_load_bitmap(rutaIconos.c_str());
		std::cout << std::endl << rutaFondos << std::endl << rutaIconos << std::endl;
		assert(ESCENAS[i] != NULL);
		//assert(OPCIONES[i] != NULL);
	}
	datosUsuario.ObtenerDatos();
	Monedas = datosUsuario.getMonedas();
}
void DrawObjects::DrawBackgrounds()
{
	int moniotpixancho = 30;
	int monitopixalto = 20;
	xMask = (xJugador / moniotpixancho);
	if (xMask < 0) xMask = 0;
	if (xMask > dimxmask) xMask = dimxmask;
	yMask = (yJugador / monitopixalto) + 2;
	if (yMask < 0) yMask = 0;
	if (yMask > dimymask) yMask = dimymask;

	xMup = xMask;
	if (xMup < 0) xMup = 0;
	if (xMup > dimxmask) xMup = dimxmask;
	yMup = yMask - 1;
	if (yMup < 0) yMup = 0;
	if (yMup > dimymask) yMup = dimymask;

	xMdown = xMask;
	if (xMdown < 0) xMdown = 0;
	if (xMdown > dimxmask) xMdown = dimxmask;
	yMdown = yMask + 1;
	if (yMdown < 0) yMdown = 0;
	if (yMdown > dimymask) yMdown = dimymask;

	xMizq = xMask - 1;
	if (xMizq < 0) xMizq = 0;
	if (xMizq > dimxmask) xMizq = dimxmask;
	yMizq = yMask;
	if (yMizq < 0) yMizq = 0;
	if (yMizq > dimymask) yMizq = dimymask;

	xMder = (xJugador / moniotpixancho) + 1;
	if (xMder < 0) xMder = 0;
	if (xMder > dimxmask) xMder = dimxmask;
	yMder = yMask;
	if (yMder < 0) yMder = 0;
	if (yMder > dimymask) yMder = dimymask;

	al_clear_to_color(al_map_rgb_f(254, 254, 254));
	al_draw_bitmap(ESCENAS[escena], 0, 0, 0);


	al_draw_text(font, al_map_rgb(255, 255, 255), 10, 10, ALLEGRO_ALIGN_LEFT, ("xjugador: " + std::to_string(xJugador)).c_str());
	al_draw_text(font, al_map_rgb(255, 255, 255), 10, 30, ALLEGRO_ALIGN_LEFT, ("yjugador: " + std::to_string(yJugador)).c_str());

	al_draw_text(font, al_map_rgb(255, 255, 255), 10, 70, ALLEGRO_ALIGN_LEFT, ("xMask: " + std::to_string(xMask)).c_str());
	al_draw_text(font, al_map_rgb(255, 255, 255), 150, 70, ALLEGRO_ALIGN_LEFT, ("yMask: " + std::to_string(yMask)).c_str());
	al_draw_text(font, al_map_rgb(255, 255, 255), 300, 70, ALLEGRO_ALIGN_LEFT, ("Hay: " + std::to_string(maskmap[yMask][xMask])).c_str());

	al_draw_text(font, al_map_rgb(255, 255, 255), 10, 90, ALLEGRO_ALIGN_LEFT, ("xMup: " + std::to_string(xMup)).c_str());
	al_draw_text(font, al_map_rgb(255, 255, 255), 150, 90, ALLEGRO_ALIGN_LEFT, ("yMup: " + std::to_string(yMup)).c_str());
	al_draw_text(font, al_map_rgb(255, 255, 255), 300, 90, ALLEGRO_ALIGN_LEFT, ("Hay: " + std::to_string(maskmap[yMup][xMup])).c_str());

	al_draw_text(font, al_map_rgb(255, 255, 255), 10, 110, ALLEGRO_ALIGN_LEFT, ("xMdown: " + std::to_string(xMdown)).c_str());
	al_draw_text(font, al_map_rgb(255, 255, 255), 150, 110, ALLEGRO_ALIGN_LEFT, ("yMdown: " + std::to_string(yMdown)).c_str());
	al_draw_text(font, al_map_rgb(255, 255, 255), 300, 110, ALLEGRO_ALIGN_LEFT, ("Hay: " + std::to_string(maskmap[yMdown][xMdown])).c_str());

	al_draw_text(font, al_map_rgb(255, 255, 255), 10, 130, ALLEGRO_ALIGN_LEFT, ("xMizq: " + std::to_string(xMizq)).c_str());
	al_draw_text(font, al_map_rgb(255, 255, 255), 150, 130, ALLEGRO_ALIGN_LEFT, ("yMizq: " + std::to_string(yMizq)).c_str());
	al_draw_text(font, al_map_rgb(255, 255, 255), 300, 130, ALLEGRO_ALIGN_LEFT, ("Hay: " + std::to_string(maskmap[yMizq][xMizq])).c_str());

	al_draw_text(font, al_map_rgb(255, 255, 255), 10, 150, ALLEGRO_ALIGN_LEFT, ("xMder: " + std::to_string(xMder)).c_str());
	al_draw_text(font, al_map_rgb(255, 255, 255), 150, 150, ALLEGRO_ALIGN_LEFT, ("yMder: " + std::to_string(yMder)).c_str());
	al_draw_text(font, al_map_rgb(255, 255, 255), 300, 150, ALLEGRO_ALIGN_LEFT, ("Hay: " + std::to_string(maskmap[yMder][xMder])).c_str());

	//al_draw_bitmap(uno.imagen, uno.xPosition, uno.yPosition, 0);

}
void DrawObjects::drawOptions(int i, int Monedas)
{
	al_draw_bitmap(OPCIONES[i], 18, 10, 0);
	al_draw_text(font, al_map_rgb(255, 255, 255), 1030, 33, 0, (std::to_string(this->Monedas).c_str()));
	al_flip_display();
}
void DrawObjects::drawPlayerAnimation()
{
	Animate(SpritePosX, SpritePosY * 56, 40.0f, 56.0f, xJugador, yJugador);
}

void DrawObjects::move(ALLEGRO_KEYBOARD_STATE keystate, ALLEGRO_EVENT_QUEUE* queue)
{
	al_get_keyboard_state(&keystate);
	ALLEGRO_EVENT events;
	al_wait_for_event(queue, &events);

	if (al_key_down(&keystate, ALLEGRO_KEY_F))
	{
		controlesCultivos.plantarCultivo(keystate, queue);
	}
	else
	{
		// colision con el mapa de mascara

		//ACAAAAAAAAAAAAA LAURAAAAAAAAA
		active = true;
		//CHECAR SI ESTA CORRIENDO
		if (al_key_down(&keystate, ALLEGRO_KEY_LSHIFT)) {
			speedPlayer = 4;
			corriendo = 4;
		}
		else {
			speedPlayer = 2;
			corriendo = 0;
		}
		//MOVIMIENTOS DEL JUGADOR
		if (al_key_down(&keystate, ALLEGRO_KEY_W) && maskmap[yMup][xMup] != 'x') {
			yJugador -= speedPlayer;
			direccion = UPW + corriendo;
		}
		else if (al_key_down(&keystate, ALLEGRO_KEY_S) && maskmap[yMdown][xMdown] != 'x') {
			yJugador += speedPlayer;
			direccion = DOWNW + corriendo;	
		}
		else if (al_key_down(&keystate, ALLEGRO_KEY_D) && maskmap[yMder][xMder] != 'x') {
			xJugador += speedPlayer;
			direccion = RIGHTW + corriendo;
		}
		else if (al_key_down(&keystate, ALLEGRO_KEY_A) && maskmap[yMizq][xMizq] != 'x') {
			xJugador -= speedPlayer;
			direccion = LEFTW + corriendo;
		}
		else active = false;
		//ANIMACION DE MOVIMIENTOS 
		PlayRefresh++;
		if (PlayRefresh == 10) {
			if (SpritePosX >= 200) SpritePosX = 0;
			if (active) SpritePosX += 40;
			else SpritePosX = 0;
			SpritePosY = direccion;
			PlayRefresh = 0;
			
		}
		//cambio de mapa
		if (xJugador > 1280 && yJugador >= 260 && yJugador <= 330 && escena == 0)
		{
			xJugador = 2;
			escena = 1;
		}
		else if (xJugador < -38 && yJugador >= 246 && yJugador <= 332 && escena == 1)
		{
			xJugador = 1242;
			escena = 0;
		}
	}
}
