#include <iostream>
#include <stdlib.h> 
#include <time.h>  
#include <string>
using namespace std;

bool winluckyDraw() {
	cout << "Pick a box to test your luck!" << endl;
	cout << "You must input an integer 1, 2, or 3. ";
	cout << "Note that other inputs will lead to disastrous results." << endl;
	cout << endl;
	cout << "  ___________     ___________     ___________  " << endl;
	cout << " |           |   |           |   |           | " << endl;
	cout << " |     *     |   |    ***    |   |    ***    | " << endl;
	cout << " |   * *     |   |   *   *   |   |   *   *   | " << endl;
	cout << " |     *     |   |      *    |   |      *    | " << endl;
	cout << " |     *     |   |    *      |   |   *   *   | " << endl;
	cout << " |   *****   |   |   *****   |   |    ***    | " << endl;
	cout << " |___________|   |___________|   |___________| " << endl;
	cout << endl;

	int result, num;
	string choice;
	cout << "Your choice: ";
	cin >> choice;


	if (isdigit(choice[0]) && choice.length() == 1 && stoi(choice) >= 1 && stoi(choice) <= 3)
	{
		num = stoi(choice);
		srand(time(NULL));
		result = (rand() % 3 + num) % 3;
		if (result == 0)
		{
			cout << "Bad luck! You did not win a prize." << endl;
			return false;
		}

		else
		{
			cout << "Great luck! You get an extra life!" << endl;
			return true;
		}
	}

	else
	{
		cout << "Failed to comply with the instructions of the input requirement!" << endl;
		cout << "By the name of ENGG1340, YOU MUST BE PUNISHED!" << endl;
		cout << "-1" << endl;
		return false;
	}
}
