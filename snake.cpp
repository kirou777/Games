#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <windows.h>

using namespace std;

bool gameover; // stan gry
const int width = 20, height = 17; // wymiary planszy
int x, y, score, fruitX, fruitY, nTail; // wynik, pozycja owocu, rozmiar ogona
int lengthY[100], lengthX[100];
enum eDirecton {STOP = 0, LEFT, RIGHT, UP, DOWN}; //sterowanie
eDirecton dir;

/*
inicjalizuje wszystkie zmienne gry na wartoœci pocz¹tkowe
resetuje ogon, wynik, pozycjê gracza i losuje pierwszego owoca
*/
void start() {
	for(int i = 0; i < 100; i++) {
    lengthX[i] = 0;
    lengthY[i] = 0;
}
	score = 0;
	nTail = 0;
	gameover = false;
	dir = STOP;
	x = width / 2, y = height / 2; // ustawienie wê¿a na œrodku
	fruitX = rand() % width, fruitY = rand() % height; //wyswietlanie owocow w lososwych miejscach
}

/*
ustawia kursor konsoli w konkretnej pozycji (x, y)
dziêki temu mo¿emy "rysowaæ" bez przewijania ekranu
*/
void gotoXY(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// rysuje ca³¹ planszê gry: œciany, wê¿a, ogon, owoc i wynik
void map() {
	gotoXY(0, 0); // ustawienie kursora w lewym górnym rogu, ¿eby nadpisywaæ ekran
	
	// górna œciana
	for(int i = 0; i < width + 2; i++) cout << "_";
	cout << endl;
	
	
	for(int ii = 0; ii < height; ii++) {
		for(int j = 0; j < width; j++) {
			
			if(j == 0) cout << "#"; // lewa œciana
			
			if(ii == y && j == x) cout << "O"; // g³owa wê¿a
			
			else if(ii == fruitY && j == fruitX) cout << "%"; // owoc
			else {
				bool print = false;
				
				// sprawdzenie czy w tym miejscu jest ogon
				for(int k = 0; k < nTail; k++) {
					if(lengthX[k] == j && lengthY[k] == ii) {
						cout << "*"; print = true;
					}
				}
				if(!print) cout << " "; // jeœli nie ma rysujemy pust¹ przestrzseñ
			}
			if(j == width -1) cout << "#"; // prawa œciana
		}
		cout << endl;
	}
	// dolna œciana
	for(int jj = 0; jj < width + 2; jj++) cout << "_";
	cout << endl;
	
	cout << "Wynik: " << score << endl;
}

/*
odczytuje wciœniête klawisze bez zatrzymywania programu (_kbhit)
sterowanie:
w - góra
s - dó³
a - lewo
d - prawo
x - zakoñczenie gry
*/
void input() {
	if(_kbhit()) {
		switch(_getch()) {
			case 'a':
				dir = LEFT;
				break;
			case 'w':
				dir = UP;
				break;
			case 's':
				dir = DOWN;
				break;
			case 'd':
				dir = RIGHT;
				break;
			case 'x':
				gameover = true;
				break;
		}
	}
}


// ukrywa migaj¹cy kursor w konsoli (estetyka gry)
void hideCursor() {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);
}

/*
obs³uguje logikê gry:
- ruch ogona
- ruch g³owy
- kolizje
- zbieranie owocu
*/
void game() {
	// aktualizacja ogona
	if(nTail > 0) {
    int prevX = x;
    int prevY = y;
    int prev2X, prev2Y;

	/*
    mechanizm "przesuwania ogona":
    ka¿dy segment przyjmuje pozycjê poprzedniego segmentu
    */
    for(int i = 0; i < nTail; i++) {
        prev2X = lengthX[i];
        prev2Y = lengthY[i];

        lengthX[i] = prevX;
        lengthY[i] = prevY;

        prevX = prev2X;
        prevY = prev2Y;
    }
}
	// ruch g³owy w zale¿noœci od kierunku
	switch(dir) {
		case LEFT:
			x--;
			break;
		case RIGHT:
			x++;
			break;
		case UP:
			y--;
			break;
		case DOWN:
			y++;
			break;
		default:
			break;
	}
	
	// rzechodzenie przez œciany (teleport)
	if(x >= width) x = 0; else if(x < 0) x = width - 1;
	if(y >= height) y = 0; else if(y < 0) y = height - 1;
	
	// kolizja z w³asnym ogonem - koniec gry
	for(int k = 0; k < nTail; k++) 
	if(lengthX[k] == x && lengthY[k] == y) 
	gameover = true;
	
	// zjedzenie owocu
	if(x == fruitX && y == fruitY) {
		score += 10;
		
		// nowy owoc w losowym miejscu
		fruitX = rand() % width;
		fruitY = rand() % height;
		
		nTail++; // wyd³u¿enie ogona
	}
}

/*
g³ówna pêtla gry
inicjalizuje wszystko i uruchamia cykl:
rysowanie -> input -> logika
*/
int main() {
	srand(time(0)); // inicjalizacja losowoœci
	hideCursor();
	start();
	while(!gameover) {
		Sleep(100); // kontrola prêdkoœci
		map();
		input();
		game();
	}
	return 0;
}
