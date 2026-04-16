#include <iostream>
using namespace std;

// plansza 3x3 z numerami pól
char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char current_marker; // aktualny symbol (X lub O)
int current_player; // aktualny gracz

/*
sprawdza, czy któryœ gracz wygra³
porównuje:
 - wiersze
 - kolumny
 - przek¹tne

jeœli znajdzie 3 takie same znaki -> zwraca current_player (wygranego),
jeœli nie -> zwraca 0
*/
int winner() {
	for(int i = 0; i < 3; i++) {
		// sprawdzanie wierszy
		if(board[i][0] == board[i][1] && board[i][1] == board[i][2]) return current_player;
		
		// sprawdzanie kolumn
		if(board[0][i] == board[1][i] && board[1][i] == board[2][i]) return current_player;
	}
	
	// sprawdzanie przek¹tnych
	if(board[0][0] == board[1][1] && board[1][1] == board[2][2]) return current_player;
	if(board[0][2] == board[1][1] && board[1][1] == board[2][0]) return current_player;
	
	return 0;
}

/*
rysuje aktualny stan planszy w konsoli
*/
void drawBoard() {
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl
    << "-----------\n "
    << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl
    << "-----------\n "
    << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}

/*
umieszcza symbol (X/O) na planszy
slot = liczba od 1 do 9 (wybierana przez gracza)
przeliczanie:
 - zamieniamy numer pola na indeksy [row][col]
 - uwaga: tablica zaczyna siê od 0, a slot od 1
*/
int placeMarker(int slot) {
	// znalezienia pola na planszy
	int row = (slot - 1) / 3;
	int col = (slot - 1) % 3;
	
	// umieszczenie symbolu na planszy (jeœli jest wolne)
	if(board[row][col] != 'X' && board[row][col] != 'O') {
    	board[row][col] = current_marker;
    	return 1;
	} else {
		cout << "Pole zajete!\n";
		return 0;
	}
}

int main() {
	int result = winner();
	bool game = true;
	int slot;
	drawBoard();
	
	// startowy gracz (na razie na sztywno)
	current_marker = 'X';
	while(game) {
		cout << "Umiesc symbol na planszy\n";
		cin >> slot;
		
		// postawienie symbolu oraz zmiana gracza
		if(placeMarker(slot) == 1 && current_marker == 'X') current_marker = 'O';
		else current_marker = 'X';
		
		drawBoard();
		
		// sprawdzenie czy gra jest skoñczona (jeszcze nie dzia³a poprawnie)
		if(result != 0) {
			cout << "Gracz wygral!\n";
			game = false;
		}
	}
	
    return 0;
}
