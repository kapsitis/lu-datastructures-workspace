#include <string.h>
#include <cassert>
#include <stdlib.h> 
#include <time.h>

#include "list.h"


static unsigned char h2d(char c)
{
    if ('0' <= c && c <= '9')
    {
        return c - '0';
    }
    if ('A' <= c && c <= 'F')
    {
        return c - 'A' + 10;
    }

    assert('a' <= c && c <= 'f');
    return c - 'a' + 10;
}



int hexToBin(const char* hex, unsigned char* bin)
{
    int cnt = 0;
    while(*hex != '\0')
    {
        assert(*(hex + 1) != '\0');
        bin[cnt] = h2d(*hex) * 16 + h2d(*(hex + 1));
        cnt++;
        hex += 2;
    }
    return cnt;
}

int binToHex(const unsigned char* input, int len, char** hex) {
    char digits[] = "0123456789abcdef";
    *hex = new char[2*strlen((const char*)input) + 1];
    int cnt = 0;
    // while (input[cnt] != '\0') {
    while (cnt < len) {
        (*hex)[2*cnt] = digits[input[cnt] / 16];
        (*hex)[2*cnt + 1] = digits[input[cnt] % 16];
        cnt++;
    }
    (*hex)[2*cnt] = '\0';
    return cnt;
}




static const char* SuccessMessage = "Test succeeded";
static const char* FailureMessage = "Test failed";


List::List() {}

int List::f() {
	return 17;
}


