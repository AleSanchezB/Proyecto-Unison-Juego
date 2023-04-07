#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/timer.h>

#include <string>
#include <iostream>
#include <list>

#include "Mochila.h"
#include "Objeto.h"
#include "TipoCultivos.h"

//std::list<Objeto*> objectos;

class Player
{
public:
	Player(std::string ruta);
	~Player();
	void action(ALLEGRO_KEYBOARD_STATE keystate, ALLEGRO_EVENT_QUEUE* queue);
	void setEscena(int escena);
	int getEscena();

private:
	ALLEGRO_BITMAP* sprite;
	ALLEGRO_FONT* font;
	enum { DOWNW, RIGHTW, UPW, LEFTW };
	float speedPlayer, direccion, SpritePosX, SpritePosY, corriendo;
	bool active = false;
	
	int PlayRefresh, AudRepeat;
	int x;
	int y;
	int escena;

	bool MapaV2;
	bool MapaCasa;


	bool f_pressed = false;
	double last_f_press = 0.0;
	const double f_cooldown_time = 2.0; // cooldown de 1 segundo

	//DIMESION DE LA MATRIZ MASCARA
	const int dimxmask = 150;
	const int dimymask = 150;

	const int filasCultivos = 4;
	const int colCultivos = 2;
	//MATRIZ DEL MAPA MASCARA
	char maskmap1[150][150] = {
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
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                                 xxxxxxxxxxxxxxxxxxx              x x       x      x   x", //9
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                                 xxx              xx              x x       x      x   x", //10
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                                 xxx              xx              x x       x      x   x", //11
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                                 xxx              xx              x x       x      xxx x", //12
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                                 xxx              xx              x x       x      xxx x", //13
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                                 xxx              xx              x  	   x      xxxxx", //14
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                                 xxx              xx              x         x          x", //15
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                                 xxx              xx              x         x  xx      x", //16
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                                 xxx              xx             xxxxxx     x  xx      x", //17
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                                 xxx              xx             xxxxxx     x  xx      x", //18
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                                 xxxxxxxxxx       xx            xxxxxxx     x          x", //19
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                                 xxxccccxxx       xx            xxxxxxx     x          x", //20
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                               xxxxxccccxxx       xx            xxxxxxxxxxxxx          x", //21
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                               xxxxxccccxxxxxxxxxxxx                     xxxx          x", //22
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                               xxxx                                      xxxxxxxxx     x", //23
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                               xxxx                                      xxxxxxxxx     x", //24
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                                 x                                        xxxxxxxx     x", //25
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                                                                             xxxxx     x", //26
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                                                                xxxxx                  x", //27
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                                                                  x                    o", //28
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                                                        xx                             o", //29
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                                                       xx                             o", //30
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                                                           xx                             o", //31
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                                                              xx                    xxx      o", //32
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                                                               xx                             o", //33
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                                                               xx                             o", //34
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

	char maskmap2[150][150] = {
		//             10        20        30        40        50        60        70       80        90       100        110      120
		//   012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx", //1
			"x                          xxxxxxxxxxxx     xxxxxx x              xxxxxxx    xxxxxx                              x           x", //2
			"x                        xxxxxxxxxxxxx      xxxxxx x                         xxxxxx                              x           x", //3
			"x                      xxxxxxxxxxxxxx       xxxxxx x                                                             x           x", //4
			"x                      xxxxxxxxxxxxxx       xxxxxx x                                                             x           x", //5
			"x                     x            x  xx    xxxxxx x                             xxxxxxxxxxxxxxxxxxxxxxxxxxxx    x           x", //6
			"x                    x             x  xx    xxxxxx x                             xx                         x    x           x", //7
			"x                    x            x   xx        xxxx                             xx                         x   xx           x", //8
			"x                   x             x   xx        xxxx                             xx                         x   xx           x", //9
			"x                   x            x    xx        xxxx                             xx                         x   xx           x", //10
			"x                   x            x    xx         xx                              xx                         x   xx           x", //11
			"x                   x            x    xx         xx                              xx                         x   xx           x", //12
			"x                   x           x     xx                                         xx                         x   xx           x", //13
			"x             xxx   x           x                                                xx                         x    x           x", //14
			"x              x    xxxxxxxxxxxxx                                                xx                         x    x           x", //15
			"x                                                                                 x                        xx    x           x", //16
			"x                                                                                 x                        xx    x           x", //17
			"x                                                                                 x                        xx    x           x", //18
			"x                                                                                 x                        xxxxxxx           x", //19
			"x                                                                                 x                        xxxxxxx           x", //20
			"x                                                                                 x                        xxxxxxx           x", //21
			"x                                                                                 xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx         x", //22
			"x                                                                                                                   x        x", //23
			"x                                                                                                                   x        x", //24
			"x                                                                                                                  x         x", //25
			"x                    xxxxxxxxxx                                                                                    x         x", //26
			"x                 xxxxxxxxxxxxxxxx                                                                                x          x", //27
			"                   x             x                                                                                x          x", //28
			"                   x             x                                                                               x           x", //29
			"                    x             x                                                                              x           x", //30
			"                    x             x                                                                              x           x", //31
			"                    x             x                                                                              x           x", //32
			"                     x             x                                                                              x          x", //33
			"                     x              xx                                           x                                 x         x", //34
			"                     x                x                                          x                                 x         x", //35
			"                     x                 x                                         x                                 x         x", //36
			"x                    x                  x                                        x                               xx          x", //37
			"x                    x                   x                                       x                               x           x", //38
			"x                    x                   x                                      x        11111111   5555         x           x", //39
			"x                    x                    x                                     x        11111111   5555         x           x", //40
			"x                     x                   x                                     x        11111111   5555         x           x", //41
			"x                     x                   x                                     x                                x           x", //42
			"x                      x                  x                                     x                                x           x", //43
			"x                      x                  x                         xxxx        x       22222222     6666        x           x", //44
			"x                       x                 x                          xx          x      22222222     6666         x          x", //45
			"x                       x                 x                          xx          x      22222222     6666         x          x", //46
			"x            xxxx        x                x                          xx          x                               x           x", //47
			"x             xx         xx               x       xx                 xx          x                               x           x", //48
			"x             xx           x              x       xx                 xx          x       33333333    7777        x           x", //49
			"x             xx           x              x       xx                 xx          x       33333333    7777        x           x", //50
			"x             xx           x              x       xx                 xx          x       33333333    7777        x           x", //52
			"x             xx           x              x       xx       xx        xx          x                               x           x", //51
			"x  xx         xx            x             x       xx       xx        xx          x                               x           x", //53
			"x  xx         xx            x              x               xx                    x      44444444                 x           x", //54
			"x  xx         xx            x              xxxxxx          xx                    x      44444444     88888       x           x", //55
			"x  xx                       x              x   xxx         xx             xx     x      44444444     88888       x           x", //56
			"x  xx                       x               x   xx                        xx     x                   88888       x           x", //57
			"x                           x               x     xx                      xx     x                               x           x", //58
			"x                  x        x                x      x                     xx     x                             xxx           x", //59
			"x                  x        x                 x    xxx                    xx     x                             xxx           x", //60
			"x                  x        x                  x   xxx         xxxx       xx     x                              xx           x", //61
			"x                  x    xx  x                   x x             xx               x                             xxx           x", //62
			"x       xxxx       x    xx  x                    x              xx          xx   x                            xx x           x", //63
			"x        xx             xx  x                     x             xx          xx   xxxxxxxx  xxxx  xxx  xxx  xxxxx x           x", //64
			"x        xx             xx  x                      x            xx          xx   xx  x  xxx    xx   xx   xx   xx x           x", //65
			"x        xx             xx   x                      x           xx          xx    x  x  x      x     x        x  x           x", //66
			"x        xx             xx    x                      x          xx          xx    x  xx x x    x    xx   xx   xx x           x", //67
			"x        xx             xx     x                      x         xx          xx     xx  x x xxxx xxxx  xxx  xxx  xx           x", //68
			"x        xx             xx      x                      xx       xx                                               x           x", //69
			"x        xx             xx       x                       xx     xx                                               x           x", //70
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx", //71
	};

	char maskmap[150][150];

	bool MatrizCultivos[2][5]{
		{false,false,false,false, false},
		{false,false,false,false, false}
	};

	int xMask, yMask, xMup, yMup, xMdown, yMdown, xMizq, yMizq, xMder, yMder;

	int vectormatriz[3];
	void Animate(float SpritePosX, float SpritePosY, float xCoordsFondos, float yJug, float movimientoX, float movimientoY);
	void move(ALLEGRO_KEYBOARD_STATE keystate, ALLEGRO_EVENT_QUEUE* queue);
	void colisiones();
	bool verificacionMochila();
	Mochila* mochila;
	ALLEGRO_MOUSE_STATE estadoMouse;
};
extern Objeto *matrizCultivos[4][2];
#endif // !PLAYER_H

