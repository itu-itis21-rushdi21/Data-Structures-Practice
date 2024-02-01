#pragma once
const int MAX = 10;
// GREAT NOTE: remember you can edit your break points this is a love saver

class myStack{
    // if we follow the design top initialy points to -1 it doesn't point to the next place to put the incoming elment (next empty place)
    // it is showing the last incoming element that has been put (the last full space) and -1 in this case means no last full space
    // circular approach is only needed for queue and even size only for queue
    // we can depend on top to find size and full/empty (in stack we have one point top of entry and exit that is why whereas in queue we have 2 front and back)
    private:
        // intialize top in the constructor doing it here is nasty
        int top;
        int arr[MAX];
    public:
        myStack();
        bool isEmpty();
        // is full not needed with LL stack cause there is not cap
        bool isFull();
        bool pop();
        bool push(int);
        int peek();
        void clear();






};