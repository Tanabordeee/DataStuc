#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
class Process{
    public:
        char data;
        int arrivalTime;
        int serviceTime;
};
bool compare(const Process&a , const Process&b){return a.arrivalTime < b.arrivalTime;}
int main(){
    int n = 0;
    int q = 0;
    cin >> n >> q;
    Process process;
    vector<Process> v(n);
    queue<Process>queue;
    for(int i = 0; i < n; i ++){
        cin >> v[i].data;
        cin >> v[i].arrivalTime;
        cin >> v[i].serviceTime;
    }
    sort(v.begin() , v.end() , compare);
    queue.push(v[0]);
    int round = 0;
    int j = 0;
    while (true)
    {
            Process temp = queue.front();
            queue.pop();
            for(int i = 0 ; i < q ; i ++){
                cout<< "round "<< round << " " << temp.data << " servicetime " << temp.serviceTime << endl;
                temp.serviceTime--;
                round++;
                if(j + 1 < n && v[j + 1].arrivalTime <= round) {
                    queue.push(v[j + 1]);
                    j++;
                }
                if (temp.serviceTime <= 0) {
                break;
                }
            }
        if(temp.serviceTime > 0){
            queue.push(temp);
            }
        if (queue.empty()) {
            break;
        }
    }
    
}