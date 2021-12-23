#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include "sim.h"

using namespace std;

Sim::Sim() {
	doorNum = 3;
	doors.resize(doorNum);
	trials = 1000000;
	srand(time(NULL));
}

Sim::~Sim() {

}

void Sim::generateSim() {
	guess = rand() % doorNum;

	car = rand() % doorNum;

	for(int i = 0; i < doorNum; i++) {
		doors[i] = 0;
	}
	doors[car] = 1;

}

void Sim::runAll() {
	int noSwitch = 0;
	int Switch = 0;

	for (int j = 0; j < trials; j++) {
		generateSim();
		noSwitch += runNoSwitch();
		Switch += runSwitch();
	}


	double percentNoSwitch = noSwitch/1.0;
	percentNoSwitch = percentNoSwitch/trials*100;
	cout << fixed << "Percent of times that not switching gets car: " << percentNoSwitch << endl;


	double percentSwitch = Switch/1.0;
	percentSwitch = percentSwitch/trials*100;
	cout << fixed << "Percent of times that switching gets car: " << percentSwitch << endl;
}

int Sim::runNoSwitch() {	
	/*	int guess;

		guess = rand() % 3;

		int car = rand() % 3;

		int doors [3] = {};

		for(int i = 0; i < 3; i++) {
		doors[i] = 0;
		}
		doors[car] = 1;
	 */
	if (guess == car) {
		return 1;
	}
	return 0;
}

int Sim::runSwitch() {
	/*	int guess;

		guess = rand() % 3;

		int car = rand() % 3;

		int doors [3] = {};

		for (int i = 0; i < 3; i++) {
		doors[i] = 0;
		}
		doors[car] = 1;
	 */
	if (doors[guess] == 0) {
		return 1;
	}
	return 0;
}

void Sim::printNoSwitch() {
	int noSwitch = 0;
	for (int j = 0; j < trials; j++) {
		generateSim();
		noSwitch += runNoSwitch();
	}

	double percentNoSwitch = noSwitch/1.0;
	percentNoSwitch = percentNoSwitch/trials*100;
	cout << fixed << "Percent of times that not switching gets car: " << percentNoSwitch << endl;
}

void Sim::printSwitch() {
	int Switch = 0;
	for (int j = 0; j < trials; j++) {
		generateSim();
		Switch += runSwitch();
	}

	double percentSwitch = Switch/1.0;
	percentSwitch = percentSwitch/trials*100;
	cout << fixed << "Percent of times that switching gets car: " << percentSwitch << endl;
}

void Sim::setTrials (int trialNum) {
	trials = trialNum;
}

int Sim::getTrials () {
	return trials;
}

void Sim::setDoors(int doorVal) {
	doorNum = doorVal;
	doors.resize(doorNum);
}

int Sim::getDoors() {
	return doorNum;
}
