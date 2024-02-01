#include<iostream>
#include "../include/myStack.hpp"

int main(void) {

    myStack s;
    for(int i =0 ; i < 10; i++) {
        s.push(i);
    }
    for(int i = 0; i < 10; i++) {
        std::cout<< s.peek() << std::endl;
        s.pop();
    }
    return 0;
}