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
    int data[64];
    int size;

    MinHeap() { size = 0; }

    void push(int idx, int weightArr[]) {
        if(size == 0) {
            data[0] = idx;
        } else if (size == 63) {
            cout << "Too many numbers in the array/heap" << endl;
            return;
        } else {
            data[size] = idx;
        }

        size++;
        upheap(idx, weightArr);
    }

    int pop(int weightArr[]) {
        if(size == 0)
            return 0;

        int lastInt = data[size - 1];
        int removedInt = data[0];

        data[0] = lastInt;

        size--;
        downheap(0, weightArr);
        return removedInt;
    }

    void upheap(int pos, int weightArr[]) {
        // TODO: swap child upward while smaller than parent
        for(int i = pos; i >= 0; i--)
        {
            int parentPlace = (i-1) /2;
//            int leftChildPlace = (2*i) + 1;
//            int rightChildPlace = (2*i) + 2;

            if(parentPlace < 0)
            {
                return;
            }

            if(weightArr[data[parentPlace]] < weightArr[data[i]])
            {
                int parentData = data[parentPlace];
                data[parentPlace] = data[i];
                data[i] = parentData;
            }
        }
    }

    void downheap(int pos, int weightArr[]) {
        // TODO: swap parent downward while larger than any child
        if(size == 0)
            return;
    }
};

#endif