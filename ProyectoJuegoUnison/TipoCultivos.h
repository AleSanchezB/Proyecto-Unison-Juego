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
	Cultivo(int x, int y, int tipo, int T_Creado = 0);
	~Cultivo();
	void Crecer(Cultivo* other);
	void action(int escena);
	int tipo;
private:
	float sx;
	float sy;
	float sw;
	float sh;
	std::string ruta;
};
extern Cultivo* matrizCultivos[8];
#endif // !1