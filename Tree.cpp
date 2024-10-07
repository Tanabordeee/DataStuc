#include <iostream>
#include <queue>
using namespace std;
class Node{
    public:
        Node *left;
        Node *right;
        int data;
        Node(int data){
            this->data = data;
            left = NULL;
            right = NULL;
        }
};
class Tree{
    public:
        Node *root;
        Tree(int data){
            root = new Node(data);
        }
        void insert(Node *&root , int data){
            if(root == NULL){
                root = new Node(data);
            }
            if(data > root->data){
                insert(root->right , data);
            }else if(data < root->data){
                insert(root->left , data);
            }
        }
        void preorder(Node *&root){
            if(root == NULL){
                return;
            }
            cout << root->data << endl;
            preorder(root->left); 
            preorder(root->right);
        }
        void postorder(Node *&root){
            if(root == NULL){
                return;
            }
            postorder(root->left);
            postorder(root->right);
            cout << root->data << endl;
        }
        void inorder(Node *&root){
            if(root == NULL){
                return;
            }
            inorder(root->left);
            cout << root->data << endl;
            inorder(root->right);
        }
        void BFS(){
            queue<Node*> bfs;
            bfs.push(root);
            while(!bfs.empty()){
                Node *temp = bfs.front();
                bfs.pop();
                cout << temp->data << endl;
                if(temp->left != NULL){
                    bfs.push(temp->left);
                }
                if(temp->right != NULL){
                    bfs.push(temp->right);
                }
            }
        }
        Node* Findmin(Node *&root){
            if(root->right == NULL) return root;
            return Findmin(root->right);
        }
        Node* Delete(Node *&root , int data){
            if(root == NULL){
                return root;
            }else if(data < root->data){
                root->left = Delete(root->left , data);
            }else if(data > root->data){
                root->right = Delete(root->right , data);
            }
            else{
                // leaf node
                if(root->left == NULL && root->right == NULL){
                    delete root;
                    root = NULL;
                }
                // one node
                else if(root->left == NULL){
                    Node *temp = root;
                    root = root->right;
                    delete temp;
                }
                else if(root->right == NULL){
                    Node *temp = root;
                    root = root->left;
                    delete temp;
                }else{
                    Node *temp = Findmin(root->left);
                    root->data = temp->data;
                    root->left = Delete(root->left, temp->data);
                }
            }
            return root;
        }
};
int main(){
    Tree *tree = new Tree(5);
    tree->insert(tree->root , 3);
    tree->insert(tree->root , 9);
    tree->insert(tree->root , 4);
    tree->insert(tree->root , 7);
    tree->insert(tree->root , 12);
    tree->insert(tree->root , 6);
    tree->insert(tree->root , 8);
    tree->Delete(tree->root , 9);
    tree->preorder(tree->root);
    cout << "---------------END-----------------" << endl;
    tree->postorder(tree->root);
    cout << "---------------END-----------------" << endl;
    tree->inorder(tree->root);
    cout << "---------------END-----------------" << endl;
    tree->BFS();
    return 0;
}