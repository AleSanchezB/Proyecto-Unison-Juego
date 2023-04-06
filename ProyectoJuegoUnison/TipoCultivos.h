#ifndef CULTIVOSUNO_H
#define CULTIVOSUNO_H
#include "Objeto.h"
#include <string>
#include <list>
#include <iostream>

class Cultivo : public Objeto
{
public:
	Cultivo(std::string ruta, int x, int y, int tipo);
	~Cultivo();
	void action();

private:
	float sx;
	float sy;
	float sw;
	float sh;
};
extern std::list<Cultivo*>cultivos;
#endif // !1