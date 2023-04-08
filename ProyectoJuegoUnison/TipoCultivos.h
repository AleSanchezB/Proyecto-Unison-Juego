#ifndef CULTIVOSUNO_H
#define CULTIVOSUNO_H
#include "Objeto.h"
#include <string>
#include <list>
#include <iostream>

class Cultivo : public Objeto
{
public:
	int aux = 0;
	int T_Plantacion;
	enum { BROTE, ADOL, COSECHABLE };
	int estado = 0;
	Cultivo(std::string ruta, int x, int y, int tipo, int T_Creado = 0);
	~Cultivo();
	void Crecer(Cultivo* other);
	void action(int escena);

private:
	float sx;
	float sy;
	float sw;
	float sh;

};
extern std::list<Cultivo*>cultivos;
#endif // !1