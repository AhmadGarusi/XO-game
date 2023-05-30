#include <iostream>
#include <string>
using namespace std;

class Player
{
private:
	std::string name;
	char sign;

public:
	Player()
	{

	} // Players

	void setName(std::string pname)
	{
		name = pname;
	} // setName players
	void setSign(char p)
	{
		sign = p;
	} // setSign Players

	std::string getName()
	{
		return name;
	}
	char getSign()
	{
		return sign;
	}

	void input(short int k, Player players[0])
	{
		std::string pn;
		char s;
		std::cout << "Player" << k << " enter your name: ";
		std::cin >> pn;
		setName(pn);

		std::cout << "Player" << k << " enter your sign: ";
		while (true)
		{
			std::cin >> s;
			if (players[0].getSign() == s)
				std::cout << "same sign: ";
			else
			{
				setSign(s);
			}
		}
	}
};

class Game
{
private:
	char p[3][3];
	char k;
	short int k1; // k shomarande ke bishtar az 9 nemire
	char place, sign;
	Player players[2];
	/* data */
public:
	Game()
	{
		k1 = 0;
		k = '0';
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				k++;
				p[i][j] = k;
			} // for j
		}	  // for i
	}		  // Board

	void input()
	{
		char si1, si2;
		std::string pn;

		players[0].input();
		while (players[1].getSign() == players[0].getSign())
		{
			players[1].input();
		}

		/* std::cout << "Player 1, enter your name: ";
		std::cin >> pn;
		players[0].setName(pn);
		std::cout << "Enter your sign: ";
		std::cin >> si1;
		players[0].setSign(si1);

		std::cout << "Player 2, enter your name: ";
		std::cin >> pn;
		players[1].setName(pn);
		std::cout << "Enter your sign: ";
		while (true)
		{
			std::cin >> si2;
			if (si1 != si2)
			{
				players[1].setSign(si2);
				break;
			}
			else
				std::cout << "Signs are same try another sign player2: ";
		} */
	}

	void run()
	{
		while (true)
		{
			if (k1 == 9) // full house
			{
				std::cout << "no winner:(";
				break;
			} // if

			std::cout << players[0].getName() << " enter a number between 1-9: ";
			getPlace(k1);
			displayBoard();

			if (check() == true) // check win
			{
				std::cout << players[0].getName() << " won!!!";
				break;
			}

			k1++;
			if (k1 == 9)
			{
				std::cout << "no winner:(";
				break;
			}

			std::cout << players[1].getName() << " enter a number between 1-9: ";
			sign = players[1].getSign();
			getPlace(k1);
			displayBoard();

			if (check() == true) // check win
			{
				std::cout << players[1].getName() << " won!!!";
				break;
			}
			k1++;
		}
	}

	void displayBoard()
	{
		std::cout << "\t\t\t\t     |     |     \n";
		std::cout << "\t\t\t\t  " << p[0][0] << "  |  " << p[0][1] << "  |  " << p[0][2] << " \n";
		std::cout << "\t\t\t\t_____|_____|_____\n";

		std::cout << "\t\t\t\t     |     |     \n";
		std::cout << "\t\t\t\t  " << p[1][0] << "  |  " << p[1][1] << "  |  " << p[1][2] << " \n";
		std::cout << "\t\t\t\t_____|_____|_____\n";

		std::cout << "\t\t\t\t     |     |     \n";
		std::cout << "\t\t\t\t  " << p[2][0] << "  |  " << p[2][1] << "  |  " << p[2][2] << " \n";
		std::cout << "\t\t\t\t     |     |     \n";
	} // displayBoard

	bool check()
	{
		for (int i = 0; i < 3; i++)
		{
			if (p[i][0] == p[i][1] && p[i][1] == p[i][2])
				return true;
			if (p[0][i] == p[1][i] && p[1][i] == p[2][i])
				return true;
		}

		if (p[0][0] == p[1][1] && p[1][1] == p[2][2])
			return true;
		if (p[0][2] == p[1][1] && p[1][1] == p[2][0])
			return true;

		else
			return false;
	} // check

	int getPlace(int k1)
	{
		int h;

		while (true)
		{
			std::cin >> h;
			if (h <= 9 && h >= 1)
			{
				for (int i = 0; i <= 2; i++)
				{
					for (int j = 0; j <= 2; j++)
					{
						if ((p[i][j] - '0') == h)
						{
							if ((k1 % 2) == 0)
							{
								p[i][j] = players[0].getSign();
								return 0;
							}
							else
							{
								p[i][j] = players[1].getSign();
								return 0;
							}
						}
					}
				}
			}
			else
				std::cout << "Wrong number :(    try again..\n";
		}
	}
};

int main()
{
	Game g;
	g.input();
	g.run();

	std::cin.get();
	return 0;
}