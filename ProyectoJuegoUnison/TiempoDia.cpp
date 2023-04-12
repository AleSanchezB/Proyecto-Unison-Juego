
#include "TiempoDia.h"

Dia::Dia() {
	this->TiempoCreacion = al_current_time();
	this->TiempoDiaEscena = 0;
}

Dia::~Dia() {

}
void Dia::IniciarDia() {
	TiempoCreacion = al_current_time();
	std::cout << "Objetivos del día\n";
	TiempoDiaEscena = 0;
	//GENERAR TAMBIEN OBJETIVOS DEL DIA(tengo que averiguar cómo :c)
}

void Dia::CambioTiempoDia(float T_Actual)
{
	int resta = (int)(T_Actual - TiempoCreacion) % 10;
	if (resta == 0 && TiempoDiaEscena < 2) {
		TiempoDiaEscena++;
		TiempoCreacion--;
	}
}