// Yu Zhou
// TA: Srinjita Bhaduri

#include <iostream>
using namespace std;

int main()
{
	//Variable Declearation
	float Pass_completions;
	float Pass_attempts;
	float Total_passing_yards;
	float Touchdowns;
	float Interceptions;
	float C , Y , T , I , PasserRating;

	cout << "Pass completions: ";
	cin >> Pass_completions;

	cout << "Pass attempts: ";
	cin >> Pass_attempts;

	cout << "Total passing yards: ";
	cin >> Total_passing_yards;

	cout << "Touchdowns!? : ";
	cin >> Touchdowns;

	cout << "Interceptions: ";
	cin >> Interceptions;

	C = (float(Pass_completions) / float(Pass_attempts) - 0.30) * 5;
	Y = float(Total_passing_yards) / (float(Pass_attempts) - 3) * 0.25;
	T = float(Touchdowns) / float(Pass_attempts) * 20;
	I = 2.375 - float(Interceptions) / float(Pass_attempts) * 25;

	PasserRating = (C+Y+T+I)/6*100;	

	if (PasserRating <= 85)
	{
		cout << "Rating: " << PasserRating << ", This is poor" << endl;
	}

	else if (PasserRating > 85 && PasserRating <= 90 )
	{
		cout << "Rating: " << PasserRating << ", This is mediocre";
	}

	else if (PasserRating > 90 && PasserRating <= 95 )
	{
		cout << "Rating: " << PasserRating << ", This is good";
	}

	else if (PasserRating > 95)
	{
		cout << "Rating: " << PasserRating << ", This is great";
	}

	return 0;
}


