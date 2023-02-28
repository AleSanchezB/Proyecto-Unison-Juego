#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <iostream>
#include <string.h>
#include "InitiMap.h"
#include "IAMobs.h"

using namespace std;

//DECLARACION DE VARIABLES ALLEGRO
ALLEGRO_DISPLAY* menu;
ALLEGRO_BITMAP* icon = NULL;
ALLEGRO_EVENT_QUEUE* queueE;
ALLEGRO_EVENT_QUEUE* aux;
ALLEGRO_FONT* fontInit;
ALLEGRO_KEYBOARD_STATE keystate2;
ALLEGRO_EVENT event;

//CLASES


//VARIABLES
bool run;
int x, y;

//CONSTANTES
const int W = 800, H = 600;

//FUNCIONES
void initMenu();
void drawOptions();
void initVars();
void destroy();

void initVars()
{
    icon = al_load_bitmap("assets/Sprites Players/NO SE USARA/PNG/IdleTam/frame01.png");
    fontInit = al_load_font("assets/fonts/Minecraft.ttf", 20, 0);
    al_set_window_title(menu, "Ventana Inicio");
    queueE = al_create_event_queue();
    run = true;
}

void initMenu() {
    menu = al_create_display(W, H);
    al_install_keyboard();
    al_install_mouse();
    al_init_image_addon();
    al_init_font_addon();
    al_init_ttf_addon();
    initVars(); //inicializa las variables
    queueE = al_create_event_queue();
    al_set_display_icon(menu, icon);
    // Registrar del display como fuente de eventos
    al_register_event_source(queueE, al_get_display_event_source(menu));
    al_register_event_source(queueE, al_get_keyboard_event_source());
    al_register_event_source(queueE, al_get_mouse_event_source());
}

int main(int argc, char** argv) {
    al_init();
    initMenu(); //crea la pantalla y registra los eventos    
    // Bucle del juego
    while (run) 
    {
        al_wait_for_event(queueE, &event);
        // Dibujar el menú
        drawOptions();
        if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        {
            run = false;
            destroy();
        }
        if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
        {
            if (event.mouse.button == 1)
            {
                //obtengo las coords del puntero del mouse
                x = event.mouse.x;
                y = event.mouse.y;

                if (x <= W / 2 + 30 && x >= W / 2 - 40 && y >= H / 2 - 35 && y <= H / 2 - 15)
                {
                    printf("Jugar");
                    run = false;
                    destroy();
                    Mapa1 mapa1 = Mapa1();
                }
                if (x <= W / 2 + 30 && x >= W / 2 - 40 && y >= H / 2 && y <= H / 2 + 30)
                {
                    aux = queueE;
                    printf("Opciones");
                    menuOptions();
                    initVars();
                    queueE = aux;
                }
                if (x <= W / 2 + 30 && x >= W / 2 - 40 && y >= H / 2 + 35 && y <= H / 2 + 55)
                {
                    printf("Salir");
                    run = false;
                    destroy();
                }

            }
        }
    }
}
void destroy() {
    al_destroy_display(menu);
    al_destroy_font(fontInit);
    al_destroy_event_queue(queueE);
    al_uninstall_keyboard();
    al_uninstall_mouse();
}
void drawOptions() {
    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_draw_text(fontInit, al_map_rgb(255, 255, 255), W / 2, H / 2 - 32, ALLEGRO_ALIGN_CENTER, "Jugar");
    al_draw_text(fontInit, al_map_rgb(255, 255, 255), W / 2, H / 2, ALLEGRO_ALIGN_CENTER, "Opciones");
    al_draw_text(fontInit, al_map_rgb(255, 255, 255), W / 2, H / 2 + 32, ALLEGRO_ALIGN_CENTER, "Salir");
    al_flip_display();
}