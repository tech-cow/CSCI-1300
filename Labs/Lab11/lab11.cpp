#include <iostream>
using namespace std;
const int SIZE = 8;


char board[8][8]={
    {'*','b','*','b','*','b','*','b'},
    {'b','*','b','*','b','*','b','*'},
    {'*','b','*','b','*','b','*','b'},
    {'*','*','*','*','*','*','*','*'},
    {'*','*','*','*','*','*','*','*'},
    {'r','*','r','*','r','*','r','*'},
    {'*','r','*','r','*','r','*','r'},
    {'r','*','r','*','r','*','r','*'}
};


void displayBoard(char board[SIZE][SIZE]) {
    // print the board

	//print first line
	cout << "  " ;
	for (int x = 0; x < SIZE; x ++){
		//for(int y = 0; y <= SIZE; y ++)

		cout << x << "|" ;
	}
	cout << "\n";

	for (int y = 0; y < SIZE; y ++){
			cout << y << "|";
		for (int x = 0; x < SIZE; x ++){
			cout << board[y][x] << "|" ;
		}
		cout << "\n";
	}

}

int main()
{
	displayBoard(board);
	return 0;
}