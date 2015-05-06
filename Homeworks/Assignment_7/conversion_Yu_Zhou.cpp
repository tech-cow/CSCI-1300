/*Write a program that asks a user if he or she would like to
 convert from metric to US customary units or from the US system 
 to metric. You will only need to work with length, so meters, 
 feet, and inches. To implement this program, you will need to ask 
 the user if he or she wants to convert from meters to feet and inches
  or from feet and inches to meters. Include in the program a loop that 
  asks the user if he or she wants to do another conversion or to stop.*/

#include <math.h>
#include <iomanip>
#include <iostream>
using namespace std;
const int INCHES_PER_FOOT = 12;
const double METERS_PER_FOOT = 0.3048;


//Prompt given to the user for input of a number of meters as a double
void inputM ( double& meters ){
  cout << "Please type a number : ____ " << endl;
  cin >> meters;
}






//Prompt given to the user for input in the format FF II,
//where FF is an int number of feet and II is a double number
//of inches feet and inches are returned as entered by the
//user.
void inputUS ( int& feet, double& inches ){
cout << "Please input _____ feet(in whole number) now and reminder inches later: " << endl;
cin >> feet;

cout << "Please input the reminder inches: _____" << endl;
cin >> inches;
}





//REQUIRED CONSTANTS: INCHES_PER_FOOT, METERS_PER_FOOT
//inches < 12, feet within range of values for an int
//meters assigned 0.3048 * (feet + inches/12)
//Observe that the requirement to produce centimeters is met
//by the value of the first two decimal places of meters.
void convertUStoM(int feet, double inches, double& meters ){
  if (inches >= INCHES_PER_FOOT){
    cout << "inches exceed it's maximum value"<< endl;
    }
    meters = METERS_PER_FOOT * (feet + inches/12);
}






// REQUIRED CONSTANTS: INCHES_PER_FOOT, METERS_PER_FOOT
//the variable feet is assigned the integer part of
//meters/METERS_PER_FOOT
//the variable inches is assigned the fractional part of
//feet after conversion to inch units.
void convertMtoUS (int& feet, double& inches, double meters ){
  feet = fmod (meters, METERS_PER_FOOT);
 // feet = (int)meters % (int)METERS_PER_FOOT;
  inches = (meters/METERS_PER_FOOT) - feet;
}





//input: the formal argument for meters fits into a double
//output:
//"the value of feet, inches" <feet, inches>
//" corresponds to meters, centimeters is " <meters>
//where meters is displayed as a number with two decimal
//places
void output( int feet, double inches, double meters ){
  //inputM(meters);
  cout << "the value of the feet, inches: " << feet <<"feet "<< inches<<" inches" << endl;

  cout << setprecision(2) << fixed;
  cout << "corresponds to meters, centimeters is " << meters << " cm." << endl;

}





// requests US measure, converts to metric, outputs both
void USToMetric(){
  int feet; 
  double inches; 
  double meters;

  inputUS(feet,inches);
  convertUStoM(feet,inches,meters);
  output(feet,inches,meters);
}





void MetricToUS(){
  int feet; 
  double inches; 
  double meters;

  inputM(meters);
  convertMtoUS(feet,inches,meters);
  output(feet,inches,meters);
}





// request metric measure, converts to US units, outputs both
//To  help  you out,  here  is  the main( ) to  call  your  functions:
int main()
{
   char ans;
   do
   {
     int which;
     cout << "Enter 1 for US units to Metric or " << endl << "Enter 2 for Metric to US units conversion" << endl;
     cin >> which;
      if ( 1 == which )
       USToMetric();
      else
      MetricToUS();

     cout << "Y or y allows another choice of conversion. " << "any other quits" << endl;
     cin >> ans;
    } while ( 'y' == ans || 'Y' == ans );
     cout << "All done." << endl;
     return 0;
}