#include <iostream>
#include <stack>
using namespace std;
class node{
    public:
        int key;
        string value;
        node *next;
        node(){
            key = -1;
            value = "-";
            next = NULL;
        }
        node(int key , string value){
            this->key = key;
            this->value = value;
            next = NULL;
        }
};
class Separate_Chaining{
    public:
        int n ;
        node * Hash_Table;
        Separate_Chaining(int size){
            Hash_Table = new node[size];
            n = size;
        }
        void add(int key , string value){
            int j = key % n;
            if(Hash_Table[j].next == NULL){
                Hash_Table[j].key = key;
                Hash_Table[j].value = value;
                Hash_Table[j].next = new node();
            }else{
                node *ptr = Hash_Table[j].next;
                while(ptr->next != NULL){
                    ptr = ptr->next;
                }
                ptr->value = value;
                ptr->key = key;
                ptr->next = new node();
            }
        }
        void show(){
            for(int i = 0 ; i < n ; i++){
                node *ptr = &Hash_Table[i];
                if(ptr->next == NULL){
                    cout << "(-1 , - )";
                }
                while(ptr->next != NULL){
                    cout <<"( " << ptr->key << " , " << ptr->value << " ) ";
                    ptr = ptr->next;
                }
                cout << endl;
            }
        }
        void Search(int key){
            int j = key % n;
            node *ptr = &Hash_Table[j];
            while(ptr != NULL && ptr->key != key){
                ptr = ptr->next;
            }
            if(ptr == NULL){
                cout << "(-1 , - )" << endl;
            }else{
                cout << ptr->value << endl;
            }
        }
};
int main(){
    Separate_Chaining sc(17);
    sc.add(5 , "test");
    sc.add(4 , "test");
    sc.add(4 , "fwafwaf");
    sc.add(3 , "test");
    sc.add(11115 , "test");
    sc.show();
    sc.Search(5);
    sc.Search(56);
    return 0;
}