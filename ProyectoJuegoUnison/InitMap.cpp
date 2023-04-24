#include "InitiMap.h"

Background* background;
Player* player;

GameRun::GameRun()
{
	al_init();
	al_init_image_addon();
	al_install_mouse();
	al_install_keyboard();
	al_init_font_addon();
	al_init_ttf_addon();
	running = true;

	for (int i = 0; i < 4; i++)
	{
		std::string ruta = "assets/fondos/Ajustes/" + std::to_string(i) + ".png";
		Ajustes[i] = al_load_bitmap(ruta.c_str());
	}
	displayGame = al_create_display(width, height);
	al_set_window_title(displayGame, "Agromania");
	iconDisplay = al_load_bitmap("assets/fondos/Icono/Icono.png");
	//cola de eventos
	queue = al_create_event_queue();

	//Timer e inicio del timer
	timer = al_create_timer(1.0 / FPS);

	//Registro de eventos
	al_register_event_source(queue, al_get_display_event_source(displayGame));
	al_register_event_source(queue, al_get_keyboard_event_source());
	al_register_event_source(queue, al_get_timer_event_source(timer));
	al_register_event_source(queue, al_get_mouse_event_source());
	al_set_display_icon(displayGame, iconDisplay);
	ColocarMusica();
	al_start_timer(timer);
	initGame();
}
GameRun::~GameRun()
{
	al_destroy_display(displayGame);
	al_destroy_timer(timer);
	al_uninstall_keyboard();
	al_destroy_event_queue(queue);
	al_destroy_sample(A_actual);
	al_destroy_sample_instance(ambientacion);
	al_uninstall_audio();
	al_uninstall_mouse();
}

void GameRun::initGame()
{
	player = new Player("assets/Player/Sprites Players/characters/Walk_run Player2.png");
	background = new Background();
	Tienda* tienda = new Tienda();
	int muteado = 0;
	player->IniciarDia();
	tienda->GenerarVendibles();
	tienda->GenerarComprables();
	while (running)
	{
		player->CambioTiempoDia(al_current_time() + 1);
		al_wait_for_event(queue, &event);
		ALLEGRO_KEYBOARD_STATE keystate;
		al_get_keyboard_state(&keystate);
		if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) break;
		else
		{
			if (event.type == ALLEGRO_EVENT_MOUSE_AXES)
			{
				if (event.mouse.x >= 18 && event.mouse.x <= 73 && event.mouse.y >= 0 && event.mouse.y <= 53) sonido = NORMALSELE + muteado;
				else sonido = NORMAL + muteado;
			}
			if (player->MenuVenderCultivos)
			{
				tienda->MenuVenderCultivos(keystate, queue);
				player->MenuVenderCultivos = false;
			}
			else if (player->MenuComprarCultivos)
			{
				tienda->MenuComprarCultivos(keystate, queue);
				player->MenuComprarCultivos = false;
			}
			if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
			{
				if (event.mouse.button == 1)
				{
					if (event.mouse.x >= 18 && event.mouse.x <= 73 && event.mouse.y >= 0 && event.mouse.y <= 53)
					{
						if (sonido == NORMAL || sonido == NORMALSELE)
						{
							muteado = 2;
							setVolumen(0);
						}
						else
						{
							muteado = 0;
							setVolumen(1.5f);
						}
					}
				}
			}
			background->action(player->getEscena(), player->TiempoDiaEscena);
			if (event.type == ALLEGRO_EVENT_TIMER)
			{
				player->action(keystate, queue);
				draw = true;
			}
			if (draw)
			{
				draw = false;
				background->dibujarEncima(player->getEscena(), player->TiempoDiaEscena);
				background->drawOptions(sonido, mochila->getMonedas(), player->getEscena());//nuevo parametro de escena
				mochila->action(player->getEscena());
				al_flip_display();
				al_clear_to_color(al_map_rgb_f(254, 254, 254));
			}
			if (player->dormir)
			{
				tienda->GenerarVendibles();
				tienda->GenerarComprables();
				player->dormir = false;
			}
		}
	}
	player->guardar_datos_mochila_en_archivo();
	GuardarCultivos();
	delete background;
	delete player;
	delete tienda;
}
void GameRun::ColocarMusica()
{
	//MUSICA DE AMBIENTE
	A_actual = al_load_sample("assets/Effects Sounds/sonidos naturales 2/Ambient/AmbientNatureOutside.wav");
	ambientacion = al_create_sample_instance(A_actual);
	al_set_sample_instance_playmode(ambientacion, ALLEGRO_PLAYMODE_LOOP);
	al_attach_sample_instance_to_mixer(ambientacion, al_get_default_mixer());
	al_play_sample_instance(ambientacion);
	al_set_sample_instance_gain(ambientacion, 1.5f);
}
void GameRun::setVolumen(int volumen)
{
	al_set_sample_instance_gain(ambientacion, volumen);
}

int GameRun::getVolumen()
{
	return this->volumen;
}