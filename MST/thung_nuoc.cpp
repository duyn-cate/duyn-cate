#include <bits/stdc++.h>

using namespace std;
const int N = 2e5 + 10;
int c[N];
struct DSU
{
    int n;
    vector<int> pa, sz, color;
    DSU (int n)
    {
        this->n = n;
        pa.resize(n + 1);
        sz.resize(n + 1);
        color.resize(n + 1);
        for(int i = 1 ; i <= n ; i++)
        {
            pa[i] = i;
            sz[i] = 1;
            color[i] = c[i];
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

        if(sz[u] < sz[v]) swap(u,v);
        pa[v] = u;
        color[u] += color[v];
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

int main()
{
    int n;
    cin>>n;
    DSU dsu(n);
    while(n--)
    {
        int u,v, type; cin>>u>>v>>type;
        if(type == 1) dsu.Union(u,v);
        else cout << dsu.same_set(u,v) << endl;
    }
}
