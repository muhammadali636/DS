#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "a3q2_header.h"
/*
*theres an error here CHECK COURSELINK
 * The downHeap function performs the downheap algorithm.
 * The key at the passed position is swapped with the key of its child with the largest value.
 * If the key is larger than or equal to both of its children's keys, no swap happens.
 * (INCORRECTTTTT) After a swap, downHeap is called recursively on the new position of the swapped key.
 *ACTUALLY - process continues until the heap property is restored.
 */

//goal is to maintain heap property in a max-heap.
//Each node value is >= to its childrens values.
//The top root node contains the BIGGEST value.

//restore heap property. Key represents heap as 1d arr, pos = position, arry[][] 2d arr with metadata with each heap element.
void downHeap(int key[20], int pos, int array[20][10]) {
    int size = 20; // Assuming the heap size is 20
    int parent = pos;

    while (isParent(parent)) { //while  parent has AT LEAST  one child
        int left = 2 * parent +1; //left child indexx
        int right = left+1;     //right child index.
        int biggest = parent;   //assyme  parent is the biggest.
        //compare with left child
        if (left < size && key[left] > key[biggest]) {
            biggest = left;
        }
        //compare with right child — if exists?
        if (right < size && key[right] > key[biggest]) {
            biggest = right;
        }
        //if biggest == parent  heap property IS satisfied and break.
        if (biggest == parent) {
            break;
        }
        //If heap property not satisifed swap with the biggest child
        swap(parent, biggest, key, array);
        //move down to the biggest child
        parent = biggest;
    }
}

/*
 * The isParent function returns true if the passed position has at least one child.
 * The heap size is fixed at 20 as per the problem constraints.
 */
bool isParent(int keyPos) {
    // A parent must have at least a left child
    int size = 20; // Fixed heap size
    if ((2 * keyPos + 1) < size) {
        return true;
    }
    return false;
}

/*
 * The swap function swaps two rows in the 2D array and their corresponding keys.
 */
void swap(int key1Pos, int key2Pos, int key[20], int array[20][10]) {
    //swap function 
    int temp;
    temp = key[key1Pos];
    key[key1Pos] = key[key2Pos];
    key[key2Pos] = temp;

    //swap corresponding rows in 2D array
    for (int i = 0; i < 10; ++i) {
        int tempVal = array[key1Pos][i];
        array[key1Pos][i] = array[key2Pos][i];
        array[key2Pos][i] = tempVal;
    }
}
