#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * @brief The main function opens the input file and prints out the solutions for both parts of the Day 2 puzzle.
 * 
 * @return int status code
 */
int main(void) {
    // header for min function
    int min(int, int, int);

    // open file and initialize variables used for solving the puzzle
    FILE *file = fopen("Day2-Input.txt", "r");
    char line[10];
    int x, y, z;
    int totalArea = 0;
    int totalLength = 0;

    // iterate over every line in the input file
    while(!feof(file)) {
        // scan in a line of the file and parse it
        fgets(line, 10, file);
        sscanf(line, "%ix%ix%i", &x, &y, &z);

        // add to the total area the surface area of the box and the area of the smallest side
        totalArea += 2 * (x * y + y * z + x * z) + min(x * y, y * z, x * z);

        // add to the total length the smallest peremeter of any face and volume of the box
        totalLength += min(2 * (x + y), 2 * (y + z), 2 * (x + z)) + x * y * z;
    }
    
    // print out the solutions to both parts of the puzzle
    printf("Part 1 Solution: %i\n", totalArea);
    printf("Part 2 Solution: %i\n", totalLength);

    return 0;
}

/**
 * @brief The min function finds and returns the minimum value of three integers.
 * 
 * @param x first integer to compare
 * @param y second integer to compare
 * @param z third integer to compare
 * @return int minimum of the inputs
 */
int min(int x, int y, int z) {
    return (x > y) ? (y > z) ? z : y : (x > z) ? z : x;
}