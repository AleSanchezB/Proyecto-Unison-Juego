#include "Player.h"
//esta matriz nos permite saber cual hoyo de siembra está disponible
Objeto* matrizCultivos[4][2];
Player::Player(std::string ruta)
{
	//creo el personaje
	this->sprite = al_load_bitmap(ruta.c_str());
	this->speedPlayer = 4;
	this->active = false;
	this->direccion = 0;
	this->SpritePosX = 0;
	this->SpritePosY = 0;
	this->corriendo = 0;
	this->PlayRefresh = 0;
	this->x = 624;
	this->y = 310;
	this->escena = 0;
	this->MapaV2 = false;
	this->MapaCasa = false;
	this->AudRepeat = 0;
	this->font = al_load_font("assets/fonts/Minecraft.ttf", 20, 0);

	//creo una mochila incial con 3 cultivos 1 de cada 1
	mochila = new Mochila(3, 1, 1, 1);

	//relleno la matriz de cultivos como NULL para verificar posteriormente si está disponible
	for (int i = 0; i < filasCultivos; i++)
	{
		for (int j = 0; j < colCultivos; j++) matrizCultivos[i][j] = NULL;
	}
}
Player::~Player()
{
	al_destroy_bitmap(this->sprite);
}
void Player::action(ALLEGRO_KEYBOARD_STATE keystate,ALLEGRO_EVENT_QUEUE* queue)
{
	//mando a mover al personaje y a animarlo
	al_get_keyboard_state(&keystate);
	move(keystate,queue);
	Animate(SpritePosX, SpritePosY * 56, 40.0f, 56.0f, this->x, this->y);
}
void Player::colisiones()
{
	//verifico las colisiones con el mapa
	int moniotpixancho = 10;
	int monitopixalto = 10;
	xMask = (this->x / moniotpixancho);
	if (xMask < 0) xMask = 0;
	if (xMask > dimxmask) xMask = dimxmask;
	yMask = (this->y / monitopixalto) + 2;
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

	xMder = (this->x / moniotpixancho) + 1;
	if (xMder < 0) xMder = 0;
	if (xMder > dimxmask) xMder = dimxmask;
	yMder = yMask;
	if (yMder < 0) yMder = 0;
	if (yMder > dimymask) yMder = dimymask;

	al_draw_text(font, al_map_rgb(255, 255, 255), 10, 10, ALLEGRO_ALIGN_LEFT, ("xjugador: " + std::to_string(this->x)).c_str());
	al_draw_text(font, al_map_rgb(255, 255, 255), 10, 30, ALLEGRO_ALIGN_LEFT, ("yjugador: " + std::to_string(this->y)).c_str());

	al_draw_text(font, al_map_rgb(255, 255, 255), 10, 70, ALLEGRO_ALIGN_LEFT, ("xMask: " + std::to_string(xMask)).c_str());
	al_draw_text(font, al_map_rgb(255, 255, 255), 150, 70, ALLEGRO_ALIGN_LEFT, ("yMask: " + std::to_string(yMask)).c_str());
	al_draw_text(font, al_map_rgb(255, 255, 255), 300, 70, ALLEGRO_ALIGN_LEFT, ("Hay: " + std::to_string(maskmap[yMask][xMask])).c_str());

	al_draw_text(font, al_map_rgb(255, 255, 255), 10, 90, ALLEGRO_ALIGN_LEFT, ("xMup: " + std::to_string(xMup)).c_str());
	al_draw_text(font, al_map_rgb(255, 255, 255), 150, 90, ALLEGRO_ALIGN_LEFT, ("yMup: " + std::to_string(yMup)).c_str());
	al_draw_text(font, al_map_rgb(255, 255, 255), 300, 90, ALLEGRO_ALIGN_LEFT, ("Hay: " + std::to_string(maskmap[yMup][xMup])).c_str());

	al_draw_text(font, al_map_rgb(255, 255, 255), 10, 110, ALLEGRO_ALIGN_LEFT, ("xMdown: " + std::to_string(xMdown)).c_str());
	al_draw_text(font, al_map_rgb(255, 255, 255), 150, 110, ALLEGRO_ALIGN_LEFT, ("yMdown: " + std::to_string(yMdown)).c_str());
	al_draw_text(font, al_map_rgb(255, 255, 255), 300, 110, ALLEGRO_ALIGN_LEFT, ("Hay: " + std::to_string(maskmap[yMdown][xMdown])).c_str());

	al_draw_text(font, al_map_rgb(255, 255, 255), 10, 130, ALLEGRO_ALIGN_LEFT, ("xMizq: " + std::to_string(xMizq)).c_str());
	al_draw_text(font, al_map_rgb(255, 255, 255), 150, 130, ALLEGRO_ALIGN_LEFT, ("yMizq: " + std::to_string(yMizq)).c_str());
	al_draw_text(font, al_map_rgb(255, 255, 255), 300, 130, ALLEGRO_ALIGN_LEFT, ("Hay: " + std::to_string(maskmap[yMizq][xMizq])).c_str());

	al_draw_text(font, al_map_rgb(255, 255, 255), 10, 150, ALLEGRO_ALIGN_LEFT, ("xMder: " + std::to_string(xMder)).c_str());
	al_draw_text(font, al_map_rgb(255, 255, 255), 150, 150, ALLEGRO_ALIGN_LEFT, ("yMder: " + std::to_string(yMder)).c_str());
	al_draw_text(font, al_map_rgb(255, 255, 255), 300, 150, ALLEGRO_ALIGN_LEFT, ("Hay: " + std::to_string(maskmap[yMder][xMder])).c_str());
}
void Player::move(ALLEGRO_KEYBOARD_STATE keystate, ALLEGRO_EVENT_QUEUE* queue)
{
	al_get_keyboard_state(&keystate);
	ALLEGRO_EVENT events;
	al_get_mouse_state(&estadoMouse);
	al_wait_for_event(queue, &events);

	//Verifico si se presiono la tecla f
	if (al_key_down(&keystate, ALLEGRO_KEY_F) && getEscena() == 1)
	{
		//verifico el cooldown 
		if (al_current_time() - last_f_press > 2) {
			//recorro la matriz para verificar si está lleno, despues se cambiará

			if (verificacionMochila())
			{
				if (maskmap[yMizq][xMizq] == '1' && matrizCultivos[0][0] == NULL)
				{
					mochila->setcantidadObjetos(mochila->getcantidadObjetos() - 1);
					Cultivo* cultivo = new Cultivo("assets/Plants/zanahoria sprites.png", 904, 395, 1, al_current_time());
					cultivos.push_back(cultivo);
					matrizCultivos[0][0] = cultivo;
				}
				if (maskmap[yMizq][xMizq] == '2' && matrizCultivos[0][1] == NULL)
				{
					mochila->setcantidadObjetos(mochila->getcantidadObjetos() - 1);
					Cultivo* cultivo = new Cultivo("assets/Plants/calabaza sprites.png", 1074, 413, 1, al_current_time());
					cultivos.push_back(cultivo);
					matrizCultivos[0][1] = cultivo;
				}
				if (maskmap[yMizq][xMizq] == '3' && matrizCultivos[1][0] == NULL)
				{
					mochila->setcantidadObjetos(mochila->getcantidadObjetos() - 1);
					Cultivo* cultivo = new Cultivo("assets/Plants/tomate sprites.png", 896, 444, 1, al_current_time());
					cultivos.push_back(cultivo);
					matrizCultivos[1][0] = cultivo;
				}
				if (maskmap[yMizq][xMizq] == '4' && matrizCultivos[1][1] == NULL)
				{
					mochila->setcantidadObjetos(mochila->getcantidadObjetos() - 1);
					Cultivo* cultivo = new Cultivo("assets/Plants/zanahoria sprites.png", 1041, 472, 1, al_current_time());
					cultivos.push_back(cultivo);
					matrizCultivos[1][1] = cultivo;
				}
				if (maskmap[yMizq][xMizq] == '5' && matrizCultivos[2][0] == NULL)
				{
					mochila->setcantidadObjetos(mochila->getcantidadObjetos() - 1);
					Cultivo* cultivo = new Cultivo("assets/Plants/calabaza sprites.png", 907, 488, 1, al_current_time());
					cultivos.push_back(cultivo);
					matrizCultivos[2][0] = cultivo;
				}
				if (maskmap[yMizq][xMizq] == '6' && matrizCultivos[2][1] == NULL)
				{
					mochila->setcantidadObjetos(mochila->getcantidadObjetos() - 1);
					Cultivo* cultivo = new Cultivo("assets/Plants/tomate sprites.png", 1035, 505, 1, al_current_time());
					cultivos.push_back(cultivo);
					matrizCultivos[2][1] = cultivo;
				}
				if (maskmap[yMizq][xMizq] == '7' && matrizCultivos[3][0] == NULL)
				{
					mochila->setcantidadObjetos(mochila->getcantidadObjetos() - 1);
					Cultivo* cultivo = new Cultivo("assets/Plants/zanahoria sprites.png", 898, 542, 1, al_current_time());
					cultivos.push_back(cultivo);
					matrizCultivos[3][0] = cultivo;
				}
				if (maskmap[yMizq][xMizq] == '8' && matrizCultivos[3][1] == NULL)
				{
					mochila->setcantidadObjetos(mochila->getcantidadObjetos() - 1);
					Cultivo* cultivo = new Cultivo("assets/Plants/tomate sprites.png", 1050, 574, 1, al_current_time());
					cultivos.push_back(cultivo);
					matrizCultivos[3][1] = cultivo;
				}
			}
			last_f_press = al_current_time();
		}
	}
	//muestra la mochila (falta interfaz)
	else if (al_key_down(&keystate, ALLEGRO_KEY_C))
	{
		mochila->action(font);
	}
	//esto sirve para el scroll del mouse, a lo mejor se usa
	else if (estadoMouse.z > 0)
	{
		std::cout << "se movió el scroll hacia arriba" << std::endl;
		estadoMouse.z = 0;
	}
	else if (estadoMouse.z < 0)
	{
		std::cout << "se movió el scroll hacia abajo" << std::endl;
		estadoMouse.z = 0;
	}
	else
	{
		// colision con el mapa de mascara

		active = true;
		//CHECAR SI ESTA CORRIENDO
		if (al_key_down(&keystate, ALLEGRO_KEY_LSHIFT)) {
			speedPlayer = 4;
			corriendo = 4;
		}
		else {
			speedPlayer = 2;
			corriendo = 0;
		}
		colisiones();
    
		if (getEscena() == 0) {
			memcpy(maskmap, maskmap1, sizeof(maskmap));
		}
		else if (getEscena() == 1) {
			memcpy(maskmap, maskmap2, sizeof(maskmap));
		}
		else if (getEscena() == 2) {
			memcpy(maskmap, maskmap3, sizeof(maskmap));
		}

		if (al_key_down(&keystate, ALLEGRO_KEY_D) && maskmap[yMdown][xMdown] == 'i')
		{
			this->y -= speedPlayer;
			direccion = UPW + corriendo;
			setEscena(0);
		}
		else if (al_key_down(&keystate, ALLEGRO_KEY_W) && maskmap[yMup][xMup] == 'c' && getEscena() == 0) 
		{
			this->y -= speedPlayer;
			direccion = UPW + corriendo;
			MapaCasa = true;
			setEscena(2);
		}
		else if (al_key_down(&keystate, ALLEGRO_KEY_D) && maskmap[yMup][xMup] == 'o') 
		{
			this->y -= speedPlayer;
			direccion = UPW + corriendo;
			MapaV2 = true;
			this->x = 2;
			setEscena(1);
		}
		else if (al_key_down(&keystate, ALLEGRO_KEY_W) && maskmap[yMup][xMup] != 'x')
		{
			this->y -= speedPlayer;
			direccion = UPW + corriendo;
		}
		else if (al_key_down(&keystate, ALLEGRO_KEY_S) && maskmap[yMdown][xMdown] != 'x')
		{
			this->y += speedPlayer;
			direccion = DOWNW + corriendo;
		}
		else if (al_key_down(&keystate, ALLEGRO_KEY_D) && maskmap[yMder][xMder] != 'x')
		{
			this->x += speedPlayer;
			direccion = RIGHTW + corriendo;
		}
		else if (al_key_down(&keystate, ALLEGRO_KEY_A) && maskmap[yMizq][xMizq] != 'x')
		{
			this->x -= speedPlayer;
			direccion = LEFTW + corriendo;
		}
		else active = false;
		//ANIMACION DE MOVIMIENTOS 
		PlayRefresh++;
		if (PlayRefresh == 10) 
		{
			if (SpritePosX >= 200) SpritePosX = 0;
			if (active) SpritePosX += 40;
			else SpritePosX = 0;
			SpritePosY = direccion;
			PlayRefresh = 0;
		}
		//cambio de mapa
		if (this->x > 1280 && this->y >= 260 && this->y <= 330 && escena == 0)
		{
			this->x = 2;
			setEscena(1);
		}
		else if (this->x < -38 && this->y >= 246 && this->y <= 332 && escena == 1)
		{
			this->x = 1242;
			setEscena(0);
		}
	}
	
	//if (MapaCasa) { al_draw_text(font, al_map_rgb(255, 255, 255), 500, 10, ALLEGRO_ALIGN_LEFT, ("Cambia MAPA CASITA"));}
	if (MatrizCultivos[0][1]) { al_draw_text(font, al_map_rgb(255, 255, 255), 500, 30, ALLEGRO_ALIGN_LEFT, ("MatrizCultivos[0][1]"));}
	if (MatrizCultivos[0][2]) { al_draw_text(font, al_map_rgb(255, 255, 255), 500, 50, ALLEGRO_ALIGN_LEFT, ("MatrizCultivos[0][2]"));}
	if (MatrizCultivos[0][3]) { al_draw_text(font, al_map_rgb(255, 255, 255), 500, 70, ALLEGRO_ALIGN_LEFT, ("MatrizCultivos[0][3]"));}
	if (MatrizCultivos[0][4]) { al_draw_text(font, al_map_rgb(255, 255, 255), 500, 90, ALLEGRO_ALIGN_LEFT, ("MatrizCultivos[0][4]"));}
	if (MatrizCultivos[1][1]){ al_draw_text(font, al_map_rgb(255, 255, 255), 500, 110, ALLEGRO_ALIGN_LEFT, ("MatrizCultivos[1][1]"));}
	if (MatrizCultivos[1][2]) { al_draw_text(font, al_map_rgb(255, 255, 255), 500, 130, ALLEGRO_ALIGN_LEFT, ("MatrizCultivos[1][2]"));}
	if (MatrizCultivos[1][3]) { al_draw_text(font, al_map_rgb(255, 255, 255), 500, 150, ALLEGRO_ALIGN_LEFT, ("MatrizCultivos[1][3]"));}
	if (MatrizCultivos[1][4]) { al_draw_text(font, al_map_rgb(255, 255, 255), 500, 170, ALLEGRO_ALIGN_LEFT, ("MatrizCultivos[1][4]"));}

	Animate(SpritePosX, SpritePosY * 56, 40.0f, 56.0f, this->x, this->y);
}
void Player::Animate(float SpritePosX, float SpritePosY, float movimientoX, float movimientoY, float xCoordsFondos, float yJug)
{
	al_draw_bitmap_region(this->sprite, SpritePosX, SpritePosY, movimientoX, movimientoY, xCoordsFondos, yJug, NULL);
}
//obtengo la escena en la que estoy
void Player::setEscena(int escena)
{
	this->escena = escena;
}
int Player::getEscena()
{
	return this->escena;
}
bool Player::verificacionMochila()
{
	if (mochila->getcantidadObjetos() > 0) return true;
	return false;
}