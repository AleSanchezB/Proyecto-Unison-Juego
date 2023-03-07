#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <math.h>
#include <string.h>

using namespace std;

const int WIDTH = 900;
const int HEIGHT = 700;
ALLEGRO_EVENT event1;
ALLEGRO_EVENT_QUEUE* evento;
ALLEGRO_DISPLAY* options;

void ia();
void menuOptions();
void destroyDisplay();
void destroyDisplay()
{
    al_destroy_display(options);
    al_destroy_event_queue(evento);
}
void menuOptions()
{
    al_init();
    options = al_create_display(300, 200);
    al_set_window_title(options, "Ventana Opciones");
    evento = al_create_event_queue();
    al_register_event_source(evento, al_get_display_event_source(options));
    bool setVisibleMenuOptiones = true;
    while (setVisibleMenuOptiones)
    {
        al_wait_for_event(evento, &event1);;
        if (event1.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        {
            setVisibleMenuOptiones = false;
            destroyDisplay();

        }
    }
}
void ia() {
    ALLEGRO_DISPLAY* display = NULL;
    ALLEGRO_EVENT_QUEUE* event_queue = NULL;
    ALLEGRO_TIMER* timer = NULL;
    float mob_x = WIDTH / 2.0;
    float mob_y = HEIGHT / 2.0;
    float player_x = WIDTH / 4.0;
    float player_y = HEIGHT / 4.0;
    float speed = 2.0;

    if (!al_init()) {
    }

    display = al_create_display(WIDTH, HEIGHT);
    if (!display) {
    }

    al_init_primitives_addon();
    al_install_keyboard();
    event_queue = al_create_event_queue();
    timer = al_create_timer(1.0 / 60.0);

    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));

    al_start_timer(timer);
    int i = 1;
    int g = 1;
    int toco = 0;
    while (true) {
        ALLEGRO_EVENT event;
        al_wait_for_event(event_queue, &event);
        ALLEGRO_KEYBOARD_STATE keystate;
        al_get_keyboard_state(&keystate);

        if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            break;
        }
        else if (event.type == ALLEGRO_EVENT_TIMER) {
            float dx = player_x - mob_x;
            float dy = player_y - mob_y;
            float dist = sqrt(dx * dx + dy * dy);

            if (dist <= 150) {
                if (al_key_down(&keystate, ALLEGRO_KEY_F) && toco == 0) {
                    toco = 1;
                   // float angle = atan2(dy, dx);
                    i = 0;
                    // mob_x += cos(angle) * speed;
                     //mob_y += sin(angle) * speed;
                    
                }
                else if (al_key_down(&keystate, ALLEGRO_KEY_F) && toco == 1) {
                    i = 1;
                    toco = 0;
                }
            }
            else if (dist > 150 && i == 0 || toco == 1) {
                i = 1;
                toco = 0;
            }
            if (mob_y < HEIGHT / 2.0 - 100 || mob_y > HEIGHT / 2.0 + 100) i = i*(-1);

             mob_y += i;
             
            
            al_clear_to_color(al_map_rgb(0, 0, 0));
            al_draw_filled_circle(mob_x, mob_y, 20, al_map_rgb(255, 0, 0));
            al_draw_filled_circle(player_x, player_y, 20, al_map_rgb(0, 255, 0));
            al_flip_display();
        }

        if (al_key_down(&keystate, ALLEGRO_KEY_S)) player_y += speed;
        if (al_key_down(&keystate, ALLEGRO_KEY_W)) player_y -= speed;
        if (al_key_down(&keystate, ALLEGRO_KEY_D)) player_x += speed;
        if (al_key_down(&keystate, ALLEGRO_KEY_A)) player_x -= speed;
    }

    al_destroy_display(display);
    al_destroy_event_queue(event_queue);
    al_destroy_timer(timer);
    al_uninstall_keyboard();

}