#include <iostream>
using namespace std;
const int SIZE = 8;
//bool is_taken = false;
//bool success = false;


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

/*Check if the location the piece is moving to is already taken.
Check if location entered by the user contains a piece to be moved.
Check if the piece is not moving diagonally.*/



void displayBoard(ostream & stream , char board[SIZE][SIZE]) {
    // print the board

	//print first line
	stream << "  " ;
	for (int x = 0; x < SIZE; x ++){
		//for(int y = 0; y <= SIZE; y ++)

		stream << x << "|" ;
	}
	stream << "\n";

	for (int y = 0; y < SIZE; y ++){
			stream << y << "|";
		for (int x = 0; x < SIZE; x ++){
			stream << board[y][x] << "|" ;
		}
		stream << "\n";
	}

}

void move(int rowSource ,int columnSource, int rowDestination, int columnDestination, int& success, char board[8][8] )
    {
    	//success = 1;
      if (board[rowDestination][columnDestination] == 'b' || board[rowDestination][columnDestination] == 'r'){

      		cout << "“Illegal move!!”." << endl;
      		success = 0;
      	//return;
      }

      else if(board[rowSource][columnSource]== '*'){
  			cout << "“Illegal move!!”." << endl;
      		success = 0;
      }


      else if(board[rowSource][columnSource] == board[rowDestination][columnDestination]){
      	 	cout << "“Illegal move!!”." << endl;
      		success = 0;
      }

      else if(success == 1){
      		int temp = board[rowSource][columnSource];
      		board[rowSource][columnSource] = board[rowDestination][columnDestination];
      		board[rowDestination][columnDestination] = temp;
      		displayBoard(cout, board);
      }
  }




int main()
{
	displayBoard(cout, board);
	int row_Source, column_Source, row_Destination, column_Destination, suc;

	cout << "Select the piece to be moved:" << endl;
	cout << "Move piece from" << endl;
	cout << "Row: ";
	cin >>  row_Source;
	cout << "Columns: ";
	cin >> column_Source;
	cout << "The box: " << endl;
	cout << "Row: ";
	cin >> row_Destination;
	cout << "Columns: "; 
	cin >> column_Destination;

	suc = 1;
	move(row_Source ,column_Source,row_Destination,column_Destination, suc, board);


	return 0;
}