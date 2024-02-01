#include "../include/Node.hpp"
#include <iostream>
Node::Node(int data){
    this->data = data;
    // this is important why though
    this->next = NULL;
    this->prev = NULL;
}
// we need this ditructor to make the implicit traversion delete for LL
// to delete iteratively we won't need this distructor
//Node::~Node(){
//    // this condition garantee that we don't call delete of next that is NULL (when we reach the end of the LL)
//    // (if the next node is empty) or if we deal with node not to delete an empty node
//    // those functions will call each other and be placed on the call stack 
//    // the first node to be deleted is the last node (tail node) (first destructor call poped)
//    if(this->next != NULL)
//        delete this->next;
//}
// default one is enough


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