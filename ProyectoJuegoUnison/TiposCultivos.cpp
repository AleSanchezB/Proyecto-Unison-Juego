#include "TipoCultivos.h"
#include <allegro5/allegro.h>
#include <allegro5/bitmap.h>

CultivoUno::CultivoUno()
{
		uno.xPosition = 10;
		uno.yPosition = 10;
		uno.imagen = al_load_bitmap("assets/Basic Plants.png");
		assert(uno.imagen != NULL);
}

CultivoUno::~CultivoUno()
{
}