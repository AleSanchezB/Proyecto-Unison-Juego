#include "GuardarDatos.h"
#include <iostream>
#include <fstream>
#include <string>

DatosUsuario::DatosUsuario()
{
}

DatosUsuario::~DatosUsuario()
{
}
void DatosUsuario::Guardardatos()
{
    // Guardamos los datos en un archivo de texto llamado "datos.txt"
    std::ofstream archivo("datos.txt");
    if (archivo.is_open()) {
        archivo << datosJuego.Monedas << std::endl;
        archivo << datosJuego.cantidadObjetos << std::endl;
        archivo.close();
    }
    else {
        std::cout << "No se pudo abrir el archivo para escribir los datos." << std::endl;
    }
    // Imprimimos los datos cargados desde el archivo
    std::cout << "Dinero: " << datosJuego.Monedas << std::endl;
    std::cout << "Cantidad de objetos: " << datosJuego.cantidadObjetos << std::endl;
}

void DatosUsuario::ObtenerDatos()
{
    // Cargamos los datos desde el archivo de texto
    std::ifstream archivoCarga("datos.txt");
    if (archivoCarga.is_open())
    {
        std::string linea;
        getline(archivoCarga, linea);
        datosJuego.Monedas = stoi(linea);
        std::cout << "Monedas: " << datosJuego.Monedas << std::endl;
        std::cout << "Monedas 2: " << getMonedas() << std::endl;
        getline(archivoCarga, linea);
        datosJuego.cantidadObjetos = stoi(linea);
        archivoCarga.close();
    }
    else
    {
        std::cout << "No se pudo abrir el archivo para cargar los datos." << std::endl;
    }
}

void DatosUsuario::setMonedas(int Monedas)
{
    datosJuego.Monedas = Monedas;
}

int DatosUsuario::getMonedas()
{
    return datosJuego.Monedas;
}