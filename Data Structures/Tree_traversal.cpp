#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

void inorder(node *root)
{
    if (root != nullptr)
    {
        inorder(root->left);
        cout << root->data << "-> ";
        inorder(root->right);
    }
    cout << endl;
}

void postorder(node *root)
{
    if (root != nullptr)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << "-> ";
    }
    cout << endl;
}

void preorder(node *root)
{
    if (root != nullptr)
    {
        cout << root->data << "-> ";
        preorder(root->left);
        preorder(root->right);
    }
    cout << endl;
}

node *create_node(int data)
{
    node *Node = new node;
    Node->data = data;
    Node->left = Node->right = nullptr;
    return Node;
}

node *insert_node(node *root, int data)
{
    if (root == nullptr)
        return create_node(data);
    if (data > root->data)
    {
        root->right = insert_node(root->right, data);
    }
    else
    {
        root->left = insert_node(root->left, data);
    }
    return root;
}

int main()
{
    node *root = nullptr;
    int n;
    cout << "Enter number of elements to be entered: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> n;
        root = insert_node(root, n);
    }
    inorder(root);
    postorder(root);
    preorder(root);
}