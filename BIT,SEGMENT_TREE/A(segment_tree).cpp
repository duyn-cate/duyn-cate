#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;
int a[N];
namespace Segment_tree
{
    int t[N * 4];
    void up(int id,int l,int r, int pos , int val)
    {
        if(pos < l || pos > r) return;
        if(l == r)
        {
            t[id] = val;
            return;
        }
        int m = l + r >> 1;
        up(id << 1, l , m , pos, val);
        up(id << 1 | 1, m + 1, r, pos, val);
        t[id] = t[id << 1] + t[id << 1 | 1];
    }
    int get(int id, int l, int r, int u, int v)
    {
        if(v < l || r < u) return 0;
        if(u <= l && r <= v)
        {
            return t[id];
        }
        int m = l + r >> 1;
        return (get(id << 1, l, m, u, v) + get(id << 1 | 1, m + 1, r, u, v));
    }
};
using namespace Segment_tree;
#ifndef ONLINE
clockid_t Start = clock();
#endif // ONLINE
void fast()
{
    cin.tie(0)->sync_with_stdio(0);
    #ifndef ONLINE
    fprintf(stderr, "%.10fs\n", (clock() - Start)/ CLOCKS_PER_SEC);
    #endif // ONLINE
}
signed main()
{
    fast();
    int n,q;
    cin>>n>>q;
    for(int i = 1 ; i <=n ; i++)
    {
        cin>>a[i];
    }
    vector<pair<int, int>> queris[n + 1];
    for(int i = 0 ; i < q; i++)
    {
        int l, r;
        cin>>l>>r;
        queris[r].emplace_back(l,i);
    }
    map<int,int> mp;
    vector<int> v(q);
    for(int r = 1; r <= n ; r++)
    {
        up(1,1,n,mp[a[r]], 0);
        mp[a[r]] = r;
        up(1,1,n, r, 1);
        for(auto [l,i] : queris[r])
        {
            v[i] = get(1,1,n,l,r);
        }
    }
    for(auto it : v) cout << it << endl;
}
