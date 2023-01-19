// file: Day3.c
// author: Sam Cordry
// solves the puzzles from Day 3

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// used to mark the end of an array of house structures
#define LAST_HOUSE (struct house) { 0, 0, -1 };

/**
 * @brief The house structure defines coordinates of the house and the number of times in has been visited.
 */
struct house {
    int x;
    int y;
    int times_visited;
};

int main(void) {
    // define visit_house function for use in main function
    void visit_house(struct house[], int, int);

    // open input file
    FILE *file = fopen("Day3-Input.txt", "r");

    // create and instatiate variables needed to solve Part 1
    struct house visited_houses1[9000];
    int x1 = 0, y1 = 0;
    visited_houses1[0] = (struct house) { x1, y1, 1 };
    visited_houses1[1] = LAST_HOUSE;

    // create and instantiate variables needed to solve Part 2
    int i = 0;
    int x2[2] = {0, 0}, y2[2] = {0, 0};
    struct house visited_houses2[9000];
    visited_houses2[0] = (struct house) { x2[0], y2[0], 1};
    visited_houses2[1] = LAST_HOUSE;

    // get first character
    char chr = fgetc(file);

    // iterate through each character of the input file
    while(!feof(file)) {
        // modify coordinate variables depending on the direction given
        switch(chr) {
            case '>':
                x1++;
                x2[i % 2]++;
                break;
            case '<':
                x1--;
                x2[i % 2]--;
                break;
            case '^':
                y1++;
                y2[i % 2]++;
                break;
            case 'v':
                y1--;
                y2[i % 2]--;
            default:;
        }

        // visit the new house in both scenarios
        visit_house(visited_houses1, x1, y1);
        visit_house(visited_houses2, x2[i % 2], y2[i % 2]);

        // get next character in file and increment index
        chr = fgetc(file);
        i++;
    }

    // count number of houses visited under the circumstances in Part 1
    int count = 0;
    while(visited_houses1[count].times_visited != -1) {
        count++;
    }

    // print Part 1 solution
    printf("Part 1 Solution: %i\n", count);

    // count number of houses visited under the circumstances in Part 2
    count = 0;
    while(visited_houses2[count].times_visited != -1) {
        count++;
    }

    // print Part 2 solution
    printf("Part 2 Solution: %i\n", count);

    return 0;
}

/**
 * @brief The visit_house function visits the house at the given coordinates and adjusts the visited houses array as needed
 * by either updating the number of times that house was visited or by adding a newly visited house.
 * 
 * @param visited_houses array of visited houses so far
 * @param x x-coordinate of the house
 * @param y y-coordinate of the house
 */
void visit_house(struct house visited_houses[], int x, int y) {
    // iterate through all valid houses in the array
    int i;
    for(i = 0; visited_houses[i].times_visited != -1; i++) {
        // check if this is the right house
        if(visited_houses[i].x == x && visited_houses[i].y == y) {
            // if so, mark that it has been visited again
            visited_houses[i].times_visited++;
            return;
        }
    }

    // if house was not found, create a new one and add it to the end of the array
    visited_houses[i] = (struct house) { x, y, 1};
    visited_houses[i + 1] = LAST_HOUSE;
}