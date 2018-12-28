#include<iostream>
#include <vector>

using namespace std;

class TowerOfHanoi {

private:
    int noOfMoves;

public:
    TowerOfHanoi();
    int entryPoint();
    void inline display(int, int, int);
    void solve(int, int, int, int);
};

TowerOfHanoi ::TowerOfHanoi() {

    noOfMoves = 0;
}

int TowerOfHanoi :: entryPoint() {

    int noOfDisks;

    cout << "\tEnter no. of disks :: ";
    cin >> noOfDisks;

    noOfMoves = 0;

    solve(noOfDisks, 1, 2, 3);

    return noOfMoves;
}

void TowerOfHanoi :: display(int diskNo, int source, int destination) {

    cout << "\tDisk " << diskNo << " moved from tower " << source << " to tower " << destination <<endl;
 }

void TowerOfHanoi::solve(int n, int fromRod, int toRod, int auxRod) {

    noOfMoves++;

    if (n == 1)
    {
        display(n, fromRod, toRod);
        return;
    }

    solve(n-1, fromRod, auxRod, toRod);
    display(n, fromRod, toRod);
    solve(n-1, auxRod, toRod, fromRod);
}

int main() {

    TowerOfHanoi towerOfHanoi;
    int choice, temp;

    do {

        cout << "\n\tEnter choice ::\n\t1) Input\n\t2) Exit\n\t";
        cin >> choice;
        switch(choice) {

            case 1:
                temp = towerOfHanoi.entryPoint();
                cout << "\n\tTotal moves :: " << temp << endl;
                break;
            case 2:
                break;
            default:
                cout<<"\n\tWrong choice!!!\n\tRe-enter.\n";
                break;
        }

    }while(choice != 2);
}