#pragma once
#include "Node.hpp"

class Double_LL{
    private:
        Node* head;
        Node* tail;
    public:  
        Double_LL();
        ~Double_LL();
        Node* search_prev(int);
        Node* search_prev_tolga(int);
        void add_node(int);
        void remove_node(int);
        void print_Double_LL();
        void clear_list();
        
        // we can do it return Node* but this violates the princeple of not letting the user access node structure
        Node* contains(int);
        void print_reverse_Double_LL();
};