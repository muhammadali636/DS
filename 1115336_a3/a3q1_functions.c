#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "a3q1_header.h"

//TEST: valgrind ./a3q1 "(((x1+5.12)*(x2-7.68))/x3)" NO MEM LEAKS 

Variable variables[10]; //stores variables
int varCount = 0; //counter of var


// The createNode function allocates memory to the tree and creates a new node using the given data before returning the node.
Node* createNode(char *data) {
    Node *node = (Node *)calloc(1, sizeof(Node)); //allocate new memory for node.
    //eason said no error checking.
    /*if (!node) {
        printf("ERROR FAILED memory allocation\n");
    }*/
    strcpy(node->data, data);    //copy data to node->data
    //set left and right to NULL
    node->left = NULL; 
    node->right = NULL; 
    return node;
}

// The parseExpression function parses the expression string passed in from command line, stores the information in a new node, and returns the root node of the tree.

Node* parseExpression(char *expr) {
    Node *stack[400];    //Stack for holding nodes
    char operatorStack[200]; //Stack for holding operators
    int stackTop = -1;   //empty node stack
    int operatorTop = -1;   //empty operator stack

    for (int i = 0; expr[i] != '\0'; i++) {
        char c = expr[i];
        //SKIP spaces/
        if (isspace(c)) {
            continue;
        }
        //push open bracket to operator stack.
        if (c == '(') {
            operatorStack[++operatorTop] = c;
        } 
        //handle varname or numbers (operands)
        else if (isalnum(c) || c == '.') {
            char operand[32]; //parse operand into this 
            int j = 0;
            while (isalnum(c) || c == '.') {
                operand[j++] = c;
                c = expr[++i];
            }
            operand[j] = '\0'; //null-terminate the operand
            i--; //backtrack after
            Node *node = createNode(operand);
            stack[++stackTop] = node;
        } 
        //Push operator to operator stack.
        else if (c == '+' || c == '-' || c == '*' || c == '/') {
            operatorStack[++operatorTop] = c;
        } 
        //Handle close brackets
        else if (c == ')') {
            while (operatorTop >= 0 && operatorStack[operatorTop] != '(') {
                char op = operatorStack[operatorTop--];
                //Pop two nodes from the stack for the operator
                Node *right = stack[stackTop--];
                Node *left = stack[stackTop--];
                char operatorStr[2] = {op, '\0'}; //creater a string from  operator and INCLUDE null term.
                Node *node = createNode(operatorStr); //PASSED TO createNode
                node-> left = left;
                node -> right = right;
                stack[++stackTop] = node;
            }
            operatorTop--; //pop the '('
        }
    }
    //NO ERROR CHECKING OR VALIDATION acc to eas
    /*
    if (stackTop != 0 || operatorTop != -1) {
        printf("ERROR: Invalid expression\n");
        return? WHAT
    }*/

    return stack[stackTop]; //ret root node of tree.
}


// The preorder function prints tree nodes in preorder traversal.
void preorder(Node *root) {
    //if tree empty.
    if (root == NULL) {
        return;
    }
    //ROOT LEFT RIGHT USE RECURSION
    printf("%s ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// The inorder function prints tree nodes in inorder traversal, fully parenthesized.
void inorder(Node *root) {
    //if tree empty
    if (root == NULL) {
        return;
    }
    if (root-> left) {
        printf("(");
    }
    //LEFT ROOT RIGHT USE RECURSION
    inorder(root -> left);
    printf("%s", root->data);
    inorder(root -> right);
    if (root -> right) printf(")");
}

// The postorder function prints tree nodes in postorder traversal.
void postorder(Node *root) {
    //if tree empty
    if (root == NULL) {
        return;
    } 
    //LEFT RIGHT ROOT USE RECURSION
    postorder(root->left);
    postorder(root->right);
    printf("%s ", root->data);
}

//The promptVariables function prompts the user to assign values to each variable found in the expression tree.
void promptVariables(Node *root) {
    //empty tree
    if (root == NULL) {
        return;
    }
    if (isalpha(root->data[0])) { //variable checker
        for (int i = 0; i < varCount; i++) {
            if (strcmp(variables[i].varName, root->data) == 0) {
                return; //already assigned
            }
        }
        printf("Enter value for %s: ", root->data); //value prompt
        scanf("%f", &variables[varCount].value);
        strcpy(variables[varCount++].varName, root->data);
    }
    //recursionnn
    promptVariables(root->left); //left subtree
    promptVariables(root->right); //right subtree
}

//The calculate function calculates the result of the expression tree.
float calculate(Node *root) {
    //empty tree.
    if (root == NULL) {
        return 0;
    } 
    if (isalnum(root->data[0])) { //operand.
        if (isalpha(root->data[0])) {
            //var val here is:
            for (int i = 0; i < varCount; i++) {
                if (strcmp(variables[i].varName, root->data) == 0) {
                    return variables[i].value;
                }
            }
        } 
        else {
            return atof(root->data); //string to num
        }
    }

    //Operator AND RECURSION
    float leftSide = calculate(root->left); //left subntree
    float rightSide = calculate(root->right); //right subtree

    //EVALUATE
    if (strcmp(root->data, "+") == 0) {
        return leftSide + rightSide;
    }
    if (strcmp(root->data, "-") == 0) {
        return leftSide - rightSide;
    }
    if (strcmp(root->data, "*") == 0) {
        return leftSide * rightSide;
    }
    if (strcmp(root->data, "/") == 0) {
        //eason said no error checkign or validation
        return leftSide / rightSide;
    }
    /* NO ERROR CHECKING ASSUME VALID INPUTS
    printf("Error: Unknown operator '%s'\n", root->data);
    return???
    */
   return 0;
}

//MY OWN FUNCTION frees all dyn alloc memory for tree. NEW FUNCTION ADDED TO HEADER.H
void freeTree(Node *root) {
    //empty tree
    if (root == NULL) {
        return; 
    } 
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}