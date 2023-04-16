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

	al_get_display_mode(al_get_num_display_modes() - 1, &disp_data);
	w = disp_data.width;
	h = disp_data.height;
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
	while (running)
	{
		player->CambioTiempoDia(al_current_time() + 1);
		al_wait_for_event(queue, &event);
		ALLEGRO_KEYBOARD_STATE keystate;
		al_get_keyboard_state(&keystate);
		if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) running = false;
		else if (event.type == ALLEGRO_EVENT_MOUSE_AXES)
		{
			if (event.mouse.x >= 18 && event.mouse.x <= 73 && event.mouse.y >= 0 && event.mouse.y <= 53) i = 1;
			else i = 0;
		}
		if (al_key_down(&keystate, ALLEGRO_KEY_E))
		{
			comprador->Menu(keystate, queue);
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
			background->drawOptions(i, mochila->getMonedas());
			mochila->action();
			al_flip_display();
			al_clear_to_color(al_map_rgb_f(254, 254, 254));
		}
	}
	delete background, player, comprador;
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

void GameRun::DibujarGradualmente()
{
	////al_clear_to_color(al_map_rgb(0, 0, 0));
	////al_draw_tinted_bitmap(ESCENA1, al_map_rgba_f(1.0, 1.0, 1.0, alpha), 0, 0, 0);
	//al_draw_rectangle(0, 0, 1280, 720, al_map_rgba_f(0, 0, 0, 0), NULL);
	////al_draw_tinted_bitmap(ESCENA2, al_map_rgba_f(1.0, 1.0, 1.0, 1.0 - alpha), 0, 0, 0);

	//// Cambiar gradualmente el nivel de opacidad de las imágenes
	//alpha -= 0.01;
	//if (alpha <= 0) {
	//	alpha = 1.0;
	//	//ALLEGRO_BITMAP* temp = ESCENA1;
	//	//ESCENA1 = ESCENA2;
	//	//ESCENA2 = temp;
	//}

	//// Actualizar la pantalla
	//al_flip_display();
}