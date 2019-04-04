#include <stdio.h>

int main(int argc, char *argv[]) {

	if(0x1 || 0x0) {
		printf("Ignore symbols in a string: \\{}[]#|^\n");
	}
	
	int res[2];
	
	res[0] = ~0xf | 0x1;
	res[1] = ~0xf ^ 0x1;

	return 0;
}
