#include "../include/Double_LL.hpp"
#include <iostream>

using namespace std;

Double_LL::Double_LL() {
    head = NULL;
    tail = NULL;
}

Double_LL::~Double_LL() {
    if(head != NULL) 
        delete head;  
}

void Double_LL::clear_list() {
    if(head != NULL)
        delete head;
    head = NULL;
    tail = NULL;  
}
Node* Double_LL::search(int data) {
    Node* p = head;

    if(data <= head->get_data()) {
        return NULL;
    } else {
        while(p->get_next()) {
            if(p->get_next()->get_data() >= data)
                return p;
            p = p->get_next();
        }
        return p;
    }
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
        Node* prev = search_prev(data);
        if(prev == NULL) {
            new_node->set_next(head);
            head = new_node;
        } else if (prev == tail){
            tail->set_next(new_node);
            tail = new_node;
        } else {
            new_node->set_next(prev->get_next());
            prev->set_next(new_node);
        }
    }
}

void Double_LL::print_LinkedList() {
    if(head == NULL) {
        return;
    }
    Node* p = head;
    while (p != NULL) {
        cout << p->get_data() << " ";
        p = p->get_next();
    }
    if(p != NULL) 
        cout << p->get_data() << endl;
}

void Double_LL::remove_node(int data) {
    if(head == NULL) {
        cout<< "ERROR: empty LL" << endl;
        return;
    }
    Node* prev = this->search_prev_tolga(data);
    
    if(data > tail->get_data() || data < head->get_data()) {
        cout << "No node with this value" << endl;
        return;
    }
    if(head == tail && head != NULL && tail != NULL ) {
        delete head;
        head = NULL;
        tail = NULL;
    } else {
        if(prev == NULL) {
            Node* old_head = head;
            head = head->get_next();
            old_head->set_next(NULL);
            delete old_head;
        } else if (prev->get_next() == tail){
            tail = prev;
            delete tail->get_next();
            tail->set_next(NULL);
        } else {
            Node* deleted_node = prev->get_next();
            prev->set_next(prev->get_next()->get_next());
            
            deleted_node->set_next(NULL);
            delete deleted_node;
        }   
    }  
}

bool Double_LL::contains(int data) {
    Node *p = head;
    while(p != NULL && p->get_data() != data) {
        p = p->get_next();
    } 
    if(p == NULL) {
        return false;
    } else {
        return true;
    }
}
