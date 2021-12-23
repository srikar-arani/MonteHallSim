#include <iostream>
#include "sim.h"

using namespace std;

Sim sim;

void displayMenu() {
	cout << "=====================================================" << endl;
	cout << " \t\tMONTY HALL SIMULATOR \t" << endl;
	cout << "=====================================================" << endl;
	cout << " 1.Run Total Simulation" << endl;
	cout << " 2.Run Just Switching" << endl;
	cout << " 3.Run Just Staying" << endl;
	cout << " 4.Change Variables" << endl;
	cout << " 5.Quit" << endl;
}

void runTotalSim() {
	sim.runAll();
}

void runJustSwitch() {
	sim.printSwitch();
}

void runJustStay() {
	sim.printNoSwitch();
}

void runChangeVariables() {
	cout << "Number of Trials: " << sim.getTrials() << endl;
	cout << "Number of Doors: " << sim.getDoors() << endl;

	int newVar;
	cout << "Change Trials: ";
	cin >> newVar;
	sim.setTrials(newVar);
	cout << "Change Doors: ";
	cin >> newVar;
	sim.setDoors(newVar);

	cout << "Number of Trials: " << sim.getTrials() << endl;
	cout << "Number of Doors: " << sim.getDoors() << endl;
}

int main (int argc, char*argv[]) {

	int choice;
	do {		
		cout << "\n\n" << endl;
		displayMenu();
		cout << "Enter choice: ";
		cin >> choice;
		switch (choice) {
			case 1:
				cout << "\n\n" << endl;
				runTotalSim();
				char cont;
				do {
					cout << "Continue? [Y/N]: ";
					cin >> cont;
					if (cont == 'Y' || cont == 'y') {
						break;
					} else if (cont == 'N' || cont == 'n') {
						return 0;
					}
				} while (cont != 'N' || cont != 'n');
				break;
			case 2:
				cout << "\n\n" << endl;
				runJustSwitch();
				do {
					cout << "Continue? [Y/N]: ";
					cin >> cont;
					if (cont == 'Y' || cont == 'y') {
						break;
					} else if (cont == 'N' || cont == 'n') {
						return 0;
					}
				} while (cont != 'N' || cont != 'n');
				break;
			case 3:
				cout << "\n\n" << endl;
				runJustStay();
				do {
					cout << "Continue? [Y/N]: ";
					cin >> cont;
					if (cont == 'Y' || cont == 'y') {
						break;
					} else if (cont == 'N' || cont == 'n') {
						return 0;
					}
				} while (cont != 'N' || cont != 'n');
				break;
			case 4:
				cout << "\n\n" << endl;
				runChangeVariables();
				break;
			case 5:
				return 0;
				break;
			default:
				cout<<"Invalid Choice";
				break;
		}
	} while (choice != 5);
}
