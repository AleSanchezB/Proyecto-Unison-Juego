#ifndef DIA_H
#define DIA_H_INCLUDED
#include <allegro5/allegro5.h>
class Dia
{
public:
	Dia();
	~Dia();

	void IniciarDia();
	void CambioTiempoDia(float T_Actual);

	int TiempoCreacion;
	int TiempoDiaEscena;
private:

};
#endif //DIA_H