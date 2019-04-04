#include <stdio.h>
#include <getopt.h>
#include <string.h>

void digraph(FILE *in, FILE *out) {
	
	/* iterate through each character in input file
	 * if it matches a digraph char, replace it with digraph
	 * otherwise copy it to output file
	 */
	int in_quotes = 0; //if a possible change is part of a string, ignore it
	int c = getc(in);
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
	
	if(!feof(in))
		printf("Something went wrong. EOF not reached.\n");
}

void trigraph(FILE *in, FILE *out) {
	
	/* iterate through each character in input file
	 * if it matches a trigraph char, replace it with trigraph
	 * otherwise copy it to output file
	 */
	int in_quotes = 0;  //if a possible change is part of a string, ignore it
	int c = getc(in);
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
	if(!feof(in))
		printf("Something went wrong. EOF not reached.\n");
}

/* This program reads a c file and converts any characters in it 
 * to their equivalent digraphs.
 */
int main(int argc, char* argv[]){

	int option_idx = 0;
	char* infile;
	char* outfile;
	int flag; // 1 for digraph, 2 for trigraph

	/* parse command line args using getopt */
	while((option_idx = getopt(argc, argv, "i:o:td")) != -1) {
		switch (option_idx) {
				case 'i': //input file name
					infile = optarg;
					printf("Input filename: %s\n", infile);
					break;
				case 'o': //output file name
					outfile = optarg;
					printf("Output filename: %s\n", outfile);
					break;
				case 'd': //digraph flag
					flag = 1;
					printf("Digraph flag selected.\n");
					break;
				case 't': //trigraph flag
					flag = 2;
					printf("Trigraph flag selected.\n");
					break;
				default:
					printf("Option incorrect.\n");
					return 1;
		}		
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
		printf("Error opening output file.\n");
		return 1;
	}

	/* check flag and either use digraph or trigraph */
	switch(flag) {
		case 1:
			digraph(in, out);
			break;
		case 2:
			trigraph(in, out);
			break;
		default:
			printf("Error. Please invoke with -d or -t.\n");
			return 1;
	}
	
	/* close files */
	fclose(in);
	fclose(out);
	
	printf("Conversion successful.\n");
	return 0;
}
