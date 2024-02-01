#pragma once
class PriorityQueue {
private:

public:
    
    int capacity;
    int size;
    int* heapArray;
    // Constructor
    PriorityQueue(int ) ;
    // Destructor
    ~PriorityQueue();

    // Function to insert an element into the priority queue
    void enqueue(int );

    //// Function to remove and return the maximum element (root) from the priority queue
    //int dequeue();
//
    //// Function to check if the priority queue is empty
    bool isEmpty() const;
    // Helper function to maintain the heap property after insertion
    void heapifyUp();

    // Helper function to maintain the heap property after removal
    void heapifyDown();

    void heapSort();

    void remove_middle(int);
    void heapifyUp_index(int);
    void heapifyDown_index(int);
};

void makeHeap(int*, int);

void makeHeap_recursive(int*, int, int);

void makeHeap_build(int*, int);