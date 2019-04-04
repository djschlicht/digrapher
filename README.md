# Digrapher

This program will take a C source file and convert any characters it can into digraphs or trigraphs. This is purely for fun or as a quick way to add some obfuscation to your code.

## How to Use

To compile use:
```
make digrapher
```

To run use:
```
./digrapher -i <input filename> -o <output filename> -flag
```

Available flags:
```
-d: convert to digraphs
-t: convert to trigraphs
```
Note: When using -t, you need to compile the newly created file using the -trigraphs flag.

## Examples

Here is some test code:
```
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
```
Here is the same code after being digraphed:
```
%:include <stdio.h>
int main(int argc, char *argv<::>) <%
	if(0x1 || 0x0) <%
		printf("Ignore symbols in a string: \\{}[]#|^\n");
	%>
	int res<:2:>;
	res<:0:> = ~0xf | 0x1;
	res<:1:> = ~0xf ^ 0x1
	return 0;
%>
```
Here is the same code after being trigraphed:
```
??=include <stdio.h>
int main(int argc, char *argv??(??)) ??<
	if(0x1 ??!??! 0x0) ??<
		printf("Ignore symbols in a string: \\{}[]#|^\n");
	??>	
	int res??(2??);	
	res??(0??) = ??-0xf ??! 0x1;
	res??(1??) = ??-0xf ??' 0x1;
	return 0;
??>
```

## Authors

Daniel Schlicht
