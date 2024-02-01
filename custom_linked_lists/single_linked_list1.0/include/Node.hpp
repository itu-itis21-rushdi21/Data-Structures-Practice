#pragma once

class Node {
    private:
        int data;
        Node* prev;
        Node* next;
    public:
        Node();
        Node(int);
        ~Node();
        int get_data();
        void set_data(int);
        Node* get_prev();
        void set_prev(Node*);
        Node* get_next();
        void set_next(Node*);
};