#include "DibujarFondo.h"

Background::Background()
{
	font = al_load_font("assets/fonts/Minecraft.ttf", 20, 0);
	std::string rutaFondos, rutaIconos;
	int aux = 0;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			rutaFondos = "assets/fondos/Escenas/ESCENA0" + std::to_string(i) + tiempos[j] + ".png";
			ESCENAS[aux] = al_load_bitmap(rutaFondos.c_str());
			assert(ESCENAS[aux] != NULL);
			aux++;
		}
	}
	aux = 0;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			rutaFondos = "assets/fondos/Escenas/ESCENA0" + std::to_string(i) + tiempos[j] + "A.png";
			ESCENASA[aux] = al_load_bitmap(rutaFondos.c_str());
			assert(ESCENASA[aux] != NULL);
			aux++;
		}
	}
	rutaIconos = "assets/fondos/Objetos/OPCIONES0" + std::to_string(0) + ".png";
	OPCIONES[0] = al_load_bitmap(rutaIconos.c_str());
	rutaIconos = "assets/fondos/Objetos/OPCIONES0" + std::to_string(1) + ".png";
	OPCIONES[1] = al_load_bitmap(rutaIconos.c_str());
}
Background::~Background()
{
	for (int i = 0; i < 12; i++)
	{
		al_destroy_bitmap(ESCENAS[i]);
		al_destroy_bitmap(ESCENASA[i]);
	}
	al_destroy_bitmap(OPCIONES[0]);
	al_destroy_bitmap(OPCIONES[1]);
	al_destroy_font(font);
}
void Background::action(int escena, int TiempoDiaEscena)
{
	al_draw_bitmap(ESCENAS[escena + TiempoDiaEscena], 0, 0, 0);
	if (escena == 3) cultivosPlantados->action(escena);
}
void Background::drawOptions(int i, int Monedas, int escena)
{
	//PARA EL ZOOM que se vea la cantidad de monedas
	int xopciones = 18, yopciones = 10, xtextomoneda = 1030, ytextomoneda = 33;

	if (escena == 6 || escena == 9) {
		xopciones = -60;
		yopciones = 50;
		xtextomoneda = 952;
		ytextomoneda = 73;
	}

	al_draw_bitmap(OPCIONES[i], xopciones, yopciones, 0);
	al_draw_text(font, al_map_rgb(255, 255, 255), xtextomoneda, ytextomoneda, 0, (std::to_string(Monedas).c_str()));
}

void Background::dibujarEncima(int escena, int TiempoDiaEscena)
{
	if (escena < 6)
		al_draw_bitmap(ESCENASA[escena + TiempoDiaEscena], 0, 0, 0);
}