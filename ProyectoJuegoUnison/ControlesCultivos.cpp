#include "controlesCultivos.h"
#include <iostream>

ControlarCultivos::ControlarCultivos()
{
}

ControlarCultivos::~ControlarCultivos()
{
}

void ControlarCultivos::plantarCultivo(ALLEGRO_KEYBOARD_STATE keystate, ALLEGRO_EVENT_QUEUE* queue)
{
    ALLEGRO_EVENT event;
    al_wait_for_event(queue, &event);
    if (event.type == ALLEGRO_EVENT_KEY_CHAR)
    {
        float current_time = al_get_time();

        if (current_time - last_time_pressed >= COOLDOWN_TIME)
        {
            // aqu� va el c�digo para la acci�n a realizar al presionar la tecla
            std::cout << "Tecla presionada!" << std::endl;
            last_time_pressed = current_time;
            cultivos++;
            if (cultivos == 1)
            {
                CultivoUno cv = CultivoUno();
            }
        }
    }
}