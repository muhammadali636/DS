#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "q1.h"

//SELF NOTE: NO NEED TO CHECK DATES according to prof.
int main(void) {
    Node *availableList = NULL;
    Node *rentedList = NULL;
    Node *repairList = NULL;

    //load data from files to the right list.
    loadListFromFile(&availableList, "available.txt", 1);
    loadListFromFile(&rentedList, "rented.txt", 0);
    loadListFromFile(&repairList, "repair.txt", 0);

    int operator; //for choices.

    //command loop
    while (true) {
        //prompt for transaction code
        printf("\nEnter transaction code please (1-7).\n");
        printf("(1) Add a new car to the available-for-rent list.\n");
        printf("(2) Add a returned car to the available-for-rent list ");
        printf("(3) Add a returned car to the in-repair list ");
        printf("(4) Transfer a car from the in-repair list to the available-for-rent list.\n");
        printf("(5) Rent the first available car ");
        printf("(6) Print all the lists.\n");
        printf("(7) Quit.\n");

        //operator input for choice selection
        scanf("%d", &operator);
        getchar(); //eat \n

        Car car;
        Node *temp = NULL;
        Node *prev = NULL;
        Node *foundCar = NULL;

        //operator choices:
        switch (operator) {
            case 1: //add a new car to the available list
                while (true) {
                    bool isInvalid = false;

                    //get plate code
                    printf("Enter plate (2-8 chars): ");
                    fgets(car.plate, sizeof(car.plate), stdin);
                    //remove \n
                    if (car.plate[strlen(car.plate) - 1] == '\n') {
                        car.plate[strlen(car.plate) - 1] = '\0';
                    }

                    //check the length of the plate MUST BE BETWEEN 2 and 8
                    if (strlen(car.plate) < 2 || strlen(car.plate) > 8) {
                        printf("Invalid plate size. Must be between 2 and 8.\n");
                        continue;
                    }

                    //Check if its alnum
                    for (int i = 0; i < strlen(car.plate); i++) {
                        if (!isalnum(car.plate[i])) {
                            printf("Invalid plate: only letters and numbers allowed.\n");
                            isInvalid = true;
                            break;
                        }
                    }
                    if (isInvalid == true) {
                        continue;
                    }

                    //check for duplicates across ALL lists

                    Node* cur = NULL; //temp
                            //check available List
                    cur = availableList;
                    while (cur != NULL) {
                        if (strcmp(cur->car.plate, car.plate) == 0) {
                                printf("Duplicate plate found in the available-for-rent list. Please enter a new and original plate.\n");
                                isInvalid = true;
                        }
                        cur = cur->next;
                    }
                    if (isInvalid == true) { 
                        continue;
                    }
                    //check rented list
                    cur = rentedList;
                    while (cur != NULL) {
                        if (strcmp(cur->car.plate, car.plate) == 0) {
                            printf("Duplicate plate found in the rented list. Please enter a new and original plate.\n");
                            isInvalid = true;
                        }
                        cur = cur->next;
                    }
                    if (isInvalid == true) { 
                        continue;
                    }
                    //check repair list
                    cur = repairList;
                    while (cur != NULL) {
                        if (strcmp(cur->car.plate, car.plate) == 0) {
                            printf("Duplicate plate found in the in-repair list. Please enter a new and original plate.\n");
                            isInvalid = true;
                        }
                        cur = cur->next;
                    }
                    if (isInvalid == true) { 
                        continue;
                    }

                    //IF THE PLATE IS VALID THEN innput mileage and add car to available list
                    printf("Enter mileage: ");
                    scanf("%d", &car.mileage);
                    getchar(); //eat\n

                    car.returnDate = -1; //set the return date to -1 FOR available cars 
                    addCarToList(&availableList, car, 1); //car is now added to available list
                    printf("Added car %s to available-for-rent list.\n", car.plate); //display to user.
                    break;
                }
                break;  //avoid fall through in switch statement.

            case 2:         //return a car to available list from rented list (but we need to charge too)
                printf("Enter plate for return: ");
                fgets(car.plate, sizeof(car.plate), stdin);
                
                //remove newline character from plate input
                if (car.plate[strlen(car.plate) - 1] == '\n') {
                    car.plate[strlen(car.plate) - 1] = '\0';
                }

                printf("Enter mileage for return: ");
                scanf("%d", &car.mileage);
                getchar(); //eat \n

                //find and remove the car from the rented list
                temp = rentedList;
                prev = NULL;
                foundCar = NULL;

                //traverse  rented list to find the car
                while (temp != NULL) {
                    if (strcmp(temp->car.plate, car.plate) == 0) {
                        //remove car from the rented list
                        if (prev) {
                            prev->next = temp->next;
                        } 
                        else {
                            rentedList = temp->next;
                        }
                        foundCar = temp;
                        break;
                    }
                    prev = temp;
                    temp = temp->next;
                }

                if (foundCar != NULL) { //meaning we found somethin
                        //chcekc mileage and calculate charge if mileage is valid
                    if (car.mileage < foundCar->car.mileage) {
                        printf("Error: Mileage cannot be less than previous recorded mileage.\n");
                        free(foundCar); // Free memory if invalid
                    } 
                    else {
                            //calc charge based on mileage
                        int extraKm = car.mileage - foundCar->car.mileage - 200;
                        int charge;

                        if (extraKm > 0) {
                            charge = 80 + (int)(extraKm * 0.15);  //FLAT RATE MEANS no decimal so cast it
                        } 
                        else {
                            charge = 80;    //oinly flat rate for up to 200 km
                        }

                        printf("Charge for %s: $%d\n", car.plate, charge);

                        //update mileage and move car to available list
                        foundCar->car.mileage = car.mileage;
                        addCarToList(&availableList, foundCar->car, 1);
                        free(foundCar); //free removed node so no memory leak
                    }
                } 
                else {
                    printf("Car not found in rented list.\n");
                }
                break;

            case 6:     //print ALL lists
                printf("Available for Rent List:\n");
                printList(availableList);
                printf("Rented List:\n");
                printList(rentedList);
                printf("Repair List:\n");
                printList(repairList);
                break;

            case 7:     //save lists to txt files and exit
                saveListToFile(availableList, "available.txt");
                saveListToFile(rentedList, "rented.txt");
                saveListToFile(repairList, "repair.txt");
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid operator choice (PICK between 1 to 7).\n");
                break;
        }
    }
    return 0;
}
