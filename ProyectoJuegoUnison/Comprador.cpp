#include "Comprador.h"

Comprador::Comprador()
{
	coins = al_load_bitmap("assets/animation/Paper Content Appear Animation/Folding & Cutout/8 Shop/coins.png");
	for (int i = 35; i >= 0; i--)
	{
		std::string ruta = "assets/animation/Paper Content Appear Animation/Folding & Cutout/8 Shop/" + std::to_string(i) + ".png";
		menu[i] = al_load_bitmap(ruta.c_str());
	}
	backgroud = new Background();
	aux = 720/2;
	animacion_x = (1280 - 44) / 2;
	animacion_y = (720- 43) / 2;
}

void Comprador::animtaion(int tipo)
{
	/*for (int i = 35; i >= 0; i--)
	{
		Sleep(60);
		al_draw_bitmap(menu[i], 0, 0, 0);
		al_flip_display();
		al_clear_to_color(al_map_rgb_f(255, 255, 255));
	}*/
	while (animacion_y > 0)
		for (int i = 0; i < 8; i++)
		{
			Sleep(60);
			al_draw_bitmap_region(coins, 44 * i, 0, 44, 43, animacion_x, animacion_y, 0);
			al_flip_display();
			al_clear_to_color(al_map_rgb_f(255, 255, 255));
			animacion_x += 10;
			animacion_y -= 10;
		}
	animacion_x = (1280 - 44) / 2;
	animacion_y = (720 - 43) / 2;
}void Comprador::Menu()
{
	al_draw_bitmap(menu[36], 0, 0, 0);
}