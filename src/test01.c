/*
 ============================================================================
 Name        : test01.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>

#define CHAR_STONE '*'

typedef struct node{
	int x, y;
	struct node *next;
}node, *Node;

Node head;

int main(int argc, char* argv[])
{
//	initscr();
//	raw();
//	noecho();
//	curs_set(2);

	initscr();
	cbreak();
	noecho();
	curs_set(0);
	srand(time(0));

	int i;
	Node tmp, p;

	Node tmp1;

	tmp1 = (node *)malloc(sizeof(node));
	tmp1->next = NULL;
	head = tmp1;

	p = head;
	for(i = 19; i <= 99; i += 20)
	{
		tmp = (node *)malloc(sizeof(node));
		tmp->x = i;
		do{
			tmp->y = rand() % 30;
		}while(tmp->y < 5);
		p->next = tmp;
		tmp->next = NULL;
		p = tmp;
	}

	init_draw();

//
//	char *c = "Hello You!";
//
////	mvprintw(LINES / 2 ,(COLS - strlen(c)) / 2, c);
//	refresh();
//
//	getch();
//	endwin();





	return 0;
}


void init_draw()
{
	Node p;
	int i, j;

	// 遍历链表
	for(p = head->next; p->next != NULL; p = p->next)
	{
		// 绘制柱子
		for(i = p->x; i > p->x-10; i--)
		{
			for(j = 0; j < p->y; j++)
			{
				move(j, i);
				addch(CHAR_STONE);
				refresh();
			}
			for(j = p->y+5; j <= 23; j++)
			{
				move(j, i);
				addch(CHAR_STONE);
				refresh();
			}
		}
		sleep(1);
	}
}


//int main(void) {
//	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
//	return EXIT_SUCCESS;
//}
