// Exercising the Screen class
#include "screen.h"
#include <iostream>

using namespace std;

int main()
{
	auto myScreen = Screen{6,6};

	for(int i=1;i<=6;i++)
	{
	myScreen.set('*');
	myScreen.move(Direction::FORWARD);	
	}
	
	myScreen.move(1,3);

	for(int i=1;i<=6;i++)
	{
	myScreen.set('*');
	myScreen.move(Direction::DOWN);	
	}
	
	myScreen.display();
	cout << endl;

	myScreen.clear();
	myScreen.reSize(16,16);
	myScreen.clear(' ');
	myScreen.drawSquare(1,1,5);
	myScreen.display();
	myScreen.drawSquare(17,17,5);//Error catching
	myScreen.drawSquare(0,0,18);//Error catching
    myScreen.display();

	return 0;
}

