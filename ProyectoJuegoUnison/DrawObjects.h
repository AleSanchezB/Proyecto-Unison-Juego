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

class Background
{
public:
	Background();
	~Background();
	void action(int escena);
	void drawOptions(int i, int Monedas);
	void dibujarEncima(int escena);
private:
	ALLEGRO_BITMAP* ESCENAS[5];
	ALLEGRO_BITMAP* OPCIONES[3];
	ALLEGRO_BITMAP* ESCENASA[2];
	ALLEGRO_FONT* font;
	Cultivo* cultivosPlantados;
	int Monedas;
};
#endif // !1