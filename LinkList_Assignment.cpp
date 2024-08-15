#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};
class LinkList{
    public:
        Node *head;
        LinkList(){
            head = nullptr;
        }
        void Show(){
            Node *ptr;
            ptr = head;
            while(ptr != nullptr){
                cout << ptr->data << " ";
                ptr = ptr->next;
            }
            cout << endl;
        }
        bool Check(int id){
            Node *ptr;
            ptr = head;
            while(ptr != nullptr){
                if(ptr->data == id){
                    return true;
                }
                ptr = ptr->next;
            }
            return false;
        }
        void Insert_Before(int value , int id){
            if(Check(value)){
                return;
            }
            Node *data = new Node(value);
            Node *ptr;
            if(head == nullptr){
                head = data;
                Show();
                return;
            }
            if(head -> data == id){
                data -> next = head;
                head = data;
                Show();
                return;
            }
            ptr = head;
            while(ptr->next != nullptr && ptr->next->data != id){
                ptr = ptr->next;
            }
            if(ptr->next == nullptr){
                ptr->next = data;
                Show();
            }else{
                data->next = ptr->next;
                ptr->next = data;
                Show();
            }
        }
        void Insert_After(int value , int id){
            if(Check(value)){
                return;
            }
            Node *data = new Node(value);
            Node *ptr;
            if(head == nullptr){
                head = data;
                Show();
                return;
            }
            ptr = head;
            while(ptr->next != nullptr && ptr->data != id){
                ptr = ptr->next;
            }
            if(ptr->next == nullptr){
                ptr->next = data;
                Show();
            }else{
                data->next = ptr->next;
                ptr->next = data;
                Show();
            }
        }
        void Delete(int id){
            if(head == nullptr){return;}
            Node *ptr;
            ptr = head;
            if(head -> data == id){
                if(head->next == nullptr){
                    return;
                }
                head = head -> next;
                delete ptr;
                Show();
                return;
            }
            while(ptr != nullptr && ptr->next->data != id){
                ptr = ptr->next;
            }
            if(ptr->next == nullptr){
                return;
            }
            Node* temp = ptr->next;
            ptr->next = ptr->next->next;
            delete temp;
            Show();
        }
};
int main(){
    LinkList l = LinkList();
    int value = 0;
    int id = 0;
    char c;
    while (true){
        cin >> c;
        if(c == 'A'){
            cin >> value >> id;
            l.Insert_After(value , id);
        }
        if(c == 'I'){
            cin >> value >> id;
            l.Insert_Before(value , id);
        }
        if(c == 'D'){
            cin >> id;
            l.Delete(id);
        }
        if(c == 'E'){
            break;
        }
    }
    return 0;
}