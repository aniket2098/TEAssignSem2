#include "PriorityQueue.cpp"

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