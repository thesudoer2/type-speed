#ifndef TYPE_SPEED_H
#define TYPE_SPEED_H

#include <ncurses.h>
#include <string>
#include <vector>


typedef unsigned short uint2_t;


class game_engine
{
public:
	virtual ~game_engine() = default;
	game_engine(WINDOW*, const std::string&);

	// the following function will take input from user and
	// evaluate the input. finally this function returns
	// number of user's wrong inputs.
	uint2_t start_game() const;

private:
	void window_initializer();
	
	// the following function will remove split the given
	// string based-on space
	std::vector<std::string> word_spliter(const std::string&) const;

	// the followling function will write the input string on
	// the taken win
	void write_on_the_win() const;

	void start_colors() const;

	uint2_t max_y, max_x;

	WINDOW* win;

	// input string after word_spliter(), will
	// be stored in this vector
	std::vector<std::string> input_str;
};

#endif  // TYPE_SPEED_H
