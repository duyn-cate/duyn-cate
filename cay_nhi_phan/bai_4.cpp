#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll maxn = 1e5+1;
bool visited[maxn];
struct node
{
    int val;
    node *left;
    node *right;
    node(int x)
    {
        val = x;
        left = right = NULL;
    }
};
void make_node(node *root,int u, int v, char c)
{
    if(c == 'L') root->left = new node(v);
    else root->right = new node(v);
}
void insert_node(node *root, int u, int v, char c)
{
    if(root == NULL) return;
    if(root-> val == u)
    {
        make_node(root, u,v,c);
    }
    else
    {
        insert_node(root->left,u,v,c);
        insert_node(root->right,u,v,c);
    }
}
int ans;
int inorder(node *root)
{
    if(root == NULL)
    {
        return 0;
    }
    else if(root->left == NULL && root->left == NULL)
    {
        return 1;
    }
    else
        return inorder(root->left) + inorder(root->right);
}
int main()
{
    node *root = NULL;
    int n; cin>>n;

    for(int i = 0 ; i <n;i++)
    {
        int u,v; char c;
        cin>>u>>v>>c;
        if(root == NULL)
        {

            root = new node(u);
            make_node(root, u,v,c);
        }
        else
        {
            insert_node(root,u,v,c);
        }
    }
    cout << inorder(root)<< endl;;
}
