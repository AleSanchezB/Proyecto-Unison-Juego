#ifndef GUARDARDATOS_H
#define GUARDARDATOS_H

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
    struct DatosJuego {
        int Monedas;
        int cantidadObjetos;
    };
    void Guardardatos();
    DatosJuego datosJuego;
};
#endif // !1