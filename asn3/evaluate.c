/*
 * AUTHOR: HADI EL-KADRI
 * THIS PROGRAM WILL TAKE A SIMPLE ARITHMETIC EXPRESSION AND
 * EVALUATE IT
 */

#include <stdio.h>
#include <stdlib.h>
//INITIALIZE METHODS
float s_exp();
float get_num();
char get_op();
float m_exp(float sub_exp, char op);

//Main will ask the user for an arithmetic expression, then call method s_exp to evaluate
//the expression printing the result, and finally ask the user if they would like to try again

int main() {
    char answer = 'Y';
    while (answer == 'Y' || answer == 'y') {
        printf("Enter a simple arithmetic expression: \n");
        float result = s_exp();
        printf("\n");
        printf("The answer to this arithmetic expression is: %f\n", result);
        printf("\n");
        printf("Do you want to go again? (Y for Yes, N for No): \n");
        scanf(" %c", &answer);
        printf("\n");
    }
}

// Input: none, read from stdin
// Effect: get the next operator of the expression
// this operator can be +, -, *, /, or ’\n’
// ’\n’ indicates the end of the expression input
// leading spaces should skipped
// Output: return the next operator of the expression.

char get_op() {
    char op = ' ';
    while(op == ' ') {
        scanf("%c", &op);
    }
    return op;
}
// Input: none, read from stdin
// Effect: get the next numeric value of the expression
// Output: return the next numeric value of the expression.

float get_num() {
    float num = ' ';
    while(num == ' ') {
        scanf("%f", &num);
    }
    return num;
}

// Input: ’sub_exp’: the value of the current sub m_expression
// to the left of ’op’ location in stdin.
// ’op’ : an operator, ’*’ or ’/’. ’op’ could also be
// ’+’, ’-’, or ’\n’ indicating the end of the m_expression.
// "+’, ’-’, or ’\n’ should be pushed back to stdin.
// the rest of the m_expression will be read in from stdin
// Effect: the m_expression is evaluated using recursion:
// get next_num with get_num() and then get next_op with get_op()
// use ’sub_exp op next_num’ and ’next_op’ to do recursive call
// Output: this function returns the value of the current m_expression

float m_exp(float sub_exp, char op) {

    if(op == '+' || op == '-' || op == '\n'){
        ungetc(op, stdin);
        return sub_exp;
    } else{
        float next_num = get_num();
        float next_op = get_op();
        float next_sub_exp;

        if(op == '*'){
            next_sub_exp = sub_exp * next_num;
        }

        else if(op == '/'){
            if(next_num == 0){
                printf("ERROR CANNOT DIVIDE BY 0\n");
                exit(EXIT_FAILURE);
            }
            else {
                next_sub_exp = sub_exp / next_num;
            }
        }
        else{
            printf("You have entered an invalid operation!");
            exit(EXIT_FAILURE);
        }
        return m_exp(next_sub_exp, next_op);
    }
}

// Input: none, the s_expression will be read in from stdin
// Effect: the s_expression is evaluated using
// a while loop or a do while loop:
// repeatedly get num with m_exp() and then get op with
// get_op() while op is ’+’ or ’-’; when op is ’\n’, exit loop.
// Output: this function returns the value of the s_expression

float s_exp(void) {
    float num = get_num();
    char op = get_op();

    if(op == '\n'){
        return num;
    }

    float temp_exp = m_exp(num,op);
    op = get_op();

    while (op != '\n' ){
       int newNum = get_num();
       int newOp = get_op();
        if(op == '+'){
            temp_exp += m_exp(newNum,newOp);
        }
        else if(op == '-'){
            temp_exp -= m_exp(newNum,newOp);

        } else{
            temp_exp = m_exp(newNum,newOp);
        }
        op = get_op();
    }
    return temp_exp;
}


