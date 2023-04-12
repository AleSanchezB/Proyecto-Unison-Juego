#include "Comprador.h"

Comprador::Comprador()
{
	this->TipoCultivo = 2;
	this->CantVender = 1;
	cantDig = std::log10(this->CantVender) + 1;
	coins = al_load_bitmap("assets/animation/Paper Content Appear Animation/Folding & Cutout/8 Shop/coins2.png");
	for (int i = 35; i > 0; i--)
	{
		std::string ruta = "assets/animation/Paper Content Appear Animation/Folding & Cutout/8 Shop/" + std::to_string(i) + ".png";
		menu[i] = al_load_bitmap(ruta.c_str());
	}
	menu[0] = al_load_bitmap("assets/Tienda/Menus/MenuVenta.png");
	//backgroud = new Background();
	animacion_x = 716;
	animacion_y = 587;

	btnflechaArriba[0] = new Boton("assets/Tienda/botones/MenuVenta/btnArriba.png", 680, 462, 22, 18);
	btnflechaArriba[1] = new Boton("assets/Tienda/botones/MenuVenta/btnArriba.png", 680, 530, 22, 18);
	btnflechaArriba[2] = new Boton("assets/Tienda/botones/MenuVenta/btnArribaP.png", 680, 462, 22, 18);
	btnflechaArriba[3] = new Boton("assets/Tienda/botones/MenuVenta/btnArribaP.png", 680, 530, 22, 18);

	btnflechaAbajo[0] = new Boton("assets/Tienda/botones/MenuVenta/btnAbajo.png", 680, 488, 22, 18);
	btnflechaAbajo[1] = new Boton("assets/Tienda/botones/MenuVenta/btnAbajo.png", 680, 556, 22, 18);
	btnflechaAbajo[2] = new Boton("assets/Tienda/botones/MenuVenta/btnAbajoP.png", 680, 488, 22, 18);
	btnflechaAbajo[3] = new Boton("assets/Tienda/botones/MenuVenta/btnAbajoP.png", 680, 556, 22, 18);

	btnSalir[0] = new Boton("assets/Tienda/botones/MenuVenta/btnSalir.png", 872, 67, 38, 38);
	btnVender[0] = new Boton("assets/Tienda/botones/MenuVenta/btnVender.png", 716, 587, 118, 39);
	btnSalir[1] = new Boton("assets/Tienda/botones/MenuVenta/btnSalirP.png", 872, 67, 38, 38);
	btnVender[1] = new Boton("assets/Tienda/botones/MenuVenta/btnVenderP.png", 716, 587, 118, 39);
}
void Comprador::animacionMenu(int tipo)
{
	for (int i = 35; i >= 0; i--)
	{
		Sleep(60);
		background->action(player->getEscena()+player->TiempoDiaEscena, 0);
		background->drawOptions(0, mochila->getMonedas());
		player->action();
		al_draw_bitmap(menu[i], 0, 0, 0);
		al_flip_display();
		al_clear_to_color(al_map_rgb_f(255, 255, 255));
	}
}
void Comprador::Menu(ALLEGRO_KEYBOARD_STATE keystate, ALLEGRO_EVENT_QUEUE* queue)
{
	ALLEGRO_EVENT events;
	al_get_keyboard_state(&keystate);
	animacionMenu(1);
	int btnCult = 0;
	int btnCant = 0;

	int btnCultB = 0;
	int btnCantB = 0;

	int btnExit = 0;
	int btnVen = 0;
	bool salir = true;
	while (!al_key_down(&keystate, ALLEGRO_KEY_ESCAPE) && salir)
	{
		al_get_keyboard_state(&keystate);
		al_wait_for_event(queue, &events);
		DibujarElFondo();
		if (events.type == ALLEGRO_EVENT_MOUSE_AXES)
		{
			//boton para seleccionar el tipo de cultivo
			if ((events.mouse.x >= btnflechaArriba[0]->x && events.mouse.x <= btnflechaArriba[0]->x + btnflechaArriba[0]->w
				&& events.mouse.y >= btnflechaArriba[0]->y && events.mouse.y <= btnflechaArriba[0]->y + btnflechaArriba[0]->h))
			{
				btnCult = 2;
			}
			else btnCult = 0;

			if (events.mouse.x >= btnflechaAbajo[0]->x && events.mouse.x <= btnflechaAbajo[0]->x + btnflechaAbajo[0]->w
				&& events.mouse.y >= btnflechaAbajo[0]->y && events.mouse.y <= btnflechaAbajo[0]->y + btnflechaAbajo[0]->h)
			{
				btnCultB = 2;
			}
			else btnCultB = 0;

			////boton para seleccionar cantidad de cultivo
			if (events.mouse.x >= btnflechaArriba[1]->x && events.mouse.x <= btnflechaArriba[1]->x + btnflechaArriba[1]->w
				&& events.mouse.y >= btnflechaArriba[1]->y && events.mouse.y <= btnflechaArriba[1]->y + btnflechaArriba[1]->h)
			{
				btnCant = 3;
			}
			else btnCant = 1;

			if (events.mouse.x >= btnflechaAbajo[1]->x && events.mouse.x <= btnflechaAbajo[1]->x + btnflechaAbajo[1]->w
				&& events.mouse.y >= btnflechaAbajo[1]->y && events.mouse.y <= btnflechaAbajo[1]->y + btnflechaAbajo[1]->h)
			{
				btnCantB = 3;
			}
			else btnCantB = 1;

			//boton de vender
			if (events.mouse.x >= btnVender[1]->x && events.mouse.x <= btnVender[1]->x + btnVender[1]->w
				&& events.mouse.y >= btnVender[1]->y && events.mouse.y <= btnVender[1]->y + btnVender[1]->h)
			{
				btnVen = 1;
			}
			else btnVen = 0;

			//boton de salir
			if (events.mouse.x >= btnSalir[1]->x && events.mouse.x <= btnSalir[1]->x + btnSalir[1]->w
				&& events.mouse.y >= btnSalir[1]->y && events.mouse.y <= btnSalir[1]->y + btnSalir[1]->h)
			{
				btnExit = 1;
			}
			else btnExit = 0;
		}

		if (events.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
		{
			if (events.mouse.button == 1)
			{
				//boton para seleccionar el tipo de cultivo
				if ((events.mouse.x >= btnflechaArriba[0]->x && events.mouse.x <= btnflechaArriba[0]->x + btnflechaArriba[0]->w
					&& events.mouse.y >= btnflechaArriba[0]->y && events.mouse.y <= btnflechaArriba[0]->y + btnflechaArriba[0]->h))
				{
					btnCult = 2;
					if (this->TipoCultivo == 3) this->TipoCultivo = 3;
					else this->TipoCultivo++;
				}
				else btnCult = 0;

				if (events.mouse.x >= btnflechaAbajo[0]->x && events.mouse.x <= btnflechaAbajo[0]->x + btnflechaAbajo[0]->w
					&& events.mouse.y >= btnflechaAbajo[0]->y && events.mouse.y <= btnflechaAbajo[0]->y + btnflechaAbajo[0]->h)
				{
					btnCultB = 2;
					if (events.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
						if (events.mouse.button == 1)
							if (this->TipoCultivo == 1) this->TipoCultivo = 1;
							else this->TipoCultivo--;
				}
				else btnCultB = 0;

				////boton para seleccionar cantidad de cultivo
				if (events.mouse.x >= btnflechaArriba[1]->x && events.mouse.x <= btnflechaArriba[1]->x + btnflechaArriba[1]->w
					&& events.mouse.y >= btnflechaArriba[1]->y && events.mouse.y <= btnflechaArriba[1]->y + btnflechaArriba[1]->h)
				{
					btnCant = 3;
					if (events.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
						if (events.mouse.button == 1)
							this->CantVender++;
				}
				else btnCant = 1;

				if (events.mouse.x >= btnflechaAbajo[1]->x && events.mouse.x <= btnflechaAbajo[1]->x + btnflechaAbajo[1]->w
					&& events.mouse.y >= btnflechaAbajo[1]->y && events.mouse.y <= btnflechaAbajo[1]->y + btnflechaAbajo[1]->h)
				{
					btnCantB = 3;
					if (this->CantVender == 0) this->CantVender = 0;
					else this->CantVender--;
				}
				else btnCantB = 1;

				//boton de vender
				if (events.mouse.x >= btnVender[1]->x && events.mouse.x <= btnVender[1]->x + btnVender[1]->w
					&& events.mouse.y >= btnVender[1]->y && events.mouse.y <= btnVender[1]->y + btnVender[1]->h)
				{
					btnVen = 1;
					if (mochila->verificacionMochila() && 
						mochila->verificarCantidadCultivosGuardados(this->TipoCultivo-1, this->CantVender))
					{
						animacionMonedas();
						VerificarVenta();
						cantDig = 0;
					}
				}
				else btnVen = 0;

				//boton de salir
				if (events.mouse.x >= btnSalir[1]->x && events.mouse.x <= btnSalir[1]->x + btnSalir[1]->w
					&& events.mouse.y >= btnSalir[1]->y && events.mouse.y <= btnSalir[1]->y + btnSalir[1]->h)
				{
					btnExit = 1;
					salir = false;
				}
				else btnExit = 0;
			}
		}
		action(btnCult, btnCant, btnCultB, btnCantB, btnExit, btnVen);
		al_flip_display();
		if (al_key_down(&keystate, ALLEGRO_KEY_M)) animacionMonedas();
	}
	AnimacionReversa();
}
void Comprador::animacionMonedas()
{
	while (animacion_y > 90)
	{
		for (int i = 0; i < 8; i++)
		{
			Sleep(60);
			DibujarElFondo();
			action();
			DibujarCantidadSelec();
			al_draw_bitmap_region(coins, 31 * i, 0, 31, 31, animacion_x, animacion_y, 0);
			al_flip_display();
			al_clear_to_color(al_map_rgb_f(255, 255, 255));
			animacion_x += 5;
			animacion_y = 0.001261 * std::pow(animacion_x, 2) - 4.1391 * animacion_x + 2903.71;
			//0.0012A B= -4.14 C 2903.7  0.017*std::pow(animacion_x,2)-20.65*animacion_x+2050   A = -0.0495 B = 86.67722 C = 37242.37588
		}
	}
	DibujarElFondo();
	action();
	al_draw_bitmap_region(coins, 0, 0, 31, 31, 988, 25, 0);
	al_flip_display();
	animacion_x = 716;
	animacion_y = 587;
}
void Comprador::DibujarCantidadSelec()
{
	int aux = xVenta;
	if (this->CantVender == 0)
	{
		xVenta = 604;
		cantDig = 1;
	}
	else
	{
		if ((int)(std::log10(this->CantVender) + 1) > cantDig) xVenta -= DX;
		else if ((int)(std::log10(this->CantVender) + 1) < cantDig) xVenta += DX;
		cantDig = std::log10(this->CantVender) + 1;
	}
	al_draw_text(background->font, al_map_rgb(0, 0, 0), 604, 478, 0, (std::to_string(this->TipoCultivo)).c_str());
	al_draw_text(background->font, al_map_rgb(0, 0, 0), xVenta, 546, 0, (std::to_string(this->CantVender)).c_str());
}
void Comprador::DibujarElFondo(int escena)
{
	background->action(player->getEscena()+player->TiempoDiaEscena, 0);
	player->action();
	background->drawOptions(0, mochila->getMonedas());
	al_draw_bitmap(menu[escena], 0, 0, 0);
	DibujarCantidadSelec();
}
void Comprador::AnimacionReversa()
{
	for (int i = 1; i <= 35; i++)
	{
		Sleep(60);
		background->action(player->getEscena()+player->TiempoDiaEscena, 0);
		background->drawOptions(0, mochila->getMonedas());
		player->action();
		al_draw_bitmap(menu[i], 0, 0, 0);
		al_flip_display();
		al_clear_to_color(al_map_rgb_f(255, 255, 255));
	}
}
void Comprador::action(int btnCult, int btnCant, int btnCultB, int btnCantB, int btnExit, int btnVen)
{
	btnflechaArriba[btnCult]->action();
	btnflechaArriba[btnCant]->action();

	btnflechaAbajo[btnCultB]->action();
	btnflechaAbajo[btnCantB]->action();

	btnSalir[btnExit]->action();
	btnVender[btnVen]->action();
}
bool Comprador::VerificarVenta()
{
	if (mochila->verificacionMochila())
	{
		if (mochila->verificarCantidadCultivosGuardados(this->TipoCultivo-1, this->CantVender))
		{
			mochila->quitarCultivo(this->TipoCultivo-1);
			int Pago = 0;
			if (TipoCultivo == 1) Pago = this->CantVender * PRECIOTOM;
			else if (TipoCultivo == 2) Pago = this->CantVender * PRECIOZCALA;
			else Pago = this->CantVender * PRECIOZANA;
			animacionDinero(Pago);
			this->CantVender = 0;
			return true;
		}
	}
	return false;
}
void Comprador::animacionDinero(int Pago)
{
	for (int i = 1; i <= Pago; i++)
	{
		mochila->setMonedas(mochila->getMonedas() + 1);
		Sleep(20);
		DibujarElFondo();
		action();
		al_flip_display();
	}
}