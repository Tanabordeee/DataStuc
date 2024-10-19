#include <iostream>
#include <algorithm>
using namespace std;
class Node{
    public:
        int data , height;
        Node*left;
        Node*right;
        Node(int val){
            data = val;
            height = 1;
            left = NULL;
            right = NULL;
        }
};  
class Avl{
    public:
        Node* root;
        Avl(int data){
            root = new Node(data);
        }
        int height(Node*&root){
            if(root == NULL) return 0;
            return 1 + max(height(root->left) , height(root->right));
        }
        void insert(Node*&root , int data){
            if(root == NULL) {
                root = new Node(data);
            }
            if(data > root->data){
                insert(root->right , data);
            }
            else if(data < root->data){
                insert(root->left , data);
            }
            root->height = height(root);
            Rotate(root);
        }
        Node* Predecessor(Node*&root){
            if(root->right == NULL) {return root;}
            return Predecessor(root->right);
        }
        Node* Delete(Node*&root , int data){
            if(data > root->data){
                root->right = Delete(root->right , data);
            }else if(data < root->data){
                root->left = Delete(root->left , data);
            }else{
                if(root->right == NULL && root->left == NULL){
                    Node* temp = root;
                    delete temp;
                    root = NULL;
                }
                else if(root->left != NULL && root->right == NULL){
                    Node* temp = root;
                    root = root->left;
                    delete temp;
                }
                else if(root->right != NULL && root->left == NULL){
                    Node* temp = root;
                    root = root->right;
                    delete temp;
                }
                else if(root->left != NULL && root->right != NULL){
                    Node* pre = Predecessor(root->left);
                    root->data = pre->data;
                    root->left = Delete(root->left , pre->data);
                }
                if(root != NULL){
                    root->height = height(root);
                    Rotate(root);
                }
            }
            return root;
        }
        void Rotate(Node*&root){
            if(height(root->left) - height(root->right) > 1){
                if(height(root->left->left) >= height(root->left->right)){
                    //left left
                    RotateRight(root);
                }else{
                    //double
                    RotateLeft(root->left);
                    RotateRight(root);
                }
            }else if(height(root->right) - height(root->left) > 1){
                if(height(root->right->right) >= height(root->right->left)){
                    RotateLeft(root);
                }else{
                    RotateRight(root->right);
                    RotateLeft(root);
                }
            }
        }
        void RotateRight(Node*&p){
            Node* c = p->left;
            Node* t2 = c->right;
            c->right = p;
            p->left = t2;
            p->height = height(p);
            c->height = height(c);
            p = c;
        }
        void RotateLeft(Node*&c){
            Node* p = c->right;
            Node* t2 = p->left;
            p->left = c;
            c->right = t2;
            c->height = height(c);
            p->height = height(p);
            c = p;
        }
        void Preorder(Node*&root){
            if(root == NULL) {
                return;
            }
            cout << root->data << " ";
            Preorder(root->left);
            Preorder(root->right);
        }
};  
int main(){
    Avl avlTree(10);
    avlTree.insert(avlTree.root, 20); // Insert 20
    avlTree.insert(avlTree.root, 30); // Insert 30 (this should trigger rotations)
    avlTree.insert(avlTree.root, 40); // Insert 40
    avlTree.insert(avlTree.root, 50); // Insert 50
    avlTree.insert(avlTree.root, 25); // Insert 25 (to test more rotations)
    avlTree.Delete(avlTree.root , 30);
    avlTree.Preorder(avlTree.root);
    return 0;
}