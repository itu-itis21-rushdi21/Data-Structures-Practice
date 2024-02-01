#include "../include/Node.hpp"
#include<iostream>

Node::Node(int data) {
    this->data = data;
    this->right = NULL;
    this->left = NULL;
}

Node::~Node() {
}

int Node::get_data() {
    return data;
}

void Node::set_data(int data) {
    this->data = data;
}


Node* Node::get_right() {
    return right;
}

void Node::set_right(Node* right) {
    this->right = right;
}

Node* Node::get_left() {
    return left;
}

void Node::set_left(Node* left) {
    this->left = left;
}





