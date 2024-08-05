#include <iostream>
using namespace std;
#define SIZE 1024
class Stack{
    public:
        int top = -1;
        char arr[SIZE];
        void push(char c){
            if(full()){
                return;
            }else{
                top++;
                arr[top] = c;
            }
        }
        void pop(){
            if(empty()){
                return;
            }else{
                arr[--top];
            }
        }
        bool full(){
            if(top >= SIZE - 1){
                return true;
            }else{
                return false;
            }
        }
        bool empty(){
            if(top <= -1){
                return true;
            }else{
                return false;
            }
        }
};

int main(){
    string str = "<html><head><title>Sample Page</title></head><body><h1>Welcome to the Sample Page</h1><p>This is a sample paragraph.</p></body></html>";
    Stack stack;
    for(int i = 0 ; i < str.length() ; i++){
        if(str[i] == '<'){
            if(str[i+1] == '/'){
                i+= 2;
                while(str[i] != '>'){
                    i++;
                }
                stack.pop();
            }else{
                i++;
                while (str[i] != '>')
                {
                    i++;
                }
                stack.push(str[i]);
            }
        }
    }
    if(stack.empty()){
        cout << "All tags are properly nested and matched" <<endl;
    }else{
        cout << "FALIED" << endl;
    }
}