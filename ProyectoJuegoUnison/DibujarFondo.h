#ifndef DRAW_H
#define DRAW_H
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <string>
#include "TipoCultivos.h"
#include "Boton.h"
class Background
{
public:
	Background();
	~Background();
	ALLEGRO_FONT* font;
	
	std::string tiempos[4] = { "","TARDE","NOCHE" };
	
	float TiempoCreacion = 0;
	int TiempoEscenaActual = 0;
	
	void action(int escenal, int TiempoEscenaActual);
	void drawOptions(int sonido = 0, int Monedas = 0, int escenam = 0);
	void dibujarEncima(int escena, int TiempoDiaEscena);
private:
	ALLEGRO_BITMAP* ESCENAS[14];
	ALLEGRO_BITMAP* OPCIONES;
	ALLEGRO_BITMAP* btnSonido[4];
	ALLEGRO_BITMAP* ESCENASA[14];
	
	Cultivo* cultivosPlantados = NULL;
};
#endif // !1