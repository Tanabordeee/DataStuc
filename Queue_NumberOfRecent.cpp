#include <iostream>
using namespace std;
#define SIZE 1024
class Queue{
    public:
        int front = -1;
        int back = -1;
        int arr[SIZE];
        void enqueue(int num){
            back++;
            arr[back] = num;
        }
        void dequeue(){
            arr[++front];
        }
        void Print(){
            for(int i = front; i <= back; i++){
                cout << arr[i] << " ";
            }
        }
        void Ping(){
            front++;
            while(arr[front] <= arr[back] - 3000){
               dequeue();
            }
            Print();
        }
};
int main(){
    Queue *queue = new Queue;
    queue->enqueue(1) ;
    queue->enqueue(100); 
    queue->enqueue(3001); 
    queue->enqueue(3002);
    queue->Ping();
    return 0;
}