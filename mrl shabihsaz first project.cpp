#include <iostream>
#include <conio.h>
using namespace std;


void display_board( char p[3][3] )
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
}

bool check( char p[3][3] )
{
	for ( int i = 0 ; i < 3 ; i++ )
	{
		if ( p[i][0] == p[i][1] && p[i][1] == p[i][2] ) return true;
		if ( p[0][i] == p[1][i] && p[1][i] == p[2][i] ) return true;
	}
	
	if ( p[0][0] == p[1][1] && p[1][1] == p[2][2] ) return true;
	if ( p[0][2] == p[1][1] && p[1][1] == p[2][0] ) return true;
	
	else return false;
}

int getPlace(char p[3][3] , bool player )
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
						if ( player == true ) 
						p[i][j] = 'X';
						else 
						p[i][j] = 'O';
						return 0;
					}
				}
			}	
		}
		else cout << "Wrong number :(    try again..\n";
	}
}

int main()
{
    short int k = 0, placer1, placec1, placer2, placec2, i, j, p1 = 0, p2 = 0;
    char place;
    char p[3][3] = {'1','2','3','4','5','6','7','8','9'};
	
	display_board( p );
	
	while(true)
	{
		
	
		if (k == 9)
    	{
        	cout << "no winner:(";
        	break;
    	}	
        
    	cout << "Player1 enter a number between 1-9: ";
    	getPlace( p , true );

    	display_board( p );

		if (check( p ) == true) 
		{
			cout << "player 1 won!!!";
			break;
		}
		
    	k++;
    	if (k == 9)
    	{
        	cout << "no winner:(";
        	break;
    	}
    	
		cout << "Player2 enter a number between 1-9: ";
		getPlace( p , false );
        
    	display_board( p );
        
		if (check( p ) == true) 
		{
			cout << "player 2 won!!!";
			break;
		}
		k++;
	}
            
    getch();
    return 0;
}