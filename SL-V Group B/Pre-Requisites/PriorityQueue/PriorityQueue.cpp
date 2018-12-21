#include<bits/stdc++.h>
#include "PriorityQueue.h"

using namespace std;

// Initialize the variables
PriorityQueue :: PriorityQueue() {

    int temp;
    cout<<"\n\tEnter no. of priority :: ";
    cin>>temp;

    front  = new int[temp];
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

        if(isEmpty(priority)) { //If empty then 
         
            front[priority]++;
        }

        rear[priority]++;
        priorityQueue[priority].push_back(no);
        return 0;
    }
    return 1;
}

void PriorityQueue :: dequeue() {

    for(int i = 0; i < priorityQueue.size(); i++) {

        if(!isEmpty(i)) {

            priorityQueue[i].erase(priorityQueue[i].begin());

            rear[i]--;
            if(rear[i] == -1) {

                front[i]--;
            }
            break;
        }
    }
}

int PriorityQueue :: isEmpty(int priority) {

    if(rear[priority] == -1)
        return 1;
    
    return 0;
}

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