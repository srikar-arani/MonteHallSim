#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main (int argc, char*argv[]) {

	int noSwitch = 0;
	int trials = 1000000;	
	srand(time(NULL));
	for (int j = 0; j < trials; j++) {
	
	int guess;

	guess = rand() % 3;

	int car = rand() % 3;

	int doors [3] = {};
	for(int i = 0; i < 3; i++) {
		doors[i] = 0;
	}
	doors[car] = 1;
	
	if (guess == car) {
		noSwitch++;
	}
	
	}
	

	double percentNoSwitch = noSwitch/1.0;
	percentNoSwitch = percentNoSwitch/trials*100;
	cout << fixed << percentNoSwitch << endl;

	int Switch = 0;
	
	for (int j = 0; j < trials; j++) {
		int guess;
		
		guess = rand() % 3;

		int car = rand() % 3;

		int doors [3] = {};

		for (int i = 0; i < 3; i++) {
			doors[i] = 0;
		}
		doors[car] = 1;

		if (doors[guess] == 0) {
			Switch++;
		}
	}
	
	double percentSwitch = Switch/1.0;
	percentSwitch = percentSwitch/trials*100;

	cout << fixed << percentSwitch << endl;
	return 0;
}
