#include <iostream>
using namespace std;

class Heap{
    public:
        int matrix[100];
        Heap(){
            matrix[0] = 0;
        }
        void insert(int data){
            matrix[0] += 1;
            matrix[matrix[0]] = data;
            int i = matrix[0];
            while(i > 1 && matrix[i/2] < matrix[i]){
                swap(matrix[i/2] , matrix[i]);
                i /=2;
            }
        }
        int remove(){
            int temp = matrix[1];
            matrix[1] = matrix[matrix[0]];
            matrix[0] -= 1;
            int i = 1;
            while(true){
                int left = i*2;
                int right = (i*2)+1;
                if(left <= matrix[0] && matrix[left] > matrix[i] && matrix[left] > matrix[right]){
                    swap(matrix[left] , matrix[i]);
                    i = left;
                }
                else if(right <= matrix[0] && matrix[right] > matrix[i] && matrix[right] > matrix[left]){
                    swap(matrix[right] , matrix[i]);
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
    h.insert(1);
    h.insert(4);
    h.insert(2);
    h.insert(3);
    h.insert(6);
    h.insert(5);
    for(int i = 0 ; i < 6 ; i++){
        cout << h.remove() << endl;
    }

    return 0;
}