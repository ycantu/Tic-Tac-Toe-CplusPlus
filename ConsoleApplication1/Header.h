#pragma once

//Maybe make a player class?
class Player
{
public:
	int position;
	char sym;

	Player()
	{

	}

	Player(int pos, char x)
	{
		position = pos;
		sym = x;
	}

};

// Board class keeps state of board, displays, and prompts
class Board
{
public:
	char values [9];
	char playerOneSym;
	char playerTwoSym;
	bool turn;
	Player one{ 1, 'x' };
	Player two{ 2, 'o' };

	Board()
	{
		for (int i = 0; i < 9; i++)
		{
			values[i] = ' ';
		}

		turn = false;
		playerOneSym = 'x';
		playerTwoSym = 'o';


	}

	void displayBoard()
	{
		std::cout << values[0] << " | " << values[1] << " | " << values[2] << std::endl;
		std::cout << "_________" << std::endl;
		std::cout << values[3] << " | " << values[4] << " | " << values[5] << std::endl;
		std::cout << "_________" << std::endl;
		std::cout << values[6] << " | " << values[7] << " | " << values[8] << std::endl;
		std::cout << std::endl << std::endl;
	}

	void introPrompt()
	{
		std::cout << "Welcome to Tic-Tac-Toe!" << std::endl;
		std::cout << "Select '1' to play against a buddy or type '2' to play against the computer!"<< std::endl;

		int mode;
		std::cin >> mode;

		if (mode == 1)
		{
			std::cout << "Player 1 choose your symbol, type 'x' or '0'" << std::endl;
			std::cin >> playerOneSym;

			if (playerOneSym == 'x')
				playerTwoSym = '0';
			else
				playerTwoSym = 'x';
		}
	}

	void turnPrompt()
	{
		if (turn == false)
			turnPrompt(one);
		else
			turnPrompt(two);
	}

	void turnPrompt(Player x)
	{
		int cell;

		std::cout << "Player " << x.position << " turn" << std::endl;
		std::cout << "Which cell would you like to fill?" << std::endl;
		std::cin >> cell;

		// Write value 
		values[cell] = x.sym;
	}

	void nextPlayer()
	{
		//Switch to next player
		turn = !turn;
	}

	
	bool checkWin()
	{
		if (turn == false)
			return checkWin(one.sym);
		else
			return checkWin(two.sym);
	}

	bool checkWin(char sym)
	{

		for (int i = 0; i < 9; i += 3)
		{
			if (values[i] == sym)
			{
				if (values[i + 1] == sym && values[i + 2] == sym)
				{
					std::cout << "Horizontal Win" << std::endl;
					displayBoard();
					return true;
				}
			}
		}

		for (int i = 0; i < 3; i++)
		{
			if (values[i + 3] == sym && values[i + 6] == sym)
			{
				std::cout << "Vertical Win" << std::endl;
				return true;
			}
		}

		if (values[0] == sym && values[4] == sym && values[8] == sym)
		{
			std::cout << "Diagonal Win" << std::endl;
			return true;
		}
		else if (values[2] == sym && values[4] == sym && values[6] == sym)
		{
			std::cout << "Diagonal Win" << std::endl;
			return true;
		}
	

		return false;
	}

};