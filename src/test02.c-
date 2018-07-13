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
#include <conio.h>
#include <curses.h>
#include <sys/time.h>
#include <stdio.h>


void init();

int main(void)
{
	char ch,*timeStr, *c1 = "\"Press z\" to Quit.";
	time_t currentTime;

	init();
	start_color();
	init_pair(1,COLOR_GREEN,COLOR_BLACK);
	init_pair(2,COLOR_CYAN,COLOR_BLACK);

	//Draw some hints,borders.
	timeStr = asctime(localtime(&currentTime));
	attron(COLOR_PAIR(2));
	mvprintw(LINES -1, COLS - strlen(c1) -20 , c1);
//	mvprintw(LINES /2 -5,(COLS - strlen(timeStr)) /2 -5, ' ');
	vline('*',10);
	attroff(COLOR_PAIR(2));

	//Draw Time String.
	attron(COLOR_PAIR(1));
	while (1) {
		currentTime = time(NULL);
		timeStr = asctime(localtime(&currentTime));

		mvprintw(LINES /2, (COLS - strlen(timeStr)) /2, timeStr);
		refresh();
//		sleep(1);

		if (kbhit()) {
			ch = getch();
			if (ch =='z' || ch == ' ') {
				endwin();
				return 0;
			}
		}
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

