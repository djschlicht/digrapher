# Digrapher

This program will take a C source file and convert any characters it can into digraphs or trigraphs. This is purely for fun or as a quick way to add some obsfuscation to your code.

## How to Use

To compile use:
```
make digrapher
```

To run type:
```
./digrapher -i <input filename> -o <output filename> -flag
```

Available flags:
```
-d: convert to digraphs
-t: convert to trigraphs
```
Note: When using -t, you need to compile the newly created file using the -trigraphs flag.

## Authors

Daniel Schlicht
