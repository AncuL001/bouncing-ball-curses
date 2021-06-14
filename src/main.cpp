#include "coords.hpp"
#include "init.hpp" //Not yet used
#include "animation.hpp"
#include <curses.h>

int main(){
	initscr();
	// coords size = init();

	coords size(80, 50);

	resize_term(size.y + 2, size.x + 2);

	print_border(size);
	animation(size);
}

