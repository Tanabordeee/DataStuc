#include <iostream>
using namespace std;
#define SIZE 5
int arr[SIZE];
class CircularQueue{
  public:
    // set start queue
    //-1 -1 [0 0 0 0 0]
    // f  b
    int front = -1;
    int back = -1;

    void Enqueue(int num){
      // if it full show full
      if(Full()){
        cout << "Queue is full" << endl;
      }else{
        //-1 [0 0 0 0 0]
        // f  b
        back++;
        
        //-1 [num 0 0 0 0]
        // f   b
        // b = 0 % 5 = 0 , b = 1 % 5 = 1 , b = 2 % 5 = 2 , b = 3 % 5 = 3 , b = 4 % 5 = 4 , b = 5 % 5 = 5
        // ครั้งต่อจาก 5 back จะไม่บวกเพิ่มแล้วเพราะมีการดัก full
        arr[back % SIZE] = num;

        // show log
        cout << "Enqueued " << num << " Positions " << back % SIZE << endl;
      }
    }

    void Dequeue(){
      // if it full show Empty
      if(Empty()){
        cout << "Queue is empty" << endl;
      }else{
        // [num num num num num]
        //   f               b
        int num = arr[++front % SIZE];
        cout << "Dequeued " << num << " Positions " << front % SIZE << endl;
      }
    }

    bool Full(){
      // back = 4 front = -1 => back - front = 4 - - 1 == SIZE = 5
      // หาระยะห่างระหว่าง front กับ back ว่ามีเท่ากับขนาดไหมถ้าเท่าแปลว่าเต็ม
      // -1 [num num num num num]
      //  f                   b
      if (back - front == SIZE){
        cout << "BACK : " <<back << " ";
        cout << "FRONT : " << front << " ";
        cout << "SPACE : " << back - front << " ";
        return true;
      }else{
        return false;
      }
    }
    bool Empty(){
      // [num 0 num num num]
      //  b   f
      //  0   1
      if (front >= back){
        return true;
      }else
        return false;
      }
      
    void Display(){
      for(int i = front + 1  ; i <= back ; i++){
        cout << arr[i] << " ";
      }
      cout << endl;
    }
};

int main(){
  CircularQueue queue;
  // testcase
  // add QUEUE
  queue.Enqueue(5);
  queue.Enqueue(5);
  queue.Enqueue(5);
  queue.Enqueue(5);
  queue.Enqueue(5);
  queue.Enqueue(5);
  queue.Enqueue(5);
  queue.Enqueue(5);
  queue.Enqueue(5);
  queue.Enqueue(5);
  queue.Enqueue(5);

  // SHOW ITEM IN ARRAY
  queue.Display();

  // POP QUEUE
  queue.Dequeue();
  queue.Dequeue();
  queue.Dequeue();
  queue.Dequeue();
  queue.Dequeue();
  queue.Dequeue();
  queue.Dequeue();
  queue.Dequeue();
  queue.Dequeue();


  //SHOW ITEM IN ARRAY
  queue.Display();

   queue.Enqueue(5);
  queue.Enqueue(5);
  queue.Enqueue(5);
  queue.Enqueue(5);
  queue.Enqueue(5);
  queue.Enqueue(5);
  queue.Enqueue(5);
  queue.Enqueue(5);
  queue.Enqueue(5);
  queue.Enqueue(5);
  queue.Enqueue(5);

  queue.Display();

}