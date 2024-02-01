#include "../include/final_tree.hpp"
#include <iostream>

using namespace std;

void func(int &var)
{
    var = 7;
    var = var + 1;
}

void func2(int *var)
{
    *var = 7;
    *var = *var + 1;
}

int main(void)
{
    final_tree *t = new final_tree();
    final_tree *t0 = new final_tree();

    t0->insert(10);
    t0->insert(5);
    t0->insert(15);
    t0->insert(7);
    t0->insert(6);
    t0->insert(9);

    // t0->remove_inorder_successor(5);

    // int var;
    // func(var);
    // func2(&var);
    ////or func(&var) if func is int* paremeter
    // int* var2;
    // func(*var2);
    // func(var);

    t->insert(10);
    t->insert(5);
    t->insert(15);
    t->insert(3);
    t->insert(7);
    t->insert(11);
    t->insert(20);
    t->insert(1);
    t->insert(4);
    t->insert(6);
    t->insert(9);

    // t->print_inorder();
    // t->print_preorder();
    // t->print_postorder();
    // t->print_BFS();
    // t->remove_inorder_successor(10);
    // t->remove_inorder_successor(5);
    // t->remove_inorder_successor(1);
    // t->remove_inorder_successor(30);
    // t->remove_inorder_successor(10);

    // My 12 test cases

    final_tree *t1 = new final_tree();
    final_tree *t2 = new final_tree();
    final_tree *t3 = new final_tree();
    final_tree *t4 = new final_tree();

    final_tree *t5_1 = new final_tree();
    final_tree *t6 = new final_tree();
    final_tree *t7 = new final_tree();
    final_tree *t8 = new final_tree();
    final_tree *t9 = new final_tree();
    final_tree *t10 = new final_tree();
    final_tree *t11 = new final_tree();
    final_tree *t12 = new final_tree();
    /*
    // t1
    t1->insert(10);
    t1->remove_inorder_successor(10);

    // t2
    t2->insert(10);
    t2->insert(5);
    t2->remove_inorder_successor(10);

    // t3
    t3->insert(10);
    t3->insert(15);
    t3->remove_inorder_successor(10);

    // t4
    t4->insert(10);
    t4->insert(5);
    t4->insert(15);
    t4->remove_inorder_successor(10);

    // t5
    t5->insert(10);
    t5->insert(5);
    t5->insert(15);
    t5->remove_inorder_successor(5);

    // t6
    t6->insert(10);
    t6->insert(5);
    t6->insert(15);
    t6->remove_inorder_successor(15);

    // t7
    t7->insert(10);
    t7->insert(5);
    t7->insert(3);
    t7->remove_inorder_successor(5);

    // t8
    t8->insert(10);
    t8->insert(5);
    t8->insert(7);
    t8->remove_inorder_successor(5);

    // t9
    t9->insert(10);
    t9->insert(5);
    t9->insert(3);
    t9->insert(7);
    t9->remove_inorder_successor(5);

    // t10
    t10->insert(10);
    t10->insert(15);
    t10->insert(13);
    t10->remove_inorder_successor(15);

    // t11
    t11->insert(10);
    t11->insert(15);
    t11->insert(17);
    t11->remove_inorder_successor(15);

    // t12
    t12->insert(10);
    t12->insert(15);
    t12->insert(13);
    t12->insert(17);
    t12->remove_inorder_successor(15);
    */
    // done

    // try same examples with remove_inorder_successor_enhanced:
    /*
    // t1 failed
    t1->insert(10);
    t1->remove_inorder_successor_enhanced(10);

    //t2 failed
    t2->insert(10);
    t2->insert(5);
    t2->remove_inorder_successor_enhanced(10);

    //t3 failed
    t3->insert(10);
    t3->insert(15);
    t3->remove_inorder_successor_enhanced(10);

    // t4 failed
    t4->insert(10);
    t4->insert(5);
    t4->insert(15);
    t4->remove_inorder_successor_enhanced(10);

    // t5 failed
    t5->insert(10);
    t5->insert(5);
    t5->insert(15);
    t5->remove_inorder_successor_enhanced(5);

    // t6 failed
    t6->insert(10);
    t6->insert(5);
    t6->insert(15);
    t6->remove_inorder_successor_enhanced(15);

    // t7 success
    t7->insert(10);
    t7->insert(5);
    t7->insert(3);
    t7->remove_inorder_successor_enhanced(5);

    // t8 failed
    t8->insert(10);
    t8->insert(5);
    t8->insert(7);
    t8->remove_inorder_successor_enhanced(5);

    // t9 success
    t9->insert(10);
    t9->insert(5);
    t9->insert(3);
    t9->insert(7);
    t9->remove_inorder_successor_enhanced(5);

    // t10 sucess
    t10->insert(10);
    t10->insert(15);
    t10->insert(13);
    t10->remove_inorder_successor_enhanced(15);

    // t11 failed
    t11->insert(10);
    t11->insert(15);
    t11->insert(17);
    t11->remove_inorder_successor_enhanced(15);

    // t12 success
    t12->insert(10);
    t12->insert(15);
    t12->insert(13);
    t12->insert(17);
    t12->remove_inorder_successor_enhanced(15);

    // done
    */

    // try same examples with remove_inorder_successor:

    // t1 failed
    t1->insert(10);
    t1->remove_inorder_successor(10);

    // t2 failed
    t2->insert(10);
    t2->insert(5);
    t2->remove_inorder_successor(10);

    // t3 failed
    t3->insert(10);
    t3->insert(15);
    t3->remove_inorder_successor(10);

    // t4 failed
    t4->insert(10);
    t4->insert(5);
    t4->insert(15);
    t4->remove_inorder_successor(10);
    //    t4->remove_inorder_successor(10);

    // t5 failed
    t5_1->insert(10);
    t5_1->insert(5);
    t5_1->insert(15);
    t5_1->remove_inorder_successor(5);

    // t6 failed
    t6->insert(10);
    t6->insert(5);
    t6->insert(15);
    t6->remove_inorder_successor(15);

    // t7 success
    t7->insert(10);
    t7->insert(5);
    t7->insert(3);
    t7->remove_inorder_successor(5);

    // t8 failed
    t8->insert(10);
    t8->insert(5);
    t8->insert(7);
    t8->remove_inorder_successor(5);

    // t9 success
    t9->insert(10);
    t9->insert(5);
    t9->insert(3);
    t9->insert(7);
    t9->remove_inorder_successor(5);

    // t10 sucess
    t10->insert(10);
    t10->insert(15);
    t10->insert(13);
    t10->remove_inorder_successor(15);

    // t11 failed
    t11->insert(10);
    t11->insert(15);
    t11->insert(17);
    t11->remove_inorder_successor(15);

    // t12 success
    t12->insert(10);
    t12->insert(15);
    t12->insert(13);
    t12->insert(17);
    t12->remove_inorder_successor(15);

    return 0;
}