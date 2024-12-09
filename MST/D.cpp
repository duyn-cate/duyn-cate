// knapstack + DSU

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1e3 + 5;
int w[N], b[N];
template<typename T>
struct DSU
{
    int n;
    vector<int> pa, sz;
    vector<int> sumW, sumB;
    DSU (int size)
    {
        this->n = size;
        pa.resize(n + 1);
        sz.resize(n + 1);
        sumB.resize(n + 1);
        sumW.resize(n + 1);
        for(int i = 1 ; i <= n ; i++)
        {
            pa[i] = i;
            sz[i] = 1;
            sumB[i] = b[i];
            sumW[i] = w[i];
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
        sumB[u] += sumB[v];
        sumW[u] += sumW[v];
        return true;
    }
    bool same_get(int u, int v)
    {
        u = get(u);
        v = get(v);

        return (u == v);
    }
};
int main()
{
    int n,m,W;
    cin>>n>>m>>W;
    for(int i = 1 ; i <= n ; i++)
    {
        cin>>w[i];
    }
    for(int i = 1 ; i <=n ; i++)
    {
        cin>>b[i];
    }
    DSU<int> dsu(n);
    vector<int> dp(W + 1);
    dp[0] = 0;
    while(m--)
    {
        int u,v; cin>>u>>v;
        dsu.Union(u,v);
    }
    vector<vector<int>> sets(n + 1);
    for(int i = 1 ; i <= n ; i++)
    {
        int p = dsu.get(i);
        sets[p].push_back(i);
    }
    for(int i = 1;  i<= n ; i++)
    {
        int p = dsu.get(i);
        if(i == p)
        {
            for(int j = W; j > 0; j--)
            {
                if(j >= dsu.sumW[p])
                    dp[j] = max(dp[j], dp[j - dsu.sumW[p]] + dsu.sumB[p]);

                for(auto x : sets[p])
                {
                    if(j >= w[x])
                    {
                        dp[j] = max(dp[j], dp[j - w[x]] + b[x]);
                    }
                }
            }
        }
    }
    cout << dp[W] << endl;
}

