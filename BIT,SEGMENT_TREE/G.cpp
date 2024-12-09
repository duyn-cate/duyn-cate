#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 10;
string a;
#ifndef ONLINE
clockid_t Start = clock();
#endif
void fast()
{
    cin.tie(0)->sync_with_stdio(0);
    #ifndef ONLINE
    fprintf(stderr, "%.10fs\n", (clock() - Start) / CLOCKS_PER_SEC);
    #endif // ONLINE
}
struct node
{
    int x, y,z;
    node() = default;
    node(int _x, int _y, int _z) : x(_x), y(_y), z(_z) {}
};
node t[N * 4];
namespace Segment_tree
{
    node operator +(const node &l,const node &r)
    {
        node res = node(0,0,0);
        int tmp = min(l.x,r.y);
        res.z = l.z + r.z + tmp * 2;
        res.x = l.x + r.x - tmp;
        res.y = l.y + r.y - tmp;
        return res;
     }
    void build(int id, int l, int r)
    {
        if(l == r)
        {
            t[id] = node(a[l] == '(', a[l] == ')', 0);
            return;
        }
        int m = l + r >> 1;
        build(id << 1, l, m);
        build(id << 1 | 1, m + 1, r);
        t[id] = t[id << 1] + t[id << 1 | 1];
    }
    node get(int id, int l, int r, int u, int v)
    {
        if(v < l || r < u) return node(0,0,0);
        if(u <= l && r <= v) return t[id];
        int m = l + r >> 1;
        return get(id << 1, l, m, u, v) + get(id << 1 | 1, m + 1, r, u, v);
    }
}
using namespace Segment_tree;

signed main()
{
    fast();
    cin>>a;
    int n = a.size();
    a = " " + a;
    build(1,1,n);
    int q;
    cin>>q;
    while(q--)
    {
        int l, r;
        cin>>l>>r;
        cout << get(1,1,n,l,r).z << "\n";
    }
}
