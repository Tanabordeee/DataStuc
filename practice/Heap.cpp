#include <iostream>
using namespace std;
class Heap{
    public:
        int arr[100];
        Heap(){
            arr[0] = 0;
        }
        void push(int data){
            arr[0] += 1;
            arr[arr[0]] = data;
            int i = arr[0];
            while(i > 1 && arr[i/2] > arr[i]){
                swap(arr[i/2] , arr[i]);
                i/=2;
            }
        }
        int Delete(){
            int temp = arr[1];
            arr[1] = arr[arr[0]];
            arr[0] -= 1;
            int i = 1;
            while(i<=arr[0]){
                int left = i*2;
                int right = i*2+1;
                if(left <= arr[0] && arr[left] < arr[i] && arr[left] <= arr[right]){
                    swap(arr[left], arr[i]);
                    i = left;
                }
                else if(right <= arr[0] && arr[right] < arr[i] && arr[right] < arr[left]){
                    swap(arr[right], arr[i]);
                    i = right;
                }else{
                    break;
                }
            }
            return temp;
        }
};

int main(){
    Heap h;
    h.push(1);
    h.push(4);
    h.push(2);
    h.push(3);
    h.push(6);
    h.push(5);
    for(int i = 0 ; i < 6 ; i++){
        cout << h.Delete() << endl;
    }
    return 0;
}