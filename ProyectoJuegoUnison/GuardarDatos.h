#include <iostream>
#include <fstream>
#include <string>

using namespace std;

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

DatosUsuario::DatosUsuario()
{
}

DatosUsuario::~DatosUsuario()
{
}
void DatosUsuario::Guardardatos()
{
    // Guardamos los datos en un archivo de texto llamado "datos.txt"
    ofstream archivo("datos.txt");
    if (archivo.is_open()) {
        archivo << datosJuego.Monedas << endl;
        archivo << datosJuego.cantidadObjetos << endl;
        archivo.close();
    }
    else {
        cout << "No se pudo abrir el archivo para escribir los datos." << endl;
    }
    // Imprimimos los datos cargados desde el archivo
    cout << "Dinero: " << datosJuego.Monedas << endl;
    cout << "Cantidad de objetos: " << datosJuego.cantidadObjetos << endl;
}

void DatosUsuario::ObtenerDatos()
{
    // Cargamos los datos desde el archivo de texto
    ifstream archivoCarga("datos.txt");
    if (archivoCarga.is_open())
    {
        string linea;
        getline(archivoCarga, linea);
        datosJuego.Monedas = stoi(linea);
        cout << "Monedas: " << datosJuego.Monedas<<endl;
        cout << "Monedas 2: " << getMonedas() << endl;
        getline(archivoCarga, linea);
        datosJuego.cantidadObjetos = stoi(linea);
        archivoCarga.close();
    }
    else 
    {
        cout << "No se pudo abrir el archivo para cargar los datos." << endl;
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