#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

using namespace std;

class ControlarCultivos
{
public:
	ControlarCultivos();
	~ControlarCultivos();
    void plantarCultivo(ALLEGRO_KEYBOARD_STATE keystate, ALLEGRO_EVENT_QUEUE* queue);
private:
	const float COOLDOWN_TIME = 0.7f;
	float last_time_pressed = 0.0f;
    ALLEGRO_EVENT event;
};

ControlarCultivos::ControlarCultivos()
{
}

ControlarCultivos::~ControlarCultivos()
{
}

void ControlarCultivos::plantarCultivo(ALLEGRO_KEYBOARD_STATE keystate, ALLEGRO_EVENT_QUEUE* queue)
{
    al_wait_for_event(queue, &event);
    if (event.type == ALLEGRO_EVENT_KEY_CHAR)
    {
        float current_time = al_get_time();

        if (current_time - last_time_pressed >= COOLDOWN_TIME)
        {
            // aquí va el código para la acción a realizar al presionar la tecla
            cout << "Tecla presionada!" << endl;
            last_time_pressed = current_time;
        }
    }
}