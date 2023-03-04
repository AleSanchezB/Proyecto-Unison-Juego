#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <iostream>
#include <string.h>
#include "InitiMap.h"
#include "SubmenuOptions.h"

using namespace std;


class MainGame : public SubMenuOptions
{
public:
    MainGame();
    ~MainGame();
    ALLEGRO_DISPLAY* firstDisplay;

private:
    //DECLARACION DE VARIABLES ALLEGRO
    ALLEGRO_BITMAP* iconDisplay = NULL;
    ALLEGRO_EVENT_QUEUE* queue;
    ALLEGRO_FONT* fontMenu;
    ALLEGRO_EVENT event;
    Panel panelOptions;
    //VARIABLES
    bool running;
    int mouseX, mouseY;

    //CONSTANTES
    const int W = 800, H = 600;

    //FUNCIONES
    void initMenu();
    void drawOptions();
    void initVars();
    void gameRun();

};

MainGame::MainGame()
{
    al_init();
    al_install_keyboard();
    al_install_mouse();
    al_init_image_addon();
    al_init_font_addon();
    al_init_ttf_addon();
    initMenu();
    gameRun();
}

MainGame::~MainGame()
{
    al_destroy_display(firstDisplay);
    al_destroy_font(fontMenu);
    al_destroy_event_queue(queue);
    al_uninstall_keyboard();
    al_uninstall_mouse();
}

void MainGame::initVars()
{
    iconDisplay = al_load_bitmap("assets/Sprites Players/NO SE USARA/PNG/IdleTam/frame01.png");
    fontMenu = al_load_font("assets/fonts/Minecraft.ttf", 20, 0);
    al_set_window_title(firstDisplay, "Ventana Inicio");
    queue = al_create_event_queue();
    running = true;
}

void MainGame::initMenu() {
    firstDisplay = al_create_display(W, H);

    //inicializa las variables
    initVars();
    queue = al_create_event_queue();
    al_set_display_icon(firstDisplay, iconDisplay);

    // Registrar del display como fuente de eventos
    al_register_event_source(queue, al_get_display_event_source(firstDisplay));
    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_mouse_event_source());
}

void MainGame::gameRun()
{
    // Bucle del juego
    while (running)
    {
        al_wait_for_event(queue, &event);
        // Dibujar el menú
        drawOptions();
        if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        {
            running = false;
        }
        if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
        {
            if (event.mouse.button == 1)
            {
                //obtengo las coords del puntero del mouse
                mouseX = event.mouse.x;
                mouseY = event.mouse.y;

                if (mouseX <= W / 2 + 30 && mouseX >= W / 2 - 40 && mouseY >= H / 2 - 35 && mouseY <= H / 2 - 15)
                {
                    printf("Jugar");
                    running = false;
                    Mapa1 mapa1 = Mapa1();
                }
                else if (mouseX <= W / 2 + 30 && mouseX >= W / 2 - 40 && mouseY >= H / 2 && mouseY <= H / 2 + 30)
                {
                    printf("Opciones");
                    //destroy();
                    //menuOptions();
                    setPanel();
                    //MainGame initGameRun = MainGame();

                }
                else if (mouseX <= W / 2 + 30 && mouseX >= W / 2 - 40 && mouseY >= H / 2 + 35 && mouseY <= H / 2 + 55)
                {
                    printf("Salir");
                    running = false;
                }
            }
        }
    }
}
void MainGame::drawOptions() {
    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_draw_text(fontMenu, al_map_rgb(255, 255, 255), W / 2, H / 2 - 32, ALLEGRO_ALIGN_CENTER, "Jugar");
    al_draw_text(fontMenu, al_map_rgb(255, 255, 255), W / 2, H / 2, ALLEGRO_ALIGN_CENTER, "Opciones");
    al_draw_text(fontMenu, al_map_rgb(255, 255, 255), W / 2, H / 2 + 32, ALLEGRO_ALIGN_CENTER, "Salir");
    al_flip_display();
}