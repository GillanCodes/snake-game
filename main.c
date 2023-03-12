#include <stdlib.h>
#include <stdio.h>

#define ROWS 30
#define COLS 60

int main() 
{

	int x[1000], y[1000];
	int quit = 0;
	while (!quit)
	{
		//Render tabs
		printf("┌");
		for (int i = 0; i < COLS; i++)
			printf("─");
		printf("┐\n");

		for (int j =0; j < ROWS; j++)
		{
			printf("|");
			for (int i = 0; i < COLS; i++)
				printf("·");
			printf("|\n");
		}
	   	
		printf("└");
	   	for (int i = 0; i < COLS; i++)
		  printf("─");
		printf("┘\n");

		// Move Cursor back to top
		printf("\e[%iA", ROWS + 2);
	
		int head = 0, tail = 0;
		x[head] = COLS / 2;
		y[head] = ROWS / 2;
		int gameover = 0;
		int xdir = 0, ydir = 0;

		while (!quit && !gameover)
		{
			//Clear Snake Tail	
			printf("\e[%iB\e[%iC·", y[tail] + 1, x[tail] + 1);
			printf("\e[%iF", y[tail] + 1);

			tail = (tail + 1) % 1000;
			int newhead = (head + 1) % 1000;
			x[newhead] = (x[head] + xdir + COLS) % COLS;
			y[newhead] = (y[head] + ydir + ROWS) % ROWS;

			//Draw Head
			printf("\e[%iB\e[%iC▓", y[head], x[head]);
			printf("\e[%iF", y[head] + 1);
		}

	}
	//Show Cursor
	printf("\e[?25h");
	return 0;
}
