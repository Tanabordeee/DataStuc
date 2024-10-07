#include <iostream>
using namespace std;
class Heap{
    // ขาซ้าย = i * 
    public:

        int q[1000] = {0};
        void insert(int num){
            q[0]+=1;
            q[q[0]] = num;
            int i = q[0];
            while(i > 1 && q[i/2] < q[i] ){
                int t = q[i/2];
                q[i/2] = q[i];
                q[i] = t;
                i/=2;
            }
        }

        int deletes(){
            int s = q[1];
            q[1] = q[q[0]];
            q[0] = q[0] - 1;
            int p = 1;
            while(p <= q[0]){
                int left = p*2; // node ลูกด้าน ซ้าย
                int right = (p*2)+1; // node ลูกด้าน ขวา
                if(q[left] > q[p] && q[left] >= q[right]){
                    int t = q[left];
                    q[left] = q[p];
                    q[p] = t;
                    p = left;
                
                }
                else if(q[right] > q[p] && q[right] > q[left] ){
                    int t = q[right];
                    q[right] = q[p];
                    q[p] = t;
                    p = right;
                }else {
                    break;
                }
            }
            return s;
        }
        void Print(){
            for(int i = 1 ; i <= q[0] ; i++){
                cout << q[i] << " ";
            }
            cout << endl;
        }
};

int main(){
    
    Heap heap;

    while (true)
    {
        char c;
        int num = 0;
        cin >> c;
        if(c=='a'){
            cin >> num;
            heap.insert(num);
        }
        else if(c=='p'){
            heap.Print();
        }
        else if(c == 'd'){
            int d = heap.deletes();
            cout << d << endl;
        }else if(c== 'e'){
            break;
        }
    }
    
    return 0;
}