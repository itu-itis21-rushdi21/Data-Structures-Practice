#include "../include/Tree.hpp"
#include <iostream>
#include <queue>

using namespace std;

Tree::Tree() {
    // again always the Node* are initialized to NULL
    this->root = NULL;
}
// one issue with this implementaion is that we can't directly access the parent we can if we have a pointer to a child traverse the tree
// in a way to find the parent but we can just add a prarent pointer in Node structure and solve the issue
// for the return type we can return bool or Node* (a pointer to the node we added in the tree(it violates the hiding principale in OOP))
// to allow the user to use the place but at the same time not access Node structure we can use the iterator abstraction 
// we hid the implementation adn at the same time we return to the user the exact place wehre the data was added throught the iterator
void Tree::add(int data) {
    Node* n = new Node(data);

    if(root == NULL) {
        root = n;
        // here to return Node* we would have returned root or n
        return;
    }
    // this is not a traversal but a binary addition in a way
    // we take a copy of the root so that we don't lose the tree when traversing
    Node* temp = root;
    // we iterate until we eithier find that the element is there or until we hit the first null meaning we found the addition place stored in temp
    while(temp != NULL) {
        // if current node (current temp is larger than data we go left of that node)
        if(temp->get_data() > data) {
            // if temp not null but its left is NULL we can make the addition here then we won't need the condition in the loop above
            if(temp->get_left() == NULL) {
                // can we set temp get_left->set_data yes but why
                temp->set_left(n);
                // if we wanted to return Node* we return temp here
                return;
            }
            temp = temp->get_left();
        }
        else if(temp->get_data() < data){
            if(temp->get_right() == NULL) {
                temp->set_right(n);
                // with this return the codition above for while is trivial
                // this return is key because if i don't return after we add we will move temp once to the right which is now the node we just added
                // so now temp will be in the node we added and cause temp is not null, on the next iteration (which is not needed), we will find the value pointed by temp
                // to be equal to data which is normal :) since they are the same thing and thus we will enter the final else and delete n thus deleting a node in the tree then in the destructer
                // it will be deleted again :)
                return;
            }
            temp = temp->get_right();
        }
        else {
            // if they are equal we don't do anything (no duplicates)
            // Note if we couldn't add the node n (no dublicates) we should delete it cause even if we destroy the tree it won't be destroyed :)
            delete n;
            // here we would have returned NULL mostly ??
            return;
        }
    }
}
// simple search binarty search only for BST whereas DFS BFS are for all trees and they are always O(n)
// this function when used to add will not result in a structure that violates binary trees ex is element added to right of a parent that is left child of an upper node
// this element is larger than both its direct parent (correct) and its parent parent (wrong cause the parent is left child of the parent parent)
// why this will never happen cause we check top down :)
bool Tree::contain(int data) {

    if(root == NULL) {
        return false;
    }
    Node* temp = root;
    while(temp != NULL) {
        if(temp->get_data() > data) {
            temp = temp->get_left();
        }
        else if(temp->get_data() < data){
            temp = temp->get_right();
        }
        else {
            return true;
        }
    }
    // if we couldn't find the temp will be null and we will go out of the loop
    return false;
}

void Tree::print_preorder_private(Node* n) {
    if(n!= NULL) {
        cout<< n->get_data();
        // now we call the function with its parameters
        this->print_preorder_private(n->get_left());
        this->print_preorder_private(n->get_right());
    }
}
// this proxy function is only key when we are talking about recursive design that require no parameter passing
void Tree::print_preorder() {
    this->print_preorder_private(this->root);
    cout<< endl;
}

void Tree::print_postorder_private(Node* n) {
    if(n != NULL) {
        this->print_postorder_private(n->get_left());
        this->print_postorder_private(n->get_right());
        cout<< n->get_data();
    }
}

void Tree::print_postorder() {
    this->print_postorder_private(this->root);
    cout<< endl;
}

void Tree::print_inorder_private(Node* n) {
    if(n!= NULL) {
        // now we call the function with its parameters
        this->print_inorder_private(n->get_left());
        cout<< n->get_data();
        this->print_inorder_private(n->get_right());
    }
}

void Tree::print_inorder() {
    this->print_inorder_private(this->root);
    cout<< endl;
}

void Tree::print_BFS() {
    Node* temp;
    queue<Node*> q;

    q.push(this->root);

    while(!q.empty()) {
        temp = q.front();
        // we don't need to check if we are calling temp->get_data() to a NULL pointer cause we will never push a NULL to begin with
        // 
        cout<< temp->get_data();
        q.pop();
        // we don't want to push NULLS at the end of the tree to the queue
        if(temp->get_left() != NULL) {
            q.push(temp->get_left());
        }
        if(temp->get_right() != NULL) {
            q.push(temp->get_right());
        }
    } 
    cout<<endl;
}

void Tree::remove(int data) {
    // if tree is empty we don't do nothing or if the data is not there
    // we should always use contain before find parent
    if(this->root == NULL || !this->contain (data)) {
        return;
    }
    Node* deleted_node;
    Node* right_most;
    Node* deleted_node_left;
    Node* deleted_node_right;
    Node* parent = find_parent_no_Dpointer(data);

    // we also need to handle the case of deleting a leaf (no children)
    // also the case of deleting a node with single child (here we have 2 cases)
    // here we need to take care of the case the deleted node is root and also inside it we need 3 cases when it has both children or 1 or non 

    //if deleted node is root
    if(parent == NULL) {
        // no child exist
        if(root->get_left() == NULL && root->get_right() == NULL) {
            delete root; 
            // if we don't delete the tree or set the root to NULL we will have a dangling pointer which will result in the tree having values added to it from other trees
            delete this;    
        }
        // right child only for the root
        else if(root->get_right() != NULL && root->get_left() == NULL) {
            Node* old_root = root;
            root = root->get_right();
            delete old_root;
        }
        // left child only for the root
        else if(root->get_left() != NULL && root->get_right() == NULL) {
            Node* old_root = root;
            root = root->get_left();
            delete old_root;
        }
        // both children exist
        else {
            Node* old_root = root;
            root = root->get_left();
            Node* right_most = old_root->get_left();
            while(right_most->get_right() != NULL) {
                right_most = right_most->get_right();
            }
            right_most->set_right(old_root->get_right());
            delete old_root;
        }
        return;
    }

    //if deleted node is leaf (no children)
    // we check for NULL first not to read if the left leaf is not there
    // left leaf case
    if(parent->get_left() != NULL) {
        if(parent->get_left()->get_data() == data && parent->get_left()->get_left() == NULL && parent->get_left()->get_right() == NULL) {
            delete parent->get_left();
            return;
        }
    }
    // right leaf case
    if(parent->get_right() != NULL) {
        if(parent->get_right()->get_data() == data && parent->get_right()->get_left() == NULL && parent->get_right()->get_right() == NULL) {
            delete parent->get_right();
            return;
        }
    }

    // if deleted node had 1 have child
    if(parent->get_left() != NULL) {
        //deleted node is left of parent AND deleted node has single child The left child (right is NULL)
        if(parent->get_left()->get_data() == data && parent->get_left()->get_right() == NULL) {
            deleted_node = parent->get_left();
            deleted_node_left = deleted_node->get_left();
            parent->set_left(deleted_node_left);
            delete deleted_node;
            return;
        }
        //deleted node is left of parent AND deleted node has single child The right child (left is NULL)
        if(parent->get_left()->get_data() == data && parent->get_left()->get_left() == NULL) {
            deleted_node = parent->get_left();
            deleted_node_right = deleted_node->get_right();
            parent->set_left(deleted_node_right);
            delete deleted_node;
            return;
        }

    }
    if(parent->get_right() != NULL) {
        //deleted node is right of parent AND deleted node has single child The left child (right is NULL)
        if(parent->get_right()->get_data() == data && parent->get_right()->get_right() == NULL) {
            deleted_node = parent->get_right();
            deleted_node_left = deleted_node->get_left();
            parent->set_right(deleted_node_left);
            delete deleted_node;
            return;
        } 
        //deleted node is right of parent AND deleted node has single child The right child (left is NULL)
        if(parent->get_right()->get_data() == data && parent->get_right()->get_left() == NULL) {
            deleted_node = parent->get_right();
            deleted_node_right = deleted_node->get_right();
            parent->set_right(deleted_node_right);
            delete deleted_node;
            return;
        }
    }

    // if deleted node has both children
    // since deleted have a both children we don't have to check for the initial NULL condition (we checked for it above cause it is possiable to read the wrong condition first and try to get data of a NULL)
    
    // if deleted node is the right child of some node 
    if(parent->get_left() != NULL) {
        if(parent->get_left()->get_data() == data) {
            deleted_node = parent->get_left();
            deleted_node_left = deleted_node->get_left();
            deleted_node_right = deleted_node->get_right();
            // attach deleted node left in its place
            parent->set_left(deleted_node_left);
            // initial place to start right most
            right_most = deleted_node_left;
        }
    }
    // if deleted node is the left child of some node
    if(parent->get_right() != NULL) {
        if(parent->get_right()->get_data() == data) {
            deleted_node = parent->get_right();
            deleted_node_left = deleted_node->get_left();
            deleted_node_right = deleted_node->get_right();
            // attach deleted node right in its place
            parent->set_right(deleted_node_left);
            right_most = deleted_node_left;
        }
    }
    
    // go right most in deleted node
    while(right_most->get_right() != NULL) {
        right_most = right_most->get_right();
    }
    // attach right most to the left child (now)
    right_most->set_right(deleted_node->get_right());
    delete deleted_node;
    return;
}

Node* Tree::find_parent_no_Dpointer(int data) {
    // when we call find parent we know the tree contains the data so we don't care about that case
    // Now if the root has the data to delete then we return NULL (no parent)
    // the first check for the case of one brother while the second is like add or search for the node but it search for the parent
    if(this->root->get_data() == data) {
        return NULL;
    } 
    Node* temp = root;
    while(temp != NULL) {
        // we return temp when one of its children data matches the data then temp was the parent
        // Note here if temp->get_right or temp->get_left are NULL but not both (our data is a leaf with no brother) we will break the code :) (cause one will return true the other will call get data null)  
        // if our data is a a leaf with brother, the code won't break cause then its parent won't have a NULL child to call (one of the terms will be true the other false overall true)
        //if(temp->get_right()->get_data() == data || temp->get_left()->get_data() == data) {
        //    return temp;
        //}
        if(temp->get_right() != NULL) {
            if(temp->get_right()->get_data() == data) {
                return temp;
            }
        }
        if(temp->get_left() != NULL) {
            if(temp->get_left()->get_data() == data) {
                // this return the address of the parent but not the child
                return temp;
            }
        } 
        // here we advance the iterative function
        // here we don't check if temp itself is null since the loop (while(temp != NULL)) is doing it for us
        if(temp->get_data() > data) {
            temp = temp->get_left();
        } else if (temp->get_data() < data){
            temp = temp->get_right();
            // it shouldn't come to the else here cause we covered all the cases above
        } else {
            return NULL;
        }
    }
    // code won't come to here too because we know that contain will garantee that the data is in the tree
    // we have to write this so that control doesn't reach end of non-void function
    // the NULL we will return is the one above if the search parent is called for root
    // typically in place of those nulls we raise exceptions
    return NULL;
}

/*
// although we call this child it is not (it is child address)
// But just loke when passing var by reference we do int* var not int* var_address
Node* Tree::find_parent_and_child(int data, Node*** child) {
    if(root->get_data() == data) {
        return NULL;
    }
    Node* temp = root;
    while(temp != NULL) {
        if(temp->get_left() != NULL) {
            if(temp->get_left()->get_data() == data) {
                Node* address = temp->get_left();
                Node ** child2 = &address; 
                //child = temp->get_left_address();
                *child = temp->get_left_address();
                return temp;
                //0x5613a48e6ed8
            }
        }
        if(temp->get_right() != NULL) {
            if(temp->get_right()->get_data() == data) {
                //Node* address = temp->get_right();
                //child = &address;
                return temp;
            }
        }
        if(temp->get_data() > data) {
            temp = temp->get_left();
        } else if(temp->get_data() < data) {
            temp = temp->get_right();
        } else {
            return NULL;
        }
    }
    return NULL;

}

void Tree::remove_enhanced(int data) {
    Node** child ;
    Node* parent = find_parent_and_child(data, &child);
    Node** proxy = parent->get_left_address();
    int i = 0;
    //0x5613a48e6ed8
}
*/


// ready implementation (still have mistakes)

Node* Tree::find_parent_and_child(int data, Node*** deleted_node) {
    if(root->get_data() == data) {
        // if data is root then we don't have a parent and our child(deleted node) is root
        (*deleted_node) = &root;
        return NULL;
    }
    Node* temp = root;
    while(temp != NULL) {   
        if(temp->get_left() != NULL) {
            if(temp->get_left()->get_data() == data) {
                (*deleted_node) = temp->get_left_address();
                return temp;
            }
        }
        if(temp->get_right() != NULL) {
            if(temp->get_right()->get_data() == data) {
                (*deleted_node) = temp->get_right_address();
                return temp;
            }
        }
        if(temp->get_data() > data) {
            temp = temp->get_left();
        } else if(temp->get_data() < data) {
            temp = temp->get_right();
        } else {
            return NULL;
        }
    }
    return NULL;
}

void Tree::remove_enhanced(int data) {
    if(this->root == NULL || !this->contain (data)) {
        return;
    }
    // find parent and child: child is deleted node
    Node** deleted_node;
    Node* parent = find_parent_and_child(data, &deleted_node);
    Node* deleted_node_left;
    Node* deleted_node_right;
    
    deleted_node_left = (*deleted_node)->get_left();    
    deleted_node_right = (*deleted_node)->get_right();    

    if(parent == NULL) {
        // this condition appearntly is not needed 
        //if(deleted_node_left == NULL && deleted_node_right == NULL) {
        //    delete this->root;
        //    delete this;
        //    return;
        //}
        if(this->root->get_left() != NULL) {
            Node* t = this->root;
            this->root = this->root->get_left();
            Node* p = this->root;
            while(p->get_right() != NULL) {
                p = p->get_right();
            }
            p->set_right(t->get_right());
            delete t;
        } else {
            delete root;
            root = deleted_node_right;
        }
    } else {
        if(deleted_node_left != NULL) {
            delete *deleted_node;
            (*deleted_node) = deleted_node_left;
            Node* t = (*deleted_node);
            while(t->get_right() != NULL) {
                t = t->get_right();
            }
            t->set_right(deleted_node_right);
        } else {
            delete *deleted_node;
            (*deleted_node) = deleted_node_right;
        }
    }   
}

void Tree::remove_reduced(int data) {
    // if tree is empty we don't do nothing or if the data is not there
    // we should always use contain before find parent
    if(this->root == NULL || !this->contain (data)) {
        return;
    }
    Node* deleted_node;
    Node* right_most;
    Node* deleted_node_left;
    Node* deleted_node_right;
    Node* parent = find_parent_no_Dpointer(data);

    //if deleted node is root
    if(parent == NULL) {
        // no child exist
        if(root->get_left() == NULL && root->get_right() == NULL) {
            delete root; 
            // if we don't delete the tree or set the root to NULL we will have a dangling pointer which will result in the tree having values added to it from other trees
            delete this;    
        }
        // right child only for the root
        else if(root->get_right() != NULL && root->get_left() == NULL) {
            Node* old_root = root;
            root = root->get_right();
            delete old_root;
        }
        // left child only for the root or both children exist
        else {
            Node* old_root = root;
            root = root->get_left();
            // right_most starts at the left child of the deleted node (root in this case)
            Node* right_most = old_root->get_left();
            while(right_most->get_right() != NULL) {
                right_most = right_most->get_right();
            }
            right_most->set_right(old_root->get_right());
            delete old_root;
        }
        return;
    }
    // if deleted node had 1 have child
    // we check for NULL first not to read if the deleted node is not there so we don't get seg fault when trying to get data of a NULL
    if(parent->get_left() != NULL) {
        //deleted node is left of parent AND deleted node has single child The right child (left is NULL) or both children NULL
        if(parent->get_left()->get_data() == data && parent->get_left()->get_left() == NULL) {
            deleted_node = parent->get_left();
            deleted_node_right = deleted_node->get_right();
            parent->set_left(deleted_node_right);
            delete deleted_node;
            return;
        }
    }
    if(parent->get_right() != NULL) { 
        //deleted node is right of parent AND deleted node has single child The right child (left is NULL) or both children NULL
        if(parent->get_right()->get_data() == data && parent->get_right()->get_left() == NULL) {
            deleted_node = parent->get_right();
            deleted_node_right = deleted_node->get_right();
            parent->set_right(deleted_node_right);
            delete deleted_node;
            return;
        }
    }

    // if deleted node has both children or left child only
    // since deleted have a both children we don't have to check for the initial NULL condition (we checked for it above cause it is possiable to read the wrong condition first and try to get data of a NULL)
    // if deleted node is the left child of some node (whether deleted node has both children or left child only)
    if(parent->get_left() != NULL) {
        if(parent->get_left()->get_data() == data) {
            deleted_node = parent->get_left();
            deleted_node_left = deleted_node->get_left();
            deleted_node_right = deleted_node->get_right();
            // attach deleted node left in its place
            parent->set_left(deleted_node_left);
            // initial place to start right most
            right_most = deleted_node_left;
        }
    }
    // if deleted node is the right child of some node (whether deleted node has both children or left child only)
    if(parent->get_right() != NULL) {
        if(parent->get_right()->get_data() == data) {
            deleted_node = parent->get_right();
            deleted_node_left = deleted_node->get_left();
            deleted_node_right = deleted_node->get_right();
            // attach deleted node right in its place
            parent->set_right(deleted_node_left);
            right_most = deleted_node_left;
        }
    }
    
    // go right most in deleted node
    while(right_most->get_right() != NULL) {
        right_most = right_most->get_right();
    }
    // attach right most to the left child (now)
    right_most->set_right(deleted_node->get_right());
    delete deleted_node;
    return;
}
