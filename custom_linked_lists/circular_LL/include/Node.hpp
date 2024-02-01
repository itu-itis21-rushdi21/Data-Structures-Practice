#pragma once

class Node {
    private:
        int data;
        const bool sentinel;
        Node* prev;
        Node* next;
    public:
        Node();
        Node(int, bool);
        int get_data();
        void set_data(int);
        Node* get_prev();
        void set_prev(Node*);
        Node* get_next();
        void set_next(Node*);
        bool isSentinel();
};