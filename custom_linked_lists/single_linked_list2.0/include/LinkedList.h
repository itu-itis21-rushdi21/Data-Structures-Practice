#pragma once
#include "Node.h"
class LinkedList {
    private:
        Node* head;
        Node* tail;
        // we make the search function private cause we don't want the user to know
        // about our implementation details (returning a Node* make the user have to do with Node class)
        // which is our internal implementation 
        // we can write a public search that returns the previous number instead
        
        Node* search_prev(int);
        
        Node* search_prev_tolga(int);
        
    public:
        void add_node(int);
        void remove_node(int);
        LinkedList();
        ~LinkedList();
        void print_LinkedList();
        void clear();
        bool contains(int);
};