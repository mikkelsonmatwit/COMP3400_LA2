#include <stddef.h>
#include <ctype.h>
#include "partc.h"

/**
 * Counts the uppercase characters in a given string
 * 
 * @param str a string of characters
 * 
 * @return the number of uppercase characters
 */
int string_count_upper(const char* str) {
    if (str == NULL) {
        return 0;
    }
    int i = 0;
    int count = 0;
    while(str[i] != '\0') {
        if(str[i] == toupper(str[i])) {
            count++;
        }
        i++;
    }
    return count;
}

/**
 * Concatenate two strings
 * 
 * @param dest the string that is getting added to
 * @param src the string being added to the other
 * 
 * @return the two string put together
 */
char* string_concat(char* dest, const char* src) {
    if(src != NULL && dest != NULL) {
        int i = 0;
        while(dest[i] != '\0') {
            i++;
        }

        int j = 0;
        while(src[j] != '\0') {
            dest[i] = src[j];
            i++;
            j++;
        }
        dest[i] = '\0';
    }
    return dest;
}
