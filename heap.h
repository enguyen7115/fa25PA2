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

    void push(int idx, int weightArr[]) {
        if(size >= 63) //Check if the heap is full.
        {
            cout << "Too many numbers in the array/heap" << endl;
            return;
        }
        data[size] = idx;

        size++;
        upheap(idx, weightArr); //Repair Heap
    }

    int pop(int weightArr[]) {
        if(size <= 0) {
            cout << "Can not pop nothing" << endl;
            return -1;
        }
        int removedInt = data[0];

        data[0] = data[size - 1]; //Set the first node to the last node
        data[size-1] = -1;

        size--;
        downheap(0, weightArr); //Downheap to repair the Heap
        return removedInt;
    }

    void upheap(int pos, int weightArr[]) {
        // TODO: swap child upward while smaller than parent
        if(pos < 0 || pos > 63)
        {
            cout << "Out of bounds" << endl;
            return;
        }

        //While loop for upheap since we don't know when to stop.
        int i = pos;

        while(i > 0)
        {
            int parent = (i-1) / 2;

            if(weightArr[data[i] >= weightArr[data[parent]]]) //The data[i] inside the weightArr is so we can get the weightArr of the number, even after we move the nodes around.
                break;

            int dataTemp = data[i];
            data[i] = data[parent];
            data[parent] = dataTemp;
            i = parent;
        }
    }

    void downheap(int pos, int weightArr[]) {
        // TODO: swap parent downward while larger than any child
        if(pos < 0 || pos > 63) {
            cout << "Out of bounds" << endl;
            return;
        }

        int parent = pos;
        if(size == 0)
        {
            return;
        }

        while(parent <= size)
        {
            int leftChild = (2 * parent) + 1;
            int rightChild = (2 * parent) + 2;

            if(weightArr[data[parent]] >= weightArr[data[leftChild]])
            {
                int dataTemp = data[parent];
                data[parent] = data[leftChild];
                data[leftChild] = dataTemp;
                parent = leftChild;
            } else if(weightArr[data[parent]] >= weightArr[data[rightChild]])
            {
                int dataTemp = data[parent];
                data[parent] = data[rightChild];
                data[rightChild] = dataTemp;
                parent = rightChild;
            } else {
                break;
            }
        }
    }
};

#endif