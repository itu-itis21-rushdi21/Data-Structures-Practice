const int QUEUE_MAX_SIZE = 10;

class MyQueue {
    private:
        int arr[QUEUE_MAX_SIZE];
        int front, back, num_of_items;
    public:
        MyQueue();
        bool enqueue(int);
        int dequeue();
        int peek_front();
        int peek_back();
        bool isEmpty();
        bool isFull();
        void clear(); 
        
};
