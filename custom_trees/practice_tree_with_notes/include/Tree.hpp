#include "Node.hpp"
#pragma once

class Tree {
    private:
        // like the head in LL
        Node* root;
        
        void print_preorder_private(Node*);
        void print_inorder_private(Node*);
        void print_postorder_private(Node*); 
        Node* find_parent_no_Dpointer(int);
        Node* find_parent_and_child(int, Node***);


    public:
        Tree();
        
        void add(int);
        void print_preorder();
        void print_inorder();
        void print_postorder();
        void print_BFS();
        bool contain(int);
        void remove(int);
        void remove_enhanced(int);
        void remove_reduced(int);
};
