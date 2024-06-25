#include<bits/stdc++.h>
// thuat toan Kruskal;
using namespace std;
using ll = long long;
const ll maxn = 1e5 + 1;
struct node
{
    int x;
    int y;
    int w;
};
int n,m;
bool visited[maxn];
vector<node> adj[maxn], dscanh;
int parent[maxn], st[maxn];
void init()
{
    for(int i = 1 ; i <=n  ; i++)
    {
        parent[i] = i;
        st[i] = 1;
    }
}
int Find(int u)
{
    if(u == parent[u]) return u;
    return parent[u] = Find(parent[u]);
}
bool Union(int u , int v)
{
    u = Find(u);
    v = Find(v);
    if(u == v) return false;
    if(st[u] < st[v])
    {
        parent[u] = v;
        st[v] += st[u];

    }
    else
    {
        parent[v] = u;
        st[u]+= st[v];
    }
    return true;
}
void Kruskal()
{
    // B1 : sap xep dscanh theo trong so
    sort(dscanh.begin(), dscanh.end(), [](node x, node y)-> bool
         {
             return x.w < y.w;
         });
    //B2 : duyet tung canh
    vector<node> mst;
    ll d = 0;
    for(int i = 0;  i< m ; i++)
    {
        if(mst.size() == n - 1)
        {
            break;
        }
        if(Union(dscanh[i].x, dscanh[i].y))
        {
            mst.push_back(dscanh[i]);
            d+= dscanh[i].w;
        }
    }
    if(mst.size() < n - 1)
    {
        cout << -1;
    }
    else
    {
        cout << d;
    }
}
void nhap()
{
    cin>>n>>m;
    for(int i = 0 ; i<m ; i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        dscanh.push_back({a,b,c});
    }
}
int main()
{
    ios_base::sync_with_stdio();
    cin.tie(nullptr);
    cout.tie(nullptr);
    nhap();
    init();
    Kruskal();
}
