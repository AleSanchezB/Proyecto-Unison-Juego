#ifndef SONIDOS_H
#define SONIDOS_H
#include <allegro5/allegro.h>
#include <allegro5/allegro_audio.h>
void SonidoUnico(const char archivo[], float volumen), SonidoLoop(const char archivo[], float volumen), DestruirSonido(ALLEGRO_SAMPLE* S, ALLEGRO_SAMPLE_INSTANCE* SA);
#endif