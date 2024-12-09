#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 10;
struct node
{
    int sum, prefix, suff, maxx;
    node() = default;
    node(int a, int b, int c, int d) : sum(a), prefix(b), suff(c), maxx(d) {}
};
int a[N];
namespace Segment_tree
{
    node t[N * 4];
    node make_node(int ans)
    {
        node res = node();

        res.sum = ans;
        res.maxx = res.suff = res.prefix = max(0LL, ans);

        return res;
    }
    node operator +(const node &l, const node &r)
    {
        node res = make_node(0);

        res.sum  = l.sum + r.sum;
        res.prefix = max(l.prefix, l.sum + r.prefix);
        res.suff = max(r.suff, r.sum + l.suff);
        res.maxx = max({l.maxx, r.maxx, l.suff + r.prefix});

        return res;
    }
    void build(int id, int l, int r)
    {
        if(l == r)
        {
            t[id] = make_node(a[l]);
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
            t[id] = make_node(val);
            return;
        }
        int m = l + r >> 1;
        up(id << 1, l, m, pos, val);
        up(id << 1 | 1, m + 1, r, pos, val);

        t[id] = t[id << 1] + t[id << 1 | 1];
    }
    node get(int id, int l, int r, int u, int v)
    {
        if(v < l || r < u) return make_node(0);
        if(u <= l && r <= v)
        {
            return t[id];
        }
        int m = l + r >> 1;
        node L = get(id << 1, l, m, u,v);
        node R = get(id << 1 | 1, m + 1, r, u,v);

        return (L + R);
    }
}
using namespace Segment_tree;

signed main()
{
    int n,q;
    cin>>n>>q;
    for (int i =1 ; i <= n ; i++)
    {
        cin>>a[i];
    }
    build(1,1,n);
    while(q--)
    {
        int pos, val;
        cin>>pos>>val;
        up(1,1,n,pos,val);
        cout << get(1,1,n,1,n).maxx << endl;
    }
}
