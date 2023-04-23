#include "TiempoDia.h"

Dia::Dia() {
	this->TiempoCreacion = al_current_time();
	this->TiempoDiaEscena = 0;
}

Dia::~Dia() {

}
void Dia::IniciarDia() {
	TiempoCreacion = al_current_time();
	TiempoDiaEscena = 0;
}

void Dia::CambioTiempoDia(float T_Actual)
{
	int resta = (int)(T_Actual - TiempoCreacion) % 30;
	if (resta == 0 && TiempoDiaEscena < 2) 
	{
		TiempoDiaEscena++;
		TiempoCreacion--;
	}
}