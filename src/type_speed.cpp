#include <sstream>
#include <iterator>
#include <math.h>

#include "type_speed.hpp"

type_speed::type_speed(WINDOW* win, const std::string& input_str)
{
	this->win = win;
	type_speed::window_initializer();

	this->input_str = type_speed::word_spliter(input_str);

	type_speed::write_on_the_win();
}

void type_speed::window_initializer()
{
	getmaxyx(this->win, this->max_y, this->max_x);

	noecho();
	curs_set(0);
	keypad(this->win, true);
}

std::vector<std::string> type_speed::word_spliter(const std::string& input_str) const
{
    std::stringstream ss(input_str);

    std::istream_iterator<std::string> begin(ss);
    std::istream_iterator<std::string> end;

    std::vector<std::string> result(begin, end);

	// adding space at end of each word (except the last one) for
	// using in write_on_the_win() functions
	for (int i = 0; i < result.size(); ++i)
	{
		if (!(i == (result.size() - 1)))
		{
			result[i] += ' ';
		}
	}

    return result;
}

void type_speed::write_on_the_win() const
{
	start_colors();

	const uint2_t START_X_POS = 2;
	const uint2_t START_Y_POS = 1;
	const uint2_t END_X_POS   = this->max_x - 2;
	const uint2_t END_Y_POS   = this->max_y - 1;
	uint2_t x_pos = START_X_POS;
	uint2_t y_pos = START_Y_POS;

	for (const auto &str : this->input_str)
	{
		if (str.size() > abs(x_pos - END_X_POS))
		{
			++y_pos;
			x_pos = START_X_POS;
		}

		for (auto ch : str)
		{
			wattron(this->win, COLOR_PAIR(1));
			mvwaddch(this->win, y_pos, x_pos, ch);
			wattroff(this->win, COLOR_PAIR(1));

			++x_pos;
		}
	}
}

void type_speed::start_colors() const
{
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_BLACK); // initial writing on the win
	init_pair(2, COLOR_GREEN, COLOR_BLACK); // correct input chars
	init_pair(3, COLOR_BLACK, COLOR_RED);   // incorrect input
	init_pair(4, COLOR_BLACK, COLOR_WHITE); // current char
}
