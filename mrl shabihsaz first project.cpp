#include <iostream>
#include <conio.h>
#include <string>
using namespace std;



class Board
{
private:
	char p[3][3];
	char k;
	/* data */
public:
	Board()
	{
		k = '0';
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				k++;
				p[i][j] = k;
			}//for j
		}//for i
		displayBoard();
	}//Board

	void displayBoard()
	{
		cout<<"\t\t\t\t     |     |     \n";
    	cout<<"\t\t\t\t  "<<p[0][0]<<"  |  "<<p[0][1]<<"  |  "<<p[0][2]<<" \n";
    	cout<<"\t\t\t\t_____|_____|_____\n";
    
    	cout<<"\t\t\t\t     |     |     \n";
    	cout<<"\t\t\t\t  "<<p[1][0]<<"  |  "<<p[1][1]<<"  |  "<<p[1][2]<<" \n";
    	cout<<"\t\t\t\t_____|_____|_____\n";
    
    	cout<<"\t\t\t\t     |     |     \n";
    	cout<<"\t\t\t\t  "<<p[2][0]<<"  |  "<<p[2][1]<<"  |  "<<p[2][2]<<" \n";
    	cout<<"\t\t\t\t     |     |     \n";
	}//displayBoard

	bool check()
	{
		for ( int i = 0 ; i < 3 ; i++ )
		{
			if ( p[i][0] == p[i][1] && p[i][1] == p[i][2] ) return true;
			if ( p[0][i] == p[1][i] && p[1][i] == p[2][i] ) return true;
		}
	
		if ( p[0][0] == p[1][1] && p[1][1] == p[2][2] ) return true;
		if ( p[0][2] == p[1][1] && p[1][1] == p[2][0] ) return true;

		else return false;
	}//check

	int getPlace( char sign )
	{
		int h;
	
	
		while(true)
		{	
			cin >> h;
			if( h<=9 && h>=1 )
			{
				for ( int i = 0 ; i<=2 ; i++ )
				{
					for ( int j = 0 ; j<=2 ; j++ )
					{
						if ( (p[i][j]-'0') == h ) 
						{
							p[i][j] = sign;
							return 0;
						}
					}
				}	
			}
			else cout << "Wrong number :(    try again..\n";
		}
	}
};

class Players
{
private:
	string name;
	char sign;

public:
	Players( string pname, bool p )
	{
		setName( pname );
		setSign( p );
	}//Players

	void setName( string pname ) 
	{
		name = pname;
	}//setName players
	void setSign( bool p )
	{
		if ( p == true ) sign = 'X';
		else sign = 'O';
	}//setSign Players

	string getName()
	{
		return name;
	}
	char getsign()
	{
		return sign;
	}
	

};

int main()
{
    short int k = 0;
    char place, sign;
	

	Board game;
	
	Players player1( "Player1", true );
	Players player2( "Player2", false );
	

	while(true)
	{
		if (k == 9)//full house
    	{
        	std::cout << "no winner:(";
        	break;
    	}//if
        
    	cout << player1.getName() <<" enter a number between 1-9: ";
		sign = player1.getsign();
    	game.getPlace( sign );
    	game.displayBoard();

		if (game.check() == true)//check win
		{
			cout << player1.getName() << " won!!!";
			break;
		}
		
    	k++;
    	if (k == 9)
    	{
        	cout << "no winner:(";
        	break;
    	}
    	
		cout << player2.getName() <<" enter a number between 1-9: ";
		sign = player2.getsign();
    	game.getPlace( sign );
    	game.displayBoard();

		if (game.check() == true)//check win
		{
			cout << player2.getName() << " won!!!";
			break;
		}
		k++;
	}
            
    getch();
    return 0;
}