#include <stdio.h>

void convert(int value) {
	printf("%d = 0x%x = 0%o\n", value, value, value);
}

int main() {
	convert(10);
}
