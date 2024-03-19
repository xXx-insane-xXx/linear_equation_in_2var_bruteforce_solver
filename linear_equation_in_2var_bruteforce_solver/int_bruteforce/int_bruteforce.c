#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define MAX_SOLUTIONS 100

// Hello

int main(void) {

    int a, b, c;

    bool result_found = false;
    int possible_solutions[MAX_SOLUTIONS][2];
    int arr_counter = 0;

    printf("Enter value for constant a : ");
    scanf("%d", &a);
    printf("Enter value for constant b : ");
    scanf("%d", &b);
    printf("Enter value for constant c : ");
    scanf("%d", &c);

    for (int i = 0; i < 100; i += 1) {

        for (int j = 0; j < 100; j += 1) {

            int result = a * i + b * j;

            if (result == c) {

                bool duplicate = false;

                for (int k = 0; k < arr_counter; k++) {
                    if (possible_solutions[k][0] == i && possible_solutions[k][1] == j) {
                        duplicate = true;
                        break;
                    }
                }

                if (!duplicate) {
                    possible_solutions[arr_counter][0] = i;
                    possible_solutions[arr_counter][1] = j;
                    arr_counter++;
                    if (arr_counter > MAX_SOLUTIONS) {
                        break;
                    }
                }
            }
        }
        if (arr_counter > MAX_SOLUTIONS) {
            break;
        }
    }
        

    for (int i = 0; i < arr_counter; i++) {
        printf("x = %d\n", possible_solutions[i][0]);
        printf("y = %d\n", possible_solutions[i][1]);
    }
    

    return 0;
}
