#include <stdio.h>

int factorial(long long int n);
double calc(double number);

int main(){
    double answer;
    printf("Please enter a number: \n");
    scanf(" %lf", &answer);
    double result = calc(answer);
    printf("The answer is %.15f", result);
}


double calc(double number){
    double temp = 1.0;
    int n= 1;
    while((double)1.0/factorial(n) >= number){
        temp += (double)1.0/factorial(n);
        n = n + 1;
    }
    return (double) temp;
}

int factorial(long long int n)
{
    int result = 1;
    while(n > 1){
        if (n > (9,223,372,036,854,775,807) / result);
        result *= n;
        --n;
    }
    return result;
}
