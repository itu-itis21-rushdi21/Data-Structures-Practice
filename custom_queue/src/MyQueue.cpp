#include "MyQueue.h"

MyQueue:: MyQueue() {
    front = 0;
    back = -1;
    num_of_items = 0;
}
// because we have mode QUEUE_MAX_SIZE we do these operations on multi steps to avoid shit code
// here we increment back then equeue so no need for temp
bool MyQueue:: enqueue(int element) {
    if(!this->isFull()) {
        back++;
        // this is confirmed to work instead of the mode
        //if(back == QUEUE_MAX_SIZE) back = 0;
        back %= QUEUE_MAX_SIZE;
        arr[back] = element;
        num_of_items++;
        return true;
    }
    return false;
}

// we take the value of the current arr[front] then increment then take mode MAX
// that is why we need to save the value of arr[front] in what is sort of a temp value and then return that temp value
// if we return then increment and mode we will not do the increment and the moding 
// mode will do nothing basically until we reach the end of the MAX_SIZE we can even say if(front == MAX_SIZE) front = 0;  
int MyQueue:: dequeue() {
    if(!this->isEmpty()) {
        int value = arr[front];
        // he does front = (front+1) % MAX 
        // front+1 means eveluated it as a part of the expression we could have used ++front instead but this is clearer 
        front++;
        //if(front == QUEUE_MAX_SIZE) front = 0;
        front %= QUEUE_MAX_SIZE;
        num_of_items--;
        return value;
    }
    return -1;
}
int MyQueue:: peek_front() {
    if(!this->isEmpty()) {
        return arr[front];
    }
    return -1;
}
int MyQueue:: peek_back() {
    if(!this->isEmpty()) {
        return arr[back];
    }
    return -1;
}
bool MyQueue:: isEmpty() {
    if(num_of_items == 0) {
        return true;
    }   
    return false;
}
bool MyQueue:: isFull() {
    // the number of items can be QUEUE_MAX_SIZE cause we can have all the places full for example here MAX = 10 so we have 0 to 9 full
    // what can't be 10 however and have a max value of MAX - 1 is the index of front and back cause the items are numbered from 0 to 9
    // we could have done it in one line: return num_of_items == QUEUE_MAX_SIZE;   
    if(num_of_items == QUEUE_MAX_SIZE ) {
        return true;
    }
    return false;
}
// Why clearing requires us to do all those three operations while isEmpty is only checked using num_of_items == 0;
// clear turns the queue empty so shouldn't num_of_items == 0 enough
// I think clear is more like a rest that is why even if the queue is empty we can add items to indexes and not starting from 0
// but clear means empty and reset the front and back arrows indexes to the 0 index at the circle
// but where is the -1 on tolga circle example only back can be -1 but when adding and then using mode we are never back to -1 unles we clear ?? neat 
void MyQueue:: clear() {
    front = 0;
    back = -1;
    num_of_items = 0;
}