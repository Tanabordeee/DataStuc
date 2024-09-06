#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int check(char c){
    if(c == '+' || c == '-'){
        return 1;
    }
    else if(c== '*' || c == '/'){
        return 2;
    }
    else if(c == '^'){
        return 3;
    }
    return 0;
}
int main() {
    string str;
    getline(cin, str);
    string result;
    stack<char> stack;

    for (int i = 0; i < str.length(); i++) {
        if(isalnum(str[i])){
            result+= str[i];
        }
        else if(str[i] == '('){
            stack.push(str[i]);
        }
        else if(str[i] == ')'){
            while (!stack.empty() && stack.top() != '(')
            {
                result+= stack.top();
                stack.pop();
            }
            stack.pop();
        }
        else{
            if(!stack.empty() && check(str[i]) <= check(stack.top())){
                result+= stack.top();
                stack.pop();
                stack.push(str[i]);
            }else{
                stack.push(str[i]);
            }
        }
    }
    while(!stack.empty()){
        result+= stack.top();
        stack.pop();
    }
    cout << result;
}