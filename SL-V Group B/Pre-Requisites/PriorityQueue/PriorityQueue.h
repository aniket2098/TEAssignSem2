#include<bits/stdc++.h>
using namespace std;

class PriorityQueue {
    private:
    vector< vector<int> > priorityQueue;    // A 2d vector to store the priority queue
    int *front, *rear;                      // Store the front and rear of the queues

    public:
    PriorityQueue();                        // Constructor to initialize the variables
    int queue(int, int);                    // Add to the queue
    void dequeue();                         // Delete from the queue
    void display();                         // Display the queue
    int isEmpty(int);                       // Check if the queue is empty.

};
