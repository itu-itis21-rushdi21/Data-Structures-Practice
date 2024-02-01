#include "../include/myStack.hpp"
#include<iostream>
// if you do stack templated you need to put the decleration and the class definition in the same file (hpp file)
// no separated cpp file to implement
using namespace std;

myStack::myStack() {
    this->top = 0;
    
}

bool myStack::isFull() {
    return top == MAX;
}

bool myStack::isEmpty(){
    return top == 0;
}

bool myStack::pop() {
    if(!this->isEmpty()){
        top--;
        return true;
    }
    return false;
}

bool myStack::push(int value){
    // adding this here is good
    if(!this->isFull()){
        arr[top++]  = value;
        return true;
    } else { 
        cout<< "stack is full"<< endl;
        return false;
    }
}

int myStack::peek() {
    int peek_top = top - 1;
    // doing --top or top-- is wrong when peeking cause top shouldn't change
    return arr[peek_top];
}

void myStack::clear() {
    top = 0;
}