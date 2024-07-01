// duyet xoan oc @
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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
void make_node(node *root, int u, int v, char c)
{
    if(c == 'L') root->left = new node(v);
    else root->right = new node(v);
}
void insert_node(node *root , int u, int v, char c)
{
    if(root == NULL)
        return;
   if(root->val == u)
   {
       make_node(root, u,v ,c);
   }
   else
   {
       insert_node(root->left, u,v,c);
       insert_node(root->right, u,v,c);
   }
}
void inorder(node* root)
{
    if(root == NULL)
    return;
    stack<node*> st1;
    stack<node*> st2;
    st1.push(root);
    while(!st1.empty()|| !st2.empty())
    {
        while(!st1.empty())
        {
        node* ans = st1.top();
        st1.pop();
        cout << ans->val<<" ";
        if(ans->right)
        {
            st2.push(ans->right);
        }
        if(ans->left)
            st2.push(ans->left);

        }
        while(!st2.empty())
        {
            node* res = st2.top();
            st2.pop();
            cout  << res->val << " ";
            if(res->left)
                st1.push(res->left);
            if(res->right)
                st1.push(res->right);
        }
    }
}
int main()
{
    node* root = NULL;
    int n; cin>>n;
    for(int i = 0 ; i<n;i++)
    {
        int u,v; char c;
        cin>>u>>v>>c;
        if(root== NULL)
        {
            root = new node(u);
            make_node(root, u,v ,c);
        }
        else
        {
            insert_node(root , u,v,c);
        }
    }
    inorder(root);
}
