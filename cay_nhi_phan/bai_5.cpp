#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct node
{
    int val;
    node *left;
    node *right;
    node (int x)
    {
        val = x;
        left = right = NULL;
    }
};
void  makeNode(node *root , int u, int v, char c)
{
    if(c== 'L') root->left = new node(v);
    else root->right = new node(v);
}
void insertNode(node *root, int u, int v, char c)
{
    if(root == NULL) return;
    if(root->val == u)
    {
        makeNode(root,u,v,c);
    }
    else
    {
        insertNode(root->left, u,v,c);
        insertNode(root->right,u,v,c);
    }
}
// chieu cao cay nhi phan
int heigh(node *root)
{
    if(root == NULL) return 0;
    int left_1 = heigh(root->left);
    int right_1 = heigh(root->right);
    return (max(right_1,left_1)) + 1;
}
int main()
{
    node *root = NULL;
    int n; cin>>n;
    for(int i = 0 ; i<n;i++)
    {
        int u,v; char c; cin>>u>>v>>c;
        if(root == NULL)
        {
            root = new node(u);
            makeNode(root, u,v,c);
        }
        else
        {
            insertNode(root,u,v,c);
        }
    }
    cout << heigh(root)<< endl;
}
