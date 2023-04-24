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
		btnSonido[i] = al_load_bitmap(("assets/fondos/Objetos/" + std::to_string(i) + ".png").c_str());
		btnSonido[i + 2] = al_load_bitmap(("assets/fondos/Objetos/" + std::to_string(i + 2) + ".png").c_str());
		for (int j = 0; j < 3; j++)
		{
			rutaFondos = "assets/fondos/Escenas/ESCENA0" + std::to_string(i) + tiempos[j] + "A.png";
			ESCENASA[aux] = al_load_bitmap(rutaFondos.c_str());
			assert(ESCENASA[aux] != NULL);
			aux++;
		}
	}
	OPCIONES = al_load_bitmap(("assets/fondos/Objetos/OPCIONES01.png"));
}
Background::~Background()
{
	for (int i = 0; i < 12; i++)
	{
		al_destroy_bitmap(ESCENAS[i]);
		al_destroy_bitmap(ESCENASA[i]);
	}
	for (int i = 0; i < 4; i++)
	{
		al_destroy_bitmap(btnSonido[i]);
	}
	al_destroy_bitmap(OPCIONES);
	al_destroy_font(font);
}
void Background::action(int escena, int TiempoDiaEscena)
{
	al_draw_bitmap(ESCENAS[escena + TiempoDiaEscena], 0, 0, 0);
	cultivosPlantados->action(escena);
}
void Background::drawOptions(int sonido, int Monedas, int escena)
{
	//PARA EL ZOOM que se vea la cantidad de monedas
	int xopciones = 18, yopciones = 10, xtextomoneda = 1030, ytextomoneda = 33, xAjustes = 18, yAjustes = 10;

	if (escena == 6) {
		xopciones = -60;
		yopciones = 50;
		xtextomoneda = 952;
		ytextomoneda = 73;
		xAjustes = 190;
		yAjustes = 50;
	}

	al_draw_bitmap(OPCIONES, xopciones, yopciones, 0);
	al_draw_bitmap(btnSonido[sonido], xAjustes, yAjustes, 0);
	al_draw_text(font, al_map_rgb(255, 255, 255), xtextomoneda, ytextomoneda, 0, (std::to_string(Monedas).c_str()));
}

void Background::dibujarEncima(int escena, int TiempoDiaEscena)
{
	if (escena < 6)
		al_draw_bitmap(ESCENASA[escena + TiempoDiaEscena], 0, 0, 0);
}