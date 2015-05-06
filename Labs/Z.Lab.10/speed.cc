#include <iostream>
#include <stdio.h>

using namespace std;

float fast_car(float distance){
	float speed = 217;
	float time = distance / speed;
	return time;
}

float slow_car(float distance){
	float speed = 60;
	float time = distance / speed;
	return time;
}