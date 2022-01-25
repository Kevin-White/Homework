//Kevin White
#include <iostream>
#include <queue>
using namespace std;

void rotateQ(queue <int> &q, int n)
{   
    for(int i = 0; i < n; i++){
        q.push(q.front());
        q.pop();
    }
}

void displayQueue(queue<int> &q){
    for(int i = 0; i < q.size(); i++){
        cout << q.front() << " ";
        q.push(q.front());
        q.pop();
    }
}

int main(){
    queue<int> test;
    for(int i = 0; i < 5; i++){
        test.push(i);
    }

    cout << "Pre Rotate: ";
    displayQueue(test);
    cout << endl << endl;

    int r;
    cout << "How many values should the queue rotate: ";
    cin >> r;
    cout << endl;

    rotateQ(test, r);

    cout << "Post Rotate: ";
    displayQueue(test);
    cout << endl;

}