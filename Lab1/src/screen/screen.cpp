#include "screen.h"

// Screen's constructor
Screen::Screen(string::size_type height, string::size_type width, char bkground) : height_{height},					 // initialises height_ with height
																				   width_{width},					 // initialises width_ with width
																				   _screen(height * width, bkground) // size of _screen is height * width
																													 // all positions initialized with
																													 // character value of bkground
{																													 /* all the work is done in the member initialization list */
}

void Screen::forward()
{ // advance cursor_ one screen element
	++cursor_;

	// wrap around if the cursor_ is at the end of the screen
	if (cursor_ == _screen.size())
		home();

	return;
}

void Screen::back()
{ // move cursor_ backward one screen element
	// check for top of screen; wrap around
	if (cursor_ == TOP_LEFT)
		end();
	else
		--cursor_;

	return;
}

void Screen::up()
{
	// Move cursor up one row of the screen
	// Wrap around if at the top
	if (row() == 1)
	{
		// Move cursor to the bottom row
		cursor_ += (height_ - 1) * width_;
	}
	else
	{
		cursor_ -= width_;
	}
}

void Screen::down()
{
	// Move cursor down one row of the screen
	// Wrap around if at the bottom
	if (row() == height_)
	{
		// Move cursor to the top row
		cursor_ -= (height_ - 1) * width_;
	}
	else
	{
		cursor_ += width_;
	}
}

void Screen::move(string::size_type row, string::size_type col)
{ // move cursor_ to absolute position
	// valid screen position?
	if (checkRange(row, col))
	{
		// row location
		auto row_loc = (row - 1) * width_;
		cursor_ = row_loc + col - 1;
	}

	return;
}
void Screen::move(Direction directiion)
{
	switch (directiion)
	{
	case Direction::HOME:
		home();
		break;
	case Direction::FORWARD:
		forward();
		break;
	case Direction::BACK:
		back();
		break;
	case Direction::UP:
		up();
		break;
	case Direction::DOWN:
		down();
		break;
	case Direction::END:
		end();
		break;
	default:
		// Handle invalid direction
		cerr << "Invalid direction!" << endl;
		break;
	}
}
char Screen::get(string::size_type row, string::size_type col)
{
	// position cursor_
	move(row, col);
	// the other get() member function
	return get();
}

void Screen::set(char ch)
{
	if (ch == '\0')
		cerr << "Screen::set warning: " << "null character (ignored).\n";
	else
		_screen[cursor_] = ch;

	return;
}

void Screen::set(const string &s)
{ // write string beginning at current cursor_ position
	auto space = remainingSpace();
	auto len = s.size();
	if (space < len)
	{
		cerr << "Screen::set - Truncating, "
			 << "space available: " << space
			 << ", string length: " << len
			 << endl;
		len = space;
	}

	_screen.replace(cursor_, len, s);
	cursor_ += len - 1;

	return;
}

void Screen::clear(char bkground)
{ // reset the cursor and clear the screen
	cursor_ = TOP_LEFT;
	// assign the string
	_screen.assign(
		// with size() characters
		_screen.size(),
		// of value bkground
		bkground);

	return;
}

void Screen::reSize(string::size_type h, string::size_type w, char bkground)
{ // can only *increase* a screen's size to height h and width w
	// remember the content of the screen
	string local{_screen};
	auto local_pos = TOP_LEFT;

	// replaces the string to which _screen refers
	_screen.assign( // assign the string
		h * w,		// with h * w characters
		bkground	// of value bkground
	);

	// copy content of old screen into the new one
	for (string::size_type ix = 0; ix < height_; ++ix)
	{									   // for each row
		string::size_type offset = w * ix; // row position
		for (string::size_type iy = 0; iy < width_; ++iy)
			// for each column, assign the old value
			_screen.at(offset + iy) = local[local_pos++];
	}

	height_ = h;
	width_ = w;
	// cursor_ remains unchanged

	return;
}

void Screen::display() const
{
	for (string::size_type ix = 0; ix < height_; ++ix)
	{											// for each row
		string::size_type offset = width_ * ix; // row position
		for (string::size_type iy = 0; iy < width_; ++iy)
			// for each column, write element
			cout << _screen[offset + iy];
		cout << endl;
	}
	return;
}

bool Screen::checkRange(string::size_type row, string::size_type col) const
{ // validate coordinates
	if (row < 1 || row > height_ || col < 1 || col > width_)
	{
		cerr << "Screen coordinates (" << row << ", " << col << " ) out of bounds.\n";
		return false;
	}
	return true;
}

string::size_type Screen::remainingSpace() const
{ // includes current position
	auto size = width_ * height_;
	return (size - cursor_);
}

string::size_type Screen::row() const
{ // return current row
	return (cursor_ + width_) / width_;
}

// 4.4
//  The move member function is  a necessity for clients of Screen.
//  It provides  functionality for moving the cursor to a specific
//  position/direction. Without this function, clients would  not be able  to
//  move  and set the cursor position

void Screen::drawSquare(string::size_type leftX, string::size_type LeftY, string::size_type length)
{

	if (checkRange(leftX, LeftY))
	{
		move(leftX, LeftY);

		if ((length * length) <= remainingSpace())
		{
			for (int i = 1; i < length; i++)
			{
				set('*');
				move(Direction::DOWN);
			}

			for (int i = 1; i < length; i++)
			{
				set('*');
				move(Direction::FORWARD);
			}

			for (int i = 1; i < length; i++)
			{
				set('*');
				move(Direction::UP);
			}

			for (int i = 1; i < length; i++)
			{
				set('*');
				move(Direction::BACK);
			}
		}
		else
		{
			cerr << "Not enough space on the screen" << endl;
		}
	}
	else
	{
		cerr << "Top left corner not on screen" << endl;
	}
}

//4.7
// The internal representation of the screen class is not required we use function defined in the .h file
//The function relies on methods like checkRange, move, set, and remainingSpace,
//s long as these methods are well-defined and accessible, you can implement drawSquare using them

// Yes it forms part of the responsibilities of the screen, as it is responsible 
//for drawing and creating the screen. 

//4.8
