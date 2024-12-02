#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "q1.h"

//add car to a list in sorted order
void addCarToList(Node** list, Car car, int orderByMileage) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->car = car;
    newNode->next = NULL;

    //insert node in order based on mileage or retdate
    if (*list == NULL || (orderByMileage == false && (*list)->car.returnDate > car.returnDate) || (orderByMileage == true && (*list)->car.mileage > car.mileage)) {
        newNode->next = *list;
        *list = newNode;
    } 
    else {
        Node* temp = *list;
        while (temp->next != NULL && ((orderByMileage == true && temp->next->car.mileage <= car.mileage) || (orderByMileage == false && temp->next->car.returnDate <= car.returnDate))) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

//print  linked list
void printList(Node* list) {
    while (list != NULL) {
        printf("Plate: %s, Mileage: %d, Return Date: %d\n", list->car.plate, list->car.mileage, list->car.returnDate);
        list = list -> next;
    }
}

//save  list to a file
void saveListToFile(Node* list, char* filename) {
    FILE* fp = fopen(filename, "w");
    while (list != NULL) {
        fprintf(fp, "%s %d %d\n", list -> car.plate, list -> car.mileage, list->car.returnDate);
        list = list->next;
    }
    fclose(fp);
}

//load data from a file into a linked list
void loadListFromFile(Node** list, char* filename, int orderByMileage) { 
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }
    Car car;
    //read each line
    while (!feof(fp)) {
        fscanf(fp, "%s %d %d", car.plate, &car.mileage, &car.returnDate);
        addCarToList(list, car, orderByMileage);
    }
    fclose(fp);
}