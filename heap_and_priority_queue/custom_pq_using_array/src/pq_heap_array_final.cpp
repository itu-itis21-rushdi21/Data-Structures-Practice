#include <iostream>
#include <stdlib.h>
#include "../include/pq_heap_array.h"

using namespace std;
PriorityQueue::PriorityQueue(int cap) {
    this->capacity = cap;
    this->heapArray = new int[cap];
    this->size = 0;
}

PriorityQueue::~PriorityQueue() {
    delete[] heapArray;
}

bool PriorityQueue:: isEmpty() const {
    return size == 0;
}

void PriorityQueue::heapifyUp() {
    // we always start from the last element (the element added) 
    // we can add in one place only
    int index = size - 1;
    // we keep on checking until we reach the root
    while(index > 0) {
        // refresh the parent index every time we iterate
        int parIndex = (index - 1) / 2;
        // this is a max heap
        if(heapArray[index] > heapArray[parIndex]) {
            // funciton in stdlib
            swap(heapArray[index], heapArray[parIndex]);
            // if we swap we will refresh the index to be the parent index and the parent index when the loop start will be refreshed too
            index = parIndex;
        } else {
            // when we can't swap this means we have finished no need for more checks
            break;
        }
    }
}

void PriorityQueue::heapifyDown() {
    // here we start from the root cause after we swap with the last element the root our problem will be the root
    // if we remove from the middle we should 
    int index = 0;
    while(true) {
        int largest = index;
        int lcI = 2 * index + 1;
        int rcI = 2 * index + 2;
        if(heapArray[lcI] > heapArray[largest] && lcI < size) {
            largest = lcI;
        } 
        if(heapArray[rcI] > heapArray[largest] && rcI < size) {
            largest = rcI;
        } 
        if(largest != index) {
            swap(heapArray[largest], heapArray[index]);
            index = largest;
        } else {
            break;
        }
    }
}

void PriorityQueue::enqueue(int value) {
    if(size == capacity) {
        cout << "heap is full" <<endl;
        return;
    }
    heapArray[size] = value;
    size++;
    heapifyUp();

}

void PriorityQueue::heapSort() {
    int temp_size = size;
    for(int i = 0; i < temp_size; i++) {
        int max = heapArray[0];
        heapArray[0] = heapArray[size - 1];
        size--;
        heapArray[size] = max;
        heapifyDown(); 
    }
    size = temp_size;
}

void makeHeap(int heapArray[], int size) {
    int start = size/2 - 1;
    for(int index = start; index >=0; index--) {
        while(true) {
            int largest = index;
            int leftIndex = 2 * index + 1;
            int rightIndex = 2 * index + 2;
            if(leftIndex < size && heapArray[leftIndex] > heapArray[largest]) {
                largest = leftIndex;
            }   
            if(rightIndex < size && heapArray[rightIndex] > heapArray[largest]) {
                largest = rightIndex;
            }   
            if(largest != index) {
                swap(heapArray[largest], heapArray[index]);
                index = largest;
            } else {
                break;
            }
        }
    }
}

void makeHeap_build(int heapArray[], int size) {
    int start = size/2 - 1;
    for(int index = start; index >=0; index--) {
       makeHeap_recursive(heapArray, size, index);
    }
}

void makeHeap_recursive(int heapArray[], int size, int index) {
    
    int largest = index;
    int leftIndex = 2 * index + 1;
    int rightIndex = 2 * index + 2;
    if(leftIndex < size && heapArray[leftIndex] > heapArray[largest]) {
        largest = leftIndex;
    }   
    if(rightIndex < size && heapArray[rightIndex] > heapArray[largest]) {
        largest = rightIndex;
    }   
    if(largest != index) {
        swap(heapArray[largest], heapArray[index]);
        makeHeap_recursive(heapArray, size, largest);
    }    
}

void PriorityQueue::remove_middle(int element) {
    bool exist = false;
    int index;
    for(index = 0; index < size; index++) {
        if(heapArray[index] == element) {
            exist = true;
            break;
        }
    }
    if(!exist) {
        cout << "element to remove doesn't exist" << endl;
        return;
    }
    heapArray[index] = heapArray[size - 1];
    size--;
    int parent = (index - 1) / 2;
    int leftIndex = (2* index) + 1;
    int rightIndex = (2* index) + 2;

    if(heapArray[index] > heapArray[parent]) {
        heapifyUp_index(index);
        return;
    }
    if(heapArray[index] < heapArray[leftIndex] || heapArray[index] < heapArray[rightIndex]) {
        heapifyDown_index(index);
        return;
    }
}

void PriorityQueue::heapifyUp_index(int index) {
    while(index != 0) {
        int parentIndex = (index-1) / 2;
        if(heapArray[index] > heapArray[parentIndex]){
            swap(heapArray[index] , heapArray[parentIndex]);
            index = parentIndex;
        } else {
            break;
        }
    }
}

void PriorityQueue::heapifyDown_index(int index) {
    while(true) {
        int largest = index;
        int leftIndex = 2* index + 1;
        int rightIndex = 2* index + 2;

        if(heapArray[largest]  < heapArray[leftIndex] && leftIndex < size){
            largest = leftIndex;
        }
        if(heapArray[largest]  < heapArray[rightIndex] && rightIndex < size){
            largest = rightIndex;
        }
        if(largest != index) {
            swap(heapArray[largest]  , heapArray[index]);
            index = largest;
        } else {
            break;
        }
    }
}