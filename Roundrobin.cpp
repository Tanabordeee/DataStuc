#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
class Data{
    public:
        int data;
        int arrivalTime;
        int serviceTime;
};
bool compare(const Data& a , const Data& b){
    return a.arrivalTime < b.arrivalTime;
}
int main(){
    int q = 1;
    vector<Data> v;
    stack<Data> s;
    stack<Data> tempstack;
    for(int i = 0 ; i < 5 ; i++){
        Data d;
        cin >> d.data;
        cin >> d.arrivalTime;
        cin >> d.serviceTime;
        v.push_back(d);
    }
    sort(v.begin() , v.end() , compare);
    int j = 0;
    int round = 0;
    s.push(v[0]);
    while (!s.empty())
    {
       while (j + 1 < v.size() && v[j + 1].arrivalTime <= round) {
            j++;
            s.push(v[j]);
        }
            Data temp = s.top();
            s.pop(); 
            cout << "round " << round << " process " << temp.data << " serviceTime " << temp.serviceTime << endl;
            temp.serviceTime--;
            round++;
        if(temp.serviceTime > 0){
            while(!s.empty()){
                tempstack.push(s.top());
                s.pop();
            }
            s.push(temp);
            while (!tempstack.empty()){
                s.push(tempstack.top());
                tempstack.pop();
            }
            
        }
    }

}