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

void trigraph(FILE *in, FILE *out) {
	
	/* iterate through each character in input file
	 * if it matches a trigraph char, replace it with trigraph
	 * otherwise copy it to output file
	 */
	int in_quotes = 0; 
	char c = getc(in);
	while(c != EOF) {
		if(in_quotes == 0) {
			switch(c) {
				case '[':
					fputs("??(", out);
					break;
				case ']':
					fputs("??)", out);
					break;
				case '{':
					fputs("??<", out);
					break;
				case '}':
					fputs("??>", out);
					break;
				case '#':
					fputs("??=", out);
					break;
				case '\\':
					fputs("??/", out);
					break;
				case '^':
					fputs("??'", out);
					break;
				case '|':
					fputs("??!", out);
					break;
				case '~':
					fputs("??-", out);
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

	char* infile;
	char* outfile;
	char* flag;
	
	/* check program invocation */
	if(argc != 4) { 
		printf("Correct usage: ./digrapher <input file> <output file> flag\n");
		printf("Flags:\n-d: digraph substitution\n-t: trigraph substitution\n");
		return 1;
	}
	else {
		infile = argv[1];	
		outfile = argv[2];
		flag = argv[3];
	}

	/* check that file is of correct type (ends in .c) */
	//TODO: also check for .h files
	char* ext = strrchr(infile, '.');
	if(ext == NULL || strcmp(ext+1, "c")) {
		printf("Argument must be a '.c' filetype.\n");
		return 1;
	}

	/* check input file exists */
	FILE *in;
	if((in = fopen(infile, "r")) == NULL) {
		printf("Error opening input file.\n");
		return 1;
	}
	
	/* create output file */
	FILE *out;
	if((out = fopen(outfile, "w")) == NULL) {
		printf("Could not create output file.\n");
		return 1;
	}

	/* check flag and either use digraph or trigraph */
	if(!strcmp(flag, "-d")) {
		digraph(in, out);
	} if(!strcmp(flag, "-t")) {
		trigraph(in, out);
	} else {
		printf("Unknown or missing flag.\n");
		printf("Use -d for digraph substitution or -t for trigraph substitution.\n");
	}
	
	/* close files */
	fclose(in);
	fclose(out);
	
	return 0;
}
