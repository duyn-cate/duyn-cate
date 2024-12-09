#include <bits/stdc++.h>

using namespace std;
struct node
{
    int u, v, w;
    bool operator <(const node &a)
    {
        return w < a.w;
    }
};
struct DSU
{
    int n;
    vector<int> pa,sz;

    DSU(int size)
    {
        this->n = size;
        pa.resize(n + 1);
        sz.resize(n + 1);
        for(int i = 1 ; i <= n ; i++)
        {
            pa[i] = i;
            sz[i] = 1;
        }
    }
    int get(int u)
    {
        return (u == pa[u] ? u : (pa[u] = get(pa[u])));
    }
    bool Union(int u, int v)
    {
        u = get(u);
        v = get(v);

        if(u == v) return false;

        if(sz[u] < sz[v]) swap(u,v);
        sz[u] += sz[v];
        pa[v] = u;
        return true;
    }
};
const int N = 1001;
int a[N][N];
int main()
{
    int n; cin>>n;
    vector<int> W;
    for(int i = 0 ; i< n ; i++)
    {
        int w; cin>>w;
        W.push_back(w);
    }
    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin>>a[i][j];
        }
    }
    vector<node> adj;
    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = 1 ; j <= i ; j++)
        {
            if(i == j) continue;
            adj.push_back({i,j, a[i][j]});
        }
    }
    for(int i = 1 ; i <= n ; i++)
    {
        adj.push_back({n + 1,i,W[i - 1]});
    }
    sort(adj.begin(), adj.end());
    int x = N;
    DSU b(x);
    int mst = 0;
    for(auto [u,v,w] : adj)
    {
        if(b.Union(u,v))
            mst+= w;
    }
    cout << mst << endl;
}
