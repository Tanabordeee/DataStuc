#include <iostream>
#include <stack>
using namespace std;
int main(){
    string str;
    stack<char> st;
    getline(cin , str);
    for(int i = 0 ; i < str.length() ; i++){
        if(str[i] == '<'){
            if(str[i+1] == '/'){
                i+=2;
                while (str[i] != '>')
                {
                    i++;
                }
                    st.pop();
                
            }else{
                i++;
                while (str[i] != '>')
                {
                    i++;
                }
                if(str[i] == '>'){
                    st.push(str[i]);
                }
            }
        }
    }
    if(st.empty()){
        cout << "PASS";
    }else{
        cout << "FAILED";
    }
    return 0;
}