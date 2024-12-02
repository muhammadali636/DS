#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include "q2.h"

int main(int argc, char* argv[]) {
    //check if right number of args
    if (argc != 2) {
        printf("You did not enter right amount of arguments");  //tell user they messed up number of args.
        return 1;  //exit
    }

    //eval postfix
    double result = evalPostFix(argv[1]);

    //check for error (-1.0)
    if (result == -1.0) {
        printf("Error, system failure.\n"); //error message
    }
    else {
        printf("%.2f\n", result);  //print e result with two decimal places .2f JUST LIKE TEST CASE EXAMPLE

    }
    return 0; 
}