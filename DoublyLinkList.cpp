#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int data){
        this->data = data;
        prev = nullptr;
        this->next = nullptr;
    }
};
void PrintNode(Node *Node){
    while(Node != nullptr){
        cout << Node->data << endl;
        Node = Node->next;
    }
}

void PrintBackNode(Node *Node){
    while(Node != nullptr){
        cout << Node->data << endl;
        Node = Node->prev;
    }
}
int main(){
    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);

    node1->next = node2;
    node2->prev = node1;
    node2->next = node3;
    node3->prev = node2;

    PrintNode(node1);
    PrintBackNode(node3);   
    return 0;
}