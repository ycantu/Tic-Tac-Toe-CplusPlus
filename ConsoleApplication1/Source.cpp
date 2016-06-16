#include <iostream>
#include "Header.h"

int main()
{
	Board n;
	bool x = false;

	while (x == false)
	{
		n.displayBoard();
		n.turnPrompt();
		x = n.checkWin();
		n.nextPlayer();
	}

	system("pause");
	return 0;


}