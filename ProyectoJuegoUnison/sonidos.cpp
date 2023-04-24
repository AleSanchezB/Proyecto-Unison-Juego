#include "sonidos.h"

void SonidoUnico(const char archivo[], float volumen) 
{
	ALLEGRO_SAMPLE* SonidoActual = al_load_sample(archivo);
	ALLEGRO_SAMPLE_INSTANCE* sonido = al_create_sample_instance(SonidoActual);
	al_set_sample_instance_playmode(sonido, ALLEGRO_PLAYMODE_ONCE);
	al_attach_sample_instance_to_mixer(sonido, al_get_default_mixer());
	al_play_sample_instance(sonido);
	al_set_sample_instance_gain(sonido, 0.4);
}
/*******************************************************************************/
void SonidoLoop(const char archivo[], float volumen) 
{
	ALLEGRO_SAMPLE* SonidoActual = al_load_sample(archivo);
	ALLEGRO_SAMPLE_INSTANCE* sonido = al_create_sample_instance(SonidoActual);
	al_set_sample_instance_playmode(sonido, ALLEGRO_PLAYMODE_LOOP);
	al_attach_sample_instance_to_mixer(sonido, al_get_default_mixer());
	al_play_sample_instance(sonido);
	al_set_sample_instance_gain(sonido, 0.4);
}
/*******************************************************************************/
void DestruirSonido(ALLEGRO_SAMPLE* S,ALLEGRO_SAMPLE_INSTANCE* SA) 
{
	al_destroy_sample(S);
	al_destroy_sample_instance(SA);
}