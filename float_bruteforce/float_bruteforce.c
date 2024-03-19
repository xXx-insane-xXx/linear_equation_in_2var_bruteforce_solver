/*
 * ******************************************************************
 *
 *
 * This program solves linear equations in two variables for floating point values and gives upto first 100 solutions
 * 
 * ax + by = c
 *
 *
 * ******************************************************************
 *
 *
 * RANGE OF x and y (by default):
 * x ranges from (-100.00, -99.02,...., 1.00, 1.10, 1.20 .... upto 100.00)
 * y ranges from (-100.00, -99.02,...., 1.00, 1.10, 1.20 .... upto 100.00)
 * default increment is 0.1
 *
 * *******************************************************************
 *
 *
 * INACCURACY by 0.1
 * 
 * Due to the way floating point numbers are stored in C, the answers have in accuray in the following fashion -> ans + (0.0 to 0.9)
 * Eg : 2x + 2y = 4
 * Results ranging from 4.00 to 4.90 are all considered correct !!
 *
 *
 *
 * *******************************************************************
 *
 *
 * Extra:
 * 1. MAX_SOLUTIONS is 100
 * 2. arr_counter goes from (0 to 99) does satisfying 100 solutions
 *
 *
 * *******************************************************************
 *
 * */


#include <stdio.h>
#include <stdbool.h>
#include <math.h>

// Maximum number of solutions 
#define MAX_SOLUTIONS 100
#define RANGE_START -100.0
#define RANGE_END 100.0
#define INCREMENT 0.1

int main(void) {
   
    // a, b and c are constants such that ax + by = c
    float a, b, c;

    // array for possible solutions upto #MAX_SOLUTIONS solutions
    float possible_solutions[MAX_SOLUTIONS][2];

    // To index solutions of array
    int arr_counter = 0;

    // User input for constants
    printf("Enter value for constant a : ");
    scanf("%f", &a);
    printf("Enter value for constant b : ");
    scanf("%f", &b);
    printf("Enter value for constant c : ");
    scanf("%f", &c);


    // Looping for x ranging -100.0 to 100.0 (increment by 0.1)
    for (float i=RANGE_START; i <= RANGE_END; i += INCREMENT) {
        
        // Looping for y ranging -100.0 to 100.0 (increment by 0.1)

        for (float j=RANGE_START; j <= RANGE_END; j += INCREMENT) {
             
            float result = a*i + b*j;
            
            // Inaccuracy is due to this comparision !!
            if ((int) result == (int) c) {
                
                // Checking for duplicate answers
                bool duplicate = false;
                for (int k=0; k < arr_counter; k++) {
                    if (possible_solutions[k][0] == i && possible_solutions[k][1] == j) {
                        duplicate = true;
                        break;
                    }
                }
                
                // Add the result to the array if not duplicate
                if (!duplicate) {
                    possible_solutions[arr_counter][0] = i;
                    possible_solutions[arr_counter][1] = j;
                    arr_counter++;
                }
            }
                
            // Break inner loop after reaching #MAX_SOLUTIONS solutions
            if (arr_counter > MAX_SOLUTIONS) {
                break;
            }
        }
         
            
        // Break outer loop after reaching #MAX_SOLUTIONS solutions
        if (arr_counter >= MAX_SOLUTIONS) {
            break;
        }

        printf("\n");
    }


    // Print through all obtained #MAX_SOLUTIONS solutions
    for (int i=0; i < arr_counter; i++) {
        printf("x = %2.f\n", possible_solutions[i][0]);
        printf("y = %.2f\n", possible_solutions[i][1]);
        printf("\n");
    }   
    

    return 0;
}
