#include "DrawObjects.h"

DrawObjects::DrawObjects()
{
	font = al_load_font("assets/fonts/Minecraft.ttf", 20, 0);
	std::string rutaFondos, rutaIconos;
	for (int i = 0; i < 4; i++)
	{
		rutaFondos = "assets/fondos/EscenasInicio/ESCENA0" + std::to_string(i) + ".png";
		ESCENAS[i] = al_load_bitmap(rutaFondos.c_str());
		//std::cout << std::endl << rutaFondos << std::endl << rutaIconos << std::endl;
		assert(ESCENAS[i] != NULL);
	}
	datosUsuario.ObtenerDatos();
	Monedas = datosUsuario.getMonedas();
	rutaIconos = "assets/fondos/Objetos/OPCIONES0" + std::to_string(0) + ".png";
	OPCIONES[0] = al_load_bitmap(rutaIconos.c_str());
	rutaIconos = "assets/fondos/Objetos/OPCIONES0" + std::to_string(1) + ".png";
	OPCIONES[1] = al_load_bitmap(rutaIconos.c_str());
}
DrawObjects::~DrawObjects()
{
	for (int i = 0; i < 2; i++)
	{
		std::string rutaFondos = "assets/fondos/EscenasInicio/ESCENA" + std::to_string(i) + ".png";
		std::string rutaIconos = "assets/fondos/Objetos/OPCIONES" + std::to_string(i) + ".png";
		al_destroy_bitmap(ESCENAS[i]);
		std::cout << std::endl << rutaFondos << std::endl << rutaIconos << std::endl;
	}
}
void DrawObjects::DrawBackgrounds(int escena)
{
	al_draw_bitmap(ESCENAS[escena], 0, 0, 0);
	if (escena == 1)	cultivosCargados->action(escena);
}
void DrawObjects::drawOptions(int i, int Monedas)
{
	al_draw_bitmap(OPCIONES[i], 18, 10, 0);
	al_draw_text(font, al_map_rgb(255, 255, 255), 1030, 33, 0, (std::to_string(this->Monedas).c_str()));
}
