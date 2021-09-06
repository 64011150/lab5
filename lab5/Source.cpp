#include<stdio.h>
#include<windows.h>
#include<conio.h>
void drawship()
{
	printf(" <-0-> ");
}
void gotoxy(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void draw_ship(int x, int y)
{
	gotoxy(x, y);
	drawship();
}
void eraseship()
{
	printf("         ");
}
void erase_ship(int x, int y)
{
	gotoxy(x, y);
	eraseship();
}
int main(){
	char ch = ' ';
	int x = 38, y = 20;
	int a = y + 1;
	int b = y - 1;
	draw_ship(x, y);
	erase_ship(x, y);
	do {
		if (_kbhit()) {
			ch = _getch();
			if (x >= 72) { x = 72; }
			if (x <= 1) { x = 1; }
			if (ch == 'a') { draw_ship(--x, y); }
			if (ch == 'd') { draw_ship(++x, y); }
			if (ch == 'w') {
				erase_ship(x, y);
				draw_ship(x, --y); 
			}
			if (ch == 's') { 
				erase_ship(x, y);
				draw_ship(x, ++y);
			}
			fflush(stdin);
		}
		Sleep(100);
	} while (ch != 'x');
	return 0;
}
