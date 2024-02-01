#include <iostream>
#include "MyQueue.h"
#include <stack>
#include <queue>

using namespace std;

int main(void)
{
    MyQueue q;
    for (int i = 0; i < 15; i++)
    {
        q.enqueue(i);
        q.enqueue(i * 2);
        cout << q.dequeue() << " ";
    }
}