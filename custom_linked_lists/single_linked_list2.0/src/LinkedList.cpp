
#include "../include/LinkedList.h"
#include <iostream>

using namespace std;

// here in our constructor is where we initialize the head and the tail to NULL
LinkedList::LinkedList() {
    head = NULL;
    tail = NULL;
}
// Great Note: This destructor will only be relevant when our linkedList is a pointer itself
LinkedList::~LinkedList() {
    // here we will do implicit traversion
    // this garantee that we don't even call delete on an empty LL
    if(head != NULL) 
        delete head;  
}
// clear deletes but also reinitialize (after calling it we will have an empty LL). Note:there is no size (0)
void LinkedList::clear() {
    // here we will do implicit traversion
    // this garantee that we don't even call delete on an empty LL
    if(head != NULL)
        delete head;
    head = NULL;
    tail = NULL;  
}
Node* LinkedList::search_prev(int data) {
    // traversing the LL
    // we always need a temp when traversing cause of 
    Node* p = head;
    // this exception right here handles the case of searching a list that is empty
    // problem is that when searching if we call p->get_data() we are trying to access NULL data which is a seg fault
    // Note too that if(p->get_next() == NULL) doesn't solve the problem cause we can't get next of a NULL to begin with
    // and head is NULL if list is empty
    // we can't get_next nor get_data of a NULL Node
    if(p == NULL){
        return NULL;
    } 
    

    // this will handle the cause where the searched data in smaller than all the elements in the LL
    // so we return NULL caues there is no prev to head(just like tail next is NULL, head prev is NULL)
    if(data <= p->get_data()) {
        return NULL;
    } else {
        // this will avoid calling p->get_next->get_data (which will call get data on NULL) when the value is to be added to the end
        // this is because tail->get_next is NULL  
        if(data > tail->get_data()) {
            return tail;
        }
        // here we do the search
        // this logic works cause i want to return the prev node not the node that is larger
        while(data > p->get_next()->get_data()) {
            // what happens if we do p->set_next(p) BS :) we will have a pointer pointing to itself
            // what will happen is When you change p = p->get_next(); to p->set_next(p);, you are setting the next pointer of the current node to itself. This means that when you try to get the next node, you will get the same node again. This will cause the program to infinitely loop.
            p = p->get_next();
        }
        return p;
    }
}
Node* LinkedList::search_prev_tolga(int data) {
    // traversing the LL
    Node* p = head;
    // this exception right here handles the case of searching a list that is empty
    // problem is that when searching if we call p->get_data() we are trying to access NULL data which is a seg fault
    // Note too that if(p->get_next() == NULL) doesn't solve the problem cause we can't get next of a NULL to begin with
    // and head is NULL if list is empty
    // we can't get_next nor get_data of a NULL Node
    // not the if we don't use it on empty lists then no need for this condition
    if(p == NULL){
        return NULL;
    }
    
    // this will handle the cause where the searched data in smaller than all the elements in the LL
    // so we return NULL caues there is no prev to head(just like tail next is NULL, head prev is NULL)
    // we can here use head->get_data because we are not modifying
    // BIG NOTE: head has data which is the first node head->get_next is the location of the second node and head->get_next->get_data is the data of the next node
    // this assure that head has data cause else how can we access the first node data
    if(data <= head->get_data()) {
        return NULL;
    } else {
        // here we do the search
        // this logic works cause i want to return the prev node not the node that is larger
        while(p->get_next()) {
            // what happens if we do p->set_next(p) BS :) we will have a pointer pointing to itself
            if(p->get_next()->get_data() >= data) {
                return p;
            }
            p = p->get_next();
        }
        // this return is to return the tail if the data is larger than all elements in the list
        return p;
    }
}
// this is ordered addition and with begining mid and end
void LinkedList::add_node(int data) {
    Node* new_node = new Node(data);
    
    // adding to empty LL case
    if(head == NULL) {
        // or head = n
        // assinging node to another assings the pointer and the vaule
        // head has get_data and set data but we will never use them
        // cause head (theoratically) is only a node with next member varaible and no data member varaiable
        // the following is wrong explained in the tab
        // head->set_next(n);
        // we set both to n cause when both are NULL this means the list is empty so the first node will have both
        // the head an the tail pointing at it
        head = new_node;
        tail = new_node;
    } else {
        // tolga search don't work if list is empty so we only searched after checking that the list is not empty (above)
        Node* prev = search_prev(data);
        // adding the node at the begining case
        if(prev == NULL) {
            // this will first set new_node next to the old head node(now 2nd node) and then set the head to point to new node (now first node (head node))
            // we didn't change the tail cause adding to begining doesn't have anything to do with the tail 
            new_node->set_next(head);
            head = new_node;
        // this case is adding to the end
        // we know it is the end when prev node is same as tail :)    
        } else if (prev == tail){
            tail->set_next(new_node);
            tail = new_node;
        // we know we are adding to the middle by elemintation if we are not adding empty or begin or end then we add mid
        // this is better as checking for the other 3 cases is easier     
        } else {
            new_node->set_next(prev->get_next());
            prev->set_next(new_node);
        }
        
    }
    // we can't delete new node here
    // the deletion is left for later (when we want to delete the node) cause if we delete new node we will be deleting the node we added 
    // what happens to the pointer new_node (i think it is deleted from the memory when we exit the function)
    //delete [] new_node;
}   

void LinkedList::print_LinkedList() {
    if(head == NULL) {
        return;
    }
    Node* p = head;
    while (p->get_next()) {
        cout << p->get_data() << " ";
        p = p->get_next();
    }
    if(p != NULL) 
        cout << p->get_data() << endl;
}

void LinkedList::remove_node(int data) {
    //we start by searching for the previous
    // Note this search can even search prev when list is empty no problem
    
    if(head == NULL) {
        cout<< "ERROR: empty LL" << endl;
        return;
    }
    Node* prev = this->search_prev_tolga(data);
    
    if(data > tail->get_data() || data < head->get_data()) {
        cout << "No node with this value" << endl;
        return;
    }
    // single node case
    if(head == tail && head != NULL && tail != NULL ) {
        delete head;
        head = NULL;
        tail = NULL;
    } else {
        // this is delete head case (more than one node in the list)

        if(prev == NULL) {
            // we store the old head cause we need a reference to it when we delete it. Moving the head one forward
            // in the next line will remove any reference to the old head and we can't set its next to NULL/delete it
            // first cause then we will lose our reference to the rest of the list (we can then do head = head->get_next() cause we already set that next to NULL) 
            Node* old_head = head;
            // this get next is safe cause we know that the head will have a next that is not NULL cause we handled
            // the case of 1 Node before
            head = head->get_next();
            // this stops the chain
            old_head->set_next(NULL);
            delete old_head;
            // this is another way of understanding that the element to be deleted is the tail element(what conditions are for)
            // while still having the ability to use the prev node to tail next's in the operation to come 
            //now this is different than when adding
            // because we want the node before next to become NULL (cutting tail node from the LL)
            // we want the prev point to point to the Node prev to tail to use its next pointer
            // prev->get_next == tail means that the tail is the next node thus prev is the one before
            // in adding we wanted tail == prev cause we add after tail using prev (tail) next to link our new node
            // here we will use the node before the last next so we did this
            // excellent tactic when you don't have prev pointers you can go many nodes back by calling prev->get_next->get_next .... == condition
            // also can do that to go multi node forward node* p = p->get_next->get_next ...
            // instead of checking if the returning node is the tail we check if the returning node is one before the tail
        } else if (prev->get_next() == tail){
            // tolga has different approach but i think it is the same
            // deleting tail doesn't garantee that the next of the prev is null
            prev->set_next(NULL);
            // note this deletes what tail points to not tail pointer itself the pointer life expires 
            // with the object(here) or the scope(other cases) evidence on this can be seen in first case head==tail
            delete tail;
            tail = prev;
            //here this the case if the element is not in the list
            // remember prev points to the element before the node to be deleted based on Node* prev = this->search_prev(data);
            // so if prev is tail this means that the node to be deleted is NULL (no node)
            // this is deleting from the middle (again by elemination we reach that this is the only remaining case of delete)
        } else {
            // prev will be the node before the node we want to delete
            // we saved the deleted node cause we want to asign its next to NULL we did this cause we have a dilema
            // just like in delete head case if first we set deleted node(prev->get_next) nexts to NULL (prev->get_next->set_next)
            // we will lose the reference to the node after the node we are deleting cause it is set to NULL thus
            // prev->set_next(prev->get_next()->get_next()); will be sat to NULL
            // and if we do it after setting prev next to prev next next without saving we can't neither delete the node nor 
            // assign its next to NULL 
            Node* deleted_node = prev->get_next();
            // we set prev next to one node ahead
            prev->set_next(prev->get_next()->get_next()); // or we could have used deleted_node->get_next
            
            deleted_node->set_next(NULL);
            delete deleted_node;
        }
        
    }  
}
  
bool LinkedList::contains(int data) {
    //if NULL we have empty LL
    //if(head != NULL) {
    // we don't need this condition cause the loop will accout for it at the first iteration
    Node *p = head;
    while(p != NULL && p->get_data() != data) {
        p = p->get_next();
    } 
    // if we fall out of while cause p is NULL this means that we couldn't find the data (didn't fall out cause of p != data)
    if(p == NULL) {
        return false;
    } else {
        return true;
    }
    //}   
    //return false;
}
