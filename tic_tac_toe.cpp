#include <iostream>
using namespace std;

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}}, current_marker;
int current_player;
int winner() {
	for(int i = 0; i < 3; i++) {
		if(board[i][0] == board[i][1] && board[i][1] == board[i][2]) return current_player;
		if(board[0][i] == board[1][i] && board[1][i] == board[2][i]) return current_player;
	}
	if(board[0][0] == board[1][1] && board[1][1] == board[2][2]) return current_player;
	if(board[0][2] == board[1][1] && board[1][1] == board[2][0]) return current_player;
	return 0;
}

void drawBoard() {
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl
    << "-----------\n "
    << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl
    << "-----------\n "
    << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}

void placeMarker(int slot) {
	int row = slot / 3, col;
	if(slot % 3 == 0) {
		row -= 1;
		col = 2;
	} else col = slot % 3 - 1;
	board[row][col] = current_marker;
}

int main() {
	int game = true;
	int slot;
	drawBoard();
	current_marker = 'X';
	while(game) {
		cout << "Umiesc symbol na planszy\n";
		cin >> slot;
		placeMarker(slot);
		if(current_marker == 'X') current_marker = 'O';
		else current_marker == 'X';
		drawBoard();
	}
	
	winner();
    return 0;
}
