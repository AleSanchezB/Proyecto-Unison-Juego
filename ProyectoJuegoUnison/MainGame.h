#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <iostream>
#include <string.h>
#include "InitiMap.h"
#include "SubmenuOptions.h"
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <Windows.h>

using namespace std;


class MainGame : public SubMenuOptions
{
public:
    MainGame();
    ~MainGame();
private:
    //DECLARACION DE VARIABLES ALLEGRO
    ALLEGRO_DISPLAY* firstDisplay;
    ALLEGRO_BITMAP* iconDisplay = NULL;
    ALLEGRO_BITMAP* fondos[5];
    ALLEGRO_EVENT_QUEUE* queue;
    ALLEGRO_FONT* fontMenu;
    ALLEGRO_EVENT event;
    ALLEGRO_MIXER* mixer;
    ALLEGRO_VOICE* voice;
    ALLEGRO_SAMPLE_INSTANCE* songInstance;
    ALLEGRO_SAMPLE* sample;
    ALLEGRO_SAMPLE_INSTANCE* efectClickInstance;
    ALLEGRO_SAMPLE* efectClick;
    ALLEGRO_SAMPLE_ID idClickEffect;

    Panel panelOptions;
    //VARIABLES
    bool running;
    int mouseX, mouseY;

    int sliderX = 100;
    int sliderY = 200;
    int sliderWidth = 200;
    int sliderHeight = 20;
    int sliderValue = 50;
    float gain = 0.5;
    int contClicks = 0;


    //CONSTANTES
    const int W = 800, H = 600;

    //FUNCIONES
    void initMenu();
    void drawOptions(int i);
    void initVars();
    void gameRun();
    void alDestroy();
    void setVolMusic(float volumen);
    void drawRec();
    void click();
};

MainGame::MainGame()
{
    al_init();
    al_install_keyboard();
    al_install_mouse();
    al_install_audio();
    al_init_primitives_addon();
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
}

void MainGame::initVars()
{
    iconDisplay = al_load_bitmap("assets/Sprites Players/NO SE USARA/PNG/IdleTam/frame01.png");
    for (int i = 0; i <= 3; i++)
    {
        string ruta = "assets/fondos/imgLogin/Banner0" + to_string(i) + ".png";
        fondos[i] = al_load_bitmap(ruta.c_str());
    }
    fontMenu = al_load_font("assets/fonts/Minecraft.ttf", 20, 0);
    //Carga la musica
    sample = al_load_sample("assets/Musica/Musica.ogg");
    songInstance= al_create_sample_instance(sample);
 
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
    float volume = 0.5;
    int i = 0;
    //Inicia la musica en loop
    al_play_sample_instance(songInstance);
    al_set_sample_instance_gain(songInstance, volume);
    drawOptions(0);

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
        if (event.type == ALLEGRO_EVENT_MOUSE_AXES) {
            if (event.mouse.x >= 298 && event.mouse.x <= 502 && event.mouse.y >= 239 && event.mouse.y <= 294)
            {
                i = 1;
                drawOptions(i);
            }
            else if (event.mouse.x >= 298 && event.mouse.x <= 502 && event.mouse.y >= 332 && event.mouse.y <= 387)
            {
                i = 2;
                drawOptions(i);
            }
            else if (event.mouse.x >= 298 && event.mouse.x <= 502 && event.mouse.y >= 423 && event.mouse.y <= 478)
            {
                i = 3;
                drawOptions(i);
            }
            else
            {
                i = 0;
                drawOptions(i);
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
                if (event.mouse.x >= 298 && event.mouse.x <= 502 && event.mouse.y >= 239 && event.mouse.y <= 294)
                {
                    running = false;
                    alDestroy();
                    Mapa1 mapa1 = Mapa1();
                }
                else if (event.mouse.x >= 298 && event.mouse.x <= 502 && event.mouse.y >= 332 && event.mouse.y <= 387)
                {
                    drawRec();
                }
                else if (event.mouse.x >= 298 && event.mouse.x <= 502 && event.mouse.y >= 423 && event.mouse.y <= 478)
                {
                    running = false;
                    alDestroy();
                }
            }
        }
    }
}
void MainGame::drawOptions(int i) {
    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_draw_bitmap(fondos[i],0,0,NULL);
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
void MainGame::drawRec()
{
    bool run = true;
    ALLEGRO_EVENT event1;
   
    while (run)
    { 
        al_wait_for_event(queue, &event1);
        al_clear_to_color(al_map_rgb(0, 0, 0));
        al_draw_filled_rectangle(10, 10, 210, 110, al_map_rgb(0, 0, 50));
        al_flip_display();
        cout << gain << endl;

        if (event1.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
        {
            if (event1.mouse.button == 1)
            {
                //obtengo las coords del puntero del mouse
                mouseX = event1.mouse.x;
                mouseY = event1.mouse.y;

                if (mouseX <= 210 && mouseX >= 10 && mouseY >= 10 && mouseY <= 110)
                {
                    if (gain <= 0) gain = 0;
                    else gain -= 0.01;
                    al_set_sample_instance_gain(songInstance, gain);
                }
                else { 
                    if (gain >= 0.5) gain = 0.5;
                    else gain += 0.01;
                    al_set_sample_instance_gain(songInstance, gain);
                }
            }
        }
    }
}