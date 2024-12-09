#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 10;
int c[N];
map<int, int> color[N];
struct DSU
{
    int n;
    vector<int> pa, sz;

    DSU (int n)
    {
        this->n = n;
        pa.resize(n + 1);
        sz.resize(n + 1);
//        color.resize(n + 1, vector<int> (n + 1));
        for(int i = 1 ; i <= n ; i++)
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
        if(sz[u] < sz[v]) swap(u,v);
        pa[v] = u;
        for(auto [x, cnt] : color[v])
            color[u][x] += cnt;
//        color[v].clear();
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
    cin.tie(0)->sync_with_stdio(0);
    int n,m;
    cin>>n;
    for(int i = 1 ; i <= n ; i++)
    {
        cin>>c[i];
        color[i][c[i]]++;
    }
    DSU dsu(n);
    m = n - 1;
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        dsu.Union(u,v);
    }
    for(int i = 1 ; i <= n ; i++)
    {
        int ans = 0;
        for(auto [x, cnt] : color[i])
        {
            ans += cnt;
        }
        cout << ans << " ";
    }
}
