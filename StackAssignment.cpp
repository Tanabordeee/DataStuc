#include <iostream>
using namespace std;
#define SIZE 100
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
   char pop(){
    if(!empty()){
        return arr[--top];
    }else{
        return ' ';
    }
   }
   bool empty(){
    if(top <= -1){
        return true;
    }else{
        return false;
    }
   }
   bool full(){
    if(top >= SIZE){
        return true;
    }else{
        return false;
    }
   }
   char seek(){
    return arr[top];
   }
};

int main(){
    Stack stack;
    string c;
    cin >> c;
    bool check = false;
    for(int i = 0 ; i < c.length() ; i++){
        if(c[i] == '('){
            stack.push(c[i]);
        }
        if(c[i] == '['){
            stack.push(c[i]);
        }
        if(c[i] == '{'){
            stack.push(c[i]);
        }
        if(c[i] == '<'){
            stack.push(c[i]);
        }
        if(c[i] == ')'){
            if(!stack.empty() && stack.seek() == '('){
                stack.pop();
            }else{
                check = true;
                break;
            }
        }
        if(c[i] == ']'){
            if(!stack.empty() && stack.seek() == '['){
                stack.pop();
            }else{
                check = true;
                break;
            }
        }
        if(c[i] == '}'){
            if(!stack.empty() && stack.seek() == '{'){
                stack.pop();
            }else{
               check = true;
               break;
            }
        }
        if(c[i] == '>'){
            if(c[i+1] == '>'){
                check = true;
                break;
            }
            if(!stack.empty()  && stack.seek() == '<'){
                stack.pop();
            }else{
                check = true;
                break;
            }
        }
    
    }
    if(check){
        cout << "failed" << endl;
    }else{
        cout << "success" << endl;
    }
    return 0;
}