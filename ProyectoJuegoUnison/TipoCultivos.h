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
	struct Tomate
	{
		std::string ruta = "assets/Plants/tomate sprites.png";
		float sw = 35.0;
		float sh = 34.0;
	};

	struct Calabaza
	{
		std::string ruta = "assets/Plants/calabaza sprites.png";
		float sw = 36.5;
		float sh = 31.0;
	};

	struct Zanahoria
	{
		std::string ruta = "assets/Plants/zanahoria sprites.png";
		float sw = 30.0;
		float sh = 25.0;
	};

private:
	float sx;
	float sy;
	float sw;
	float sh;

};
extern std::list<Cultivo*>cultivos;
#endif // !1