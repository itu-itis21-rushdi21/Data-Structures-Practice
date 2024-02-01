#include<iostream>
#include"../include/Double_LL.hpp"

using namespace std;

int main(void) {

    Double_LL* L = new Double_LL();

    L->add_node(5);
    L->add_node(1);
    L->add_node(10);
    L->add_node(8);

    L->clear_list();
    
    L->add_node(5);
    L->add_node(1);
    L->add_node(10);
    L->add_node(8);
    
    L->print_Double_LL();

    L->print_reverse_Double_LL();
    Double_LL* L2 = new Double_LL();
    delete L2;
    delete L;

    return 0;
}