#include "../include/Circular_LL.hpp"
#include <iostream>

using namespace std;

Circular_LL::Circular_LL() {
    // value is not important as we will never access it
    // head is sentinal and the tail is pointing to the head which is useless
    head = new Node(-1, true);
    // i think tail = head is wrong
    // we need 2 sentinels even from the begining to add in between always
    tail = new Node(-1, true);
}

// iterative distructor
Circular_LL::~Circular_LL() {
    // in destruction we should delete sentinel
    Node* p = head;
    Node* n = head;
    // for tail its next is NULL because from our node definition next and prev by default are null
    // so yes this function will stop when n reaches tail->next == null
    // this will delete all the 
    while(n != NULL) {
        n = p->get_next();
        delete p;
        p = n;
    }
}
// iterative clear
void Circular_LL::clear_list() {
    Node* p = head->get_next();
    Node* n = head->get_next();
    while(p != tail) {
        n = p->get_next();
        delete p;
        p = n;
    }
    // the head is the sentinel so its next link is connected to the first node so we have to set that to NULL to sever the link
    // the prev link from the head next node is severed by the delete p operation
    head->set_next(tail);
    tail->set_prev(head);
}

Node* Circular_LL::search_prev(int data) {
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

Node* Circular_LL::search_prev_tolga(int data) {
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

void Circular_LL::add_node(int data) {
    Node* new_node = new Node(data, false);
    
    if(head == NULL) {
        head = new_node;
        tail = new_node;
    } else {
        // we still need to search for the prev of the added node although we are in D_LL. Reason being is that we have have the value of the added node node some node that is already in the list and we need to find the node before the one we need to add in the SORTED LL
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

void Circular_LL::print_Circular_LL() {
    Node* p = head;
    // tolga used while(head != tail) 
    while (p != NULL) {
        cout << p->get_data() << " ";
        p = p->get_next();
    }
    if(p != NULL) 
        cout << p->get_data() << endl;
}

void Circular_LL::print_reverse_Circular_LL() {
    Node* p = tail;
    // tolga used while(tail != head) 
    while(p != NULL) {
        cout << p->get_data() << " ";
        p = p->get_prev();
    }
    if(p != NULL) 
        cout << p->get_data() << endl;
}

void Circular_LL::remove_node(int data) {
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
    }

}

Node* Circular_LL::contains(int data) {
    Node *p = head;
    while(p != NULL && p->get_data() != data) {
        p = p->get_next();
    } 
    return p;
    
}
