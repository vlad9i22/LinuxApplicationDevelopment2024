#include <curses.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


char** read_file_to_buffer(char *filename, size_t* line_size) {
	int n = 10;
	int cur = 0;
	char **res = calloc(sizeof(char*), 10);
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	fp = fopen(filename, "r");
	if (fp == NULL) exit(1);
	while((read = getline(&line, &len, fp)) != -1) {
		res[cur] = calloc(sizeof(char), read + 1);
		strncpy(res[cur], line, read + 1);
		cur++;
		if(cur == n) {
			n *= 2;
			res = realloc(res, sizeof(char*) * n);
		}
	}
	*line_size = cur;
	return res;
}

int main(int argc, char *argv[])
{
	if(argc <= 1) {
		printf("Provdie filename to read from");
		exit(1);
	}
	char* filename = argv[1];
	initscr();
	curs_set(0);
	mvaddstr(0, 0, argv[1]);
	refresh();
	const int height = LINES - 4;
	const int width = COLS - 4;

	int offsetx = (COLS - width) / 2;
	int offsety = (LINES - height) / 2;

	size_t line_size = 0;
	char** buffer = read_file_to_buffer(filename, &line_size);
	
	WINDOW *win = newwin(height, width, offsety, offsetx);

	const int MAX_LINE_SIZE = width - 20;
	const int LINES_PER_SCREEN = height - 4;
	int start_of_file = 0;
	for(;;) {
		for(int i = start_of_file; i < start_of_file + LINES_PER_SCREEN; ++i) {
			char num_of_line[13];
			sprintf(num_of_line, "%d:", i);
			mvwaddnstr(win, i - start_of_file + 1, 1, num_of_line,
				       	MAX_LINE_SIZE);
			mvwaddnstr(win, i - start_of_file + 1, 13, buffer[i],
				       	MAX_LINE_SIZE);
		}
		box(win,0 ,0);
		wrefresh(win);
		move(0, 0);
		int ch = getch();
		if(ch == 27) {
			break;
		} else if(ch == ' ') {
			if(start_of_file + LINES_PER_SCREEN < line_size) {
				start_of_file++;
			}
		}
	}
	delwin(win);
	endwin();
	for(int i = 0; i < line_size; ++i) {
		if(buffer[i]) {
			free(buffer[i]);
		}
	}
	free(buffer);
}
