#ifndef CONTROLESCULTIVOS_H
#define CONTROLESCULTIVOS_H


#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "TipoCultivos.h"

class ControlarCultivos
{
public:
	ControlarCultivos();
	~ControlarCultivos();
	void plantarCultivo(ALLEGRO_KEYBOARD_STATE keystate, ALLEGRO_EVENT_QUEUE* queue);
private:
	const float COOLDOWN_TIME = 0.7f;
	float last_time_pressed = 0.0f;
	ALLEGRO_EVENT event;
	int cultivos = 0;
};
#endif // !1