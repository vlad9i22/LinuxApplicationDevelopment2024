#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>


int main(int argc, char *argv[])
{
	if(argc != 3) {
		printf("move file_to_move destination_file\n");
		return 1;
	}
	if(strcmp(argv[1], argv[2]) == 0) {
		printf("This is the same file\n");
		return 0;
	}
	char* filename = argv[1];
	char* dest = argv[2];
	FILE* fp = fopen(argv[1], "r");
	if(fp == NULL) {
		int errsv = errno;
		printf("Could not open source\n");
		printf("%s", strerror(errsv));
		return errsv;
	}
	size_t len = 0;
	ssize_t read;
	char* line = NULL;
	FILE* fwp = fopen(argv[2], "w");
	while((read = getline(&line, &len, fp)) != -1) {
		fprintf(fwp, "%s", line);
	}
	int errsv = errno;
	printf("%d: %s\n", errsv, strerror(errsv));
	free(line);
	if(fclose(fwp) == 0 && errsv == 0) {
		remove(argv[1]);
	} else {
		remove(argv[2]);
	}
	fclose(fp);
	return errsv;
}
