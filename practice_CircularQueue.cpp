#include <iostream>
using namespace std;
#define SIZE 5
class Queue{
    public:
        int front = -1;
        int back = -1;
        int arr[SIZE];
        void push(int num){
            if(full()){
                cout << "full" << endl;
                return;
            }else{
                back++;
                arr[back % SIZE] = num;
            }
        }
        int pop(){
            if(empty()){
                return -1;
            }else{
                return arr[++front % SIZE];
            }
        }
        bool full(){
            if(back - front == SIZE) return true;
            else return false;
        }
        bool empty(){
            if(front >= back) return true;
            else return false;
        }
        void display(){
            for(int i = 0 ; i < SIZE ; i++){
                cout << arr[i] << " ";
            }
            cout << endl;
        }
};

int main(){
    Queue q;
    for(int i = 0 ; i < 5 ; i++){
        q.push(i);
    }
    q.display();
    for(int i = 0 ; i < 5 ; i++){
        q.push(i);
    }
    for(int i = 0 ; i < 5 ; i++){
        q.pop();
    }
    for(int i = 0 ; i < 5 ; i++){
        q.push(i);
    }
    q.display();

    return 0;
}