#include "SubmenuOptions.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <iostream>

SubMenuOptions::SubMenuOptions()
{
	run = true;
	i = 1;
}

SubMenuOptions::~SubMenuOptions()
{
}

void SubMenuOptions::draw_panel(Panel panel)
{
	al_draw_filled_rectangle(panel.x, panel.y, panel.x + panel.width, panel.y + panel.height, panel.color);
}
void SubMenuOptions::setPanel()
{
	al_init_primitives_addon();
	Panel panel = {
		panel.x = 100,
		panel.y = 100,
		panel.width = 200,
		panel.height = 100,
		panel.color = al_map_rgb(0,0,255),
		panel.content = "Hola"
	};
	while (run)
	{
		al_clear_to_color(al_map_rgb(0, 0, 0));
		draw_panel(panel);
		al_flip_display();
		i += 2;
		std::cout << i << endl;
		if (i >= 1000) run = false;
	}
}