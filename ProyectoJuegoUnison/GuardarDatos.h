#include <iostream>
#include <fstream>
#include <string>

using namespace std;

    struct DatosJuego {
        int dinero;
        int cantidadObjetos;
    };
    void Guardardatos();
    void ObtenerDatos();
    DatosJuego datosJuego;

void Guardardatos() 
{
    // Creamos una instancia de la estructura DatosJuego con algunos datos
    datosJuego.dinero = 900;
    datosJuego.cantidadObjetos = 5;

    // Guardamos los datos en un archivo de texto llamado "datos.txt"
    ofstream archivo("datos.txt");
    if (archivo.is_open()) {
        archivo << datosJuego.dinero << endl;
        archivo << datosJuego.cantidadObjetos << endl;
        archivo.close();
    }
    else {
        cout << "No se pudo abrir el archivo para escribir los datos." << endl;
    }
    // Imprimimos los datos cargados desde el archivo
    cout << "Dinero: " << datosJuego.dinero << endl;
    cout << "Cantidad de objetos: " << datosJuego.cantidadObjetos << endl;
}

void ObtenerDatos()
{
    // Cargamos los datos desde el archivo de texto
    ifstream archivoCarga("datos.txt");
    if (archivoCarga.is_open())
    {
        string linea;
        getline(archivoCarga, linea);
        datosJuego.dinero = stoi(linea);
        //setMonedas(datosJuego.dinero);
        getline(archivoCarga, linea);
        datosJuego.cantidadObjetos = stoi(linea);
        archivoCarga.close();
    }
    else 
    {
        cout << "No se pudo abrir el archivo para cargar los datos." << endl;
    }
}