# Minimal SHA-1
I set out to try and create a small implementation of SHA-1. `sha1.c` contains the original implementation I wrote and `minsha1.c` contains the shrunk down version.

## Running
Both can be compiled with either clang or gcc (might requite `-std=c99` flag). The input is read from stdin.

    clang minsha1.c
    ./a.out "The quick brown fox jumps over the lazy dog"
    2fd4e1c67a2d28fced849ee1bb76e7391b93eb12

## Caveats
Due to the way I simplified the string parsing only an input of 55 characters or less will hash correctly

## Size
    wc -c sha1.c 
        2280 sha1.c
    wc -c minsha1.c 
         726 minsha1.c

