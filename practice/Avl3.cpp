#include <iostream>
#include <queue>
using namespace std;
class Node{
    public:
        int data,height;
        Node* left;
        Node* right;
        Node(int data){
            this->data = data;
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
        int Height(Node*&root){
            if(root == NULL){
                return 0;
            }
            return 1 + max(Height(root->left) , Height(root->right));
        }
        void insert(Node*&root , int data){
            if(root == NULL){
                root = new Node(data);
            }
            else if(data > root->data){
                insert(root->right , data);
            }
            else if(data < root->data){
                insert(root->left , data);
            }
            root->height = Height(root);
            Rotate(root);
        }
        void Rotate(Node*&root){
            if(Height(root->left) - Height(root->right) > 1){
                if(Height(root->left->left) >= Height(root->left->right)){
                    RoateRight(root);
                }else{
                    RotateLeft(root->left);
                    RoateRight(root);
                }
            }else if(Height(root->right) - Height(root->left) > 1){
                if(Height(root->right->right) >= Height(root->right->left)){
                    RotateLeft(root);
                }else {
                    RoateRight(root->right);
                    RotateLeft(root);
                }
            }
        }
        void RoateRight(Node*& root){
            Node*c = root->left;
            Node*t2 = c->right;
            c->right = root;
            root->left = t2;
            c->height = Height(c);
            root->height = Height(root);
            root = c;
        }
        void RotateLeft(Node*&root){
            Node*p = root->right;
            Node*t2 = p->left;
            p->left = root;
            root->right = t2;
            root = p;
        }
        void Preorder(Node*& root){
            if(root == NULL){
                return;
            }
            cout << root->data << " ";
            Preorder(root->left);
            Preorder(root->right);
        }
        void Traversal(){
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
};
int main(){
    Avl avlTree(10);
    avlTree.insert(avlTree.root, 20); // Insert 20
    avlTree.insert(avlTree.root, 30); // Insert 30 (this should trigger rotations)
    avlTree.insert(avlTree.root, 40); // Insert 40
    avlTree.insert(avlTree.root, 50); // Insert 50
    avlTree.insert(avlTree.root, 25); // Insert 25 (to test more rotations)
    avlTree.Preorder(avlTree.root);
    cout << endl;
    avlTree.Traversal();
    return 0;
}