#ifndef CULTIVOSUNO_H
#define CULTIVOSUNO_H
#include "Objeto.h"
#include <string>
#include <list>
#include <fstream>
#include <sstream>

void CargarCulivos();
void inicializar_cultivos();
void GuardarCultivos();

class Cultivo : public Objeto
{
public:
	Cultivo(int x, int y, int tipo, int espacio, int estado, int T_Creado = 0 , int sy = 0);
	~Cultivo();

	enum { BROTE, ADOL, COSECHABLE };

	int aux = 0;
	int T_Plantacion;
	int estado = 0;
	int tipo;
	int espacio;
	void action(int escena);
	void Crecer(Cultivo* other);

	int getTipo();
	int getSy();
	int getespacio();
	int getEstado();
	int getTiempoPlantacion();
	int getPosX();
	int getPosY();

	void setTipo(int tipo);
	void setespacio(int espacio);
	void setEstado(int estado);
	void setTiempoPlantacion(int tiempo);
private:
	float sx;
	float sy;
	float sw;
	float sh;
	std::string ruta;

};
extern Cultivo* cultivosPlantados[8];
#endif // !1