#pragma once
#include "Node.hpp"
class final_tree {
    private:
        Node* root;
        void print_inorder_recursive(Node*);
        void print_preorder_recursive(Node*);
        void print_postorder_recursive(Node*); 

    public:
        final_tree();
        ~final_tree();
        Node* get_root();
        void set_root(Node*);

        // iterative insert, remove, search
        void insert(int);
        void remove_advanced(int);
        void remove_inorder_successor(int);
        Node* search(int);
        int get_height();
        
        // iterative print functions
        void print_BFS();
        void print_preorder();
        void print_inorder();
        void print_postorder();
        // recursive print functions
        void print_inorder_recursive();
        void print_preorder_recursive();
        void print_postorder_recursive(); 

};