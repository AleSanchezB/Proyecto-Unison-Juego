#ifndef OBJECTS_H
#define OBJECTS_H
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
#include <list>

class Objects
{
public:
	Objects();
	~Objects();
private:
	int xPosicion;
	int yPosicion;
	ALLEGRO_BITMAP* sprite;
};

std::list<Objects*>instancias;
Objects::Objects()
{
}

Objects::~Objects()
{
}
#endif // OBJECTS_H