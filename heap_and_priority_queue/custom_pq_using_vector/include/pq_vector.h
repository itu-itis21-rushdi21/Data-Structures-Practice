#pragma once
#include <vector>
using namespace std;
class PriorityQueue {
public:
	struct Node {
		int value;
		int priority;
		Node(int value, int priority) : value(value), priority(priority) {}
	};
	vector<Node> heap;
	void insert(int , int );
	Node extractMax();
};