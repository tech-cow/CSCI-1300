/*
Yu Zhou
Assignment 6
4/5/2015
*/

/*Intro
  Header prints out the header
  For loop constuct the table from 0-127
  Algorithm for Binary takes in number 0-127, transfer from dec to binary, store in array and reverse the order.
  Character, Hexa and Octal are built in function that can does the casting auotmatically which is nice.
  setw helps make the table pretty by setting up the width
  Thanks for grading 
*/



#include <iostream>
#include <iomanip>
using namespace std;


//Binary function


int main()
{

//Empty line
cout << "\n";



//Header
cout << setw(2)<< " Binary "<< "|Decimal" << "|Char" << "|Hexa" << "|Octal|"  << endl;

//For loop that construct the table
 for(int num = 0; num < 128; num++)
    {
      
      //Algorithm to calculate Binary.
      int answer = num; 
      int bits[8];
      for (int i = 0; i < 8; i++)
        {
            int remainder = answer % 2;       
            bits[7 - i] = remainder;
            cout << dec << bits[i];
            answer /= 2;
        }

      //Print out Decimial/Character/Hexa and Octal  
    	if(num <= 32 || num == 127){           // Print Out range from 32-126
    	cout <<"|" << setw(6) << dec << num    // Decimal
          <<" | " << setw(2)  << " - |"      // Character(-)
                  <<setw(3)<< hex << num     // Hex
          <<" | " <<setw(3) << oct << num    // Oct
          <<" | " << endl;
    	}
    	else{                                  // Print out all the others
        cout <<"|"<< setw(6) << dec<< num    // Decimal
        << " | " << setw(2) << (char)num     // Chracter(-)
        << " | " <<setw(2)<< hex << num      // Hex
        << " | " <<setw(3) << oct << num     // Oct
        << " | " << endl;
    	}
    



    }
  return 0;
}