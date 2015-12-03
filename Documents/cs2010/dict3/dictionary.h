#ifndef DICTIONARY_H
#define DICTIONARY_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <iostream>
using namespace std;
const int MAX = 100;
typedef string STRING;
typedef bool BOOL;
typedef string WORD;
/*
structure describing a word entry in the dictionary
*/
typedef struct entry {


int count; /* frequency count for a particular word */
WORD w; /* the word itself */


struct entry *nextWord; /* pointer to next entry */
} ENTRY;
/*
structure describing the dictionary
*/




typedef struct dict {
int maxEntries; /* maximum number of entries allowed; this is an artificial limit */
/* link lists can be as big as you want. This limit ensures that */
/* this code tries to behave like the previous ones */
int NumWords; /* number of words in the dictionary */
ENTRY *Words; /* pointer to the entries in the dictionary */
} 

DICT;

ENTRY *LocateWord(DICT& , WORD);
BOOL FullDictionary(DICT&);
BOOL InsertWord(DICT&,WORD);
WORD GetNextWord(void);
void DumpDictionary(DICT&);
/*
note that these are global variables so that they are already initialized to 0
*/

extern DICT dictionary; //Your dictionary
extern WORD word; //Word being worked with
#endif
