#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "p3.h"



void trim(char name[], int size){
    int len = strlen(name);
    if(len > 0 && name[len - 1] == '\n'){
        name[len - 1] = '\0';
    }

}

void parse_monster(char *line, monster *m) {
    // Tokenize the string and assign to struct members
    char *token = strtok(line, ",");  // First token: Monster's name
    strcpy(m->name, token);           // Copy token to the name field

    token = strtok(NULL, ",");        // Second token: Monster's type
    strcpy(m->type, token);           // Copy token to the type field

    token = strtok(NULL, ",");        // Third token: Monster's HP
    m->hp = atoi(token);              // Convert token to an integer and assign to hp

}
