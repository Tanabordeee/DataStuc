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
        void insert(Node*& root , int data){
            if(root == NULL) {
                root = new Node(data);
            }
            if(data > root->data){
                insert(root->right , data);
            }
            else if(data < root->data){
                insert(root->left , data);
            }
        }
        Node* remove(Node*& root , int data){
            if(root == NULL){
                return root;
            }
            if(data > root->data){
                root->right = remove(root->right , data);
            }
            else if(data < root->data){
                root->left = remove(root->left , data);
            }
            else if(data == root->data){
                if(root->left == NULL && root->right == NULL){
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
                }else if(root->left != NULL && root->right != NULL){
                    Node* sc = Successor(root->right);
                    root->data = sc->data;
                    root->right = remove(root->right , sc->data);
                }
            }
            return root;
        }
        Node* Successor(Node*&root){
            if(root->left == NULL){
                return root;
            }
            return Successor(root->left);
        }
        void PreOrder(Node*& root){
            if(root == NULL){
                return;
            }
            cout << root->data << " ";
            PreOrder(root->left);
            PreOrder(root->right);
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
        void PostOrder(Node*& root){
            if(root == NULL){
                return;
            }
            PreOrder(root->left);
            PreOrder(root->right);
            cout << root->data << " ";
        }
        void InOrder(Node*& root){
            if(root == NULL){
                return;
            }
            PreOrder(root->left);
            cout << root->data << " ";
            PreOrder(root->right);
        }
};
int main(){
        // Create a Tree with root node 50
    Tree t(50);

    // Insert nodes
    t.insert(t.root, 30);
    t.insert(t.root, 70);
    t.insert(t.root, 20);
    t.insert(t.root, 40);
    t.insert(t.root, 60);
    t.insert(t.root, 80);

    // Preorder traversal after insertion
    cout << "PreOrder Traversal after insertion: ";
    t.PreOrder(t.root);  // Expected output: 50 30 20 40 70 60 80
    cout << endl;

    // Remove node 20 (leaf)
    t.remove(t.root, 20);
    cout << "PreOrder Traversal after deleting 20: ";
    t.PreOrder(t.root);  // Expected output: 50 30 40 70 60 80
    cout << endl;

    // Remove node 30 (node with one child)
    t.remove(t.root, 30);
    cout << "PreOrder Traversal after deleting 30: ";
    t.PostOrder(t.root); 
    cout << endl;

    // Remove node 50 (node with two children)
    t.remove(t.root, 50);
    cout << "PreOrder Traversal after deleting 50: ";
    t.InOrder(t.root);  
    cout << endl;
    cout << "Traversal after deleting 50: ";
    t.Traversal();
    cout << endl;
    return 0;
}