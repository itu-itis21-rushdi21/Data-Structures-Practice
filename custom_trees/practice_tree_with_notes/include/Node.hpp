#pragma once

class Node {
    private:
        int data;
        Node* left;
        Node* right;
    public:
        Node(int);

        void set_data(int);
        void set_left(Node*);
        void set_right(Node*);
        Node** get_left_address();
        Node** get_right_address();
        int get_data();
        Node* get_left();
        Node* get_right();

        
};
