/*
 * File containing utility functions                           
 * James Wadsworth (0813414)
 */
#include "util.h"

/* 
 * toUpperCase(string word)
 *      convert a given string to upper case
 */
string toUpperCase(string word) {
    for (int i = 0; i < word.length(); i++) {
        word[i] = toupper(word[i]);
    }
    return word;
}
