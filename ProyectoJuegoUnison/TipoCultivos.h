#ifndef CULTIVOSUNO_H
#define CULTIVOSUNO_H
#include "Objeto.h"
#include <string>
#include <list>

class Cultivo : public Objeto
{
public:
	Cultivo(int x, int y, int tipo, int T_Creado = 0);
	~Cultivo();
	
	enum { BROTE, ADOL, COSECHABLE };
	
	int aux = 0;
	int T_Plantacion;
	int estado = 0;
	int tipo;
	
	void action(int escena);
	void Crecer(Cultivo* other);
private:
	float sx;
	float sy;
	float sw;
	float sh;
	std::string ruta;
};
extern Cultivo* cultivosPlantados[8];
#endif // !1