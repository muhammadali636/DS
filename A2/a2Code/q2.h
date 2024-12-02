//node sturct for stack
struct Node {
    double value; //value of the node (operand or result)
    struct Node* next; //point to next node
};
typedef struct Node Node;

void push(struct Node** top, double value);

double pop(struct Node** top);

double evalPostFix(char* expression);