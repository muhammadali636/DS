#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include "q2.h"

//push to stack. WE DONT HAVE STACKOVERFLOW warning SINCE LINKEDLIST IMPLEMENTATION
void push(struct Node** top, double value) {
    struct Node* newNode = (Node*)malloc(sizeof(struct Node));     //allocate memory for a new node
    newNode->value = value; //set newnodes value
    newNode->next = *top;   //link new node to  prev top
    *top = newNode;     //update  top to  new node
}

//pop rom the stack
double pop(Node** top) {
    //isEmpty
    if (*top == NULL) {
        printf("Stack underflow!!!\n"); // Print error message
        return -1.0; //return -1.0 to show undeflow
    }
    Node* cur = *top;  //cur node is top
    double value = cur->value; //store value for pop
    *top = (*top)->next;       //next node is now top of the stackk
    free(cur);       //free mem of popped node
    return value;     //return popped node
}

//eval postfix expr
double evalPostFix(char* expression) {
    Node* stack = NULL; //init stack

    //go over each character 
    for (int i = 0; expression[i] != '\0'; i++) {
        char ch = expression[i];

        bool isOperator = false;
        if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            isOperator = true;
        }

        //if char is digitp ush on stack
        if (isdigit(ch)) {
            double value = ch - '0'; //turn char to double by subing with 0 GOT FROM INTERNET
            push(&stack, value);   //push num value on  stack
        } 
        //if char is operator pop two operands, apply the operator
        else if (isOperator == true) {
            //pop two values from the stack 
            double operand2 = pop(&stack);
            double operand1 = pop(&stack);

            //check for errors during pop like if the stack was empty)
            if (operand1 == -1.0 || operand2 == -1.0) {
                return -1.0;  //return -1.0 means an error
            }

            double result;
            //schange to switch
            if (ch == '+') {
                result = operand1 + operand2; 
            }
            else if (ch == '-') {
                result = operand1 - operand2; 

            }

            else if (ch == '*') {
                result = operand1 * operand2; 
            }

            else if (ch == '/') {
                result = operand1 / operand2; //are we suppose to check for div zero ASK TA OR PROF on discbord
            }

            else {
                printf("Unknown operator %c used.\n", ch);
                return -1.0; //return -1.0 erorrr

            }
            push(&stack, result); //push the result o op back on stack
        } 
        //if char is not digit or not a valid operator --> error
        else {
            printf("Error: Invalid character '%c' in expression\n", ch);
            return -1.0; //return -1.0 (error)
        }
    }

    double final = pop(&stack);     //pop final result from the stqck

    //checks if there are still elements in the stack thats meaning invalid expression
    if (stack != NULL) {
        printf("Something went wrong, there are elements still in stack.\n");
        return -1.0;  //return -1.0 mearnign RROR 
    }

    return final;  //ret final result of expr
}