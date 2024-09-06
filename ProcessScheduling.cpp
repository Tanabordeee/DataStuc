#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;
class Process{
    public:
        int data;
        int ArrivalTime;
        int ServiceTime;
};
bool compare(const Process& a, const Process& b){
    return a.ArrivalTime < b.ArrivalTime;
}
int main(){
    int n = 0;
    cin >> n;
    vector<Process> v(n);
    stack<Process> stack;
    for(int i = 0 ; i < n ; i++){
        cin >> v[i].data;
        cin >> v[i].ArrivalTime;
        cin >> v[i].ServiceTime;
    }
    sort(v.begin() , v.end() , compare);
    stack.push(v[0]);
    int j = 1;
    int round = 0;
    while (!stack.empty())
    {
        Process temp = stack.top();
        stack.pop();
        int tempServiceTime = temp.ServiceTime;
        for(int i = 0 ; i < temp.ServiceTime ; i++){
            cout << temp.data << " : " << tempServiceTime << endl;
            tempServiceTime--;
            round++;
            if(round == v[j].ArrivalTime){
                stack.push(v[j]);
                j++;
            }
        }
    }
    return 0;
}