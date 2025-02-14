#ifndef SCREEN_H
#define SCREEN_H

#include <string>
#include <iostream>
#include "Direction.h"
using namespace std;

// The unsigned integral type which is used to store the number of
// characters in a string is nested within the string class, so it
// is accessed using "string::size_type".
// The range of string::size_type is guaranteed to be large enough to store the maximum
// *size* of any string that can be held by the string class as well as any index into
// the string.

class Screen {
public:
	// Screen's constructor
	Screen(string::size_type height, string::size_type width, char bkground = '#');

	// get the Screen's height
	string::size_type height() const { return height_; }
	// get the Screen's width
	string::size_type width() const { return width_; }

	// place the cursor at the top-left corner of the screen
	void home() { cursor_ = 0;  return; }
	// place the cursor at the bottom-right corner of the screen
	void end() { cursor_ = width_ * height_ - 1; return; }
	// move the cursor one position to the right
	void forward();
	// move the cursor one position to the left
	void back();
	// move the cursor up one row
	void up();
	// move the cursor down one row
	void down();
	// move the cursor to the specified row and column
	void move(string::size_type row, string::size_type col);

	void move(Direction directiion);
	void drawSquare(string::size_type leftX, string::size_type LeftY, string::size_type length);

	// get the character at the cursor's current position
	char get() const { return _screen[cursor_]; }//It is marked as const to indicate that it does not modify any member variables.
	// get the character at the specified row and column
	char get(string::size_type row, string::size_type col);

	// write a character on the screen at the current cursor position
	void set( char ch );
	// write a string of characters on the screen starting at the current cursor position
	void set( const string& s );
	// overwrite the entire screen with the specified character
	void clear( char bkground = '#');

	// resize the screen
	void reSize( string::size_type height, string::size_type width, char bkground = '#');

//The at member function of the string class allows you to access a specific character within the string.
//It takes an index (position) as an argument and returns the character at that position.
//Unlike the operator[], which does not perform bounds checking, the at function performs bounds checking and throws an exception if the index is out of range.


	// display the screen
	void display() const;
	// check whether the specified co-ordinates lie within the screen
	bool checkRange(string::size_type row, string::size_type col) const;//It is marked as const to indicate that it does not modify any member variables.

private:
	// constants
	// 0 represents the top-left screen element
	const string::size_type TOP_LEFT = 0;

	// private member functions
//They can be safely called on a const object of the Screen class.
	string::size_type remainingSpace() const;//It is marked as const to indicate that it does not modify any member variables.
	string::size_type row() const;//It is marked as const to indicate that it does not modify any member variables.


	// private data members
	// (using a trailing underscore is a naming convention for private data - not a requirement)

	// number of Screen rows
	string::size_type height_;
	// number of Screen columns
	string::size_type width_;
	// default position of the Screen's cursor, use in-class initilisation
	string::size_type cursor_ = TOP_LEFT;
	// the Screen's data is stored as a string
	string _screen;
};


#endif

