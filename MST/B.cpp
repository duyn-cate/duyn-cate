#include <bits/stdc++.h>

using namespace std;
using ll = long long;
template<typename T>
struct DSU
{
    int n;
    vector<int> pa, sz;
    DSU (int size)
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
};
int main()
{
    int n,m; cin>>n;
    DSU<int> dsua(n), dsub(n);
    for(int i = 1 ; i < n; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        if(w == 1) dsua.Union(u,v);
        else dsub.Union(u,v);
    }
    ll ans = 0;
    for(int u = 1 ; u <= n ; u++)
    {
        int zero = dsub.get(u);
        int one = dsua.get(u);

        if(one == u) ans += (1LL * (dsua.sz[one] - 1) * dsua.sz[one]);

        if (zero == u) ans += (1LL * (dsub.sz[zero] - 1) * dsub.sz[zero]);

        ans +=  (1LL * (dsua.sz[one] - 1) * (dsub.sz[zero] - 1));
    }
    cout << ans << endl;

}
