/* AUTHOR: HADI EL-KADRI
 * THIS PROGRAM WILL TAKE AN INPUT INTEGER AND DISPLAY IT IN SEVEN-SEGMENT DISPLAY FORMAT
 */

#include <stdio.h>
#include <stdlib.h>
int main() {
    //Initialize the 3-D array containing the numbers in seven-segment display format
    const char segments[10][3][3] =
            {{{' ', '_', ' '}, {'|', ' ', '|'}, {'|', '_', '|'}},
             {{' ', ' ', ' '}, {' ', ' ', '|'}, {' ', ' ', '|'}},
             {{' ', '_', ' '}, {' ', '_', '|'}, {'|', '_', ' '}},
             {{' ', '_', ' '}, {' ', '_', '|'}, {' ', '_', '|'}},
             {{' ', ' ', ' '}, {'|', '_', '|'}, {' ', ' ', '|'}},
             {{' ', '_', ' '}, {'|', '_', ' '}, {' ', '_', '|'}},
             {{' ', '_', ' '}, {'|', '_', ' '}, {'|', '_', '|'}},
             {{' ', '_', ' '}, {' ', ' ', '|'}, {' ', ' ', '|'}},
             {{' ', '_', ' '}, {'|', '_', '|'}, {'|', '_', '|'}},
             {{' ', '_', ' '}, {'|', '_', '|'}, {' ', ' ', '|'}}};

    const char negative[1][3][3] = {{{' ', ' ', ' '}, {'_', '_', ' '}, {' ', ' ', ' '}}};
    //Take in an input integer from the user
    int number;
    char isNegative;
    printf("Hello. Please enter an integer: ");
    scanf("%d", &number);

    if(number < 0){
        isNegative = 'Y';
    } else{
        isNegative = 'N';
    }
    number = abs(number);

    //Find how many digits are in the integer
    int n = number;
    int count = 0;

    while (n >= 1) {
        n = n / 10;
        count++;
    }

    //Initialize an array the size of the number of digits in the integer
    int numArray[count];

    //Fill the array from end to front because it is easier to get the digits from right to left
    for (int i = count - 1; i > -1; i--) {
        numArray[i] = number % 10;
        number = number / 10;
    }

    //Go through the array of digits and print the TOP of all digits in seven-segment display format
    if(isNegative == 'Y'){
        for (int d = 0; d < 3; d++) {
            printf("%c", negative[0][0][d]);}
    }
    for (int a = 0; a < count; a++) {
        int number = numArray[a];
        for (int d = 0; d < 3; d++) {
            printf("%c", segments[number][0][d]);
        }
    }
    printf("\n");

    //Go through the array of digits and print the MIDDLE of all digits in seven-segment display format
    if(isNegative == 'Y'){
        for (int d = 0; d < 3; d++) {
            printf("%c", negative[0][1][d]);}
    }
    for (int a = 0; a < count; a++) {
        int number = numArray[a];
        for (int d = 0; d < 3; d++) {
            printf("%c", segments[number][1][d]);
        }
    }
    printf("\n");

    //Go through the array of digits and print the BOTTOM of all digits in seven-segment display format
    if(isNegative == 'Y'){
        for (int d = 0; d < 3; d++) {
            printf("%c", negative[0][2][d]);}
    }
    for (int a = 0; a < count; a++) {
        int number = numArray[a];
        for (int d = 0; d < 3; d++) {
            printf("%c", segments[number][2][d]);
        }
    }

    printf("\n");
    printf("\n");

    //Ask the user if they wish to continue, if yes call main, if no program terminates
    char answer;
    printf("Would you like to go again? (Y for Yes, N for No): ");
    scanf(" %c", &answer);
    if(answer == 'Y' || answer == 'y'){
        printf("\n");
        main();
    }
}
