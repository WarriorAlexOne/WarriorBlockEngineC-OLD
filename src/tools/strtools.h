#ifndef STRTOOLS_H
#define STRTOOLS_H

#include <string.h>

int isNum (char c);
int isAlpha (char c);
char stringCopy ();

int isNum (char c) {
    return c >= '0' && c <= '9';
}

int isAlpha (char c) {
    return c >='A' && c <= 'Z' || c >= 'a' && c <= 'z';
}

char stringCopy () {
    char ret;
}

#endif