
//car structure with plate, mileage and return date.
typedef struct {
    char plate[9];
    int mileage;
    int returnDate;
}Car;

//node structure for linked list. We will have 3 linkedlist (available, rented and  repair.
typedef struct Node {
    Car car;
    struct Node* next;
}Node;

//prototypes
void addCarToList(Node** list, Car car, int orderByMileage);
void printList(Node* list);
void saveListToFile(Node* list, char* filename);
void loadListFromFile(Node** list, char* filename, int orderByMileage); 