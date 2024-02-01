#include<stack>
#include<queue>
#include<iostream>
#include<deque>
#include<vector>

using namespace std;

void stack_example() {
    stack<int> s;
    
    for(int i = 0; i < 15; i++) {
        s.push(i);
    }
    for(int i = 0; i < 15; i++) {
        if(!s.empty()) {
            cout << s.top() << " "; 
            s.pop();
        }
    }
    cout << endl;
}
void queue_example() {
    queue<int> q;
    for(int i = 0; i < 15; i++) {
        q.push(i);
        q.push(i*2);
        cout<< q.back() << " ";
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}
void deque_example() {
    deque<int> dq;
    // the front starts from the left of the queue (imaginary)
    // the back starts from the right of the queue (imaginary)
    dq.push_front(1);
    dq.push_front(2);
    dq.push_back(-1);
    dq.push_back(-2);

    // auto takes a container(dq) and calculates the number of elements inside that container
    // it puts those elements inside the variable i 
    // this same move surperisingly doesn't work with stacks and normal queues
    for(auto i: dq) {
        cout << i << " ";
    }
    cout << endl;
    /* alternative
    for (int i: dq){
        cout << i << " ";
    }
    */
    // imagine this operation as poping the first element on the right
    dq.pop_back();
    for(auto i: dq) {
        cout << i << " ";
    }
    cout << endl;
    // imagine this operation as poping the first element on the left
    dq.pop_front();
    for(auto i: dq) {
        cout << i << " ";
    }
}
void vector_example() {
    vector<int> v;

    for(int i = 0; i < 15; i++) {
        // because we can push back and pop back only we are using the vector in a way like a stack but not as a quee
        v.push_back(i);
    }
    v.pop_back();
    for(int i: v){
        cout << i << " ";
    }
    /* alternative
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }
    */
    // we can also use iterators with vectors
    // iterator is a generic structure to iterate over collection
    cout << endl;
    vector<int>::iterator it;
    // the iterator doesn't give you the element directly it gives you a pointer to those elements
    for(it = v.begin(); it != v.end(); it++) {
        // the derefence is key
        cout<< *it << " ";
    }
    cout << endl;

    // another way
    vector<int>::reverse_iterator rit;

    for(rit = v.rbegin(); rit != v.rend(); rit++) {
        cout<< *rit << " ";
    }
    cout << endl;


}


int main(void) {
    
    
    // examples
    //stack_example();
    //queue_example();
    //deque_example();   
    vector_example();



    return 0;
}