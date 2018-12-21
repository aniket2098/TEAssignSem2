#include<bits/stdc++.h>
#include "PriorityQueue.h"

using namespace std;

// Initialize the variables
PriorityQueue :: PriorityQueue() {

    int temp;
    cout<<"\n\tEnter no. of priority :: ";
    cin>>temp;

    front  = new int[temp];                     // Array of front equal to no. of priorities
    rear = new int[temp];

    for(int i = 0; i < temp; i++) {         

        vector<int> temporary;
        priorityQueue.push_back(temporary);     //Add no. of queues
        front[i] = -1;
        rear[i] = -1;
    }
}

// Function for queuing
int PriorityQueue :: queue(int no, int priority) {

    if(priority >= 0 && priority < priorityQueue.size()) {  // Check if priority inserted is valid

        if(isEmpty(priority)) { // If empty then increment front pointer at the given priority
         
            front[priority]++;
        }

        rear[priority]++;       // Increment rear at the given priority
        priorityQueue[priority].push_back(no);  // Add no. to the appropriate priority queue
        return 0;               // return 0 if no error
    }
    return 1;                   // return 1 if error in inserting
}

//Function to dequeue elements from the front
void PriorityQueue :: dequeue() {

    for(int i = 0; i < priorityQueue.size(); i++) { // Check all the queues(priority wise, with 0 being the highest) till element found

        if(!isEmpty(i)) {

            priorityQueue[i].erase(priorityQueue[i].begin());   // Delete from first

            rear[i]--;
            if(rear[i] == -1) {                                 // If last element

                front[i]--;
            }
            break;                                              //If element found, break
        }
    }
}

// Return 1 if empty else 0
int PriorityQueue :: isEmpty(int priority) {

    if(rear[priority] == -1)
        return 1;
    
    return 0;
}

// Display all the elements priority wise
void PriorityQueue :: display() {

    for(int i = 0; i < priorityQueue.size(); i++) {

        int temp = front[i];
        cout<<"\tPriority "<<i<<" ::\n\t";
        
        while(temp != rear[i]+1 && !isEmpty(i)) {
         
            cout<<priorityQueue[i].at(temp++)<<" | ";
        }
        cout<<endl<<endl;
    }    
}