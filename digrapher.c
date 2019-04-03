#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void digraph(FILE *in, FILE *out) {
	
	/* iterate through each character in input file
	 * if it matches a digraph char, replace it with digraph
	 * otherwise copy it to output file
	 */
	int in_quotes = 0; 
	char c = getc(in);
	while(c != EOF) {
		if(in_quotes == 0) {
			switch(c) {
				case '[':
					fputs("<:", out);
					break;
				case ']':
					fputs(":>", out);
					break;
				case '{':
					fputs("<%", out);
					break;
				case '}':
					fputs("%>", out);
					break;
				case '#':
					fputs("%:", out);
					break;
				case '"':
					in_quotes = 1;
					putc(c, out);
					break;
				default:
					putc(c, out);
			}
		}
		else {
			putc(c, out);
			if(c == '"') in_quotes = 0;
		}
		c = getc(in);
	}
}


/* This program reads a c file and converts any characters in it 
 * to their equivalent digraphs.
 */
int main(int argc, char* argv[]){

	char* file;
	
	/* check program invocation */
	if(argc != 2) { 
		printf("Correct usage: ./digrapher <input file>.c <output file>.c -flag\n");
		printf("Flags:\n-digraph for digraph substitution\n-trigraph for trigraph substitution\n");
		return 1;
	}
	else {
		file = argv[1];	
	}

	/* check that file is of correct type (ends in .c) */
	//TODO: also check for .h files
	char* ext = strrchr(file, '.');
	if(ext == NULL || strcmp(ext+1, "c")) {
		printf("Argument must be a '.c' filetype.\n");
		return 1;
	}

	/* check input file exists */
	FILE *in;
	if((in = fopen(file, "r")) == NULL) {
		printf("Error opening input file.\n");
		return 1;
	}
	
	/* create output file */
	//TODO: have output file named like <file>_digraphed.<ext>
	FILE *out;
	if((out = fopen("output.c", "w")) == NULL) {
		printf("Could not create output file.\n");
		return 1;
	}

	digraph(in, out);
	
	/* close files */
	fclose(in);
	fclose(out);
	
	return 0;
}
