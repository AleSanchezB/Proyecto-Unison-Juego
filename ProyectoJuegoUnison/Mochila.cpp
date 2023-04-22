#include "Mochila.h"


Mochila::Mochila(int cantidadObjetos, int cantidadTomates, int cantidadCalabaza, int cantidadZanahoria,
	int cantidadBerenjena, int cantidadEjotes, int cantidadMaiz, int cantidadPapa,
	int cantidadPapaya, int cantidadRemolacha, ALLEGRO_FONT* font)
{
	this->cantidadObjetos = cantidadTomates + cantidadCalabaza + cantidadZanahoria + cantidadBerenjena + cantidadEjotes + cantidadMaiz + cantidadPapa
		+ cantidadPapaya + cantidadRemolacha;
	this->cantidadTomates = cantidadTomates;
	this->cantidadCalabaza = cantidadCalabaza;
	this->cantidadZanahoria = cantidadZanahoria;

	this->cantidadBerenjena = cantidadBerenjena;
	this->cantidadEjotes = cantidadEjotes;
	this->cantidadMaiz = cantidadMaiz;
	this->cantidadPapa = cantidadPapa;
	this->cantidadPapaya = cantidadPapaya;
	this->cantidadRemolacha = cantidadRemolacha;

	this->capacidadMochila = 10;
	this->casillaSelect = 0;
	this->font = font;
	this->Monedas = 10;
	barraHerramientas = al_load_bitmap("assets/fondos/Objetos/barraHerramientas.png");
	seleccionHerramienta = al_load_bitmap("assets/fondos/Objetos/seleccionHerramienta.png");
	tom = al_load_bitmap("assets/Plants/tomate item.png");
	cal = al_load_bitmap("assets/Plants/calabaza item.png");
	zana = al_load_bitmap("assets/Plants/zanahoria item.png");
	bere = al_load_bitmap("assets/Plants/berenjena item.png");
	ejo = al_load_bitmap("assets/Plants/ejote item.png");
	maiz = al_load_bitmap("assets/Plants/maiz item.png");
	papa = al_load_bitmap("assets/Plants/papa item.png");
	papaya = al_load_bitmap("assets/Plants/papaya item.png");
	remo = al_load_bitmap("assets/Plants/remolacha item.png");
}
Mochila::~Mochila()
{
	al_destroy_font(font);
	al_destroy_bitmap(seleccionHerramienta);
	al_destroy_bitmap(barraHerramientas);
	al_destroy_bitmap(tom);
	al_destroy_bitmap(cal);
	al_destroy_bitmap(zana);
}
void Mochila::setCantidadCultivos(int cantidadObjetos)
{
	this->cantidadObjetos = cantidadObjetos;
}

int Mochila::getCantidadTipoCultivo(int tipo)
{
	switch (tipo)
	{
	case 0:
		return this->cantidadTomates;

	case 1:
		return this->cantidadCalabaza;

	case 2:
		return this->cantidadZanahoria;

	case 3:
		return this->cantidadBerenjena;

	case 4:
		return this->cantidadEjotes;

	case 5:
		return this->cantidadMaiz;

	case 6:
		return this->cantidadPapa;

	case 7:
		return this->cantidadPapaya;

	case 8:
		return this->cantidadRemolacha;

	default:
		break;
	}
	return false;
}

void Mochila::setCantidadTipoCultivos(int cantCultivo, int tipo)
{
	switch (tipo)
	{
	case 0:
		this->cantidadTomates = cantCultivo;
		break;
	case 1:
		this->cantidadCalabaza = cantCultivo;
		break;
	case 2:
		this->cantidadZanahoria = cantCultivo;
		break;
	case 3:
		this->cantidadBerenjena = cantCultivo;
		break;
	case 4:
		this->cantidadEjotes = cantCultivo;
		break;
	case 5:
		this->cantidadMaiz = cantCultivo;
		break;
	case 6:
		this->cantidadPapa = cantCultivo;
		break;
	case 7:
		this->cantidadPapaya = cantCultivo;
		break;
	case 8:
		this->cantidadRemolacha = cantCultivo;
		break;
	default:
		break;
	}
}
int Mochila::getCantidadCultivos()
{
	return this->cantidadObjetos;
}


void Mochila::action(int escena)
{
	int yPosBarra = 658, selectHer = 663, bitmapver =669, textCant =690;
	
	//Para establecer la barra de herraminetas cada que le haga zoom
	if (escena == 6 || escena == 9) {
		yPosBarra = 555;
		selectHer = 560;
		bitmapver =566; 
		textCant = 586;}




	al_draw_bitmap(barraHerramientas, 530, yPosBarra, 0);
	al_draw_bitmap(seleccionHerramienta, 538 + 42 * casillaSelect, selectHer, 0);
	al_draw_bitmap(tom, 548, bitmapver, 0);
	al_draw_bitmap(cal, 589, bitmapver, 0);
	al_draw_bitmap(zana, 635, bitmapver, 0);
	al_draw_bitmap(bere, 676, bitmapver, 0);
	al_draw_bitmap(ejo, 717, bitmapver, 0);
	al_draw_text(font, al_map_rgb(255, 255, 255), 572, textCant, ALLEGRO_ALIGN_LEFT, std::to_string(cantidadTomates).c_str());
	al_draw_text(font, al_map_rgb(255, 255, 255), 572 + 42, textCant, ALLEGRO_ALIGN_LEFT, std::to_string(cantidadCalabaza).c_str());
	al_draw_text(font, al_map_rgb(255, 255, 255), 572 + 42 * 2, textCant, ALLEGRO_ALIGN_LEFT, std::to_string(cantidadZanahoria).c_str());
	al_draw_text(font, al_map_rgb(255, 255, 255), 572 + 42 * 3, textCant, ALLEGRO_ALIGN_LEFT, std::to_string(cantidadBerenjena).c_str());
	al_draw_text(font, al_map_rgb(255, 255, 255), 572 + 42 * 4, textCant, ALLEGRO_ALIGN_LEFT, std::to_string(cantidadEjotes).c_str());
	
}
void Mochila::cambiarCasilla(int casillaSelect)
{
	/*if (this->casillaSelect == 0 && casillaSelect < 0) this->casillaSelect = 4;
	else if (this->casillaSelect == 4 && casillaSelect > 1) this->casillaSelect = 0;
	else this->casillaSelect = casillaSelect;*/
	this->casillaSelect = casillaSelect;
}

int Mochila::verificarObjectoSeleccionado()
{
	return this->casillaSelect;
}
void Mochila::quitarCultivo(int tipo)
{
	switch (tipo)
	{
	case 0: //tomate
		setCantidadTipoCultivos(getCantidadTipoCultivo(tipo) - 1, tipo);
		break;
	case 1: //calabaza
		setCantidadTipoCultivos(getCantidadTipoCultivo(tipo) - 1, tipo);
		break;
	case 2: //zanahoria
		setCantidadTipoCultivos(getCantidadTipoCultivo(tipo) - 1, tipo);
		break;
	case 3: //berenjena
		setCantidadTipoCultivos(getCantidadTipoCultivo(tipo) - 1, tipo);
		break;
	case 4: //ejotes
		setCantidadTipoCultivos(getCantidadTipoCultivo(tipo) - 1, tipo);
		break;
	case 5: //maiz
		setCantidadTipoCultivos(getCantidadTipoCultivo(tipo) - 1, tipo);
		break;
	case 6: //papa
		setCantidadTipoCultivos(getCantidadTipoCultivo(tipo) - 1, tipo);
		break;
	case 7: //papaya
		setCantidadTipoCultivos(getCantidadTipoCultivo(tipo) - 1, tipo);
		break;
	case 8: //remolacha
		setCantidadTipoCultivos(getCantidadTipoCultivo(tipo) - 1, tipo);
		break;
	default:
		break;
	}
	setCantidadCultivos(getCantidadCultivos() - 1);
}
int Mochila::getEspacioMochila()
{
	return this->capacidadMochila;
}
void Mochila::setEspacioMochila(int cantidad)
{
	this->capacidadMochila = cantidad;
}
bool Mochila::verificarCantidadCultivos(int tipo)
{
	switch (tipo)
	{
	case 0:
		if (getCantidadTipoCultivo(tipo) > 0) return true;
		else return false;
	case 1:
		if (getCantidadTipoCultivo(tipo) > 0) return true;
		else return false;
	case 2:
		if (getCantidadTipoCultivo(tipo) > 0) return true;
		else return false;
	case 3:
		if (getCantidadTipoCultivo(tipo) > 0) return true;
		else return false;
	case 4:
		if (getCantidadTipoCultivo(tipo) > 0) return true;
		else return false;
	case 5:
		if (getCantidadTipoCultivo(tipo) > 0) return true;
		else return false;
	case 6:
		if (getCantidadTipoCultivo(tipo) > 0) return true;
		else return false;
	case 7:
		if (getCantidadTipoCultivo(tipo) > 0) return true;
		else return false;
	case 8:
		if (getCantidadTipoCultivo(tipo) > 0) return true;
		else return false;
	default:
		break;
	}
	return false;
}
bool Mochila::verificacionMochila()
{
	if (getCantidadCultivos() > 0) return true;
	return false;
}
void Mochila::setMonedas(int Monedas)
{
	this->Monedas = Monedas;
}
int Mochila::getMonedas()
{
	return this->Monedas = Monedas;
}

bool Mochila::verificarCantidadCultivosGuardados(int tipo, int cantidad)
{
	switch (tipo)
	{
	case 0:
		if (cantidad > 0 && cantidad <= getCantidadTipoCultivo(tipo)) return true;
		else return false;
	case 1:
		if (cantidad > 0 && cantidad <= getCantidadTipoCultivo(tipo)) return true;
		else return false;
	case 2:
		if (cantidad > 0 && cantidad <= getCantidadTipoCultivo(tipo)) return true;
		else return false;
	case 3:
		if (cantidad > 0 && cantidad <= getCantidadTipoCultivo(tipo)) return true;
		else return false;
	case 4:
		if (cantidad > 0 && cantidad <= getCantidadTipoCultivo(tipo)) return true;
		else return false;
	case 5:
		if (cantidad > 0 && cantidad <= getCantidadTipoCultivo(tipo)) return true;
		else return false;
	case 6:
		if (cantidad > 0 && cantidad <= getCantidadTipoCultivo(tipo)) return true;
		else return false;
	case 7:
		if (cantidad > 0 && cantidad <= getCantidadTipoCultivo(tipo)) return true;
		else return false;
	case 8:
		if (cantidad > 0 && cantidad <= getCantidadTipoCultivo(tipo)) return true;
		else return false;
	default:
		break;
	}
	return false;
}

bool Mochila::verificarMochilaLlena(int cantidadIngresar)
{
	if (cantidadIngresar + getCantidadCultivos() > this->capacidadMochila) return false;
	else return true;
}