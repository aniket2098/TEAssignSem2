#include<bits/stdc++.h>
using namespace std;

class PriorityQueue {
    private:
    vector< vector<int> > priorityQueue;
    int *front, *rear;

    public:
    PriorityQueue();
    int queue(int, int);
    void dequeue();
    void display();
    int isEmpty(int);

};

PriorityQueue :: PriorityQueue() {

    int temp;
    cout<<"\n\tEnter no. of priority :: ";
    cin>>temp;

    front  = new int[temp];
    rear = new int[temp];

    for(int i = 0; i < temp; i++) {

        vector<int> temporary;
        priorityQueue.push_back(temporary);
        front[i] = -1;
        rear[i] = -1;
    }
}

int PriorityQueue :: queue(int no, int priority) {

    if(priority >= 0 && priority < priorityQueue.size()) {

        if(isEmpty(priority)) {
         
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

int main() {

    PriorityQueue priorityQueue;
    int choice, temp, priority;

    do {

        cout<<"\n\tEnter choice ::\n\t1)Queue\n\t2)Dequeue\n\t3)Display\n\t4)Exit\n\t";
        cin>>choice;

        switch(choice) {

            case 1:
                cout<<"\n\tEnter no. :: ";
                cin>>temp;
                cout<<"\tEnter priority :: ";
                cin>>priority;
                if(priorityQueue.queue(temp, priority)) {

                    cout<<"\n\tError inserting!!!\n";
                }
                break;
            case 2:
                priorityQueue.dequeue();
                break;
            case 3:
                priorityQueue.display();
                break;
            case 4:
                break;
            default:
                cout<<"\tWrong choice!\nRe-enter!\n";
                break;
        }
    } while(choice != 4);

    return 0;
}