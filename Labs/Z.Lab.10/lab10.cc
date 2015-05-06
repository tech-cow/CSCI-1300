#include <iostream>
#include <stdio.h>
#include "speed.h"
#include "speed.cc"

using namespace std;

int main()
{
	float dist;
	cout << "Enter distance for the car chase game:" << endl;
	cin >> dist;
	cout << "Time taken by slow car: " << slow_car(dist) << endl;
	cout << "Time taken by fast car: " << fast_car(dist) << endl;
	cout << "Ferrari, the faster car has won the car chase game!!" << endl;
	return 0;
}