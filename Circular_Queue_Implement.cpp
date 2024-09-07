#include <iostream>
using namespace std;
#define SIZE 100
class CircularQueue{
    public:
        int arr[SIZE];
        int front = -1;
        int back = -1;
        void enqueue(int value){
            if((back+1)%SIZE == front){
                return;
            }
            back = (back + 1) % SIZE;
            arr[back%SIZE] = value;
        }
        void dequeue(){
            if(front == back){
                return;
            }
            int value = arr[(front+1)%SIZE];
            cout << value << endl;
            front = (front + 1) % SIZE;
        }
        void show(){
            for(int i = (front+1)%SIZE ; i != (back+1) % SIZE ; i = (i+1)%SIZE){
                cout << arr[i] << " ";
            }
            cout << endl;
        }
        void show_fist_back(){
            cout << arr[(front+1)%SIZE] << " " << arr[back%SIZE] << endl; 
        }
        void check_size(){
                int count = (back - front + SIZE) % SIZE;
                cout << count << endl;
        }
};
int main(){
    CircularQueue queue;
    while (true)
    {
        char sc;
        int num = 0;
        cin >> sc;
        if(sc == 'e'){
            cin >> num;
            queue.enqueue(num);
        }
        else if(sc == 'd'){
            queue.dequeue();
        }
        else if(sc == 'p'){
            queue.show();
        }
        else if(sc == 's'){
            queue.show_fist_back();
        }
        else if(sc == 'n'){
            queue.check_size();
        }
        else if(sc == 'x'){
            break;
        }
    }
    

    return 0;
}