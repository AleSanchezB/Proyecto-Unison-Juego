#ifndef CULTIVOSUNO_H
#define CULTIVOSUNO_H
#include <allegro5/bitmap.h>

class CultivoUno
{
private:
	struct TipoUnoCultivo
	{
		int xPosition;
		int yPosition;
		ALLEGRO_BITMAP* imagen;
	};
public:
	CultivoUno();
	~CultivoUno();
	TipoUnoCultivo uno;
};
#endif // !1