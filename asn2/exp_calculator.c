#include <stdio.h>
//AUTHOR: Hadi El-Kadri

//Functions made
float exp_calculator(float base, int exponent);

//The main function
int main() {
    //Taking in an input from the user for the base
    float base = 0;
    printf("Hello. Welcome to the exponential calculator. \n");
    printf("Please enter a base number (positive and a float): \n " );
    scanf(" %f", &base);
    printf("\n");

    //If the base is less than 0, re-ask for the base
    if (base <= 0){
        printf("You have entered an invalid base number! Please try again. \n");
        printf("\n");
        main();
    }

    //If the base is valid, ask for the exponent
    else{
        int exponent = 0;
        printf("Now, please enter a non-negative integer number for the exponent: \n");
        scanf(" %d", &exponent);
        printf("\n");

        //If the exponent is less than 0, re-ask for the exponent
        while(exponent < 0 ){
            printf("That is not a non-negative integer number! Please try again. \n");
            printf("Now, please enter a non-negative integer number for the exponent: \n");
            scanf(" %d", &exponent);
            printf("\n");
        }

        //Call the exp_calculator function to preform the calculations with the base and exponent
        printf("The calculation was successfully made! \n");
        printf("%f", base);
        printf(" to the power of");
        printf(" %d", exponent);
        printf(" is");
        printf(" %f", exp_calculator(base,exponent));
        printf("\n");
        printf("\n");
    }
}

//exp_calculator function with 2 inputs
float exp_calculator(float base, int exponent){
    //If the exponent is 0
    if (exponent == 0) return 1;

    //If the exponent is even
    else if(exponent % 2 == 0){
        float answer = exp_calculator(base * base, exponent / 2);
        return answer;
    }

    //If the exponent is odd
    else if ( exponent % 2 == 1){
        float answer = exp_calculator(base * base, (exponent - 1) / 2) * base;
        return answer;
    }
}
