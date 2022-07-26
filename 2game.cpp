#include <iostream>
#include <stdlib.h> 
#include <time.h> 
#include <string>

using namespace std;

bool win_rock_papers_scissors() {
	string player_choice;
	int cpu_rand;
	int result = 0;

	cout << "Welcome to rock, papers, scissors!" << endl;
	cout << "Enter 'R', 'P', or 'S' to indicate your choice for simplicity." << endl;
	cout << "Input other than 'R', 'P', & 'S' will be punished." << endl;
	cout << endl;

	cout << "Your choice: " << endl;
	cin >> player_choice;

	if (player_choice == "R" || player_choice == "P" || player_choice == "S")
	{
		srand(time(NULL));
		cpu_rand = rand() % 3;

		if (cpu_rand == 0)
		{
			cout << "cpu_choice = 'R'" << endl;
			if (player_choice == "S")
			{
				result = -1;
			}
		}

		if (cpu_rand == 1)
		{
			cout << "cpu_choice = 'P'" << endl;
			if (player_choice == "R")
			{
				result = -1;
			}
		}

		if (cpu_rand == 2)
		{
			cout << "cpu_choice = 'S'" << endl;
			if (player_choice == "P")
			{
				result = -1;
			}
		}

		if (result == -1)
		{
			cout << "You lose!" << endl;
			return false;
		}

		else
		{
			cout << "Enemy defeated." << endl;
			return true;
		}
	}

	else
	{
		cout << "Failed to comply with the instructions of the input requirement!" << endl;
		cout << "By the highest name of ENGG1340, YOU MUST BE PUNISHED!" << endl;
		cout << "-1" << endl;
		return false;
	}
}
