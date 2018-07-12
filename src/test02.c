/*
 ============================================================================
 Name        : test02.c
 Author      :
 Version     :
 Copyright   : Vonyung
 Description : Test the way of using PdCurses.
 ============================================================================
 */

#include <stdlib.h>
#include <curses.h>

int main(void)
{
	char ch,*c1 = "See Me, See Me!";
	time_t currentTime;
	char *timeStr;

	init();
	start_color();
	init_pair(1,COLOR_GREEN,COLOR_BLACK);
	attron(COLOR_PAIR(1));

	while (1) {
		currentTime = time(NULL);
		timeStr = asctime(localtime(&currentTime));
		mvprintw(LINES /2, (COLS - strlen(timeStr)) /2, timeStr);
		refresh();
		sleep(1);

		ch = getch();
		if (ch =='z' || ch == ' ') {
			endwin();
			return 0;
		}
		refresh();
	} ;



	attroff(COLOR_PAIR(1));
	refresh();

	int i1 = getch();
	printf("%d",i1);

	getch();
	endwin();
	return 0;

}



void init()
{
	initscr();
	raw();
	noecho();
	curs_set(0);

}
