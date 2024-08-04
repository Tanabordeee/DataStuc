#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node *next;
};
class Stack{
private:
    Node *top;
public:
    Stack(){
        top = nullptr;
    }

    void push(int x){
        Node *newNode = new Node();
        newNode->data = x;
        newNode->next = top;
        top = newNode;
        cout << x << " pushed into stack \n";
    }

    int pop(){
        if(top == nullptr){
            cout << "Stack Underflow" << endl;
            return 0;
        }
        Node *temp = top;
        int poppedValue = top->data;
        top = top->next;
        delete top;
        return poppedValue;
    }

    bool isEmpty() {return top == nullptr;}

    int peek(){
        if(!isEmpty()){
            return top->data;
        }else{
            cout << "Stack Empty" << endl;
            return -1;
        }
    }
};
int main(){
    Stack s;
    s.push(10);
    s.push(20);
    cout << "TOP ELEMENT IS " << s.peek() << endl;
    cout << "POP FROM STACK " << s.pop() << endl;
    return 0;
}