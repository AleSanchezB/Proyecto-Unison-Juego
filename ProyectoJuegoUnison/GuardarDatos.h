#ifndef GUARDARDATOS_H
#define GUARDARDATOS_H

#include <iostream>

class DatosUsuario
{
public:
    DatosUsuario();
    ~DatosUsuario();

    //set and getters
    void setMonedas(int monedas);
    int getMonedas();
    void ObtenerDatos();

private:
    int Monedas;
    int cantidadObjetos;
    void Guardardatos();
};
#endif // !1