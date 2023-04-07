#include "MainGame.h"
using namespace std;
int main(int argc, char** argv) {
	//MainGame main = MainGame();
	bool running = true;
	al_init();
	al_init_image_addon();
	al_install_mouse();
	ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
	ALLEGRO_EVENT event;
	ALLEGRO_DISPLAY* displayGame = al_create_display(800, 600);


	al_register_event_source(queue, al_get_display_event_source(displayGame));
	Objects* ob = new Objects();
	while (running)
	{
		al_wait_for_event(queue, &event);
		ALLEGRO_KEYBOARD_STATE keystate;
		al_get_keyboard_state(&keystate);

		if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			running = false;
		}
		for (std::list<Objects*>::iterator it = instancias.begin(); it != instancias.end(); it++)
		{
			Objects* other = *it;
		}
	}
}