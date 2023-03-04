#include <allegro5/allegro.h>
#include "Cultivos.h"

class PlayerMovement
{
public:
	PlayerMovement();
	~PlayerMovement();
	void move(ALLEGRO_KEYBOARD_STATE keystate);
	int xJugador = 152;
	int yJugador = 217;
	int PlayerX = 1280;
	int PlayerY = 0;

private:
	float speedPlayer = 2;
	Cultivos cultivos;
	Mapa1 mapa1;
};

PlayerMovement::PlayerMovement()
{
}

PlayerMovement::~PlayerMovement()
{
}

void PlayerMovement::move(ALLEGRO_KEYBOARD_STATE keystate)
{
	al_get_keyboard_state(&keystate);
	//colision con los marcos
	if (yJugador <= 0) yJugador = 1;
	else if (yJugador >= 620) yJugador = 619;
	else if (xJugador <= 0) xJugador = 1;
	else if (xJugador >= 1205) xJugador = 1204;

	cultivos.plantarCultivo(keystate);

	if ((PlayerY <= 720 && PlayerY >= -720) && (PlayerX <= 1279.5 && PlayerX >= -1279.5))
	{
		if (al_key_down(&keystate, ALLEGRO_KEY_W)) yJugador -= 1.2 * speedPlayer;
		if (al_key_down(&keystate, ALLEGRO_KEY_S)) yJugador += speedPlayer;
		if (al_key_down(&keystate, ALLEGRO_KEY_D)) PlayerX -= speedPlayer;
		if (al_key_down(&keystate, ALLEGRO_KEY_A)) PlayerX += speedPlayer;
		xJugador = 640;

	}
	else
	{
		if (PlayerX > 1280) PlayerX -= speedPlayer - 1;
		else if (PlayerX < -1280) PlayerX += speedPlayer - 1;

		if (xJugador <= 640 && xJugador >= 0 && PlayerX > 1279)
		{
			if (al_key_down(&keystate, ALLEGRO_KEY_W)) yJugador -= speedPlayer;
			if (al_key_down(&keystate, ALLEGRO_KEY_S)) yJugador += speedPlayer;
			if (al_key_down(&keystate, ALLEGRO_KEY_D)) xJugador += speedPlayer;
			if (al_key_down(&keystate, ALLEGRO_KEY_A)) xJugador -= speedPlayer;

			if (xJugador > 640) PlayerX = 1279;
		}
		else if (xJugador >= 640 && xJugador <= 1280 && PlayerX < -1279) {
			if (al_key_down(&keystate, ALLEGRO_KEY_W)) yJugador -= speedPlayer;
			if (al_key_down(&keystate, ALLEGRO_KEY_S)) yJugador += speedPlayer;
			if (al_key_down(&keystate, ALLEGRO_KEY_D)) xJugador += speedPlayer;
			if (al_key_down(&keystate, ALLEGRO_KEY_A)) xJugador -= speedPlayer;

			if (xJugador < 640) PlayerX = -1279;
		}
	}
	mapa1.drawBackground(xJugador, yJugador, PlayerX, PlayerY);
}