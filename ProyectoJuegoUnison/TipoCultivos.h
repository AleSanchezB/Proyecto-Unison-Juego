#ifndef CULTIVOSUNO_H
#define CULTIVOSUNO_H
#include "Objeto.h"
#include <string>

class Cultivo : public Objeto
{
public:
	Cultivo(std::string ruta, int x, int y, int tipo);
	~Cultivo();
	void action();
};
#endif // !1