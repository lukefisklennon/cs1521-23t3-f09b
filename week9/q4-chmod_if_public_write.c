#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

void chmod_if_public_write(char *path);

int main(int argc, char *argv[]) {
	if (argc < 2) {
		// Print an error to standard error if needed
		fprintf(stderr, "Please provide 1 or more arguments");
	}

	// Loop through the arguments and process each one
	int i = 1;
	while (i < argc) {
		chmod_if_public_write(argv[i]);
		i++;
	}

	return EXIT_SUCCESS;
}

void chmod_if_public_write(char *path) {
	struct stat info;
	int result = stat(path, &info);
	if (result != 0) {
		perror(path);
		return;
	}

	if (info.st_mode & S_IWOTH) {
		printf("removing public write from %s\n", path);

		mode_t mode = info.st_mode & ~S_IWOTH;
		int result = chmod(path, mode);
		if (result != 0) {
			perror(path);
			return;
		}
	} else {
		printf("%s is not publically writable\n", path);
	}
}
