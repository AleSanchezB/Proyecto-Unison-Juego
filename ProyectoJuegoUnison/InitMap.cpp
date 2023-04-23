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
	Comprador* comprador = new Comprador();

	player->IniciarDia();
	comprador->GenerarVendibles();
	while (running)
	{
		player->CambioTiempoDia(al_current_time() + 1);
		al_wait_for_event(queue, &event);
		ALLEGRO_KEYBOARD_STATE keystate;
		al_get_keyboard_state(&keystate);
		if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) break;
		else if (al_key_down(&keystate, ALLEGRO_KEY_ESCAPE))
		{
			DibujarAjustes(keystate);
		}
		else
		{
			if (event.type == ALLEGRO_EVENT_MOUSE_AXES)
			{
				if (event.mouse.x >= 18 && event.mouse.x <= 73 && event.mouse.y >= 0 && event.mouse.y <= 53) i = 1;
				else i = 0;
			}
			if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
			{
				if (event.mouse.button == 1)
				{
					if (event.mouse.x >= 18 && event.mouse.x <= 73 && event.mouse.y >= 0 && event.mouse.y <= 53)
					{
						i = 0;
						DibujarAjustes(keystate);
					}
				}
			}
			if (player->menu)
			{
				comprador->Menu(keystate, queue);
				player->menu = false;
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
				background->drawOptions(i, mochila->getMonedas(), player->getEscena());//nuevo parametro de escena
				mochila->action(player->getEscena());
				al_flip_display();
				al_clear_to_color(al_map_rgb_f(254, 254, 254));
			}
			if (player->dormir)
			{
				comprador->GenerarVendibles();
				player->dormir = false;
			}
		}
	}
	delete background;
	delete player;
	delete comprador;
}

void GameRun::ColocarMusica()
{
	//MUSICA DE AMBIENTE
	A_actual = al_load_sample("assets/Effects Sounds/sonidos naturales 2/Ambient/AmbientNatureOutside.wav");
	ambientacion = al_create_sample_instance(A_actual);
	al_set_sample_instance_playmode(ambientacion, ALLEGRO_PLAYMODE_LOOP);
	al_attach_sample_instance_to_mixer(ambientacion, al_get_default_mixer());
	al_play_sample_instance(ambientacion);
	al_set_sample_instance_gain(ambientacion, 0.4);
}

void GameRun::DibujarAjustes(ALLEGRO_KEYBOARD_STATE keystate)
{
	bool mostrar = true;
	int escena = 0;
	while (mostrar)
	{
		al_wait_for_event(queue, &event);
		ALLEGRO_KEYBOARD_STATE keystate;
		al_get_keyboard_state(&keystate);
		background->action(player->getEscena(), player->TiempoDiaEscena);
		player->action();
		if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			running = false;
			break;
		}
		else if (al_key_down(&keystate, ALLEGRO_KEY_ESCAPE)) break;
		else
		{
			if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
			{
				if (event.mouse.button == 1)
				{
					if (event.mouse.x >= 536 && event.mouse.x <= 744 && event.mouse.y >= 239 && event.mouse.y <= 294)
					{
						mostrar = false;
					}
					else if (event.mouse.x >= 536 && event.mouse.x <= 744 && event.mouse.y >= 332 && event.mouse.y <= 387)
					{

					}
					else if (event.mouse.x >= 536 && event.mouse.x <= 744 && event.mouse.y >= 423 && event.mouse.y <= 478)
					{
						running = false;
						mostrar = false;
					}
				}
			}
			if (event.type == ALLEGRO_EVENT_MOUSE_AXES)
			{
				if (event.mouse.x >= 536 && event.mouse.x <= 744 && event.mouse.y >= 239 && event.mouse.y <= 294)
				{
					escena = 1;
				}
				else if (event.mouse.x >= 536 && event.mouse.x <= 744 && event.mouse.y >= 332 && event.mouse.y <= 387)
				{
					escena = 2;
				}
				else if (event.mouse.x >= 536 && event.mouse.x <= 744 && event.mouse.y >= 423 && event.mouse.y <= 478)
				{
					escena = 3;
				}
				else escena = 0;
			}
		}
		background->drawOptions(0, mochila->getMonedas(), player->getEscena());//nuevo parametro de escena
		al_draw_bitmap(Ajustes[escena], 536, 239, 0);
		al_flip_display();
		al_clear_to_color(al_map_rgb_f(254, 254, 254));
	}
}