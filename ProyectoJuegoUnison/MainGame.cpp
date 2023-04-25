#include "MainGame.h"

MainGame::MainGame()
{
	al_init();
	al_install_keyboard();
	al_install_mouse();
	al_install_audio();
	al_init_acodec_addon();
	al_reserve_samples(2);
	al_init_image_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	initMenu();
	gameRun();
}

MainGame::~MainGame()
{
	for (int i = 0; i < 4; i++)
	{
		al_destroy_bitmap(fondos[i]);
	}
	for (int i = 0; i < 8; i++)
	{
		al_destroy_bitmap(Instrucciones[i]);
	}
	for (int i = 0; i < 3; i++)
	{
		al_destroy_bitmap(btn[i]);
	}
}

void MainGame::gameRun()
{
	float volume = 0.5;
	int i = 0;
	//Inicia la musica en loop
	al_play_sample_instance(songInstance);
	al_set_sample_instance_gain(songInstance, volume);
	dibujarMenu(0);

	// Bucle del juego
	while (running)
	{
		al_wait_for_event(queue, &event);
		// Dibujar el menú
		if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			running = false;
			alDestroy();
		}
		if (event.type == ALLEGRO_EVENT_MOUSE_AXES)
		{
			if (event.mouse.x >= 539 && event.mouse.x <= 743 && event.mouse.y >= 282 && event.mouse.y <= 337)
			{
				i = 1;
			}
			else if (event.mouse.x >= 539 && event.mouse.x <= 743 && event.mouse.y >= 375 && event.mouse.y <= 430)
			{
				i = 2;
			}
			else if (event.mouse.x >= 539 && event.mouse.x <= 743 && event.mouse.y >= 466 && event.mouse.y <= 521)
			{
				i = 3;
			}
			else
			{
				i = 0;
			}
		}
		if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
		{
			if (event.mouse.button == 1)
			{
				click();
				//obtengo las coords del puntero del mouse
				mouseX = event.mouse.x;
				mouseY = event.mouse.y;
				if (event.mouse.x >= 539 && event.mouse.x <= 743 && event.mouse.y >= 282 && event.mouse.y <= 337)
				{
					running = false;
					alDestroy();
					GameRun mapa1 = GameRun();
				}
				else if (event.mouse.x >= 539 && event.mouse.x <= 743 && event.mouse.y >= 375 && event.mouse.y <= 430)
				{
					i = 0;
					dibujarInstrucciones();
				}
				else if (event.mouse.x >= 539 && event.mouse.x <= 743 && event.mouse.y >= 466 && event.mouse.y <= 521)
				{
					running = false;
					alDestroy();
				}
			}
		}
		dibujarMenu(i);
	}
}
void MainGame::iniciarVariables()
{
	iconDisplay = al_load_bitmap("assets/fondos/Icono/Icono.png");
	for (int i = 0; i < 4; i++)
	{
		string ruta = "assets/fondos/imgLogin/" + to_string(i) + ".png";
		fondos[i] = al_load_bitmap(ruta.c_str());
	}
	for (int i = 0; i < 8; i++)
	{
		Instrucciones[i] = al_load_bitmap(("assets/fondos/Ajustes/" + to_string(i) + ".png").c_str());
	}
	for (int i = 0; i < 3; i++)
	{
		btn[i] = al_load_bitmap(("assets/fondos/Ajustes/B" + to_string(i) + ".png").c_str());
	}
	fontMenu = al_load_font("assets/fonts/Minecraft.ttf", 20, 0);

	//Carga la musica
	sample = al_load_sample("assets/Musica/Musica.ogg");
	songInstance = al_create_sample_instance(sample);

	efectClick = al_load_sample("assets/Effects Sounds/Menu_Selection_Click.wav");
	efectClickInstance = al_create_sample_instance(efectClick);

	//Seteo la musica en loop
	al_set_sample_instance_playmode(songInstance, ALLEGRO_PLAYMODE_LOOP);
	al_attach_sample_instance_to_mixer(songInstance, al_get_default_mixer());

	al_set_sample_instance_playmode(efectClickInstance, ALLEGRO_PLAYMODE_ONCE);
	al_attach_sample_instance_to_mixer(efectClickInstance, al_get_default_mixer());

	al_set_window_title(firstDisplay, "Agromania");
	queue = al_create_event_queue();

	running = true;
}
void MainGame::initMenu()
{
	firstDisplay = al_create_display(W, H);

	//inicializa las variables
	iniciarVariables();
	queue = al_create_event_queue();
	al_set_display_icon(firstDisplay, iconDisplay);

	// Registrar del display como fuente de eventos
	al_register_event_source(queue, al_get_display_event_source(firstDisplay));
	al_register_event_source(queue, al_get_keyboard_event_source());
	al_register_event_source(queue, al_get_mouse_event_source());
}
void MainGame::dibujarMenu(int i)
{
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_draw_bitmap(fondos[i], 0, 0, 0);
	al_flip_display();
}
void MainGame::alDestroy()
{
	al_destroy_display(firstDisplay);
	al_destroy_font(fontMenu);
	al_destroy_event_queue(queue);
	al_uninstall_keyboard();
	al_uninstall_mouse();
	al_destroy_sample(sample);
	al_destroy_sample_instance(songInstance);
}
void MainGame::setVolMusic(float volumen)
{
	al_set_sample_instance_gain(songInstance, volumen);
}
void MainGame::click()
{
	al_stop_sample(&idClickEffect);
	al_play_sample(efectClick, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, &idClickEffect);
}
void MainGame::dibujarInstrucciones()
{
	bool run = true;
	int i = 0, j = 0;
	while (run)
	{
		al_clear_to_color(al_map_rgb(0, 0, 0));
		al_draw_bitmap(Instrucciones[i], 0, 0, 0);
		al_draw_bitmap(btn[j], 1037, 666, 0);
		al_flip_display();
		al_wait_for_event(queue, &event);
		// Dibujar el menú
		if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			running = false;
			break;
		}
		if (event.type == ALLEGRO_EVENT_MOUSE_AXES)
		{
			if (event.mouse.x >= 1037 && event.mouse.x <= 1134 && event.mouse.y >= 666 && event.mouse.y <= 710)
			{
				j = 1;
			}
			else if (event.mouse.x >= 1145 && event.mouse.x <= 1242 && event.mouse.y >= 666 && event.mouse.y <= 710)
			{
				j = 2;
			}
			else
			{
				j = 0;
			}
		}
		if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
		{
			if (event.mouse.button == 1)
			{
				click();
				if (event.mouse.x >= 1037 && event.mouse.x <= 1134 && event.mouse.y >= 666 && event.mouse.y <= 710)
				{
					if (i > 0)
						i--;
				}
				else if (event.mouse.x >= 1145 && event.mouse.x <= 1242 && event.mouse.y >= 666 && event.mouse.y <= 710)
				{
					if (i > 6) run = false;
					else i++;
				}
			}
		}
	}
}