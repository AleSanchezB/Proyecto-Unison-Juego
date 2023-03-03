#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

using namespace std;
class Cultivos
{
public:
	Cultivos();
	~Cultivos();
	void plantarCultivo(ALLEGRO_KEYBOARD_STATE keystate);
private:

};

Cultivos::Cultivos()
{
}

Cultivos::~Cultivos()
{
}
void Cultivos::plantarCultivo(ALLEGRO_KEYBOARD_STATE keystate)
{
	al_get_keyboard_state(&keystate);

	if (al_key_down(&keystate, ALLEGRO_KEY_F)) cout<<"Presionaste la f"<<endl;
}
