digrapher: 
	gcc -Wall -Wno-trigraphs -o digrapher digrapher.c
	
clean:
	rm -f digrapher digrapher.o
