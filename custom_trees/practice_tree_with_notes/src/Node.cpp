#include "../include/Node.hpp"
#include <iostream>

Node::Node(int data) {
    // when we initialize don't forget to make the Node* NULL
    this->data = data;
    this->left = NULL;
    this->right = NULL;
}

void Node::set_data(int data) {
    this->data = data;
}

void Node::set_left(Node* left) {
    this->left = left;
}

void Node::set_right(Node* right) {
    this->right = right;
}

int Node::get_data() {
    return this->data;
}

Node* Node::get_left() {
    return this->left;
}

Node* Node::get_right() {
    return this->right;
}

Node** Node::get_left_address() {
    return &(this->left);
}

Node** Node::get_right_address() {
    return &(this->right);
}
