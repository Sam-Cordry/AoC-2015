#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * @brief The main function opens the input file and prints out the solutions for both parts of the Day 1 puzzle.
 * 
 * @return int status code
 */
int main(void) {
    // open file and initialize variables used to solve the puzzle
    FILE *file = fopen("Day1-Input.txt", "r");
    int floor = 0;
    char chr = fgetc(file);
    int position = 0;
    bool hasSetPosition = false;

    // iterate through characters in the file
    for(int i = 1; !feof(file); i++) {
        // keeps track of what the current floor is
        floor += (chr == '(') ? 1 : -1;

        // check if this is the first time that -1 is the current floor
        if(floor == -1 && !hasSetPosition) {
            // store current position in file (counting from 1) and mark that -1 has been found
            position = i;
            hasSetPosition = true;
        }

        // get next character and increment 
        chr = fgetc(file);
    }

    // print out solutions to both parts
    printf("Part 1 Solution: %i\n", floor);
    printf("Part 2 Solution: %i\n", position);

    return 0;
}