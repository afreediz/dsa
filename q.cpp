#include<iostream>
using namespace std;

class Q{
    private:
        int a[100];
        int front = -1, rear = -1;
        int i, element;
    public:
        void traverse(){
            if(front == -1){
                cout << "q is empty";
                return;
            };
            for(i=front; i<=rear;i++){
                cout << a[i] << " ";
            };
            return;
        };
        void enqueue(int key){
            if(front == -1){
                front = 0;
            };
            a[++rear] = key;
        };
        int dequeue(){
            if(front == -1){
                cout << "q is empty" << endl;
            }
            element = a[front];
            front++;
            return element;
        };
        int peek(){
            if( front == -1 ){
                cout << "Q is empty";
                return -1;
            }
            return a[front];
        };
};

int main(){
    Q list;
    list.enqueue(5);
    list.enqueue(3);
    list.enqueue(1);
    list.enqueue(7);
    list.enqueue(2);
    cout << list.dequeue() << endl;
    cout << list.peek() << endl;
    list.traverse();
}