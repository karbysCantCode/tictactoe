
#include <iostream>

using namespace std;

char gameHolder[9] = { '1','2','3','4','5','6','7','8','9' };
bool currentTurn = false;
int chosenTile = 0;
int turns = 0;
int promptRes = 0;
int currentTile = 0;
bool won = false;
bool running = true;
char teamWon;

void resetBaseValues() {
	for (int i = 0; i < 9; ++i) {
		gameHolder[i] = '1' + i;
	}
	currentTurn = false;
	chosenTile = 0;
	turns = 0;
	promptRes = 0;
	currentTile = 0;
	won = false;
	running = true;
	char teamWon = '\0';
}


void drawGrid() {
	cout << endl;
	cout << "     |     |     " << endl;
	cout << "  " << gameHolder[0] << "  |  " << gameHolder[1] << "  |  " << gameHolder[2] << endl;
	cout << "     |     |     " << endl;
	cout << "-----|-----|-----" << endl;
	cout << "     |     |     " << endl;
	cout << "  " << gameHolder[3] << "  |  " << gameHolder[4] << "  |  " << gameHolder[5] << endl;
	cout << "     |     |     " << endl;
	cout << "-----|-----|-----" << endl;
	cout << "     |     |     " << endl;
	cout << "  " << gameHolder[6] << "  |  " << gameHolder[7] << "  |  " << gameHolder[8] << endl;
	cout << "     |     |     " << endl;
}

int promptUser() {
	if (currentTurn) {
		cout << "X turn, select tile: ";
		cin >> chosenTile;
	}
	else
	{
		cout << "O turn, select tile: ";
		cin >> chosenTile;
	}

	currentTile = --chosenTile;
	if (gameHolder[currentTile] == 'O' || gameHolder[currentTile] == 'X') {
		return 1; // prompt again bum bum
	}
	return 0;
}

void updateTile() {

	if (gameHolder[currentTile] != 'O' && gameHolder[currentTile] != 'X') {

		if (currentTurn) {
			gameHolder[currentTile] = 'X';
			currentTurn = false;
			turns++;
		}
		else {
			gameHolder[currentTile] = 'O';
			currentTurn = true;
			turns++;
		}
	}
}

bool checkForWin() {
	char currentChar = 'X';
	for (int i = 0; i < 2; ++i) {
		if (i == 1) {
			currentChar = 'O';
		}
		// horizontals
		if (gameHolder[0] == currentChar && gameHolder[1] == currentChar && gameHolder[2] == currentChar) {
			cout << "win!";
			teamWon = currentChar;
			return true;
		}
		else if (gameHolder[3] == currentChar && gameHolder[4] == currentChar && gameHolder[5] == currentChar) {
			cout << "win!";
			teamWon = currentChar;
			return true;
		}
		else if (gameHolder[6] == currentChar && gameHolder[7] == currentChar && gameHolder[8] == currentChar) {
			cout << "win!";
			teamWon = currentChar;
			return true;
		}
		// verticals
		if (gameHolder[0] == currentChar && gameHolder[3] == currentChar && gameHolder[6] == currentChar) {
			cout << "win!";
			teamWon = currentChar;
			return true;
		}
		else if (gameHolder[1] == currentChar && gameHolder[4] == currentChar && gameHolder[7] == currentChar) {
			cout << "win!";
			teamWon = currentChar;
			return true;
		}
		else if (gameHolder[2] == currentChar && gameHolder[5] == currentChar && gameHolder[8] == currentChar) {
			cout << "win!";
			teamWon = currentChar;
			return true;
		}
		// diags

		if (gameHolder[0] == currentChar && gameHolder[4] == currentChar && gameHolder[8] == currentChar) {
			cout << "win!";
			teamWon = currentChar;
			return true;
		}
		else if (gameHolder[6] == currentChar && gameHolder[4] == currentChar && gameHolder[2] == currentChar) {
			cout << "win!";
			teamWon = currentChar;
			return true;
		}
	}
	return false;
}

int runGame() {
	drawGrid();

	while (turns < 9 && won == false) {
		promptRes = promptUser();
		while (promptRes == 1) {
			promptRes = promptUser();
		}
		updateTile();
		drawGrid();
		won = checkForWin();
	}

	if (won) {

		cout << endl << "game over, " << teamWon << " won!";
	}
	else {
		cout << "game over! YOU ALL LOST AHAHAHAH)A";
	}
	cout << endl << "restart? [Y]/[N]: ";
	char reload;
	cin >> reload;
	if (reload == 'N' || reload == 'n') {
		running = false;
	}
	else
	{
		resetBaseValues();
	}
	return 0;
}

int main() {

	while (running) {
		runGame();
	}

	return 0;
}