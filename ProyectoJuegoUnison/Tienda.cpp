#include "Tienda.h"

Tienda::Tienda()
{
	this->TipoCultivo = 1;
	this->CantVender = 0;
	this->CantComprar = 0;
	this->animacion_x = 716;
	this->animacion_y = 587;
	this->cantDig = std::log10(this->CantVender) + 1;
	this->font = al_load_font("assets/fonts/Minecraft.ttf", 18, 0);
	this->coins = al_load_bitmap("assets/animation/Paper Content Appear Animation/Folding & Cutout/8 Shop/coins2.png");
	this->MenuImg = 0;
	srand(time(NULL));
	menu[0] = al_load_bitmap("assets/Tienda/Menus/Menu0.png");
	menu[36] = al_load_bitmap("assets/Tienda/Menus/Menu1.png");
	for (int i = 35; i > 0; i--)
	{
		std::string ruta = "assets/animation/Paper Content Appear Animation/Folding & Cutout/8 Shop/" + std::to_string(i) + ".png";
		menu[i] = al_load_bitmap(ruta.c_str());
		assert(menu[i] != NULL);
	}

	for (int i = 0; i < 2; i++)
	{
		btnflechaArriba[i] = new Boton("assets/Tienda/botones/MenuVenta/btnArriba0.png", 680, 462 + 68 * (i % 2), 22, 18);
		btnflechaArriba[i + 2] = new Boton("assets/Tienda/botones/MenuVenta/btnArriba1.png", 680, 462 + 68 * (i % 2), 22, 18);

		btnflechaAbajo[i] = new Boton("assets/Tienda/botones/MenuVenta/btnAbajo0.png", 680, 488 + 68 * (i % 2), 22, 18);
		btnflechaAbajo[i + 2] = new Boton("assets/Tienda/botones/MenuVenta/btnAbajo1.png", 680, 488 + 68 * (i % 2), 22, 18);

		btnSalir[i] = new Boton("assets/Tienda/botones/MenuVenta/btnSalir" + std::to_string(i) + ".png", 872, 67, 38, 38);
		botones[i] = new Boton("assets/Tienda/botones/MenuVenta/" + std::to_string(i) + ".png", 716, 587, 118, 39);
		botones[i + 2] = new Boton("assets/Tienda/botones/MenuVenta/" + std::to_string(i + 2) + ".png", 716, 587, 118, 39);
	}
}
Tienda::~Tienda()
{
	for (int i = 0; i < 36; i++)
	{
		al_destroy_bitmap(menu[i]);
	}
	for (int i = 0; i < 2; i++)
	{
		delete btnflechaArriba[i];
		delete btnflechaArriba[i + 2];

		delete btnflechaAbajo[i];
		delete btnflechaAbajo[i + 2];

		delete btnSalir[i];
		delete botones[i];
	}
}
void Tienda::MenuVenderCultivos(ALLEGRO_KEYBOARD_STATE keystate, ALLEGRO_EVENT_QUEUE* queue)
{
	ALLEGRO_EVENT events;
	al_get_keyboard_state(&keystate);
	animacionMenu();
	int btnCult = 0;
	int btnCant = 0;

	int btnCultB = 0;
	int btnCantB = 0;

	int btnExit = 0;
	int btnVen = 0;
	bool salir = true;
	this->CantVender = 0;
	this->MenuImg = 0;
	this->TipoCultivo = 1;
	while (!al_key_down(&keystate, ALLEGRO_KEY_ESCAPE) && salir)
	{
		al_get_keyboard_state(&keystate);
		al_wait_for_event(queue, &events);
		DibujarFondo();
		if (events.type == ALLEGRO_EVENT_DISPLAY_CLOSE) break;
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
			if (events.mouse.x >= botones[1]->x && events.mouse.x <= botones[1]->x + botones[1]->w
				&& events.mouse.y >= botones[1]->y && events.mouse.y <= botones[1]->y + botones[1]->h)
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
					{
						if (events.mouse.button == 1)
						{
							if (this->TipoCultivo == 1) this->TipoCultivo = 1;
							else this->TipoCultivo--;
						}
					}
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
				if (events.mouse.x >= botones[1]->x && events.mouse.x <= botones[1]->x + botones[1]->w
					&& events.mouse.y >= botones[1]->y && events.mouse.y <= botones[1]->y + botones[1]->h)
				{
					btnVen = 1;
					if (mochila->verificacionMochila() &&
						mochila->verificarCantidadCultivosGuardados(vendibles[this->TipoCultivo - 1], this->CantVender))
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
void Tienda::MenuComprarCultivos(ALLEGRO_KEYBOARD_STATE keystate, ALLEGRO_EVENT_QUEUE* queue)
{
	ALLEGRO_EVENT events;
	al_get_keyboard_state(&keystate);
	animacionMenu();
	int btnCult = 0;
	int btnCant = 0;

	int btnCultB = 0;
	int btnCantB = 0;

	int btnExit = 0;
	int btnVen = 2;
	bool salir = true;

	this->MenuImg = 36;
	this->TipoCultivo = 1;
	this->CantComprar = 0;

	while (!al_key_down(&keystate, ALLEGRO_KEY_ESCAPE) && salir)
	{
		al_get_keyboard_state(&keystate);
		al_wait_for_event(queue, &events);
		DibujarFondo();
		if (events.type == ALLEGRO_EVENT_DISPLAY_CLOSE) break;
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
			if (events.mouse.x >= botones[1]->x && events.mouse.x <= botones[1]->x + botones[1]->w
				&& events.mouse.y >= botones[1]->y && events.mouse.y <= botones[1]->y + botones[1]->h)
			{
				btnVen = 3;
			}
			else btnVen = 2;

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
					{
						if (events.mouse.button == 1)
						{
							if (this->TipoCultivo == 1) this->TipoCultivo = 1;
							else this->TipoCultivo--;
						}
					}
				}
				else btnCultB = 0;

				////boton para seleccionar cantidad de cultivo
				if (events.mouse.x >= btnflechaArriba[1]->x && events.mouse.x <= btnflechaArriba[1]->x + btnflechaArriba[1]->w
					&& events.mouse.y >= btnflechaArriba[1]->y && events.mouse.y <= btnflechaArriba[1]->y + btnflechaArriba[1]->h)
				{
					btnCant = 3;
					if (events.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
					{
						if (events.mouse.button == 1)
							this->CantComprar++;
					}
				}
				else btnCant = 1;

				if (events.mouse.x >= btnflechaAbajo[1]->x && events.mouse.x <= btnflechaAbajo[1]->x + btnflechaAbajo[1]->w
					&& events.mouse.y >= btnflechaAbajo[1]->y && events.mouse.y <= btnflechaAbajo[1]->y + btnflechaAbajo[1]->h)
				{
					btnCantB = 3;
					if (this->CantComprar == 0) this->CantComprar = 0;
					else this->CantComprar--;
				}
				else btnCantB = 1;

				//boton de vender
				if (events.mouse.x >= botones[1]->x && events.mouse.x <= botones[1]->x + botones[1]->w
					&& events.mouse.y >= botones[1]->y && events.mouse.y <= botones[1]->y + botones[1]->h)
				{
					btnVen = 3;

					if (VerificarCompra())
					{
						cantDig = 0;
						this->CantComprar = 0;
					}

				}
				else btnVen = 2;

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
	}
	AnimacionReversa();
}
void Tienda::animacionMenu()
{
	for (int i = 35; i >= 0; i--)
	{
		Sleep(60);
		background->action(player->getEscena() + player->TiempoDiaEscena, 0);
		background->drawOptions(0, mochila->getMonedas(), player->getEscena());//nuevo parametro escena
		player->action();
		al_draw_bitmap(menu[i], 0, 0, 0);
		al_flip_display();
		al_clear_to_color(al_map_rgb_f(255, 255, 255));
	}
}
void Tienda::action(int btnCult, int btnCant, int btnCultB, int btnCantB, int btnExit, int btnVen)
{
	btnflechaArriba[btnCult]->action();
	btnflechaArriba[btnCant]->action();

	btnflechaAbajo[btnCultB]->action();
	btnflechaAbajo[btnCantB]->action();

	btnSalir[btnExit]->action();
	botones[btnVen]->action();
}
void Tienda::DibujarFondo()
{
	background->action(player->getEscena() + player->TiempoDiaEscena, 0);
	player->action();
	background->drawOptions(0, mochila->getMonedas(), player->getEscena());//nuevo parametro de escena
	al_draw_bitmap(menu[this->MenuImg], 0, 0, 0);
	DibujarPrecios();
	DibujarCantidadSelec();
}
void Tienda::DibujarPrecios()
{
	if (player->MenuVenderCultivos)
		for (int i = 0; i < 3; i++)
		{
			al_draw_text(this->font, al_map_rgb(0, 0, 0), 425.3, 251 + 74 * i, 0, MensajeVendibles[i].c_str());
		}
	else
		for (int i = 0; i < 3; i++)
		{
			al_draw_text(this->font, al_map_rgb(0, 0, 0), 425.3, 251 + 74 * i, 0, MensajeComprables[i].c_str());
		}
}
void Tienda::DibujarCantidadSelec()
{
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
	if (player->MenuComprarCultivos) this->CantVender = this->CantComprar;
	al_draw_text(background->font, al_map_rgb(0, 0, 0), xVenta, 546, 0, (std::to_string(this->CantVender)).c_str());
}
void Tienda::AnimacionReversa()
{
	for (int i = 1; i <= 35; i++)
	{
		Sleep(60);
		background->action(player->getEscena() + player->TiempoDiaEscena, 0);
		background->drawOptions(0, mochila->getMonedas(), player->getEscena()); //nuevo parametro de escena
		player->action();
		al_draw_bitmap(menu[i], 0, 0, 0);
		al_flip_display();
		al_clear_to_color(al_map_rgb_f(255, 255, 255));
	}
}

void Tienda::animacionDinero(int Pago)
{
	if (player->MenuVenderCultivos)
		for (int i = 1; i <= Pago; i++)
		{
			mochila->setMonedas(mochila->getMonedas() + 1);
			Sleep(20);
			DibujarFondo();
			action(0, 1, 0, 1, 0, 2);
			al_flip_display();
		}
	else
		for (int i = Pago; i > 0; i--)
		{
			mochila->setMonedas(mochila->getMonedas() - 1);
			Sleep(20);
			DibujarFondo();
			action(0,1,0,1,0,3);
			al_flip_display();
		}

}
void Tienda::animacionMonedas()
{
	while (animacion_y > 90)
	{
		for (int i = 0; i < 8; i++)
		{
			Sleep(60);
			DibujarFondo();
			action();
			DibujarCantidadSelec();
			al_draw_bitmap_region(coins, 31 * i, 0, 31, 31, animacion_x, animacion_y, 0);
			al_flip_display();
			al_clear_to_color(al_map_rgb_f(255, 255, 255));
			animacion_x += 5;
			animacion_y = 0.001261 * std::pow(animacion_x, 2) - 4.1391 * animacion_x + 2903.71;
		}
	}
	DibujarFondo();
	action();
	al_draw_bitmap_region(coins, 0, 0, 31, 31, 988, 25, 0);
	al_flip_display();
	animacion_x = 716;
	animacion_y = 587;
}
bool Tienda::VerificarVenta()
{
	if (mochila->verificacionMochila())
	{
		if (mochila->verificarCantidadCultivosGuardados(vendibles[this->TipoCultivo - 1], this->CantVender))
		{
			mochila->quitarCultivo(vendibles[this->TipoCultivo - 1]);
			mochila->setCantidadCultivos(mochila->getCantidadCultivos() - this->CantVender);
			int Pago = 0;

			switch (vendibles[this->TipoCultivo - 1])
			{
			case 0: //tomate
				Pago = this->CantVender * precios[0];
				break;
			case 1: //calabaza
				Pago = this->CantVender * precios[1];
				break;
			case 2: //zanahoria
				Pago = this->CantVender * precios[2];
				break;
			case 3: //berenjena
				Pago = this->CantVender * precios[3];
				break;
			case 4: //ejotes
				Pago = this->CantVender * precios[4];
				break;
			case 5: //maiz
				Pago = this->CantVender * precios[5];
				break;
			case 6: //papa
				Pago = this->CantVender * precios[6];
				break;
			case 7: //papaya
				Pago = this->CantVender * precios[7];
				break;
			case 8: //remolacha
				Pago = this->CantVender * precios[8];
			default:
				break;
			}
			animacionDinero(Pago);
			this->CantVender = 0;
			return true;
		}
	}
	return false;
}

bool Tienda::VerificarCompra()
{
	if (mochila->getMonedas() >= precios[comprables[this->TipoCultivo - 1]] && this->CantComprar > 0 && !mochila->verificarCapacidadMochila(this->CantComprar))
	{
		mochila->setCantidadTipoCultivos(mochila->getCantidadTipoCultivo(comprables[this->TipoCultivo - 1]) + this->CantVender, comprables[this->TipoCultivo - 1]);
		mochila->setCantidadCultivos(mochila->getCantidadCultivos() + this->CantVender);
		animacionDinero(this->CantComprar * precios[comprables[this->TipoCultivo - 1]]);
		return true;
	}
	return false;
}

void Tienda::GenerarVendibles()
{
	int aleatorio;
	int indices[3];
	std::string aux;
	for (int i = 0; i < 3; i++)
	{
		do {
			aleatorio = rand() % 9;
			indices[i] = aleatorio;
		} while (std::find((int*)indices, indices + i, aleatorio) != indices + i);
		this->MensajeVendibles[i] = cultivos[aleatorio];
		vendibles[i] = aleatorio;
	}
}
void Tienda::GenerarComprables()
{
	int aleatorio;
	int indices[3];
	std::string aux;
	Sleep(100);

	for (int i = 0; i < 3; i++)
	{
		do {
			aleatorio = rand() % 9;
			indices[i] = aleatorio;
		} while (std::find(indices, indices + i, aleatorio) != indices + i);
		this->MensajeComprables[i] = cultivos[aleatorio];
		comprables[i] = aleatorio;
	}
}
void Tienda::Sleep(int segundos)
{
	int i = 0;
	int finespera = 300000 * segundos;

	while (i < finespera)
	{
		i++;
	}
}