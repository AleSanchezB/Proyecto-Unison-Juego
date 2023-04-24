#ifndef MAINGAME_H
#define MAINGAME_H
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <string.h>

#include "InitiMap.h"
#include "SubmenuOptions.h"

using namespace std;

class MainGame : public SubMenuOptions
{
public:
    MainGame();
    ~MainGame();
private:
    //DECLARACION DE VARIABLES ALLEGRO
    ALLEGRO_DISPLAY* firstDisplay;
    ALLEGRO_BITMAP* iconDisplay;
    ALLEGRO_BITMAP* fondos[5];
    ALLEGRO_BITMAP* btn[3];
    ALLEGRO_EVENT_QUEUE* queue;
    ALLEGRO_FONT* fontMenu;
    ALLEGRO_EVENT event;
    ALLEGRO_MIXER* mixer;
    ALLEGRO_VOICE* voice;
    ALLEGRO_SAMPLE* sample;
    ALLEGRO_SAMPLE* efectClick;
    ALLEGRO_SAMPLE_INSTANCE* songInstance;
    ALLEGRO_SAMPLE_INSTANCE* efectClickInstance;
    ALLEGRO_SAMPLE_ID idClickEffect;
    ALLEGRO_BITMAP* Instrucciones[8];
    Panel panelOptions;
    //VARIABLES
    int mouseX, mouseY;
    bool running;

    float gain = 0.5;

    //CONSTANTES
    const int W = 1280, H = 720;

    //FUNCIONES
    void initMenu();
    void dibujarMenu(int i);
    void iniciarVariables();
    void gameRun();
    void alDestroy();
    void setVolMusic(float volumen);
    void dibujarInstrucciones();
    void click();
};
#endif // !1