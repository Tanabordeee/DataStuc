#include<iostream>
#include <queue>
using namespace std;
class Node{
        public:
            int data;
            Node*left;
            Node*right;
            Node(int data){
                this->data = data;
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
        void insert(Node*& root , int data){
            if(root == NULL){
                root = new Node(data);
            }
            else if(data > root->data){
                insert(root->right , data);
            }
            else if(data < root->data){
                insert(root->left , data);
            }
        }
        Node* successor(Node *&root){
            if(root->left == NULL) return root;
            successor(root->left);
        }
        Node* remove(Node*&root , int data){
            if(data > root->data){
                root->right = remove(root->right , data);
            }
            else if(data < root->data){
                root->left = remove(root->left , data);
            }
            else if(data == root->data){
                if(root->left == NULL && root->right == NULL){
                    delete root;
                    root = NULL;
                }else if(root->right == NULL && root->left != NULL){
                    Node *temp = root;
                    root = root->left;
                    delete temp;
                }else if(root->left == NULL && root->right != NULL){
                    Node *temp = root;
                    root = root->right;
                    delete temp;
                }else{
                    Node* sc = successor(root->right);
                    root->data = sc->data;
                    root->right = remove(root->right , sc->data);
                }
            }
        }
        void Travasel(){
            queue<Node*> q;
            q.push(root);
            while(!q.empty()){
                Node* temp = q.front();
                q.pop();
                cout << temp->data << " ";
                if(temp->left != NULL){
                    q.push(temp->left);
                }
                if(temp->right != NULL){
                    q.push(temp->right);
                }
            }
        }
        void preorder(Node *&root){
            if(root == NULL){
                return;
            }
            cout << root->data << " ";
            preorder(root->left);
            preorder(root->right);
        }
        void postorder(Node *&root){
            if(root == NULL){
                return;
            }
            postorder(root->left);
            postorder(root->right);
            cout << root->data << " ";
        }
        void Inorder(Node *&root){
            if(root == NULL){
                return;
            }
            Inorder(root->left);
            cout << root->data << " ";
            Inorder(root->right);
        }
};
int main(){


    return 0;
}