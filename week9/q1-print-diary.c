#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIARY_FILE ".diary"

int main(int argc, char *argv[]) {
	char *home = getenv("HOME");
	if (home == NULL) {
		home = ".";
	}

	int path_len = strlen(DIARY_FILE) + strlen(home) + 2;
	char *diary_path = malloc(path_len);
	snprintf(diary_path, path_len, "%s/%s", home, DIARY_FILE);

	FILE *diary_file = fopen(diary_path, "r");
	if (diary_file == NULL) {
			perror(diary_path);
			return EXIT_FAILURE;
	}

	int c;
	while ((c = fgetc(diary_file)) != EOF) {
			printf("%c", c);
	}

	fclose(diary_file);
	free(diary_path);

	return EXIT_SUCCESS;
}
