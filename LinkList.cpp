#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;

    Node(int data){
        this->data = data;
        this->next = nullptr;
    }
};
void PrintNode(Node *node){
    while(node != nullptr){
        cout << node->data << endl;
        node = node->next;
    }
}
int main(){
    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);

    node1->next = node2;
    node2->next = node3;
    PrintNode(node1);
    
    return 0;
}