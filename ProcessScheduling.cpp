#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int round =0 ;
    cin >> round;
    stack<int> numStack;  
    stack<int> arrivalStack;
    stack<int> servalStack;
    vector<int> arrnum(round);
    vector<int> arrArrival(round);
    vector<int> arrServal(round);
    vector<int> index_serval(round);
    int count = 0;
    for(int i = 0; i < round; i++){
        cin >> arrnum[i];
        cin >> arrArrival[i];
        cin >> arrServal[i];
        index_serval[i] = i;
    }
    sort(index_serval.begin(), index_serval.end(), [&](int a, int b) {
    return arrArrival[a] < arrArrival[b];
    });
    int nextnum = arrnum[0];
    int nextServal = arrServal[0];
    
    for(int i =0 ; i < round ; i++){
        for(int j = 0 ; j < nextServal; j++){
            count++;
            if(count == arrArrival[j]){
                numStack.push(arrnum[j]);
                servalStack.push(arrServal[j]);
            }
            cout << nextnum << ":" << nextServal - j << endl;
        }
        nextnum = numStack.top();
        nextServal = servalStack.top();
        numStack.pop();
        servalStack.pop();
    }
    return 0;
}