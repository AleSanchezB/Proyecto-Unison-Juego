#pragma once
#ifndef MOCHILA_H
#define MOCHILA_H

class Mochila
{
public:
	Mochila();
	~Mochila();
	void setcantidadObjetos(int cantidadObjetos);
	void setcantidadCultivos1(int cantidadObjetos);
	void setcantidadCultivos2(int cantidadObjetos);
	void setcantidadCultivos3(int cantidadObjetos);

	int getcantidadObjetos();
	int getcantidadCultivos1();
	int getcantidadCultivos2();
	int getcantidadCultivos3();
private:
	int cantidadObjetos;
	int cantidadCultivos1;
	int cantidadCultivos2;
	int cantidadCultivos3;
};
#endif // !MOCHILA_H