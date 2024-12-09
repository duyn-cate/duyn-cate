#include <bits/stdc++.h>

using namespace std;
using ll = long long;
struct DSU
{
    int n;
    vector<int>pa, sz;
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
        return (u == pa[u] ? u : pa[u] = get(pa[u]));
    }
    bool Union(int u, int v)
    {
        u = get(u);
        v = get(v);

        if(u == v) return false;

        if(sz[u] < sz[v]) swap(u,v);
        pa[v] = u;
        sz[u] += sz[v];
        return true;
    }
    bool same_set(int  u, int v)
    {
        u = get(u);
        v = get(v);

        return (u == v);
    }
};
const int N = 2e5 + 10;
ll p[N];
signed main()
{
    int n;
    ll a,b; cin>>n>>a>>b;
    map<ll, int> mp;
    for(int i = 1 ; i <= n ; i++)
    {
        cin>>p[i];
        mp[p[i]] = i;
    }
    vector<int> B(n + 1, 0);
    DSU dsu(n);
    for(int i = 1 ; i <= n ; i++)
    {
        if(mp.count(a - p[i]))
        {
            B[i] |= 1;
            dsu.Union(mp[p[i]],mp[a - p[i]]);
        }
        if(mp.count(b - p[i]))
        {
            B[i] |= 2;
            dsu.Union(mp[p[i]],mp[b - p[i]]);
        }
    }
    vector<int> g(n + 1, 3);
    for(int i = 1 ; i <= n ; i++)
    {
        // 2 & 3 = 2, 3 & 3 = 3, 1 & 3 = 1
        g[dsu.get(i)] &= B[i];
    }
    for(int i = 1 ; i <= n ; i++)
    {
//        cout << g[i] << " " << B[i] << endl;
        if(g[i] == 0)
        {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout <<"YES" << endl;
    for(int i = 1 ; i <= n ; i++)
    {
        int val = g[dsu.get(i)];
        if(val == 3) cout <<0 << " \n"[i == n];
        else cout << (val - 1) << " \n"[i == n];
    }

}
