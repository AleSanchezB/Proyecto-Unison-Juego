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
	void DrawBackgrounds(int escenal, int TiempoEscenaActual);
	void drawOptions(int i, int Monedas);
	void InicioDia();
	void CambioTiempoEscena(float T_Actual,int escena);
	std::string tiempos[4] = { "","TARDE","NOCHE" };
	float TiempoCreacion=0;
	int TiempoEscenaActual = 0;
private:
	ALLEGRO_BITMAP* ESCENAS[14];
	ALLEGRO_BITMAP* OPCIONES[3];
	ALLEGRO_FONT* font;
	DatosUsuario datosUsuario;

	float xCoordsFondos = 1280;
	int Monedas;
	Cultivo* cultivosCargados;
};
#endif // !1