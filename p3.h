#ifndef P3_H
#include <stdio.h>
#define STR 100

void trim(char name[], int size);

typedef struct{
    char name[STR];
    char type [STR];
    int hp;
 //   int at;
}monster;

void parse_monster(char *line, monster *m);




#endif   // extra tokens at end of #indef