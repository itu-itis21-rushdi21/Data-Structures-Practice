#include<iostream>
#include"../include/pq_heap_array.h"

using namespace std;

int main() {
    PriorityQueue p(4);

    p.enqueue(3);
    p.enqueue(4);
    p.enqueue(2);
    p.enqueue(5);
    for(int i = 0; i < p.capacity; i++) {
        cout << p.heapArray[i] << " ";
    }
    cout << endl;
    p.heapSort();
    for(int i = 0; i < p.capacity; i++) {
        cout << p.heapArray[i] << " ";
    }
    cout << endl;    

    int arr[6] = {3, 4, 2, 5, 1 , 7};
    makeHeap(arr, 6);

    for(int i = 0; i < 6; i++) {
        cout << arr[i] << " ";
    }
    cout<<endl;

    int arr2[6] = {3, 4, 2, 5, 1 , 7};
    makeHeap_build(arr2, 6);

    for(int i = 0; i < 6; i++) {
        cout << arr[i] << " ";
    }
    cout<<endl;
    

    PriorityQueue p2(6);
    p2.enqueue(7);
    p2.enqueue(2);
    p2.enqueue(5);
    p2.enqueue(1);
    p2.enqueue(0);
    p2.enqueue(4);
    for(int i = 0; i < p2.capacity; i++) {
        cout << p2.heapArray[i] << " ";
    }
    cout << endl;

    p2.remove_middle(1);
    for(int i = 0; i < p2.capacity; i++) {
        cout << p2.heapArray[i] << " ";
    }

    return 0;

}