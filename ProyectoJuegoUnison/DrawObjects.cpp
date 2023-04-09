#include "DrawObjects.h"

DrawObjects::DrawObjects()
{
	font = al_load_font("assets/fonts/Minecraft.ttf", 20, 0);
	std::string rutaFondos, rutaIconos;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++) {
			rutaFondos = "assets/fondos/EscenasInicio/ESCENA0" + std::to_string(i) + tiempos[j] + ".png";
			//rutaIconos = "assets/fondos/Objetos/OPCIONES0" + std::to_string(i) + ".png";
			ESCENAS[i] = al_load_bitmap(rutaFondos.c_str());
			//OPCIONES[i] = al_load_bitmap(rutaIconos.c_str());
			//std::cout << std::endl << rutaFondos << std::endl << rutaIconos << std::endl;
			assert(ESCENAS[i] != NULL);
			//assert(OPCIONES[i] != NULL);
		}
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
void DrawObjects::DrawBackgrounds(int escena,int TiempoEscenaActual)
{
	al_draw_bitmap(ESCENAS[escena+TiempoEscenaActual], 0, 0, 0);
	if(escena == 1)
		cultivosCargados->action();

}
void DrawObjects::drawOptions(int i, int Monedas)
{
	al_draw_bitmap(OPCIONES[i], 18, 10, 0);
	al_draw_text(font, al_map_rgb(255, 255, 255), 1030, 33, 0, (std::to_string(this->Monedas).c_str()));
}
/***********************FUNCIONES NUEVAS, LAS QUE PROBABLEMENTE TENGAS QUE COMENTAR*****************************************/
void DrawObjects::InicioDia() {
	TiempoCreacion = al_current_time();
	std::cout << "Objetivos del d�a\n";
	TiempoEscenaActual = 0;
	//GENERAR TAMBIEN OBJETIVOS DEL DIA(tengo que averiguar c�mo :c)
}

void DrawObjects::CambioTiempoEscena(float T_Actual,int escena) {
	TiempoEscenaActual = 0;
	int resta = (int)(T_Actual - TiempoCreacion) % 60;
	if (resta == 0) {
		TiempoEscenaActual++;
		DrawBackgrounds(escena,TiempoEscenaActual);
	}
/****************************************************************************************************************************/