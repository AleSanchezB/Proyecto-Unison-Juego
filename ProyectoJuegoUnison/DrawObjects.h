#ifndef DRAW_H
#define DRAW_H
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <string>
#include <iostream>
#include <thread>

#include "GuardarDatos.h"
#include "TipoCultivos.h"

class Background
{
public:
	Background();
	~Background();
	void action(int escenal, int TiempoEscenaActual);
	void drawOptions(int i, int Monedas);
	void InicioDia();
	void CambioTiempoEscena(float T_Actual, int escena);
	std::string tiempos[4] = { "","TARDE","NOCHE" };
	float TiempoCreacion = 0;
	int TiempoEscenaActual = 0;
	void dibujarEncima(int escena);
	ALLEGRO_FONT* font;
private:
	ALLEGRO_BITMAP* ESCENAS[14];
	ALLEGRO_BITMAP* OPCIONES[3];
	ALLEGRO_BITMAP* ESCENASA[14];
	Cultivo* cultivosPlantados;
	int Monedas;
};
#endif // !1