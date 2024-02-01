#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include"../include/coordinate.hpp"
using namespace std;

void heap_stl();
void priority_queues();
void comparator_examples();

int main(int argc, char* argv[]) {

    heap_stl();
    priority_queues();
    comparator_examples();

    return 0;
}

void heap_stl() {
    vector<int> v1 = {12, 35, 21, 10, 11, 8, 22, 23, 20};

    // this orders the items in the vector in a heap fashion
    // this is a max heap
    make_heap(v1.begin(), v1.end());
    // we push back 45 first
    v1.push_back(45);
    // then we heapify
    push_heap(v1.begin(), v1.end());

    for(int i: v1) {
        cout << i << " ";
    }
    cout << endl;
    // this pops the root of the heap but only swaps it to the end of the vector so it is in the vector but it is not in the heap logically
    pop_heap(v1.begin(), v1.end());
    for(int i: v1) {
        cout << i << " ";
    }
    cout << endl;
    // to get rid of the root physically we have to pop it from the vector too
    v1.pop_back();
    for(int i: v1) {
        cout << i << " ";
    }
    cout << endl;
    // this of uses iterators
    // this is not a heap anymore but it is sorted using heap sort
    sort_heap(v1.begin(), v1.end());
    
    for(int i: v1) {
        cout << i << " ";
    }
    cout << endl;

    // to check if the container is a heap
    if(is_heap(v1.begin(), v1.end()))
        cout << "This is a heap\n";
    // again greater ">" gives min heap
    make_heap(v1.begin(), v1.end(), greater<>{});
    for(int i: v1) {
        cout << i << " ";
    }
    // this is cause min heap is used to order from largest to smallest by poping the root which is what > does to the array as well
    
    cout << endl;
    // less "<" makes max heap / less is the default 
    make_heap(v1.begin(), v1.end());
    for(int i: v1) {
        cout << i << " ";
    }
    cout << endl;
    // this is cause max heap is used to order from smallest to largest by poping the root

}

void priority_queues() {
    //priority_queue<int> q;
    // we can do even one better
    // we defined the container data type and the compartion operation

    priority_queue<int, vector<int>, greater<int>> q;
    q.push(30);
    q.push(20);
    q.push(40);
    q.push(10);
    q.push(400);
    while(!q.empty()) {
        cout << q.top() << " ";
        q.pop();
    }
    cout << endl;


}

void comparator_examples() {
    

    vector<Cordinate> v;
    // we can the constructor in the vector push back like calling new Node() 
    // no need for temp variables 
    v.push_back(Cordinate(3,5));
    v.push_back(Cordinate(4,8));
    v.push_back(Cordinate(6,2));

    for(auto c : v) {
        c.print();
    }
    cout << endl;

    // 
    for(auto c : v) {
        // we can call the function CordinateComparator()(c,Cordinate(6,2)); as we can't pass something to a fucntion that has reference parameter without it being a variable
        Cordinate temp = Cordinate(6,2);
        if(CordinateComparator()(c,temp)){
            c.print();
        }
        // another way to make the call, we alias the CordinateComparator into a variable
        CordinateComparator cc;
        if(cc(c,temp)){
            c.print();
        }
    }
    cout << endl;

    CordinateComparator3 cc3;
    CordinateComparator2 cc2;
    sort(v.begin(), v.end(), cc2);
    for(auto c : v)
        c.print();
    cout << endl;

    v.push_back(Cordinate(4,4));
    v.push_back(Cordinate(1,1));
    v.push_back(Cordinate(7,0));
    // greater ">" than gives a min heap. (heaps are in an opposite order)
    // you can make a heap out of any object as long as you define the compartion operator 
    make_heap(v.begin(), v.end() , cc2); 
    for(auto c : v)
        c.print();
    cout << endl; 

    // smaller "<" than gives a max heap
    make_heap(v.begin(), v.end() , cc3);
    for(auto c : v)
        c.print();
    cout << endl; 
    // this is how we do sorting using lamda function
    sort(v.begin(), v.end(), [] (Cordinate& c1, Cordinate& c2)->bool {
        return (c1.get_xCor() < c2.get_xCor());
    });
    // this will make a max heap based on the length of the points if they were vector heads
    make_heap(v.begin(), v.end(), [] (Cordinate& c1, Cordinate& c2)->bool {
        return (c1.length() < c2.length());
    });

}