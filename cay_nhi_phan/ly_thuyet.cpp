#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct node
{
    int val;
    node *left; // luu dia chi cua node con ben trai
    node *right;
    //constructor
    node(int x)
    {
        val = x;
        left = right = NULL;
    }
};

//3 6 R makeRoot(root, 3, 6, R)
void makeRoot(node *root, int u, int v, char c)
{
    if(c == 'L') root->left = new node(v);
    else root->right = new node(v);
}

void insertNode(node *root, int u, int v, char c)
{
    if(root == NULL) return;
    if(root->val == u)
    {
        makeRoot(root, u, v, c);
    }
    else
    {
        insertNode(root->left, u, v, c);
        insertNode(root->right, u, v, c);
    }
}
void inorder(node *root)
{
    if(root != NULL)
    {
        inorder(root ->left);
        cout << root->val << " ";
        inorder(root -> right);
    }
}
int main()
{
    node *root = NULL;
    int n; cin >> n;
    for(int i = 1; i <= n; i++)
    {
        int u, v; char c;
        cin >> u >> v >> c;
        if(root == NULL)
        {
            root = new node(u);
            makeRoot(root, u, v, c);
        }
        else
        {
            insertNode(root, u, v, c);
        }
    }
    inorder(root);
}
