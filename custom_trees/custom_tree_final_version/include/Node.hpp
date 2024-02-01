#pragma once

class Node{
    private:
        int data;
        Node* right;
        Node* left;
    public:
        Node(int);
        ~Node();
        int get_data();
        Node* get_right();
        Node* get_left();
        void set_data(int);
        void set_right(Node*);
        void set_left(Node*);
        
};