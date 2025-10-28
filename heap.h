//
// Created by Manju Muralidharan on 10/19/25.
//

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <stack>
#include <string>
using namespace std;

struct MinHeap {
    int data[64]; //Stores indices for the char.
    int size;

    MinHeap() { size = 0; }

    /* Push to the array. Basically sets the current data at the size to the index. Then adds to the size so size
     * goes to the next open available spot in the array.
     * Upheap to repair the node structure.
     */
    void push(int idx, int weightArr[]) {
        if(size >= 63)
        {
            cout << "Too much data in the heap" << endl;
            return;
        }
        data[size] = idx;

        size++;
        upheap(size-1, weightArr);
    }

    /*
     * Pop from the array. Basically, makes the first "node" to the last one and then "removes" the last node.
     * Downheap to repair the node structure.
     */
    int pop(int weightArr[]) {
        if(size <= 0) {
            cout << "Can not pop nothing" << endl;
            return -1;
        }
        int removedInt = data[0];

        data[0] = data[size - 1];
        data[size-1] = -1;

        size--;

        if(size > 0)
            downheap(0, weightArr);
        return removedInt;
    }

    //Repair the Heap going down. Check if the parent weight is smaller than the child. It will then switch.
    /*
     * Have base cases for when the position is greater than or the size or if the position is less than 0.
     * Another base case for when nothing is in the array.
     * Have a loop, while there a parent that is greater than 0, we keep going and swapping if necessary.
     */
    void upheap(int pos, int weightArr[]) {
        // TODO: swap child upward while smaller than parent
        if(pos < 0 || pos >= size)
        {
            cout << "Out of bounds: Upheap" << endl;
            return;
        }

        if(size == 0)
            return;

        int i = pos;
        while(i > 0)
        {
            int parent = (i-1) / 2;

            if(data[parent] == -1 || data[i] == -1)
                break;

            if(weightArr[data[i]] >= weightArr[data[parent]] && data[i] >= data[parent])
                break;

            int dataTemp = data[i];
            data[i] = data[parent];
            data[parent] = dataTemp;
            i = parent;
        }
    }

    //Repair the Heap going down. Check if the current weight is bigger than the child. It will then switch.
    /*
     * Have base cases for out of bounds, whether the size is nothing or just 1, and then if there is only one child.
     * Then do the left and right child until we break out of the array, whenever the leftChild is bigger than the size.
     * Check weights of both and swaps if necessary.
     */
    void downheap(int pos, int weightArr[]) {
        if(pos < 0 || pos >= 63) {
            cout << "Out of bounds: Downheap" << endl;
            return;
        }

        if(size == 0 || size == 1)
            return;

        if(size == 2)
        {
            if(weightArr[data[0]] >= weightArr[data[1]])
            {
                int dataTemp = data[0];
                data[0] = data[1];
                data[1] = dataTemp;
                return;
            }

            return;
        }

        int parent = pos;
        while(true)
        {
            int leftChild = (2 * parent) + 1;
            int rightChild = (2 * parent) + 2;

            if(leftChild >= size)
                break;

            int smallestChild = leftChild;

            if(rightChild < size)
            {
                if(data[rightChild] != -1 && data[leftChild] != -1)
                {
                    if(weightArr[data[rightChild]] < weightArr[data[leftChild]] && data[rightChild] < data[leftChild])
                    {
                        smallestChild = rightChild;
                    }
                }
            }

            if(data[parent] == -1 || data[smallestChild] == -1) break;

            if(weightArr[data[parent]] <= weightArr[data[smallestChild]] && data[parent] <= data[smallestChild])
                break;

            int dataTemp = data[parent];
            data[parent] = data[smallestChild];
            data[smallestChild] = dataTemp;

            parent = smallestChild;
        }
    }
};

#endif