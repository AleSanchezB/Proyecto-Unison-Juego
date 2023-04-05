#include "InitiMap.h"

GameRun::GameRun()
{
	al_init();
	al_init_image_addon();
	al_install_mouse();
	al_install_keyboard();
	al_init_font_addon();
	al_init_ttf_addon();
	al_init_primitives_addon();
	running = true;

	al_set_new_display_flags(ALLEGRO_RESIZABLE);

	displayGame = al_create_display(width, height);
	al_set_window_title(displayGame, "Juego version Beta");

	//cola de eventos
	queue = al_create_event_queue();

	//Timer e incio del timer
	_timer = al_create_timer(1.0 / 120);
	al_start_timer(_timer);

	//Registro de eventos
	al_register_event_source(queue, al_get_display_event_source(displayGame));
	al_register_event_source(queue, al_get_keyboard_event_source());
	al_register_event_source(queue, al_get_timer_event_source(_timer));
	al_register_event_source(queue, al_get_mouse_event_source());
	ColocarMusica();
	initGame();
}
GameRun::~GameRun()
{
	al_destroy_display(displayGame);
	al_destroy_timer(_timer);
	al_uninstall_keyboard();
}

void GameRun::initGame()
{
	Player* player = new Player("assets/IdleTam/Sprites Players/characters/Walk_run Player.png");
	DrawObjects* drawPlayer = new DrawObjects();
	//cultivos.push_back(new Cultivo("assets/Basic Plants.png", 5, 10, 0));
	while (running)
	{
		al_wait_for_event(queue, &event);
		ALLEGRO_KEYBOARD_STATE keystate;
		al_get_keyboard_state(&keystate);

		if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) running = false;
		else if (event.type == ALLEGRO_EVENT_MOUSE_AXES) 
		{
			if (event.mouse.x >= 18 && event.mouse.x <= 73 && event.mouse.y >= 0 && event.mouse.y <= 53) i = 1;
			else i = 0;
		}
		al_clear_to_color(al_map_rgb_f(254, 254, 254));
		drawPlayer->DrawBackgrounds(player->getEscena());
		player->action(keystate, queue);
		drawPlayer->drawOptions(i, 900);
		al_flip_display();
	}
}
void GameRun::ColocarMusica() {
	//MUSICA DE AMBIENTE
	A_actual = al_load_sample("assets/Effects Sounds/sonidos naturales 2/Ambient/AmbientNatureOutside.wav");
	ambientacion = al_create_sample_instance(A_actual);
	al_set_sample_instance_playmode(ambientacion, ALLEGRO_PLAYMODE_LOOP);
	al_attach_sample_instance_to_mixer(ambientacion, al_get_default_mixer());
	al_play_sample_instance(ambientacion);
	al_set_sample_instance_gain(ambientacion, 0.4);
}
void GameRun::DibujarGradualmente()
{
	al_clear_to_color(al_map_rgb(0, 0, 0));
	//al_draw_tinted_bitmap(ESCENA1, al_map_rgba_f(1.0, 1.0, 1.0, alpha), 0, 0, 0);
	al_draw_rectangle(0, 0, 1280, 720, al_map_rgba_f(0, 0, 0, 0), NULL);
	//al_draw_tinted_bitmap(ESCENA2, al_map_rgba_f(1.0, 1.0, 1.0, 1.0 - alpha), 0, 0, 0);

	// Cambiar gradualmente el nivel de opacidad de las imágenes
	alpha -= 0.01;
	if (alpha <= 0) {
		alpha = 1.0;
		//ALLEGRO_BITMAP* temp = ESCENA1;
		//ESCENA1 = ESCENA2;
		//ESCENA2 = temp;
	}

	// Actualizar la pantalla
	al_flip_display();
}