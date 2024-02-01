#include <iostream>
#include <stdlib.h>
#include <vector>
#include "../include/pq_vector.h"

using namespace std;

void PriorityQueue::insert(int value, int priority) {
	heap.push_back(Node(value, priority));
	int idx = heap.size() -1;
	while (idx!=0){
		int parentIndex = (idx -1)/2;
		if(heap[parentIndex].priority < heap[idx].priority){
			swap(heap[parentIndex], heap[idx]);
			idx=parentIndex;
		} else{
			break;
		}
	}
	
}

PriorityQueue::Node PriorityQueue::extractMax() {
	Node maxNode = heap[0];
	heap[0] = heap.back();
	heap.pop_back();

	int index = 0;
	while(index < heap.size()){
		int leftIndex = index*2+1;
		int rightIndex = index*2+2;
		int largest = leftIndex;

		if(rightIndex < heap.size() && heap[rightIndex].priority > heap[leftIndex].priority){
			largest = rightIndex;
		}
		if(largest < heap.size() && heap[largest].priority > heap[index].priority){
			swap(heap[largest], heap[index]);
			index = largest;
		}else{
			break;
		}

	}
	return maxNode;
}