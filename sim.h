#ifndef SIM_H
#define SIM_H

#include <vector>

class Sim {
	public:
		Sim();
		~Sim();

		void generateSim();
		void runAll();
		void printSwitch();
		void printNoSwitch();

		void setTrials(int trialNum);
		int getTrials();
		void setDoors(int doorVal);
		int getDoors();
	private:
		int runNoSwitch();
		int runSwitch();
		int guess;
		int car;
		
		int doorNum;
		std::vector<int> doors; 
		int trials;
};

#endif
