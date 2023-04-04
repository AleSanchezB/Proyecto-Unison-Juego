#ifndef DRAW_H
#define DRAW_H
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <string>
#include "GuardarDatos.h"
#include "controlesCultivos.h"
#include "TipoCultivos.h"
#include <allegro5/allegro_audio.h>

class DrawObjects
{
public:
	DrawObjects();
	~DrawObjects();
	void Animate(float SpritePosX, float SpritePosY, float movimientoX, float movimientoY, float xCoordsFondos, float yJug);
	void initImg();
	void DrawBackgrounds();
	void move(ALLEGRO_KEYBOARD_STATE keystate, ALLEGRO_EVENT_QUEUE* queue);
	void drawOptions(int i, int Monedas);
	void drawPlayerAnimation();
private:
	ALLEGRO_BITMAP* player;
	ALLEGRO_BITMAP* ESCENAS[5];
	ALLEGRO_BITMAP* OPCIONES[3];
	ALLEGRO_FONT* font;
	DatosUsuario datosUsuario;
	enum { DOWNW, RIGHTW, UPW, LEFTW };
	float speedPlayer = 2;
	bool active = false;
	float direccion = 0, SpritePosX = 0, SpritePosY = 0, corriendo = 0;
	int PlayRefresh = 0,AudRepeat=0;
	float xJugador = 640;
	float yJugador = 400;
	float xCoordsFondos = 1280;
	int Monedas;

	//DIMESION DE LA MATRIZ MASCARA
	const int dimxmask = 50;
	const int dimymask = 50;
	//MATRIZ DEL MAPA MASCARA
	char maskmap[50][50] = {
		//            10        20        30        40 
		//   1234567890123456789012345678901234567890123
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx", //1
			"           x                              x", //2
			"           x                              x", //3
			"           x                              x", //4
			"           x                              x", //5
			"           x                              x", //6
			"           x                              x", //7
			"           x                              x", //8
			"           x                              x", //9
			"           x                              x", //10
			"           x                              x", //11
			"           x                              x", //12
			"           x                              x", //13
			"           x                              x", //14
			"           x                              x", //15
			"           x                               ", //16
			"         xxx                               ", //17
			"         x                                 ", //18
			"         x                                 ", //19
			"         x                                 ", //20
			"xxxxxxxxxx      x                         x", //21
			"x                   xx                    x", //22
			"x                                         x", //23
			"x                                         x", //24
			"x                                         x", //25
			"x                                         x", //26
			"x                                         x", //27
			"x                                         x", //28
			"x                                         x", //29
			"x                                         x", //30
			"x                                         x", //31
			"x                                         x", //32
			"x                                         x", //33
			"x                                         x", //34
			"x                                         x", //35
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx", //36
	};

	int escena = 0;
	int xMask, yMask, xMup, yMup, xMdown, yMdown, xMizq, yMizq, xMder, yMder;

	ControlarCultivos controlesCultivos;
};
#endif // !1