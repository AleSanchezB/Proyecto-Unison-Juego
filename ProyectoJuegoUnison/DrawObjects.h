#ifndef DRAW_H
#define DRAW_H
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <string>
#include "GuardarDatos.h"
#include "controlesCultivos.h"
#include "TipoCultivos.h"

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
	void printMessage();
	bool MapaV2 = false;
	bool MapaCasa = false;
	int nummapa = 0;

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
	float xJugador = 624;
	float yJugador = 310;
	float xCoordsFondos = 1280;
	int Monedas;
	

	//DIMESION DE LA MATRIZ MASCARA
	const int dimxmask = 150;
	const int dimymask = 150;
	//MATRIZ DEL MAPA MASCARA
	char maskmap[150][150] = {
		// 
		// 
		// 
		// 
		// 
		//             10        20        30        40        50        60        70       80        90       100        110      120
		//   012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx", //1
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                                                    x      x         x   x", //2
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                                                    x      x         x   x", //3
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                                                    x      x         x   x", //4
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                                                    x      x         x   x", //5
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx   xxxxxxxxxxxx                                                   x      xxxxxxxxxxx   x", //6
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx   xxxxxxxxxxxx                                                   x         x      x   x", //7
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx   xxxxx                                                          x         x      x   x", //8
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                                  xxxxxxxxxxxxxxxxx               x x       x      x   x", //9
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                                  xx              x               x x       x      x   x", //10
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                                  xx              x               x x       x      x   x", //11
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                                  xx              x               x x       x      xxx x", //12
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                                  xx              x               x x       x      xxx x", //13
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                                  xx              x               x  	   x      xxxxx", //14
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                                  xx              x               x         x          x", //15
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                                  xx              x               x         x  xx      x", //16
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                                  xx              x              xxxxxx     x  xx      x", //17
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                                  xx              x              xxxxxx     x  xx      x", //18
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                                  xxxxxxxxx       x             xxxxxxx     x          x", //19
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                                  xxccccxxx       x             xxxxxxx     x          x", //20
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                               xxxxxccccxxx       x             xxxxxxxxxxxxx          x", //21
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                               xxxxxccccxxxxxxxxxxx                      xxxx          x", //22
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                               xxxx                                      xxxxxxxxx     x", //23
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                               xxxx                                      xxxxxxxxx     x", //24
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                                 x                                        xxxxxxxx     x", //25
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                                                                             xxxxx     x", //26
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                                                                xxxxx                  x", //27
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                                                                  x                    o", //28
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                                                                                       o", //29
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                                                        x                             o", //30
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                                                            x                             o", //31
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                                                               x                    xxx      o", //32
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                                                                x                             o", //33
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                                                                x                             o", //34
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx           xxxx                                                                               o", //35
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx           xxxx                                                                               o", //36
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx           xxxx                                                                               x", //37
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                                                                                     xxxx     x", //38
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                                                                                     xxxx     x", //39
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                             xxxxxxxx                                                xxxx     x", //40
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                             xxxxxxxx                                                xxxx     x", //41
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                                                                                     xxxx     x", //42
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                                                                                     xxxx     x", //43
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx     xxxx                                                                            xxxx     x", //44
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx      xx                                                                             xxxx     x", //45
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx      xx                                                                             xxxx     x", //46
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx      xx                                                                             xxxxxxxxxx", //47
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx      xx                                                                                 xx   x", //48
			"xxxxxxxxxxxxxxxxxxxxxxxx             xx                                                                                 xx   x", //49
			"xxxxxxxxxxxxxxxxxxxxxxxx             xx                                                                                 xx   x", //50
			"xxxxxxxxxxxxxxxxxxxxxxxx   x         xx                                                                                 xx   x", //52
			"xxxxxxxxxxxxxxxxxxxxxxxx   x         xx                                                                                 xx   x", //51
			"xxxxxxxxxxxxxxxxxxxxxxxx   x                                                                   xx             x         xx   x", //53
			"xxxxxxxxxxxxxxxxxxxxxxxx   x                                                                  xxxx            x         xx   x", //54
			"xxxxxxxxxxxxxxxxxxxxxxxx   x                                                                   xx            xx         xx   x", //55
			"xxxxxxxxxxxxxxxxxxxxxxxx   x               x                                                   xx            xx              x", //56
			"xxxxxxxxxxxxxxxxxxxxxxxx                  xx                             xxxx                  xx            xx              x", //57
			"xxxxxxxxxxxxxxxxxxxxxxxx                  xx                              xx                   xx                            x", //58
			"xxxxxxxxxxxxxxxxxxxxxxxx       xxxx       xx      xxxx                    xx                   xx                            x", //59
			"xxxxxxxxxxxxxxxxxxxxxxxx        xx        xx       xx                     xx                   xx                            x", //60
			"xxxxxxxxxxxxxxxxxxxxxxxx        xx                 xx                     xx          x        xx                            x", //61
			"xxxxxxxxxxxxxxxxxxxxxxxx        xx                 xx                     xx         xx        xx                            x", //62
			"xxxxxxxxxxxxxxxxxxxxxxxx        xx                 xx                     xx         xx                                      x", //63
			"xxxxxxxxxxxxxxxxxxxxxxxx        xx                 xx                     xx         xx                            xx        x", //64
			"xxxxxxxxxxxxxxxxxxxxxxxx        xx                 xx            x        xx         xx                            xx        x", //65
			"xxxxxxxxxxxxxxxxxxxxxxxx        xx       xx        xx           xx        xx         xx             x              xx        x", //66
			"xxxxxxxxxxxxxxxxxxxxxxxx       xxx       xx        xx           xx                                  x              xx        x", //67
			"xxxxxxxxxxxxxxxxxxxxxxxx       xxx       xx        xx           xx             x                    xx             xx        x", //68
			"xxxxxxxxxxxxxxxxxxxxxxxx       xxx       xx             x       xx   x        xx           xx       xx             xx        x", //69
			"xxxxxxxxxxxxxxxxxxxxxxxx                 xx             x            x        xx           xx       xx             xx        x", //70
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx", //71
	};

	int escena = 0;
	int xMask, yMask, xMup, yMup, xMdown, yMdown, xMizq, yMizq, xMder, yMder;

	ControlarCultivos controlesCultivos;
};

#endif // !1
