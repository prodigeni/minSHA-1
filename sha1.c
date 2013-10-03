#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    unsigned int h0 = 0x67452301;
    unsigned int h1 = 0xEFCDAB89;
    unsigned int h2 = 0x98BADCFE; 
    unsigned int h3 = 0x10325476;
    unsigned int h4 = 0xC3D2E1F0;

    unsigned int w[80] = { 0 };

    //copy the input
    char *s = argv[1];
    unsigned int l = strlen(s);
    unsigned char *str = (unsigned char*)malloc(sizeof(unsigned char) * (l + 1));
    memcpy(str, s, sizeof(char) * l);

    //add the '1' bit that needs appending to the input during preprocessing
    str[l] = 1 << 7;

    unsigned int *word = &w[0];
    int counter = 24;
    l++;

    //for each character slide along the words and insert
    //all characters from input end up in most significant bits (with the 1 bit already appended)
    for(unsigned i = 0; i < l; i++)
    {
        *word += str[i] << counter;
        counter -= 8;

        if(counter < 0)
        {
            word++;
            counter = 24;
        }
    }

    free(str);

    //calculate bit length and add to least sig bits of
    unsigned int bl = (l - 1) * 8;
    w[15] = bl;

    //calculate the rest of the words
    for(int i = 16; i < 80; i++)
    {
        unsigned tmp = w[i - 3] ^ w[i - 8] ^ w[i - 14] ^ w[i - 16];
        w[i] = (tmp << 1) | (tmp >> 31);
    }
    
    unsigned int a = h0;
    unsigned int b = h1;
    unsigned int c = h2;
    unsigned int d = h3;
    unsigned int e = h4;
    unsigned int f, k;

    //main sha1 loop
    for(int i = 0; i < 80; i++)
    {
        if(i <= 19)
        {
            f = (b & c) | ((~b) & d);
            k = 0x5A827999;
        }
        else if(i <= 39)
        {
            f = b ^ c ^ d;
            k = 0x6ED9EBA1;
        }
        else if(i <= 59)
        {
            f = (b & c) | (b & d) | (c & d);
            k = 0x8F1BBCDC;
        }
        else if(i <= 79)
        {
            f = b ^ c ^ d;
            k = 0xCA62C1D6;
        }
        unsigned int t = ((a << 5) | (a >> 27)) + f + e + k + w[i];
        e = d;
        d = c;
        c = (b << 30) | (b >> 2);
        b = a;
        a = t;
    }
    h0 += a;
    h1 += b;
    h2 += c;
    h3 += d;
    h4 += e;

    printf("%08x%08x%08x%08x%08x\n", h0, h1, h2, h3, h4);
    
    return 0;
}

