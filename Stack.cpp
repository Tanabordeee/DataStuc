#include <iostream>
#define MAXSIZE 100
using namespace std;
class Stack{
    private:
    int top;
    int arr[MAXSIZE];
    public:
    Stack() {
        top = -1;
    }
    void push(int x){
        if(top >= MAXSIZE - 1){
            cout << "Stack overflow: " << endl;
        }else{
            arr[++top] = x;
            cout << x << " PUSH INTO STACK" << endl;
        }
    }

    int pop() {
        if (top < 0){
            cout << "Stack Underflow" << endl;
            return 0;
        }else{
            int data = arr[top--];
            return data;
        }
    }

    int peek(){
        if(top < 0){
            cout << "Stack is Empty" << endl;
            return 0;
        }else{
            int x = arr[top];
            return x;
        }
    }
};
int main(){
    Stack s;
    s.push(1);
    s.push(2);
    cout << "TOP ELEMENT IS " << s.peek() << endl;
    cout << "POP FROM STACK " << s.pop() << endl;
    cout << "TOP ELEMENT IS " << s.peek() << endl;
    return 0;
}