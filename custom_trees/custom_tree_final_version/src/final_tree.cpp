#include"../include/Node.hpp"
#include"../include/final_tree.hpp"
#include<iostream>
#include<queue>
#include<stack>

using namespace std;

final_tree::final_tree() {
    this->root = NULL;
}

final_tree::~final_tree() {
    queue<Node*> q;
    Node* temp;
    if(this->root != NULL)
        q.push(this->root);
    while(!q.empty()) {
        temp = q.front();
        q.pop();
        if(temp->get_left() != NULL)
            q.push(temp->get_left()); 
        if(temp->get_right() != NULL)
            q.push(temp->get_right());
        delete temp;
    }
}

Node* final_tree::get_root() {
    return root;
}

void final_tree::set_root(Node* root) {
    this->root = root;
}

void final_tree::insert(int data) {
    Node* new_node = new Node(data);
    Node* temp = root;
    /* this will work most certianly
    if(temp == NULL) {
        root = new_node;
        return;
    }
    while(true) {
        if(temp->get_data() > data) {
            temp = temp->get_left();
        } else if(temp->get_data() < data) {
            temp = temp->get_right();
        } else {
            cout << "value is dublciate" << endl;
            delete new_node;
            return;
        }
        if(temp == NULL) {
            temp = new_node;
            return
        }
    }
    cout << "value is dublciate" << endl;
    delete new_node;
    */
   // this is so that we don't get the data of a NULL
   if(temp == NULL) {
        root = new_node;
        return;
    }
    while(true) {
        if(temp->get_data() > data) {
            if(temp->get_left() == NULL){
                temp->set_left(new_node);
                return;
            }
            temp = temp->get_left();
        } else if(temp->get_data() < data) {
            if(temp->get_right() == NULL){
                temp->set_right(new_node);
                return;
            }
            temp = temp->get_right();
        } else {
            // if we reach here means the value is dublicate
            cout << "value is dublciate" << endl;
            delete new_node;
            return;
        }
    }
}

Node* final_tree::search(int data) {
    Node* temp = this->root;
    if(root == NULL) {
        cout << "tree is empty" << endl;
        return NULL;
    }
    
    while(true) {
        // will never be null on first iteration cause of the above if
        if(temp->get_data() > data) {
            temp = temp->get_left();
        } else if (temp->get_data() < data) {
            temp = temp->get_right();
            // it is important that this is after those 2 conditons cause ex if temp left is NULL and temp > data we will get data if a NULL on the last else if 
            // here we print the massage from the function
        } else if(temp == NULL){
            cout << "value to search is not in the tree" << endl;
            return NULL;
            // not need to else if else alone is enough
        } else {
            return temp;
        }
    }
    /*
    while(true) {
        if(temp->get_data() > data) {
            temp = temp->get_left();
        } else if (temp->get_data() < data) {
            temp = temp->get_right();
        } else {
            // this here returns a silent NULL. it can either return the value or NULL without us knowing the warning we have to check it in main
            return temp;
        }
    }
    // we can never reach this cause when temp = NULL the above else will return it
    return NULL;
    */
}

void final_tree::remove_advanced(int data) {
    if(root == NULL) {
        cout<< "tree is empty" << endl;
        return;
    }

    Node* parent = NULL;
    Node* current = root;
    // we will quit if current = NULL basically if the data is not in the tree
    // or if current->get_data() != data basically if we found the data aka current = deleted node
    // the root == NULL if above protect us from calling NULL->get_data() in the while condition 
    // Note we will quit cause of one of them not both of them or else we would have got in the case of both being true seg fault
    while(current != NULL && current->get_data() != data) {
        // we can take the && condition of while to here
        //if(current->get_data() == data) {
        //    break;
        //}
        parent = current;
        if(current->get_data() > data) {
            current = current->get_left();
        } else if(current->get_data() < data) {
            current = current->get_right();
        } 
    }
    if(current == NULL) {
        cout << "value to deleted is not in the tree" << endl;
        return;
    }
    
    Node* current_left = current->get_left();
    Node* current_right = current->get_right();
    // this here is because root is not the left or right child of a node
    // we can't do parent->get_left() or parent->get_right()
    if(parent == NULL) {
        if(current_left != NULL) {
            delete current;
            root = current_left;
            Node* right_most = current_left;
            while(right_most->get_right() != NULL) {
                right_most = right_most->get_right();
            }
            right_most->set_right(current_right);
        } else {
            delete current;
            root = current_right;
        }
        return;
    }

    bool is_left = false;
    if(current == parent->get_left()) {
        is_left = true;
    }

    if(current_left != NULL) {
        if(is_left) {
            parent->set_left(current_left);
        } else {
            parent->set_right(current_left);
        }
        Node* right_most = current_left;
        while(right_most->get_right() != NULL) {
            right_most = right_most->get_right();
        }
        right_most->set_right(current_right);
        delete current;
    } else {
        if(is_left) {
            parent->set_left(current_right);
        } else {
            parent->set_right(current_right);
        }
        delete current;
    }
}

void final_tree::remove_inorder_successor(int data) {
    if(root == NULL) {
        cout << "tree is empty" << endl;
        return;
    }
    Node* parent = NULL;
    Node* current = root;

    while(current != NULL && current->get_data() != data) {
        parent = current;
        if(current->get_data() > data) {
            current = current->get_left();
        } else if(current->get_data() < data) {
            current = current->get_right();
        }
    }
    if(current == NULL)  {
        cout << "value is not in the tree" << endl;
        return;
    }
    if(current->get_left() == NULL || current->get_right() == NULL) {
        
        Node* newCurr;
        // if deleted node has 1 child, determine which child 
        // if no children then newCurr will be NULL
        if(current->get_right() != NULL) {
            newCurr = current->get_right();
        } else {
            newCurr = current->get_left();
        }
        // if deleted node is root
        // we either attach the root to newCurr (newCurr will be NULL if we have no children)
        if(parent == NULL) { 
            delete current;
            root = newCurr;
            return;
        }
        // here we attach to left or right of the parent of deleted node based on whether the deleted node current was left or right of the its parent
        // (del node is not root cause root parent is NULL which has no left or right) 
        // if current is leaf then we will attach a NULL new current which is correct
        if(current == parent->get_right()) {
            parent->set_right(newCurr);
        } else {
            parent->set_left(newCurr);
        }
        delete current;
    } else {
        Node* successorParent = current;
        Node* successor = current->get_right();
        while(successor->get_left() != NULL) {
            successorParent = successor;
            successor = successor->get_left();
        }
        current->set_data(successor->get_data());

        // note successors can never have left children
        // successors are left of their parent except when their parent in the deleted nodes
        // if the successor don't have right children (a leaf)
        
        if(successorParent == current) {
            successorParent->set_right(successor->get_right());
        } else {
            successorParent->set_left(successor->get_right());
        }
        delete successor;
    }
}

int final_tree::get_height() {
    if(root == NULL) {
        return -1;
    }
    queue<Node*> q;
    q.push(root);
    int height = 0;
    while(!q.empty()) {
        int size = q.size();
        for(int i = 0; i < size; i++) {
            Node* temp = q.front();
            q.pop();
            if(temp->get_left() != NULL) {
                q.push(temp->get_left());
            }
            if(temp->get_right() != NULL) {
                q.push(temp->get_right());
            }
        }
        height++;
    }     
    return height;
}

void final_tree::print_preorder_recursive(Node* n) {
    if(n != NULL) {
        cout << n->get_data() << " ";
        print_preorder_recursive(n->get_left());
        print_preorder_recursive(n->get_right());
    }
    return;
}

void final_tree::print_inorder_recursive(Node* n) {
    if(n != NULL) {
        print_inorder_recursive(n->get_left());
        cout << n->get_data() << " ";
        print_inorder_recursive(n->get_right());
    }
    return;
}

void final_tree::print_postorder_recursive(Node*n) {
    if(n != NULL) {
        print_postorder_recursive(n->get_left());
        print_postorder_recursive(n->get_right());
        cout << n->get_data() << " ";
    }
    return;
}

void final_tree::print_inorder_recursive() {
    print_inorder_recursive(this->root);
    cout << endl;
}

void final_tree::print_preorder_recursive() {
    print_preorder_recursive(this->root);
    cout<< endl;
}

void final_tree::print_postorder_recursive() {
    print_postorder_recursive(this->root);
    cout<< endl;
}

void final_tree::print_BFS() {
    if(root == NULL) {
        return;
    }
    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();
        cout << temp->get_data();
        if(temp->get_left() != NULL) {
            q.push(temp->get_left());
        }
        if(temp->get_right() != NULL) {
            q.push(temp->get_right());
        }
    }
    cout << endl;
}
// similar to BFS just using stack and pushing right then left instead of left right
void final_tree::print_preorder(){
    if(root == NULL) {
        return;
    }
    stack<Node*> s;
    s.push(this->root);
    while(!s.empty()) {
        Node* temp = s.top(); 
        s.pop();
        cout << temp->get_data() << " ";

        if(temp->get_right() != NULL) {
            s.push(temp->get_right());
        }
        if(temp->get_left() != NULL) {
            s.push(temp->get_left());
        }
    }
}

/*The combination temp != NULL || !s.empty() therefore means
 "continue traversing if there are still nodes to be visited directly (temp != NULL)
  or if there are nodes to backtrack to in order to visit their right subtrees (!s.empty())."
*/
void final_tree::print_inorder(){
    //It checks two conditions: 
    //whether temp is not NULL (indicating that there are more nodes to go down to) and
    // whether the stack is not empty (indicating that there are nodes that have been visited but their right subtrees have not been explored yet)
    if(root == NULL) {
        return;
    }
    stack<Node*> s;
    Node* temp = root;
    while(temp != NULL || !s.empty()) {
        while(temp != NULL) {
            s.push(temp);
            temp = temp->get_left();    
        }
        temp = s.top();
        s.pop();
        cout<< temp->get_data() << " ";

        temp = temp->get_right();
    }
}
// 2 stacks stack 2 does the job of traversing stack one is more of a temp stack
void final_tree::print_postorder(){
    if(root = NULL) {
        return;
    }
    
    stack<Node*> s1;
    stack<Node*> s2;
    s1.push(root);

    while(!s1.empty()) {
        Node* temp = s1.top();
        s1.pop();
        s2.push(temp);
        // s1 is trraversing preorder reversed meaning it is root right left not left right and at the end instead of printing when we pop we push to s2
        // now preorder reversed when read from the opposite direction (s2) becomes postorder which make sense rev-preorder root right left postorder left right root
        if(temp->get_left() != NULL) {
            s1.push(temp->get_left());
        }
        if(temp->get_right() != NULL) {
            s1.push(temp->get_right());
        }
    }
    while(!s2.empty()) {
        Node* temp = s2.top();
        s2.pop();
        cout << temp->get_data() << endl;
    }
}




