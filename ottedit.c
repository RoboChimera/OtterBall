#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <ncurses.h>

#define DELAY 60000

int x = 0, y = 0;
int max_y = 0, max_x = 0;
int next_y = 0, next_x = 0;
int x_direction = 1, y_direction = 2;
int sprite = 0;
int y_hasCollided = 0;

void ballPhysics() {
	if (next_x >= max_x || next_x < 0) {
		x_direction *= -1;
		y_direction *= -1;
	}
	if (next_y >= max_y || next_y < 0) {
		y_direction *= -1;
		y_hasCollided = 1;
	}

	if (y_hasCollided == 1) {
		if (next_y <= max_y / 2) {
			y_direction *= -1;
		}
	}
}

int main(int argc, char *argv[]) {
	initscr();
	noecho();
	curs_set(FALSE);

	while(1) {
		clear();
		mvprintw(y, x,	"o");

		refresh();
		usleep(DELAY);

		getmaxyx(stdscr, max_y, max_x);
		next_x = x + x_direction;
		next_y = y + y_direction;

		ballPhysics();
		x = x + x_direction;
		y = y + y_direction;
	}

	endwin();
}

