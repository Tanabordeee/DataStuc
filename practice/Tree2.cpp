#include <iostream>
#include <queue>
using namespace std;
class Node{
    public:
        int data;
        Node* left;
        Node* right;
        Node(int val){
            data = val;
            left = NULL;
            right = NULL;
        }
};
class Tree{
    public:
        Node* root;
        Tree(int data){
            root = new Node(data); 
        }
        void insert(Node*&root , int data){
            if(root == NULL){
                root = new Node(data);
            }
            if(root->data > data){
                insert(root->left , data);
            }
            else if(root->data < data){
                insert(root->right , data);
            }
        }
        Node* predecessor(Node* root){
            if(root->right == NULL) return root;
            return predecessor(root->right);
        }
        Node* remove(Node*&root , int data){
            if(root->data > data){
                root->left = remove(root->left , data);
            }else if(root->data < data){
                root->right = remove(root->right , data);
            }
            else{
                if(root->left == NULL && root->right == NULL){
                    delete root;
                    root = NULL;
                }
                else if(root->left == NULL && root->right != NULL){
                    Node* temp = root;
                    root = root->right;
                    delete temp;
                }
                else if(root->left != NULL && root->right == NULL){
                    Node * temp = root;
                    root = root->left;
                    delete temp;
                }else{
                    Node* predecessors = predecessor(root->left);
                    root->data = predecessors->data;
                    root->left = remove(root->left , predecessors->data);
                }
            }
            return root;
        }
        void Traversal(){
            queue <Node*> q;
            q.push(root);
            while(!q.empty()){
                Node* temp = q.front();
                cout << temp->data << " ";
                q.pop();
                if(temp->left != NULL){
                    q.push(temp->left);
                }
                if(temp->right != NULL){
                    q.push(temp->right);
                }
            }
        }
        void Preorder(){
            
        }
};
int main(){
    Tree t(4);
    t.insert(t.root,2);
    t.insert(t.root,6);
    t.insert(t.root,1);
    t.insert(t.root,3);
    t.insert(t.root,5);
    t.insert(t.root,7);
    t.remove(t.root,2);
    t.remove(t.root,4);
    t.Traversal();

    return 0;
}