#include <iostream>
#include <stack>
using namespace std;
int main(){
    stack<char> stack;
    string s;
    getline(cin , s); 
    int count = 0;
    for(int i = 0 ; i < s.length() ; i++){
        if(i==0){
            if(s[i] == ')' || s[i] == '}' || s[i] == ']' || s[i] == '>'){
                break;
            }
        }
        if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
            stack.push(s[i]);
        }
        else if(s[i] == '<'){
          if(i + 1 < s.length() && s[i + 1] == '<'){
            stack.push(s[i]);
            stack.push(s[i + 1]);
            i++;
         }else{
            stack.push(s[i]);
         }
        }
        else if (s[i] == ')' && !stack.empty() && stack.top() == '(') {
            count++;
            stack.pop();
        }
        else if(s[i] == ']' && !stack.empty() && stack.top() == '['){
            count++;
            stack.pop();
         }
        else if(s[i] == '}' && !stack.empty() && stack.top() == '{'){
            stack.pop();
            count++;
         }
        else if(s[i] == '>' && !stack.empty() && stack.top() == '<'){
            if(s[i+1] == '>'){
                stack.pop();
                stack.pop();
                count++;
                i++;
            }else{
                stack.pop();
                count++;
            }
         }
        }
    if(stack.empty()){
        cout << count << " Matched";
    }else{
        cout << "Not Matched" << endl;
        cout << count << " Matched";
    }
}