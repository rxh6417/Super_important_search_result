#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "p3.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);  // Correct usage message
        return 1;
    }

    FILE *ptr = fopen(argv[1], "r");   
    if (ptr == NULL) {
        printf("Couldn't open this file\n");
        return 1;
    }

    monster my_mon[100];  // You can store up to 100 monsters
    char line[100];       // Buffer to store each line from the file
    int count = 0;        // Counter for the number of monsters

    // Read each line from the file
    while (fgets(line, sizeof(line), ptr)) {                    
        if (count >= 100) {  // Avoid exceeding the maximum number of monsters
            break;
        }

        trim(line, sizeof(line));  // Call trim function to remove trailing newline

        parse_monster(line, &my_mon[count]);  // Parse the line into the monster array

        count++;  // Increment the count of monsters
    }

    // Output the parsed monsters
    printf("Loaded %d monsters:\n", count);
    for (int i = 0; i < count; i++) {
        printf("Monster %d: Name: %s, Type: %s, HP: %d\n",
               i + 1, my_mon[i].name, my_mon[i].type, my_mon[i].hp);
    }

    fclose(ptr);  // Close the file

    return 0;
}
