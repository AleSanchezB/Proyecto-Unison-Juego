#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <string>
#include <iostream>
#include <list>

#include "Objeto.h"
std::list<Objeto*> objectos;

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
	
	enum { DOWNW, RIGHTW, UPW, LEFTW };
	float speedPlayer, direccion, SpritePosX, SpritePosY, corriendo;
	bool active = false;
	
	int PlayRefresh;
	int x;
	int y;
	int escena;

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
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                                                                                       x", //2
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                                                                                       x", //3
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                                                                                       x", //4
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                                                                                       x", //5
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                                                                                       x", //6
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                                                                                       x", //7
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                                                                                       x", //8
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                                                                                       x", //9
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                                                                                       x", //10
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                                                                                       x", //11
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                                                                                       x", //12
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                                                                                       x", //13
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                                                                                       x", //14
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                                                                                       x", //15
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                                                                                       x", //16
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                                                                                       x", //17
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                                                                                       x", //18
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                                                                                       x", //19
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                                                                                       x", //20
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                                                                                       x", //21
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                                                                                       x", //22
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                                                                                       x", //23
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                                                                                       x", //24
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                                                                                        ", //25
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                                                                                        ", //26
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                                                                                        ", //27
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                                                                                        ", //28
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                                                                                        ", //29
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                                                                                       ", //30
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                                                                                           ", //31
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                                                                                              ", //32
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                                                                                               ", //33
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                                                                                               ", //34
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                                                                                               ", //35
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                                                                                               ", //36
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                                                                                               ", //37
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                                                                                               ", //38
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                                                                                               ", //39
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                             xxxxxxxx                                                          ", //40
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                             xxxxxxxx                                                         x", //41
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                                                                                              x", //42
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                                                                                              x", //43
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                                                                                              x", //44
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                                                                                              x", //45
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                                                                                              x", //46
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                                                                                              x", //47
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                                                                                              x", //48
			"xxxxxxxxxxxxxxxxxxxxxxxx                                                                                                     x", //49
			"xxxxxxxxxxxxxxxxxxxxxxxx                                                                                                     x", //50
			"xxxxxxxxxxxxxxxxxxxxxxxx                                                                                                     x", //51
			"xxxxxxxxxxxxxxxxxxxxxxxx   x                                                                                                 x", //52
			"xxxxxxxxxxxxxxxxxxxxxxxx   x                                                                                                 x", //53
			"xxxxxxxxxxxxxxxxxxxxxxxx   x                                                                                                 x", //54
			"xxxxxxxxxxxxxxxxxxxxxxxx   x                                                                                                 x", //55
			"xxxxxxxxxxxxxxxxxxxxxxxx   x                                                                                                 x", //56
			"xxxxxxxxxxxxxxxxxxxxxxxx                                                                                                     x", //57
			"xxxxxxxxxxxxxxxxxxxxxxxx                                                                                                     x", //58
			"xxxxxxxxxxxxxxxxxxxxxxxx                                                                                                     x", //59
			"xxxxxxxxxxxxxxxxxxxxxxxx                                                                                                     x", //60
			"xxxxxxxxxxxxxxxxxxxxxxxx                                                                                                     x", //61
			"xxxxxxxxxxxxxxxxxxxxxxxx                                                                                                     x", //62
			"xxxxxxxxxxxxxxxxxxxxxxxx                                                                                                     x", //63
			"xxxxxxxxxxxxxxxxxxxxxxxx                                                                                                     x", //64
			"xxxxxxxxxxxxxxxxxxxxxxxx                                                                                                     x", //65
			"xxxxxxxxxxxxxxxxxxxxxxxx                                                                                                     x", //66
			"xxxxxxxxxxxxxxxxxxxxxxxx                                                                                                     x", //67
			"xxxxxxxxxxxxxxxxxxxxxxxx                                                                                                     x", //68
			"xxxxxxxxxxxxxxxxxxxxxxxx                                                                                                     x", //69
			"xxxxxxxxxxxxxxxxxxxxxxxx                                                                                                     x", //70
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx", //71
	};
	int xMask, yMask, xMup, yMup, xMdown, yMdown, xMizq, yMizq, xMder, yMder;


	void Animate(float SpritePosX, float SpritePosY, float xCoordsFondos, float yJug, float movimientoX, float movimientoY);
	void move(ALLEGRO_KEYBOARD_STATE keystate, ALLEGRO_EVENT_QUEUE* queue);
	void colisiones();

};
#endif // !PLAYER_H

