#include<iostream>
#include "../include/Node.h"
#include "../include/LinkedList.h"
using namespace std;

int main() {
    /*
    Node* head ;
    head = new Node(1);
    // we don't need to set it to NULL as it will be Null by default
    
    Node* two = new Node(2);
    head->set_next(two);
    // set and intialize in one line
    // but then we have no variable name for 3 it is there but we can't refer to it
    two->set_next(new Node(3));
    // since we can't access 3 as a named varaible we have to do this and chain (unless we want to create named variable for each node )
    // we will have a chain of get-nexts then one set next
    two->get_next()->set_next(new Node(4));
    two->get_next()->get_next()->set_next(new Node(5));
    */
    LinkedList* L1 = new LinkedList();
    //Node* found_3 = L1.search_prev(1);
    // KEY no need to have a holder value for intializing a new node
    // you can do it in the method add_node
    L1->add_node(5);
    L1->add_node(1);
    L1->add_node(10);
    L1->add_node(8);
    L1->print_LinkedList();
    L1->remove_node(5);
    L1->remove_node(1);
    L1->remove_node(3);
    L1->remove_node(10);
    L1->remove_node(8);
    L1->remove_node(3);
    //L1->remove_node(8);
    cout << "\n";
    L1->print_LinkedList();
    cout << "\n";
    //Node* found = L1.search_prev(2);    
    //Node* found_2 = L1.search_prev_tolga(2);
    //found = L1.search_prev(6);
    //found_2 = L1.search_prev_tolga(6);
    delete L1;
    return 0;
}
