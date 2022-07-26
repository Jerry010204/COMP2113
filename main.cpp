#include <iostream>
#include <vector>
#include <stdlib.h> 
#include <time.h> 
#include <string>
#include <algorithm>

using namespace std;

#define options       5 // no of possible options
#define no_of_wheels  6

struct character {
	int x;
	int y;
	int health;
	char skin;
};

struct Player {
	string name;
	int step;
};

struct Player player;
vector<character> enemies;
vector<Player> fastestRecord;


bool operator<(const Player& a, const Player& b) {
	if (a.step != b.step)
		return a.step < b.step;
	return a.name < b.name;
}
bool ExceedMap(int x, int y) {
	return y > 18 || y<1 || x < 1 || x > 88;
}

bool isMap1(int x, int y) {
	return (y <= 5 && x == 20) ||
		(y >= 14 && x == 69) ||
		(y == 10 && x <= 19);
}
void changePos(char move, int* kingX, int* kingY) {
	if (move == 'a') {
		(*kingX)--;
		player.step++;
		if (ExceedMap(*kingX, *kingY)|| isMap1(*kingX, *kingY)) {
			(*kingX)++;
			player.step--;
		}
	}
	else if (move == 'd') {
		(*kingX)++;
		player.step++;
		if (ExceedMap(*kingX, *kingY )|| isMap1(*kingX, *kingY)) {
			(*kingX)--;
			player.step--;
		}
	}
	else if (move == 'w') {
		(*kingY)--;
		player.step++;
		if (ExceedMap(*kingX, *kingY) || isMap1(*kingX, *kingY)) {
			(*kingY)++;
			player.step--;
		}
	}
	else if (move == 's') {
		(*kingY)++;
		player.step++;
		if (ExceedMap(*kingX, *kingY) || isMap1(*kingX, *kingY)) {
			(*kingY)--;
			player.step--;
		}
	}
	
}

bool foundEnemy(int x, int y) {
	vector<character>::iterator iter;
	for (iter = enemies.begin(); iter != enemies.end(); iter++) {
		if (iter->x == x && iter->y == y)
			return true;
	}
	return false;
}
void showMap(int posX, int posY, char skin) {
	for (int y = 0; y < 20; y++) {
		for (int x = 0; x < 90; x++) {
			if (x == 0 || y == 0 || y == 19 || x == 89) {
				cout << "x";
			}
			else if (x == posX && y == posY) {
				cout << skin;
			}
			else if (foundEnemy(x, y)) {
				cout << "o";
			}
			else if (isMap1(x, y))
				cout << "x";
			else if (isMap1(x, y))
				cout << "x";
			else if (isMap1(x, y))
				cout << "x";
			else
				cout << " ";
		}
		cout << endl;
	}
}

void add_enemy(character c) {
	enemies.push_back(c);
}

void randomGenerateEnemy() {
	character c;
	c.x = rand() % 86 + 2;
	c.y = rand() % 16 + 2;
	while (isMap1(c.x, c.y)) {
		c.x = rand() % 86 + 2;
		c.y = rand() % 16 + 2;
	}
	add_enemy(c);
}



bool winluckyDraw();

bool win_rock_papers_scissors();

int transcribe(int val);

bool winLogicWheel();
	
bool winFinalBattle() {
	return winLogicWheel();
}
void clearTheEnemy(character *king) {
	vector<character>::iterator iter;
	int index = 0;
	for (iter = enemies.begin(); iter != enemies.end(); iter++) {
		if (iter->x == king->x && iter->y == king->y){
			enemies.erase(enemies.begin() + index);
			return;
		}
		index++;

	}
}
void winInBattle(character *king) {
	(king->health)++;
	clearTheEnemy(king);
}

void loseInBattle(character *king) {
	(king->health)--;
	king->x++;
	king->y--;
}

void printHealth(int health) {
	for (int i = 0; i < health; i++) {
		cout << '*';
	}
}
void battle(character *king) {
	int i = rand() % 2 + 1;
	if (i == 1) {
		if (winluckyDraw()) {
			winInBattle(king);
		}
		else
			loseInBattle(king);
	}
		
	else {
		if (win_rock_papers_scissors()) {
			winInBattle(king);
		}
		else
			loseInBattle(king);
	}
}

bool enemiesExist(int numOfEnemies) {
	return numOfEnemies != 0;
}

bool isDead(int health) {
	return health == 0;
}

bool incorrectSelection(int s) {
	return s != 1 && s != 2 && s != 3 && s != 4 && s !=5;
}

void selectSkin(char *s) {
	cout<<"Type a character to be your skin: " << endl;
	cin >> s;
}

void initialTheGame(int *x, int *y, int *health) {
	*x = 87;
	*y = 17;
	*health = 3;
	player.step = 0;
	enemies.clear();
	for (int i = 0; i < 3; i++) {  ////////////////////////////////////////////
		randomGenerateEnemy();
	}

}

void putInToRecord() {
	struct Player currentPlayer;
	currentPlayer.name = player.name;
	currentPlayer.step = player.step;
	if (fastestRecord.size() == 5) {
		fastestRecord[5] = currentPlayer;
	}
	else
		fastestRecord.push_back(currentPlayer);
	struct Player temp;
	sort(fastestRecord.begin(), fastestRecord.end());
}
void showTheFastestRecord() {
	vector<Player>::iterator iter;
	int i = 0;
	for (iter = fastestRecord.begin(); iter != fastestRecord.end(); iter++) {
		i++;
		if (iter->name == "Null")
			break;
		cout << i << ": " << iter->name << endl<< " He takes " << iter->step << " to finish the game." << endl;
	}
	if (i == 0) {
		cout << "--- No record  ---" << endl;
	}
	char a;
	cout << "Type any letter to leave the page..." << endl;
	cin >> a;
}
void printInformation(int health) {
	cout << "health: ";
	printHealth(health);
	cout << "                       Number of enemies: " << enemies.size() << "     Number of steps you have taken:" << player.step << endl;
}
void mainGame(character* king, char *move, bool *haveRecord, bool isNewGame) {
	if (!(*haveRecord)|| isNewGame) {
		initialTheGame(&(*king).x, &(*king).y, &(*king).health);
		cout << "What is your name? ";
		cin >> player.name;
		cout << "You are imprison in dungeon! Kill all the enemy the escape from here!" << endl;
		cout << "Type 'w', 's', 'a', 'd' to control your character; Type 'x' if you want to exit the game." << endl;
	}
	cout << "Type any letter to start the game now!" << endl;
	cin >> move;
	while (!(*move == 'x')) {
		changePos(*move, &(*king).x, &(*king).y);
		showMap((*king).x, (*king).y, (*king).skin);
		if (foundEnemy((*king).x, (*king).y)) {
			battle(king);
			if (isDead((*king).health)) {
				cout << "You are dead!" << endl;
				*haveRecord = false;
				break;
			}
			else if (!enemiesExist(enemies.size())) {
				cout << "You will be transfered to another game. You will successfully excape from here if you win the game!" << endl;
				cout << "Type any letter to go to next step" << endl;
				cin >> move;
				while (!winFinalBattle()) {
					king->health--;
					showMap((*king).x, (*king).y, (*king).skin);
					printInformation((*king).health);
					cout<< endl;
					cout<< endl;
					cout<< endl;
					cout<< endl;
					cout<< endl;
					if (isDead((*king).health)) {
						cout << "You are dead!" << endl;
						*haveRecord = false;
						break;
					}
					cout << "Type any letter to play again." << endl;
					cin >> move;
				}
				cout << "You win!!" << endl;
				*haveRecord = false;
				putInToRecord();
				break;
			}
			showMap((*king).x, (*king).y, (*king).skin);
		}
		printInformation((*king).health);

		
		cin >> move;
	}
}

void saveGameOrNot(char *move, character *king, bool *haveRecord){
	if (*move == 'x') {
		cout << "Do you want to save the game? (Y/N)" << endl;
		char save;
		cin >> save;
		while (save != 'Y' && save != 'N') {
			cout << "Please type the correct character." << endl;
			cout << "Do you want to save the game? (Y/N)" << endl;
			cin >> save;
		}
		if (save == 'N') {
			*haveRecord = false;
			initialTheGame(&(*king).x, &(*king).y, &(*king).health);
		}
		else if (save == 'Y')
			*haveRecord = true;
	}
}

int main() {
	char move;
	struct character king;
	king.skin = '*';
	int selection = 0;
	bool haveRecord = false;
	//bool isWinned = false;
	initialTheGame(&king.x, &king.y, &king.health);
	// level One of game
	while (selection != 5) {
		cout << "      Welcome to 《Escape from dungeon》!!      " << endl;
		cout << endl;
		cout << "***---- 1. Start a new game       ----***" << endl;
		cout << "***---- 2. Continue the last game ----***" << endl;
		cout << "***---- 3. Select the skin        ----***" << endl;
		cout << "***---- 4. Fastest Record         ----***" << endl;
		cout << "***---- 5. Exit                   ----***" << endl;
		cout << "What do you want to do? ";
		
		cin >> selection;
		while (incorrectSelection(selection)) {
			cout << "***---- 1. Start a new game       ----***" << endl;
			cout << "***---- 2. Continue the last game ----***" << endl;
			cout << "***---- 3. Select the skin        ----***" << endl;
			cout << "***---- 4. Fastest Record         ----***" << endl;
			cout << "***---- 5. Exit                   ----***" << endl;
			cout << "Please type the correct number!" << endl;
			cout << "What do you want to do? ";
			
			cin >> selection;
		}
		if (selection == 1) {
			//isWinned = false;
			mainGame(&king, &move, &haveRecord, true);
			saveGameOrNot(&move, &king, &haveRecord);
		}
		else if (selection == 2) {
			if (haveRecord) {
				mainGame(&king, &move, &haveRecord, false);
				saveGameOrNot(&move, &king, &haveRecord);
			}
			else
				cout << "Record is not found, please start a new game." << endl;
			
		}
		else if (selection == 3) {
			selectSkin(&king.skin);
		}
		else if (selection == 4) {
			showTheFastestRecord();
		}

	}
	
	return 0;
}
