#include "Player.h"
#include <iostream>

//esta matriz nos permite saber cual hoyo de siembra está disponible
Mochila* mochila;
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
	mochila = new Mochila(5, 1, 1, 1, 1, 1);
	//relleno la matriz de cultivos como NULL para verificar posteriormente si está disponible
	for (int i = 0; i < 8; i++)
	{
		cultivosPlantados[i] = NULL;
	}
}

Player::~Player()
{
	al_destroy_bitmap(this->sprite);
	al_destroy_font(font);
	delete mochila;
}
void Player::move(ALLEGRO_KEYBOARD_STATE keystate, ALLEGRO_EVENT_QUEUE* queue)
{
	al_get_keyboard_state(&keystate);
	ALLEGRO_EVENT events;
	al_get_mouse_state(&estadoMouse);
	al_wait_for_event(queue, &events);

	//esto sirve para el scroll del mouse, a lo mejor se usa
	if (al_key_down(&keystate, ALLEGRO_KEY_1))
	{
		mochila->cambiarCasilla(0);
	}
	if (al_key_down(&keystate, ALLEGRO_KEY_2))
	{
		mochila->cambiarCasilla(1);
	}
	if (al_key_down(&keystate, ALLEGRO_KEY_3))
	{
		mochila->cambiarCasilla(2);
	}
	if (al_key_down(&keystate, ALLEGRO_KEY_4))
	{
		mochila->cambiarCasilla(3);
	}
	if (al_key_down(&keystate, ALLEGRO_KEY_5))
	{
		mochila->cambiarCasilla(4);
	}
	//tecla para cosechar
	if (al_key_down(&keystate, ALLEGRO_KEY_C))
	{
		if (maskmap[yMizq][xMizq] == '1' && cultivosPlantados[0] != NULL)
		{
			Cosechar(0);
		}
		if (maskmap[yMizq][xMizq] == '2' && cultivosPlantados[1] != NULL)
		{
			Cosechar(1);
		}
		if (maskmap[yMizq][xMizq] == '3' && cultivosPlantados[2] != NULL)
		{
			Cosechar(2);
		}
		if (maskmap[yMizq][xMizq] == '4' && cultivosPlantados[3] != NULL)
		{
			Cosechar(3);
		}
		if (maskmap[yMizq][xMizq] == '5' && cultivosPlantados[4] != NULL)
		{
			Cosechar(4);
		}
		if (maskmap[yMizq][xMizq] == '6' && cultivosPlantados[5] != NULL)
		{
			Cosechar(5);
		}
		if (maskmap[yMizq][xMizq] == '7' && cultivosPlantados[6] != NULL)
		{
			Cosechar(6);
		}
		if (maskmap[yMizq][xMizq] == '8' && cultivosPlantados[7] != NULL)
		{
			Cosechar(7);
		}
	}
	//Verifico si se presiono la tecla f(planta)
	if (al_key_down(&keystate, ALLEGRO_KEY_F))
	{
		//verifico el cooldown 
		if (al_current_time() - last_f_press > 2) {
			//recorro la matriz para verificar si está lleno, despues se cambiará
			if (mochila->verificacionMochila())
			{
				int tipo = mochila->verificarObjectoSeleccionado();
				if (mochila->verificarCantidadCultivos(tipo))
				{
					if (maskmap[yMizq][xMizq] == '1' && cultivosPlantados[0] == NULL)
					{
						Cultivo* cultivo = new Cultivo(900, 390, tipo, al_current_time());
						cultivosPlantados[0] = cultivo;
						mochila->quitarCultivo(tipo);
					}
					if (maskmap[yMizq][xMizq] == '2' && cultivosPlantados[1] == NULL)
					{
						Cultivo* cultivo = new Cultivo(1060, 380, tipo, al_current_time());
						cultivosPlantados[1] = cultivo;
						mochila->quitarCultivo(tipo);
					}
					if (maskmap[yMizq][xMizq] == '3' && cultivosPlantados[2] == NULL)
					{
						Cultivo* cultivo = new Cultivo(890, 440, tipo, al_current_time());
						cultivosPlantados[2] = cultivo;
						mochila->quitarCultivo(tipo);
					}
					if (maskmap[yMizq][xMizq] == '4' && cultivosPlantados[3] == NULL)
					{
						Cultivo* cultivo = new Cultivo(1065, 438, tipo, al_current_time());
						cultivosPlantados[3] = cultivo;
						mochila->quitarCultivo(tipo);
					}
					if (maskmap[yMizq][xMizq] == '5' && cultivosPlantados[4] == NULL)
					{
						Cultivo* cultivo = new Cultivo(900, 485, tipo, al_current_time());
						cultivosPlantados[4] = cultivo;
						mochila->quitarCultivo(tipo);
					}
					if (maskmap[yMizq][xMizq] == '6' && cultivosPlantados[5] == NULL)
					{
						Cultivo* cultivo = new Cultivo(1055, 492, tipo, al_current_time());
						cultivosPlantados[5] = cultivo;
						mochila->quitarCultivo(tipo);
					}
					if (maskmap[yMizq][xMizq] == '7' && cultivosPlantados[6] == NULL)
					{
						Cultivo* cultivo = new Cultivo(893, 540, tipo, al_current_time());
						cultivosPlantados[6] = cultivo;
						mochila->quitarCultivo(tipo);
					}
					if (maskmap[yMizq][xMizq] == '8' && cultivosPlantados[7] == NULL)
					{
						Cultivo* cultivo = new Cultivo(1074, 542, tipo, al_current_time());
						cultivosPlantados[7] = cultivo;
						mochila->quitarCultivo(tipo);
					}
				}
			}
			last_f_press = al_current_time();
		}
	}

	active = true;
	//CHECAR SI ESTA CORRIENDO
	if (al_key_down(&keystate, ALLEGRO_KEY_LSHIFT))
	{
		speedPlayer = 4;
		corriendo = 4;
	}
	else {
		speedPlayer = 2;
		corriendo = 0;
	}
	colisiones();

	//ESTABLECE EL MAPA LOGICO DE COLISIONES Y EL ZOOM DE CAMARA

	scale = 1.0f;

	if (getEscena() == 0)
	{
		memcpy(maskmap, maskmap1, sizeof(maskmap));
	}
	else if (getEscena() == 3)
	{
		memcpy(maskmap, maskmap2, sizeof(maskmap));
	}
	else if (getEscena() == 6) {
		memcpy(maskmap, maskmap3, sizeof(maskmap));
		//ZOOM DISPLAY
		scale = 1.25f;

	}
	else if (getEscena() == 9) {
		memcpy(maskmap, maskmap4, sizeof(maskmap));
		//ZOOM DISPLAY
		scale = 1.2f;

	}
	

	//ZOOM DISPLAY
	al_identity_transform(&camera);
	if (getEscena() == 3 || getEscena() == 6)
	{
		al_translate_transform(&camera, -790, -214);
		al_scale_transform(&camera, scale, scale);
		al_translate_transform(&camera, -cameraPosition[0] + 776, -cameraPosition[1] + 216);
	}
	else al_scale_transform(&camera, scale, scale);
	al_use_transform(&camera);
	//salir del cuarto
	if (al_key_down(&keystate, ALLEGRO_KEY_D) && maskmap[yMdown][xMdown] == 'i')
	{
		this->x += speedPlayer;
		direccion = RIGHTW + corriendo;
		
	}
	else if ((maskmap[yMup][xMup] == 'i' || maskmap[yMdown][xMdown] == 'i') && al_key_down(&keystate, ALLEGRO_KEY_O) && getEscena() == 0) {
		setEscena(0);
	}

	//AVISO PARA QUE PRESIONE TECLA H 
	else if (al_key_down(&keystate, ALLEGRO_KEY_W) && maskmap[yMup][xMup] == 'c' ) 
	{
		this->y -= speedPlayer;
		direccion = UPW + corriendo;
		TeclaCasa = true;
	}
	//CAMBIA A LA TIENDA

	else if (getEscena() == 9 && al_key_down(&keystate, ALLEGRO_KEY_T)) {
		setEscena(0);
		this->x = 600;
		this->y = 444;
	}

	else if (getEscena() != 9 && al_key_down(&keystate, ALLEGRO_KEY_T)) {
		setEscena(9);
		this->x = 600;
		this->y = 444;
	}
	
	//CAMBIO DE ESCENA A CASITA CUANDO PRESIONA H
	else if ((maskmap[yMup][xMup] == 'c' || maskmap[yMdown][xMdown] == 'c') && al_key_down(&keystate, ALLEGRO_KEY_H) && getEscena() == 0) {
		setEscena(6);
		MapaCasa = true;
	}

	else if (maskmap[yMup][xMup] == 'o' && getEscena() == 3) //cambia a escena de cultivos
	{
		this->y -= speedPlayer;
		direccion = UPW + corriendo;
		this->x = 1242;
		setEscena(0);
	}
	else if (maskmap[yMup][xMup] == 'o' && getEscena() == 0) //cambia a escena de cultivos
	{
		this->y -= speedPlayer;
		direccion = UPW + corriendo;
		this->x = 10;
		setEscena(3);
	}
	else if (al_key_down(&keystate, ALLEGRO_KEY_A) && maskmap[yMup][xMup] == 'b') //cama
	{
		this->x -= speedPlayer;
		direccion = LEFTW + corriendo;
		
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

	

	if (al_key_down(&keystate, ALLEGRO_KEY_G) && maskmap[yMup][xMup] == 'c' && getEscena() == 3)
	{
		this->y -= speedPlayer;
		direccion = UPW + corriendo;
		setEscena(9);
	}
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
	Animate(SpritePosX, SpritePosY * 56, 40.0f, 56.0f, this->x, this->y);
}

void Player::Cosechar(int i)
{
	Cultivo* other = cultivosPlantados[i];
	if (other->estado == other->COSECHABLE)
	{
		std::random_device rd;
		std::mt19937 gen(rd());

		if (other->tipo == 0)
		{
			std::discrete_distribution<> dist({ 3, 2, 1, 1 });
			int cantidadCosechada = dist(gen) + 2;
			mochila->setcantidadTomates(mochila->getcantidadTomates() + cantidadCosechada);
			mochila->setcantidadObjetos(mochila->getcantidadObjetos() + cantidadCosechada);
		}
		else if (other->tipo == 1)
		{
			std::discrete_distribution<> dist({ 3, 1, 1, 0.5 });
			int cantidadCosechada = dist(gen) + 2;
			mochila->setcantidadCalabaza(mochila->getcantidadCalabaza() + cantidadCosechada);
			mochila->setcantidadObjetos(mochila->getcantidadObjetos() + cantidadCosechada);

		}
		else if (other->tipo == 2)
		{
			std::discrete_distribution<> dist({ 3, 1, 0.5, 0.1 });
			int cantidadCosechada = dist(gen) + 2;
			mochila->setcantidadZanahoria(mochila->getcantidadZanahoria() + cantidadCosechada);
			mochila->setcantidadObjetos(mochila->getcantidadObjetos() + cantidadCosechada);
		}
		else if (other->tipo == 3)
		{
			std::discrete_distribution<> dist({ 3, 1, 0.5, 0.1 });
			int cantidadCosechada = dist(gen) + 2;
			mochila->setcantidadBerenjena(mochila->getcantidadBerenjena() + cantidadCosechada);
			mochila->setcantidadObjetos(mochila->getcantidadObjetos() + cantidadCosechada);
		}
		else if (other->tipo == 4)
		{
			std::discrete_distribution<> dist({ 3, 1, 0.5, 0.1 });
			int cantidadCosechada = dist(gen) + 2;
			mochila->setcantidadEjotes(mochila->getcantidadEjotes() + cantidadCosechada);
			mochila->setcantidadObjetos(mochila->getcantidadObjetos() + cantidadCosechada);
		}
		else if (other->tipo == 5)
		{
			std::discrete_distribution<> dist({ 3, 1, 0.5, 0.1 });
			int cantidadCosechada = dist(gen) + 2;
			mochila->setcantidadMaiz(mochila->getcantidadMaiz() + cantidadCosechada);
			mochila->setcantidadObjetos(mochila->getcantidadObjetos() + cantidadCosechada);
		}
		else if (other->tipo == 6)
		{
			std::discrete_distribution<> dist({ 3, 1, 0.5, 0.1 });
			int cantidadCosechada = dist(gen) + 2;
			mochila->setcantidadPapa(mochila->getcantidadPapa() + cantidadCosechada);
			mochila->setcantidadObjetos(mochila->getcantidadObjetos() + cantidadCosechada);
		}
		else if (other->tipo == 7)
		{
			std::discrete_distribution<> dist({ 3, 1, 0.5, 0.1 });
			int cantidadCosechada = dist(gen) + 2;
			mochila->setcantidadPapaya(mochila->getcantidadPapaya() + cantidadCosechada);
			mochila->setcantidadObjetos(mochila->getcantidadObjetos() + cantidadCosechada);
		}
		else if (other->tipo == 8)
		{
			std::discrete_distribution<> dist({ 3, 1, 0.5, 0.1 });
			int cantidadCosechada = dist(gen) + 2;
			mochila->setcantidadRemolacha(mochila->getcantidadRemolacha() + cantidadCosechada);
			mochila->setcantidadObjetos(mochila->getcantidadObjetos() + cantidadCosechada);
		}
		cultivosPlantados[i] = NULL;
	}
}

void Player::action(ALLEGRO_KEYBOARD_STATE keystate, ALLEGRO_EVENT_QUEUE* queue)
{
	//mando a mover al personaje y a animarlo
	al_get_keyboard_state(&keystate);
	move(keystate, queue);
	Animate(SpritePosX, SpritePosY * 56, 40.0f, 56.0f, this->x, this->y);
}
void Player::action()
{
	Animate(SpritePosX, SpritePosY * 56, 40.0f, 56.0f, this->x, this->y);
}
void Player::Animate(float SpritePosX, float SpritePosY, float movimientoX, float movimientoY, float xCoordsFondos, float yJug)
{
	al_draw_bitmap_region(this->sprite, SpritePosX, SpritePosY, movimientoX, movimientoY, xCoordsFondos, yJug, NULL);
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

	al_draw_text(font, al_map_rgb(255, 255, 255), 210, 10, ALLEGRO_ALIGN_LEFT, ("xjugador: " + std::to_string(this->x)).c_str());
	al_draw_text(font, al_map_rgb(255, 255, 255), 210, 30, ALLEGRO_ALIGN_LEFT, ("yjugador: " + std::to_string(this->y)).c_str());

	al_draw_text(font, al_map_rgb(255, 255, 255), 210, 70, ALLEGRO_ALIGN_LEFT, ("xMask: " + std::to_string(xMask)).c_str());
	al_draw_text(font, al_map_rgb(255, 255, 255), 350, 70, ALLEGRO_ALIGN_LEFT, ("yMask: " + std::to_string(yMask)).c_str());
	al_draw_text(font, al_map_rgb(255, 255, 255), 500, 70, ALLEGRO_ALIGN_LEFT, ("Hay: " + std::to_string(maskmap[yMask][xMask])).c_str());

	al_draw_text(font, al_map_rgb(255, 255, 255), 210, 90, ALLEGRO_ALIGN_LEFT, ("xMup: " + std::to_string(xMup)).c_str());
	al_draw_text(font, al_map_rgb(255, 255, 255), 350, 90, ALLEGRO_ALIGN_LEFT, ("yMup: " + std::to_string(yMup)).c_str());
	al_draw_text(font, al_map_rgb(255, 255, 255), 500, 90, ALLEGRO_ALIGN_LEFT, ("Hay: " + std::to_string(maskmap[yMup][xMup])).c_str());

	al_draw_text(font, al_map_rgb(255, 255, 255), 210, 110, ALLEGRO_ALIGN_LEFT, ("xMdown: " + std::to_string(xMdown)).c_str());
	al_draw_text(font, al_map_rgb(255, 255, 255), 350, 110, ALLEGRO_ALIGN_LEFT, ("yMdown: " + std::to_string(yMdown)).c_str());
	al_draw_text(font, al_map_rgb(255, 255, 255), 500, 110, ALLEGRO_ALIGN_LEFT, ("Hay: " + std::to_string(maskmap[yMdown][xMdown])).c_str());

	al_draw_text(font, al_map_rgb(255, 255, 255), 210, 130, ALLEGRO_ALIGN_LEFT, ("xMizq: " + std::to_string(xMizq)).c_str());
	al_draw_text(font, al_map_rgb(255, 255, 255), 350, 130, ALLEGRO_ALIGN_LEFT, ("yMizq: " + std::to_string(yMizq)).c_str());
	al_draw_text(font, al_map_rgb(255, 255, 255), 500, 130, ALLEGRO_ALIGN_LEFT, ("Hay: " + std::to_string(maskmap[yMizq][xMizq])).c_str());

	al_draw_text(font, al_map_rgb(255, 255, 255), 210, 150, ALLEGRO_ALIGN_LEFT, ("xMder: " + std::to_string(xMder)).c_str());
	al_draw_text(font, al_map_rgb(255, 255, 255), 350, 150, ALLEGRO_ALIGN_LEFT, ("yMder: " + std::to_string(yMder)).c_str());
	al_draw_text(font, al_map_rgb(255, 255, 255), 500, 150, ALLEGRO_ALIGN_LEFT, ("Hay: " + std::to_string(maskmap[yMder][xMder])).c_str());
	if(TeclaCasa) al_draw_text(font, al_map_rgb(255, 255, 255), 500, 20, ALLEGRO_ALIGN_LEFT, ("PRESIONA H PARA ENTRAR A LA CASITA " ));
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