#ifndef SUBMENU_H
#define SUBMENU_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

using namespace std;

class SubMenuOptions
{
public:
	SubMenuOptions();
	~SubMenuOptions();
	struct Panel {
		int x;
		int y;
		int width;
		int height;
		ALLEGRO_COLOR color;
		const char* content;
	};
	void draw_panel(Panel panel);
	void setPanel();
private:
	bool run;
	int i;
};
#endif // !1