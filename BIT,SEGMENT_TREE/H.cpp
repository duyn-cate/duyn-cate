#include <bits/stdc++.h>
#define int long long
using namespace std;
struct node
{
    int prefix, suffix, sum, maxx;
    node() = default;
    node(int _x, int _y, int _z, int _c) : prefix(_x), suffix(_y), sum(_z), maxx(_c) {}
};
#ifndef ONLINE
clockid_t Start = clock();
#endif // ONLINE
const int N = 2e5 + 10;
int a[N];
namespace Segment_tree
{
    node t[N * 4];
    node operator +(const node &l, const node &r)
    {
        node res = node(0,0,0,0);
        res.sum =l.sum + r.sum;
        res.prefix = max(l.prefix, l.sum + r.prefix);
        res.suffix = max(r.suffix, r.sum + l.suffix);
        res.maxx = max({l.maxx, r.maxx, l.suffix + r.prefix});
        return res;
    }
    void build(int id, int l, int r)
    {
        if(l == r)
        {
            t[id] = node(max(0LL,a[l]), max(0LL, a[l]), a[l], max(0LL, a[l]));
            return;
        }
        int m = l + r >> 1;
        build(id << 1, l, m);
        build(id << 1 | 1, m + 1, r);
        t[id] = t[id << 1] + t[id << 1 | 1];
    }
    void up(int id, int l, int r, int pos, int val)
    {
        if(pos < l || pos > r) return;

        if(l == r)
        {
            t[id] = node(max(0LL,val), max(0LL, val), val, max(0LL, val));
            return;
        }
        int m = l + r >> 1;
        up(id << 1, l , m, pos, val);
        up(id << 1 | 1, m + 1, r, pos, val);
        t[id] = t[id << 1] + t[id << 1 | 1];
    }
    node get(int id,int l, int r, int u, int v)
    {
        if(v < l || r < u) return node(0,0,0,0);
        if(u <= l && r <= v)
        {
            return t[id];
        }
        int m = l + r >> 1;
        return get(id << 1, l, m, u, v) + get(id << 1 | 1, m + 1, r, u, v);
    }
}
using namespace Segment_tree;
void fast()
{
    cin.tie(0)->sync_with_stdio(0);
    #ifndef ONLINE
    fprintf(stderr, "%.10fs\n", ((clock() - Start)/CLOCKS_PER_SEC));
    #endif // ONLINE
}
signed main()
{
    fast();
    int n, q; cin>>n>>q;
    for(int i = 1; i <= n; i++)
    {
        cin>>a[i];
    }
    build(1,1,n);
    while(q--)
    {
        int type; cin>>type;
        if(type == 1)
        {
            int pos, val;
            cin>>pos>>val;
            up(1,1,n,pos, val);
        }
        else
        {
            int l , r;
            cin>>l>>r;
            cout<< get(1,1,n,l,r).maxx << "\n";
        }

    }
}
