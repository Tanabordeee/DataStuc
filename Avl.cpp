#include <iostream>
#include <algorithm>
using namespace std;
class Node
{
public:
    int data, height;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
        height = 1;
    }
};
class AVL
{
public:
    // check Height
    int Height(Node *&root)
    {
        if (root == NULL)
        {
            return 0;
        }
        return 1 + max(Height(root->left), Height(root->right));
    }

    // insert ค่าลง TREE
    void insert(Node *&root, int data)
    {
        if (root == NULL)
        {
            root = new Node(data);
            return;
        }
        if (root->data < data)
        {
            insert(root->right, data);
        }
        else if (root->data > data)
        {
            insert(root->left, data);
        }
        root->height = Height(root);
        rotate(root);
    }

    void rotate(Node *&root)
    {
        if (Height(root->left) - Height(root->right) > 1)
        {
            // ซ้ายหนักกว่า
            if (Height(root->left->left) >= Height(root->left->right))
            {
                // left left case
                rightRotate(root);
            }
            else
            {
                // left right case
                leftRotate(root->left);
                rightRotate(root);
            }
        }
        else if (Height(root->left) - Height(root->right) < -1)
        {
            // ขวาหนักกว่า
            if (Height(root->right->right) >= Height(root->right->left))
            {
                // right right case
                leftRotate(root);
            }
            else
            {
                // right left case
                rightRotate(root->right);
                leftRotate(root);
            }
        }
        return;
    }
    void rightRotate(Node *&root)
    {
        Node *c = root->left;
        Node *t = c->right;
        c->right = root;
        root->left = t;
        root->height = max(Height(root->left), Height(root->right)) + 1;
        c->height = max(Height(c->left), Height(c->right)) + 1;
        // update new root
        root = c;
    }
    void leftRotate(Node *&root)
    {
        Node *c = root->right;
        Node *t = c->left;
        c->left = root;
        root->right = t;
        root->height = max(Height(root->left), Height(root->right)) + 1;
        c->height = max(Height(c->left), Height(c->right)) + 1;
        //update new root
        root = c;
    }

    // print preorder
    void preorder(Node *&root)
    {
        if (root == NULL)
        {
            return;
        }
        cout << root->data << endl;
        preorder(root->left);
        preorder(root->right);
    }

    Node *Delete(Node *&root,int data){
        if(root == NULL){ 
            return root;
        }
        else if(data < root->data){ root->left = Delete(root->left , data);}
        else if(data > root->data){ root->right = Delete(root->right , data);}
        else{
            if(root->left == NULL && root->right == NULL){
                delete root;
                root = NULL;
            }else{
                if(root->left != NULL && root->right == NULL){
                    Node *temp = root->left;
                    delete root;
                    root = temp;
                }
                else if(root ->right != NULL && root ->left == NULL){
                    Node *temp = root->right;
                    delete root;
                    root = temp;
                }
                else if(root ->left != NULL && root->right != NULL){
                    Node *temp = Predesser(root->left);
                    root->data = temp->data;
                    root->left = Delete(root->left , temp->data);
                }
            }
        }
        if(root != NULL){
            root->height = Height(root);
            rotate(root);
        }
        return root;
    }
    Node *Predesser(Node *&root){
        if(root->right == NULL) {return root;}
        return Predesser(root->right);
    }
};
int main()
{
    Node *root = NULL;
    AVL avl;
    avl.insert(root , 12);
    avl.insert(root , 8);
    avl.insert(root , 18);
    avl.insert(root , 17);
    avl.insert(root , 11);
    avl.insert(root , 5);
    avl.insert(root , 4);
    avl.Delete(root , 4);
    avl.preorder(root);
    return 0;
}