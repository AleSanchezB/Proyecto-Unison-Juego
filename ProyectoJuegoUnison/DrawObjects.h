#include <allegro5/allegro_image.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <string>
#include "GuardarDatos.h"

using namespace std;

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
	int PlayRefresh = 0;
	float xJugador = 40;
	float yJugador = 40;
	float xCoordsFondos = 1280;
	int Monedas;

	//DIMESION DE LA MATRIZ MASCARA
	const int dimxmask = 50;
	const int dimymask = 50;
	//MATRIZ DEL MAPA MASCARA
	char maskmap[50][50] = {
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx",
			"x                                         x",
			"x                                         x",
			"x                                         x",
			"x                                         x",
			"x                                         x",
			"x                                         x",
			"x                                         x",
			"x                                         x",
			"x                                         x",
			"x                                         x",
			"x                                         x",
			"x                                         x",
			"x                                         x",
			"x                                         x",
			"x                                         x",
			"x                                         x",
			"x                                         x",
			"x                                         x",
			"x                                         x",
			"x                                         x",
			"x                                         x",
			"x                                         x",
			"x                                         x",
			"x                                         x",
			"x                                         x",
			"x                                         x",
			"x                                         x",
			"x                                         x",
			"x                                         x",
			"x                                         x",
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx",
	};

	int xMask, yMask, xMup, yMup, xMdown, yMdown, xMizq, yMizq, xMder, yMder;
	int escena = 0;
};

DrawObjects::DrawObjects()
{
}

DrawObjects::~DrawObjects()
{
	al_destroy_bitmap(player);
	for (int i = 0; i < 2; i++)
	{
		string rutaFondos = "assets/fondos/EscenasInicio/ESCENA" + to_string(i) + ".png";
		string rutaIconos = "assets/fondos/Objetos/OPCIONES" + to_string(i) + ".png";
		al_destroy_bitmap(ESCENAS[i]);
		//OPCIONES[i] = al_load_bitmap(rutaIconos.c_str());
		cout << endl << rutaFondos << endl << rutaIconos << endl;
		assert(ESCENAS[i] != NULL);
		//assert(OPCIONES[i] != NULL);
	}
}

void DrawObjects::Animate(float SpritePosX, float SpritePosY, float movimientoX, float movimientoY, float xCoordsFondos, float yJug) {
	al_draw_bitmap_region(player, SpritePosX, SpritePosY, movimientoX, movimientoY, xCoordsFondos, yJug, NULL);
}
void DrawObjects::initImg() {
	al_init();
	al_init_image_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	font = al_load_font("assets/fonts/Minecraft.ttf", 20, 0);
	player = al_load_bitmap("assets/IdleTam/Sprites Players/characters/Walk_run Player.png");
	string rutaFondos, rutaIconos;
	for (int i = 0; i < 2; i++)
	{
		rutaFondos = "assets/fondos/EscenasInicio/ESCENA0" + to_string(i) + ".png";
		rutaIconos = "assets/fondos/Objetos/OPCIONES0" + to_string(i) + ".png";
		ESCENAS[i] = al_load_bitmap(rutaFondos.c_str());
		OPCIONES[i] = al_load_bitmap(rutaIconos.c_str());
		cout << endl << rutaFondos << endl << rutaIconos << endl;
		assert(ESCENAS[i] != NULL);
		//assert(OPCIONES[i] != NULL);
	}
	datosUsuario.ObtenerDatos();
	Monedas = datosUsuario.getMonedas();
}
void DrawObjects::DrawBackgrounds()
{
	int moniotpixancho = 30;
	int monitopixalto = 20;
	xMask = (xJugador / moniotpixancho);
	if (xMask < 0) xMask = 0;
	if (xMask > dimxmask) xMask = dimxmask;
	yMask = (yJugador / monitopixalto) + 2;
	if (yMask < 0) yMask = 0;
	if (yMask > dimymask) yMask = dimymask;

	xMup = xMask;
	if (xMup < 0) xMup = 0;
	if (xMup > dimxmask) xMup = dimxmask;
	yMup = yMask - 1;
	if (yMup < 0) yMup = 0;
	if (yMup > dimymask) yMup = dimymask;

	xMdown = xMask;
	if (xMdown < 0) xMdown = 0;
	if (xMdown > dimxmask) xMdown = dimxmask;
	yMdown = yMask + 1;
	if (yMdown < 0) yMdown = 0;
	if (yMdown > dimymask) yMdown = dimymask;

	xMizq = xMask - 1;
	if (xMizq < 0) xMizq = 0;
	if (xMizq > dimxmask) xMizq = dimxmask;
	yMizq = yMask;
	if (yMizq < 0) yMizq = 0;
	if (yMizq > dimymask) yMizq = dimymask;

	xMder = (xJugador / moniotpixancho) + 1;
	if (xMder < 0) xMder = 0;
	if (xMder > dimxmask) xMder = dimxmask;
	yMder = yMask;
	if (yMder < 0) yMder = 0;
	if (yMder > dimymask) yMder = dimymask;

	al_draw_bitmap(ESCENAS[1], xCoordsFondos, 0, 0);
	al_draw_bitmap(ESCENAS[0], xCoordsFondos - 1280, 0, 0);
	al_draw_text(font, al_map_rgb(255, 255, 255), 10, 10, ALLEGRO_ALIGN_LEFT, ("xjugador: " + to_string(xJugador)).c_str());
	al_draw_text(font, al_map_rgb(255, 255, 255), 10, 30, ALLEGRO_ALIGN_LEFT, ("yjugador: " + to_string(yJugador)).c_str());

	al_draw_text(font, al_map_rgb(255, 255, 255), 10, 70, ALLEGRO_ALIGN_LEFT, ("xMask: " + to_string(xMask)).c_str());
	al_draw_text(font, al_map_rgb(255, 255, 255), 150, 70, ALLEGRO_ALIGN_LEFT, ("yMask: " + to_string(yMask)).c_str());
	al_draw_text(font, al_map_rgb(255, 255, 255), 300, 70, ALLEGRO_ALIGN_LEFT, ("Hay: " + to_string(maskmap[yMask][xMask])).c_str());

	al_draw_text(font, al_map_rgb(255, 255, 255), 10, 90, ALLEGRO_ALIGN_LEFT, ("xMup: " + to_string(xMup)).c_str());
	al_draw_text(font, al_map_rgb(255, 255, 255), 150, 90, ALLEGRO_ALIGN_LEFT, ("yMup: " + to_string(yMup)).c_str());
	al_draw_text(font, al_map_rgb(255, 255, 255), 300, 90, ALLEGRO_ALIGN_LEFT, ("Hay: " + to_string(maskmap[yMup][xMup])).c_str());

	al_draw_text(font, al_map_rgb(255, 255, 255), 10, 110, ALLEGRO_ALIGN_LEFT, ("xMdown: " + to_string(xMdown)).c_str());
	al_draw_text(font, al_map_rgb(255, 255, 255), 150, 110, ALLEGRO_ALIGN_LEFT, ("yMdown: " + to_string(yMdown)).c_str());
	al_draw_text(font, al_map_rgb(255, 255, 255), 300, 110, ALLEGRO_ALIGN_LEFT, ("Hay: " + to_string(maskmap[yMdown][xMdown])).c_str());

	al_draw_text(font, al_map_rgb(255, 255, 255), 10, 130, ALLEGRO_ALIGN_LEFT, ("xMizq: " + to_string(xMizq)).c_str());
	al_draw_text(font, al_map_rgb(255, 255, 255), 150, 130, ALLEGRO_ALIGN_LEFT, ("yMizq: " + to_string(yMizq)).c_str());
	al_draw_text(font, al_map_rgb(255, 255, 255), 300, 130, ALLEGRO_ALIGN_LEFT, ("Hay: " + to_string(maskmap[yMizq][xMizq])).c_str());

	al_draw_text(font, al_map_rgb(255, 255, 255), 10, 150, ALLEGRO_ALIGN_LEFT, ("xMder: " + to_string(xMder)).c_str());
	al_draw_text(font, al_map_rgb(255, 255, 255), 150, 150, ALLEGRO_ALIGN_LEFT, ("yMder: " + to_string(yMder)).c_str());
	al_draw_text(font, al_map_rgb(255, 255, 255), 300, 150, ALLEGRO_ALIGN_LEFT, ("Hay: " + to_string(maskmap[yMder][xMder])).c_str());

	al_clear_to_color(al_map_rgb_f(254, 254, 254));
	al_draw_bitmap(ESCENAS[escena], 0, 0, 0);

}
void DrawObjects::drawOptions(int i, int Monedas)
{
	al_draw_bitmap(OPCIONES[i], 18, 10, 0);
	al_draw_text(font, al_map_rgb(255, 255, 255), 1030, 33, 0, (to_string(this->Monedas).c_str()));
	al_flip_display();
}
void DrawObjects::drawPlayerAnimation()
{
	Animate(SpritePosX, SpritePosY * 50, 33.0f, 51.0f, xJugador, yJugador);
}

void DrawObjects::move(ALLEGRO_KEYBOARD_STATE keystate, ALLEGRO_EVENT_QUEUE* queue)
{
	al_get_keyboard_state(&keystate);
	ALLEGRO_EVENT events;
	al_wait_for_event(queue, &events);

	if (al_key_down(&keystate, ALLEGRO_KEY_F))
	{
		//obtengo las coords del puntero del mouse
		//controlsCultivos.plantarCultivo(keystate, queue);
	}
	else
	{
		// colision con el mapa de mascara

		//ACAAAAAAAAAAAAA LAURAAAAAAAAA
		active = true;
		if (al_key_down(&keystate, ALLEGRO_KEY_LSHIFT)) {
			speedPlayer = 4;
			corriendo = 4;
		}
		else {
			speedPlayer = 2;
			corriendo = 0;
		}
		if (al_key_down(&keystate, ALLEGRO_KEY_W) && maskmap[yMup][xMup] != 'x') {
			yJugador -= speedPlayer;
			direccion = UPW + corriendo;
		}
		else if (al_key_down(&keystate, ALLEGRO_KEY_S) && maskmap[yMdown][xMdown] != 'x') {
			yJugador += speedPlayer;
			direccion = DOWNW + corriendo;
		}
		else if (al_key_down(&keystate, ALLEGRO_KEY_D) && maskmap[yMder][xMder] != 'x') {
			xJugador += speedPlayer;
			direccion = RIGHTW + corriendo;
		}
		else if (al_key_down(&keystate, ALLEGRO_KEY_A) && maskmap[yMizq][xMizq] != 'x') {
			xJugador -= speedPlayer;
			direccion = LEFTW + corriendo;
		}
		else active = false;
		PlayRefresh++;
		if (PlayRefresh == 6) {
			if (SpritePosX >= 165) SpritePosX = 0;
			if (active) SpritePosX += 33;
			else SpritePosX = 0;
			SpritePosY = direccion;
			PlayRefresh = 0;
		}

		if (xJugador > 1280 && yJugador >= 260 && yJugador <= 330 && escena == 0) {
			xJugador = 2;
			yJugador = 298;
			escena = 1;
		}
		else if (xJugador < -38 && yJugador >= 246 && yJugador <= 332 && escena == 1)
		{
			xJugador = 1242;
			yJugador = 300;
			escena = 0;
		}

		cout << "x: " << xJugador << endl << "y: " << yJugador << endl;
	}
}
