#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 10;
int a[N];
namespace Segment_tree
{
    int t[N * 4], lazy[N * 4];
    void build(int id, int l, int r)
    {
        if(l == r)
        {
            t[id] = a[l];
            return;
        }
        int m = l + r >> 1;
        build(id << 1, l ,m );
        build(id << 1 | 1, m + 1,r);

        t[id] = (t[id << 1] ^ t[id << 1 | 1]);
    }
    void down(int id, int l, int r)
    {
        if(lazy[id] != 0)
        {
            int m = l + r >> 1;

            t[id << 1] ^= lazy[id];
            t[id << 1 | 1] ^= lazy[id];

            lazy[id << 1] ^= lazy[id];
            lazy[id << 1 | 1] ^= lazy[id];

            lazy[id] = 0;
        }
    }
    void up(int id, int l, int r, int pos, int val)
    {
        if(pos < l || pos > r) return;
        if(l == r)
        {
            t[id] = val;
            lazy[id] = val;
            return;
        }
        int m = l + r >> 1;
//        down(id, l, r);
        up(id << 1, l, m,pos, val);
        up(id << 1 | 1, m + 1, r, pos, val);

        t[id] = (t[id << 1] ^ t[id << 1 | 1]);
    }
    int get(int id, int l, int r, int u, int v)
    {
        if(v < l || r < u) return 0;
        if(u <= l && r <= v) return t[id];
        int m = l + r >> 1;
    //        down(id, l, r);
        return (get(id << 1, l, m, u, v) ^ get(id << 1 | 1, m + 1, r, u, v));
    }
}
using namespace Segment_tree;

signed main()
{
//    freopen("out.txt", "r" , stdin);
    int n, q;
    cin>>n>>q;
    for(int i = 1 ; i <= n ; i++)
    {
        cin>>a[i];
    }
    build(1,1,n);
    while(q--)
    {
        int l,r; cin>>l>>r;
        cout <<get(1,1,n,l,r) <<"\n";
    }
}
