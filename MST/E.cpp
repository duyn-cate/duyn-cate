#include <bits/stdc++.h>


using namespace std;
using ll = long long;
const int N = 1e5 + 10;
int p[N];
struct DSU
{
    int n;
    vector<int> pa,sz;

    DSU (int u)
    {
        this->n = u;
        pa.resize(n + 1);
        sz.resize(n + 1);

        for(int i = 1; i <= n ; i++)
        {
            pa[i] = i;
            sz[i] = 1;
        }
    }
    int get(int u)
    {
        return (u == pa[u] ? u : pa[u] = get(pa[u]));
    }
    bool Union(int u, int v)
    {
        u = get(u);
        v = get(v);

        if(u == v) return false;

        if(sz[u] < sz[v])swap(u,v);

        pa[v] = u;
        sz[u] += sz[v];
        return true;
    }
    bool same_set(int u, int v)
    {
        u = get(u);
        v = get(v);
        return (u == v);
    }
};
struct node
{
    int u,v;
    ll w;
};
int main()
{
    int n,m; cin>>n>>m;
    ll maxW = 0;
    for(int i = 1 ; i <= n ; i++)
    {
        cin>>p[i];
    }
    vector<node> adj;
    for(int i = 0 ; i < m ; i++)
    {
        int u, v;
        ll w;
        cin>>u>>v>>w;
        adj.push_back({u, v, w});
        maxW = max(maxW, w);
    }
//    sort(adj.begin(), adj.end());
    int l = 1, r = maxW + 1;
    ll ans = -1;
    while(l <= r)
    {
        DSU dsu(n);
        int x = (l + r) / 2;
        for(auto [u, v, w] : adj)
        {
            if(w >= x)
            {
                dsu.Union(u, v);
            }
        }
        bool found  = true;
        for(int i = 1 ; i <= n ; i++)
        {
//            int U = dsu.get(u);
//            int V = dsu.get(v);
            if(dsu.same_set(i,p[i]) == false)
            {
                found = false;
                break;
            }
        }
        if(found)
        {
            l = x + 1;
            ans = x;
        }
        else
        {
            r = x - 1;
        }
    }
    cout << (ans == (maxW + 1) ? -1 : ans) << endl;

}
