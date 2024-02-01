#include "../include/Double_LL.hpp"
#include <iostream>

using namespace std;

Double_LL::Double_LL() {
    head = NULL;
    tail = NULL;
}

// iterative distructor
Double_LL::~Double_LL() {
    Node* p = head;
    Node* n = head;
    // Why do we make n = head or tail 
    // if the list is empty and we enter the loop then p->get_next will try to get the next of a NULL pointer --> seg fault
    // but when we equate it to head or tail, if list is empty, head/tail will be NULL thus n will be equal NULL
    // so we won't enter the loop tp begin with
    // aalternative if(head == NULL) {return;}
    while(n != NULL) {
        n = p->get_next();
        delete p;
        p = n;
    }
}
// iterative clear
void Double_LL::clear_list() {
    Node* p = head;
    Node* n = head;
    while(n != NULL) {
        n = p->get_next();
        delete p;
        p = n;
    }
    head = NULL;
    tail = NULL;
}

Node* Double_LL::search_prev(int data) {
    Node* p = head;
    if(p == NULL){
        return NULL;
    } 

    if(data <= p->get_data()) {
        return NULL;
    } else {
        if(data > tail->get_data()) {
            return tail;
        }
        while(data > p->get_next()->get_data()) {
            p = p->get_next();
        }
        return p;
    }
}

Node* Double_LL::search_prev_tolga(int data) {
    Node* p = head;
    if(p == NULL){
        return NULL;
    }

    if(data <= head->get_data()) {
        return NULL;
    } else {
        while(p->get_next()) {
            if(p->get_next()->get_data() >= data) {
                return p;
            }
            p = p->get_next();
        }
        return p;
    }
}

void Double_LL::add_node(int data) {
    Node* new_node = new Node(data);
    
    if(head == NULL) {
        head = new_node;
        tail = new_node;
    } else {
        // we still need to search for the prev of the added node although we are in D_LL. Reason being is that we have the value of the added node NOT some node that is already in the list and we need to find the node before the one we need to add in the SORTED LL.
        Node* prev = search_prev(data);
        // we can use thsi optional 
        // old_next = prev->get_next();
        // we don't want old_prev cause we searched for prev already :)
        if(prev == NULL) {
            // the order of the first 2 doens't matter
            new_node->set_next(head);
            head->set_prev(new_node); // or new_node->get_next()->set_prev(new_node)
            head = new_node;
        } else if(prev == tail) {
            tail->set_next(new_node);
            new_node->set_prev(tail);
            tail = new_node;
        } else {
            
            new_node->set_next(prev->get_next());
            new_node->set_prev(prev);
            // the order of these two operations matter here
            // if we have used old_next it won't matter
            prev->get_next()->set_prev(new_node);
            prev->set_next(new_node);
            // alternative solution but shity
            //prev->set_next(new_node);
            //new_node->get_next()->set_prev(new_node);
        }

    }
}

void Double_LL::print_Double_LL() {
    Node* p = head;
    // tolga used while(head != tail) 
    while (p != NULL) {
        cout << p->get_data() << " ";
        p = p->get_next();
    }
    if(p != NULL) 
        cout << p->get_data() << endl;
}

void Double_LL::print_reverse_Double_LL() {
    Node* p = tail;
    // tolga used while(tail != head) 
    while(p != NULL) {
        cout << p->get_data() << " ";
        p = p->get_prev();
    }
    if(p != NULL) 
        cout << p->get_data() << endl;
}

void Double_LL::remove_node(int data) {
    // here we search for the node itself not its prev
    Node* removed_node = contains(data);

    if(removed_node == NULL) {
        cout<< "element_not_found or Empty LL" << endl;
        return;
    }  
    // we get the prev just not to call it over and over again
    Node* prev = removed_node->get_prev();
    // if only 1 node
    if(head == tail) {
        delete head;
        head = NULL;
        tail == NULL;
    } else {
        // delete from the begin
        // we could say prev == NULL
        if(removed_node == head) {
            Node* old_head = head;
            head = head->get_next();
            delete old_head;
            head->set_prev(NULL);
        // delete from the end
        // we could say prev->get_next() == tail
        } else if(removed_node == tail) {
            Node* old_tail = tail;
            tail = tail->get_prev();
            delete old_tail;
            tail->set_next(NULL);
            //alternative
            /*
            tail = prev; // another way to say tail = tail->get_prev();
            delete removed_node; // this avoids the need for old tail since we know the old_tail is the removed node :)
            tail->set_next(NULL);
            */
        } else {
            // order of first 2 is irrelevant
            prev->set_next(removed_node->get_next());
            removed_node->get_next()->set_prev(prev);
            delete removed_node;
            /* alternative
            use Node* next = removed_node()->get_next();
            */
        }
        // we can delete removed_node; // cause we will do it in all these cases (old_head/old_tail == removed_node so we take those out)
    }

}

Node* Double_LL::contains(int data) {
    Node *p = head;
    while(p != NULL && p->get_data() != data) {
        p = p->get_next();
    } 
    return p;
    
}
