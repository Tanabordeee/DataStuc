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
        void insert(int data){
            Node* n = root;
            while(true){
                if(n->data < data && n->left != NULL){
                    n = n->left;
                }
                else if(n->data > data && n->right != NULL){
                    n = n->right;
                }
                else if(n->data < data && n->left == NULL){
                    n->left = new Node(data);
                    break;
                }
                else if(n->data > data && n->right == NULL){
                    n->right = new Node(data);
                    break;
                }
                else{
                    break;
                }
            }
        }
        bool search(int data){
            Node* n = root;
            while(true){
                if(n->data < data && n->left != NULL){
                    n = n->left;
                }
                else if(n->data > data && n->right != NULL){
                    n = n->right;
                }
                else if(n->data == data){
                    return true;
                    break;
                }
                else{
                    return false;
                    break;
                }
            }
        }
        void DeleteNodeChild(Node *n){
            if(n->right->left == NULL){
                int s = n->right->data;
                Delete(s);
                n->data = s;
            }else{
                Node *tn = n->right;
                while (true)
                {
                    if(tn->left == NULL){
                        break;
                    }
                    tn = tn->left;
                }
                int s = tn->data;
                Delete(s);
                n->data = s;
                
            }
        }
        void Delete(int data){
            if(search(data)){
                if(root->data == data && root->left == NULL && root->right == NULL){
                    delete root;
                    return;
                }
                else if(root->data == data && root->left != NULL && root->right == NULL){
                    root = root->left;
                }
                else if(root->data == data && root->left == NULL && root->right != NULL){
                    root = root->right;
                }else if(root->data == data && root->left != NULL && root->right != NULL){
                    DeleteNodeChild(root);
                }else{
                    Node *p = root;
                    while(true){
                        if(p->data > data && p->left != NULL){
                            Node *c = p->left;
                            if(c->data == data){
                                if(c->left == NULL && c->right == NULL){
                                    p->left == NULL;
                                    return;
                                }
                            }
                            else if(c->left == NULL && c->right != NULL){
                                p->left = c->right;
                                return;
                            }
                            else if(c->left != NULL && c->right == NULL){
                                p->left = c->left;
                                return;
                            }
                            else if(c->left != NULL && c->right != NULL){
                                DeleteNodeChild(c);
                                return;
                            }
                            p = p->left;
                        }                            
                        else if(p->data < data && p->right != NULL){
                            Node *c = p->right;
                            if(c->data == data){
                                if(c->left == NULL && c->right == NULL){
                                    p->right = NULL;
                                    return;
                                }
                                else if(c->left == NULL && c->right != NULL){
                                    p->right = c->right;
                                    return;
                                }
                                else if(c->left != NULL && c->right == NULL){
                                    p->right = c->left;
                                    return;
                                }
                                else if(c->left != NULL && c->right != NULL){
                                    DeleteNodeChild(c);
                                    return;
                                }
                            }
                            p = p->right;
                        }
                    }
                }
            }
        }
        void Travesal(){
            queue <Node*> q;
            q.push(root);
            while(!q.empty()){
                Node *c = q.front();
                cout << c->data << " ";
                q.pop();
                if(c->left != NULL){
                    q.push(c->left);
                }else if(c->right != NULL){
                    q.push(c->right);
                }
            }
        }
        void Preorder(Node *root){
            if(root == NULL) return;
            cout << root->data << " ";
            Preorder(root->left);
            Preorder(root->right);
        }
        void Postorder(Node *root){
            if(root == NULL) return;
            Postorder(root->left);
            Postorder(root->right);
            cout << root->data << " ";
        }
        void Inorder(Node *root){
            if(root == NULL) return;
            Inorder(root->left);
            cout << root->data << " ";
            Inorder(root->right);
        }
};
int main(){
    Tree t(1);
    t.insert(2);
    t.insert(3);
    t.insert(4);
    t.insert(5);
    t.insert(6);
    t.insert(7);
    t.Travesal();
    cout << endl;
    t.Postorder(t.root);
        cout << endl;
    t.Preorder(t.root);
     cout << endl;
    t.Inorder(t.root);
    return 0;
}