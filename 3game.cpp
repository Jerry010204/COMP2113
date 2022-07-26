#include <iostream>
#include <cstdlib> 
#include <string>

#define options       5 // no of possible options
#define no_of_wheels  6 // no of alphabet the player has to guess

using namespace std;

int transcribe(int val) // change integer values to symbol
{
    switch (val)
    {
        case 0:
	    return 'E';
	case 1:
	    return 'G';
	case 2:
            return 'L';
	case 3:
	    return 'N';
	case 4:
            return 'A';
    }
    return 0;
}

bool winLogicWheel()
{
    char answers[no_of_wheels];
    char initial[no_of_wheels];
    int correct_answers = 0;
    int attempts_left = 10;

    cout << "Welcome to the logic wheels!" << endl;
    cout << "In this minigame, you have to guess all the alphabets correctly." << endl;
    cout << "You have ten rounds of input." << endl;
    cout << "The possible alphabets are 'E', 'N', 'L', 'A', and 'G'." << endl;
    cout << "In each round of input, you can guess any combination." << endl;
    cout << "Example: " << endl;
    cout << "Initial:        !$%&&% (No correct answers for the initial)" << endl;
    cout << "Correct answer: #&##!# (Will not show correct answer)" << endl; 
    cout << "Input :         %&!#!! (Your input should not contain spaces.";
    cout << "Otherwise the input cannot be read properly.";
    cout << "(Only the first six characters will be read. Invalid characters will not work.)" << endl;
    cout << "Output : 3 correct answers. 9 attempt left." << endl;
    cout << "The game ends when you run out of moves or you guess all correct answers." << endl;

    srand(time(NULL));
    for (int i=0; i<no_of_wheels; i++)
        {answers[i] = transcribe(rand() % options);}

    for (int i=0; i<no_of_wheels; i++)
        {
	int temp = rand() % options;
	if (transcribe(temp) == answers[i])
            {initial[i] = transcribe((temp + (rand()%(options-1)+1))%options);} //make sure the no correct answers for provided initial	    
	    
        else
            {initial[i] = transcribe(temp);}
	}

    for (int i=0; i<no_of_wheels; i++)
        {cout << answers[i] << " ";}
    cout << endl;

    cout << "Initial answers:           ";
    for (int i=0; i<no_of_wheels; i++)
        {cout << initial[i];}
    cout << endl;
    cout << "Number of correct answers: 0" << endl;
    cout << endl; 

    while (correct_answers < no_of_wheels && attempts_left > 0)
        {
	string input_str;
	int min;
	cout << "Reminder: The possible letters are 'A', 'N', 'G', 'E', and 'L'." << endl;
        cout << "Your answer:               ";

	cin >> input_str;
        cout << endl;
        attempts_left --;
	correct_answers = 0;
	int len = input_str.length();
        
	if (len < no_of_wheels)
	    {min = len;}
	else
	    {min =no_of_wheels;}

        cout << "Answers accepted:          ";

        if (min != 0)
	    {
            for (int i=0; i<min; i++) // length of input maybe < no_of_wheels
	        {
		cout << input_str[i];
                if (answers[i] == input_str[i])
	            {correct_answers ++;}
	        }
            }

        cout << endl;
        cout << "Number of correct answers: " << correct_answers << endl;
        cout << "Number of attempts left:   " << attempts_left   << endl;
        cout << endl;
	}

    if (correct_answers == no_of_wheels)
        {
	cout << "Success!" << endl;
	return true;
	}


    cout << "You failed." << endl;
    return false;
}
