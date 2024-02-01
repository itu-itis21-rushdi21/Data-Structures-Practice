#pragma once
class Node{ 
    private:
        int data;
        Node* next;
    public:
        Node(int);
        ~Node();
        void set_data(int);
        void set_next(Node*);
        int get_data();
        Node* get_next();
};