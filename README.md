# Digrapher

This program will take any C source file and convert any characters it can into digraphs or trigraphs. This is purely for fun or as a quick way to add some obsfuscation to your code.

## How to Compile

Download digrapher.c and compile it with GCC by typing:
```
gcc -o digrapher digrapher.c
```

## How to Use

Once compiled run the program by typing:
```
./digrapher <input filename> <output filename> <flag>
```

Available flags are:
```
-t: convert with trigraphs
-d: convert with digraphs
```

## Authors

Daniel Schlicht
