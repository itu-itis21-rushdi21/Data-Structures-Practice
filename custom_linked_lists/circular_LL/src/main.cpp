#include<iostream>
#include"../include/Circular_LL.hpp"

using namespace std;

int main(void) {

    Circular_LL* L = new Circular_LL();

    L->add_node(5);
    L->add_node(1);
    L->add_node(10);
    L->add_node(8);

    L->clear_list();
    
    L->add_node(5);
    L->add_node(1);
    L->add_node(10);
    L->add_node(8);
    
    L->print_Circular_LL();

    L->print_reverse_Circular_LL();
    Circular_LL* L2 = new Circular_LL();
    delete L2;
    delete L;

    return 0;
}