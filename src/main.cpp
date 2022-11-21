#include <ncurses.h>

#include "game_engine.hpp"

using namespace std;

int main()
{
	int max_y, max_x;

	/////////////////////////// FOR TESTING ///////////////////////////////////////
    string str = "   Hello World    this is a testing \n\n\n\n for this  \t\t\t project, this is a testing for writing words on the given board and testing its functionality and so and so and so";
	////////////////////////// END OF TESTING ////////////////////////////////////	

	initscr();
	noecho();
	curs_set(0);

	getmaxyx(stdscr, max_y, max_x);

	WINDOW* win = newwin(max_y, max_x, 0, 0);

	box(win, 0, 0);

	type_speed *ptr = new type_speed(win, str);

	wgetch(win);

	endwin();
	return 0;
}
