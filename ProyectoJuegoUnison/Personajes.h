#pragma once
#ifndef PERSO_H
#define PERSO_H
#include "Objetcs.h"

class Personaje : public Objects
{
public:
	Personaje();
	~Personaje();
private:
	
};

Personaje::Personaje():Object()
{
}

Personaje::~Personaje()
{
}

#endif