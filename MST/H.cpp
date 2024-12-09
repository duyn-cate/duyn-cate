#include <bits/stdc++.h>
#define int int64_t

using namespace std;
const int mod = 998244353;
struct DSU
{
    int n;
    vector<int> pa, sz;

    DSU (int n)
    {
        this->n = n;
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
        return (u == pa[u] ? u : pa[u] = get(pa[u]));
    }
    bool Union(int u, int v)
    {
        u = get(u);
        v = get(v);
        if(u == v) return false;
        if(sz[u] < sz[v]) swap(u,v);
        pa[v] = u;
        sz[u] += (sz[v] % mod);
        sz[u] %= mod;
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
    int u,v, w;
    bool operator <(const node& a)
    {
        return w < a.w;
    }
};

int bpow(int a, int b)
{
    int ans = 1;
    while(b)
    {
        if(b & 1) ans = (1LL * ans * a) % mod;
        a = (1LL * a * a) % mod;
        b >>= 1;
    }
    return ans;
}
void so()
{
    int n, S;
    cin>>n>>S;
    vector<node> adj;
    for(int i = 1 ; i < n ; i++)
    {
        int u, v,w;
        cin>>u>>v>>w;
        adj.push_back({u,v,w});
    }
    DSU dsu(n);
    sort(adj.begin(), adj.end());
    int mst = 1;
    for(auto [u,v,w] : adj)
    {
        int su = dsu.sz[dsu.get(u)];
        int sv = dsu.sz[dsu.get(v)];

        mst = (1LL * mst * bpow((S - w + 1),(su * sv - 1))) % mod;
        dsu.Union(u,v);
    }
    cout << mst << endl;
}
signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t;cin>>t;
    while(t--)
    {
        so();
    }
}

