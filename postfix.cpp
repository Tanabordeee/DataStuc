#include <iostream>
#include <stack>
using namespace std;
int main(){
    string str;
    cin >> str;
    string result;
    string temp;
    string tempch;
    stack<string> st;
    for(int i = 0; i < str.length(); i++){
        temp = "";
        if(isalnum(str[i])){
            temp = str[i];
            st.push(temp);
        }
        else if (str[i] == '+'){
            tempch = st.top();
            st.pop();
            temp+='(';
            temp+= st.top();
            st.pop();
            temp+= '+';
            temp+=tempch;
            temp+= ')';
            st.push(temp);
        }
        else if (str[i] == '-'){
            tempch = st.top();
            st.pop();
            temp+='(';
            temp+= st.top();
            st.pop();
            temp+= '-';
            temp+=tempch;
            temp+= ')';
            st.push(temp);
        }
        else if (str[i] == '*'){
            tempch = st.top();
            st.pop();
            temp+='(';
            temp+= st.top();
            st.pop();
            temp+= '*';
            temp+=tempch;
            temp+= ')';
            st.push(temp);
        }
        else if (str[i] == '/'){
            tempch = st.top();
            st.pop();
            temp+='(';
            temp+= st.top();
            st.pop();
            temp+= '/';
            temp+=tempch;
            temp+= ')';
            st.push(temp);
        }
        else if (str[i] == '^'){
            tempch = st.top();
            st.pop();
            temp+='(';
            temp+= st.top();
            st.pop();
            temp+= '^';
            temp+=tempch;
            temp+= ')';
            st.push(temp);
        }
    }
    while(!st.empty()){
        result+= st.top();
        st.pop();
    }
    cout << result;
    return 0;
}