#include <bits/stdc++.h>
#define int int64_t

using namespace std;
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
    int u,v, w;
    bool operator <(const node& a)
    {
        return w < a.w;
    }
};
void so()
{
    int n,p; cin>>n>>p;
    vector<int> a(n + 1);
    for(int i = 1;  i<= n ; i++)
    {
        cin>>a[i];
    }
//    sort(a + 1, a + n + 1);
    vector<int> id(n + 1);
    // danh dau mang tu 1->n;
    iota(id.begin() , id.end(), 0);
//    for(auto it : id) cout << it << " "; cout << endl;
    sort(id.begin(), id.end(), [&](const auto& i, const auto& j)
         {
             return a[i] < a[j];
         });

    int ans = 0;
    DSU dsu(n);
    for(auto& i : id)
    {
        if(i == 0) continue;
        if(a[i] >= p) break;
        int l = i - 1;
        int r = i + 1;
        int g = a[i];
        /* tim kiem ve ben trai thoa man gcd(a[i], a[l]) = a[i]
        thi a[i] vua la gia tri nho nhat vua la gcd thoa man*/
        while(l > 0)
        {
            g = __gcd(g, a[l]);
            if(g != a[i]) break;
            if(!dsu.Union(l, i)) break;
            ans += a[i];
            l--;
        }
        // tuong tu tiep theo ve phai
        g = a[i];
        while(r <= n)
        {
            g = __gcd(g, a[r]);
            if(g != a[i]) break;
            if(!dsu.Union(r, i)) break;
            ans += a[i];
            r++;
        }
    }
    int cnt = 0;
    for(int i = 1 ; i <= n ; i++)
    {
        if(dsu.get(i) == i) cnt++;
    }
    cout << ans  + (cnt - 1) *p << endl;
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
