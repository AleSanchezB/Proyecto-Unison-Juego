#ifndef DRAW_H
#define DRAW_H
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <string>
#include <iostream>
#include "GuardarDatos.h"
#include "TipoCultivos.h"

class DrawObjects
{
public:
	DrawObjects();
	~DrawObjects();
	void action();
	void DrawBackgrounds(int escena);
	void drawOptions(int i, int Monedas);
private:
	ALLEGRO_BITMAP* ESCENAS[5];
	ALLEGRO_BITMAP* OPCIONES[3];
	ALLEGRO_FONT* font;
	DatosUsuario datosUsuario;

	float xCoordsFondos = 1280;
	int Monedas;
	Cultivo* cultivosCargados;
};
#endif // !1