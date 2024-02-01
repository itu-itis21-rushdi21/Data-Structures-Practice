#include "../include/Tree.hpp"
#include <iostream>

using namespace std;

void func(int& var) {
    var = 7;
    var = var + 1;
}

void func2(int* var) {
    *var = 7;
    *var = *var + 1;
}

int main(void) {
    //Tree* t= new Tree();
    //Tree* t0 = new Tree();
//
    //t0->add(10);
    //t0->add(5);
    //t0->add(15);
    //t0->add(7);
    //t0->add(6);
    //t0->add(9);
//
    //t0->remove(5);
//
    ////int var;
    ////func(var);
    ////func2(&var);
    //////or func(&var) if func is int* paremeter
    ////int* var2;
    ////func(*var2);
    ////func(var);
//
    //t->add(10);
    //t->add(5);
    //t->add(15);
    //t->add(3);
    //t->add(7);
    //t->add(11);
    //t->add(20);
    //t->add(1);
    //t->add(4);
    //t->add(6);
    //t->add(9);
//
    //t->print_inorder();
    //t->print_preorder();
    //t->print_postorder();
    //t->print_BFS();
    ////t->remove(10);
    ////t->remove(5);
    ////t->remove(1);
    //t->remove(30);
    //t->remove(10);
//
    //if(t->contain(3)) {
    //    cout<< "contain 3";
    //}
    //
    //if(t->contain(10)) {
    //    cout<< "contain 10";
    //}
//

    // My 12 test cases
    
    Tree* t1= new Tree();
    Tree* t2= new Tree();
    Tree* t3= new Tree();
    Tree* t4= new Tree();
    Tree* t5= new Tree();
    Tree* t6= new Tree();
    Tree* t7= new Tree();
    Tree* t8= new Tree();
    Tree* t9= new Tree();
    Tree* t10= new Tree();
    Tree* t11= new Tree();
    Tree* t12= new Tree();
    /*
    // t1
    t1->add(10);
    t1->remove(10);
    
    // t2
    t2->add(10);
    t2->add(5);
    t2->remove(10);

    // t3
    t3->add(10);
    t3->add(15);
    t3->remove(10);

    // t4
    t4->add(10);
    t4->add(5);
    t4->add(15);
    t4->remove(10);

    // t5
    t5->add(10);
    t5->add(5);
    t5->add(15);
    t5->remove(5);
    
    // t6
    t6->add(10);
    t6->add(5);
    t6->add(15);
    t6->remove(15);

    // t7
    t7->add(10);
    t7->add(5);
    t7->add(3);
    t7->remove(5);

    // t8
    t8->add(10);
    t8->add(5);
    t8->add(7);
    t8->remove(5);

    // t9
    t9->add(10);
    t9->add(5);
    t9->add(3);
    t9->add(7);
    t9->remove(5);

    // t10
    t10->add(10);
    t10->add(15);
    t10->add(13);
    t10->remove(15);

    // t11
    t11->add(10);
    t11->add(15);
    t11->add(17);
    t11->remove(15);

    // t12
    t12->add(10);
    t12->add(15);
    t12->add(13);
    t12->add(17);
    t12->remove(15);
    */
    // done

    //try same examples with remove_enhanced:
    /*
    // t1 failed
    t1->add(10);
    t1->remove_enhanced(10);

    //t2 failed
    t2->add(10);
    t2->add(5);
    t2->remove_enhanced(10);

    //t3 failed
    t3->add(10);
    t3->add(15);
    t3->remove_enhanced(10);

    // t4 failed
    t4->add(10);
    t4->add(5);
    t4->add(15);
    t4->remove_enhanced(10);

    // t5 failed
    t5->add(10);
    t5->add(5);
    t5->add(15);
    t5->remove_enhanced(5);

    // t6 failed
    t6->add(10);
    t6->add(5);
    t6->add(15);
    t6->remove_enhanced(15);

    // t7 success
    t7->add(10);
    t7->add(5);
    t7->add(3);
    t7->remove_enhanced(5);

    // t8 failed
    t8->add(10);
    t8->add(5);
    t8->add(7);
    t8->remove_enhanced(5);

    // t9 success
    t9->add(10);
    t9->add(5);
    t9->add(3);
    t9->add(7);
    t9->remove_enhanced(5);

    // t10 sucess
    t10->add(10);
    t10->add(15);
    t10->add(13);
    t10->remove_enhanced(15);

    // t11 failed
    t11->add(10);
    t11->add(15);
    t11->add(17);
    t11->remove_enhanced(15);

    // t12 success
    t12->add(10);
    t12->add(15);
    t12->add(13);
    t12->add(17);
    t12->remove_enhanced(15);
    
    // done    
    */ 

    //try same examples with remove_enhanced:
    
    // t1 failed
    t1->add(10);
    t1->remove_enhanced(10);

    //t2 failed
    t2->add(10);
    t2->add(5);
    t2->remove_enhanced(10);

    //t3 failed
    t3->add(10);
    t3->add(15);
    t3->remove_enhanced(10);

    // t4 failed
    t4->add(10);
    t4->add(5);
    t4->add(15);
    t4->remove_enhanced(10);

    // t5 failed
    t5->add(10);
    t5->add(5);
    t5->add(15);
    t5->add(7);
    t5->remove_enhanced(5);

    // t6 failed
    t6->add(10);
    t6->add(5);
    t6->add(15);
    t6->remove_enhanced(15);

    // t7 success
    t7->add(10);
    t7->add(5);
    t7->add(3);
    t7->remove_enhanced(5);

    // t8 failed
    t8->add(10);
    t8->add(5);
    t8->add(7);
    t8->remove_enhanced(5);

    // t9 success
    t9->add(10);
    t9->add(5);
    t9->add(3);
    t9->add(7);
    t9->remove_enhanced(5);

    // t10 sucess
    t10->add(10);
    t10->add(15);
    t10->add(13);
    t10->remove_enhanced(15);

    // t11 failed
    t11->add(10);
    t11->add(15);
    t11->add(17);
    t11->remove_enhanced(15);

    // t12 success
    t12->add(10);
    t12->add(15);
    t12->add(13);
    t12->add(17);
    t12->remove_enhanced(15);


    return 0;
}