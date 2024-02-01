#include "../include/Node.hpp"
#include <iostream>
Node::Node(int data, bool sentinel):sentinel(sentinel) {
    this->data = data;
    // we can't initialize cons this way
    //this->sentinel = sentinel;
    // this is important why though
    this->next = NULL;
    this->prev = NULL;
}

void Node::set_data(int data){
    this->data = data;
}

void Node::set_next(Node* next) {
    this->next = next;
}

int Node::get_data() {
    return data;
}

Node* Node::get_next(){
    return next;
}
void Node::set_prev(Node* prev) {
    this->prev = prev;
}

Node* Node::get_prev(){
    return prev;
}

// note no need for a setter as the sentinal node is set and not changed later 
bool Node::isSentinel() {
    return this->sentinel;
}