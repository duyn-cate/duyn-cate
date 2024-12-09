#include <bits/stdc++.h>
#define int long long
using namespace std;
struct node
{
    int sum, cnt, len;
    node() = default;
    node(int a, int b, int c) : sum(a), cnt(b), len(c){}
};
const int N = 1e5 + 10;
const int mod = 1007050321;
int pw[N];
string s;
#ifndef ONLINE
clockid_t Strat = clock();
#endif // ONLINE
namespace SegmentTree
{
    node t[N * 4];
    void init()
    {
        pw[0] = 1;
        for(int i = 1 ; i < N; i++)
        {
            pw[i] = (2LL * pw[i - 1]) % mod;
        }
    }
    void build(int id, int l, int r)
    {
        if(l == r)
        {
            t[id] = node(s[l] - '0', 1, 1);
            return;
        }
        int m = l + r >> 1;
        build(id << 1, l ,m);
        build(id << 1 | 1, m + 1, r);
        t[id].len = t[id << 1].len + t[id << 1 | 1].len;
        t[id].sum = (1LL * t[id << 1].sum * pw[t[id << 1 | 1].cnt]  % mod+ t[id << 1 | 1].sum) % mod;
        t[id].cnt = (t[id << 1].cnt + t[id << 1 | 1].cnt) % mod;
    }
    void up(int id, int l, int r, int pos)
    {
        if(pos< l || r < pos) return;
        t[id].len--;
        if(l == r)
        {
             t[id].sum = t[id].cnt = 0;
             return;
        }
        int m = l + r >> 1;
        up(id << 1, l, m, pos);
        up(id << 1 | 1, m + 1, r, pos);
        t[id].sum = (1LL * t[id << 1].sum * pw[t[id << 1 | 1].cnt]  % mod+ t[id << 1 | 1].sum) % mod;
        t[id].cnt = (t[id << 1].cnt + t[id << 1 | 1].cnt) % mod;
    }

    int Find(int id, int l, int r, int pos)
    {
        if(l == r)
            return l;
        int m = l + r >> 1;
        if(pos <= t[id << 1].len) return Find(id << 1, l, m, pos);
        return Find(id << 1 | 1, m + 1, r, pos - t[id << 1].len);
    }
    node get(int id, int l, int r, int u, int v)
    {
        if(v < l || r < u) return node(0,0,0);
        if(u <= l && r <= v)
            return t[id];
        int m = l  + r >> 1;
        node L = get(id << 1, l, m, u, v), R = get(id << 1 | 1,m + 1, r,u ,v);
        node res;
        res.len = L.len + R.len;
        res.sum = (1LL * L.sum * pw[R.cnt] % mod + R.sum) % mod;
        res.cnt = L.cnt + R.cnt;
        return res;
    }
}
using namespace SegmentTree;
void fast()
{
    cin.tie(0)->sync_with_stdio(0);
    #ifndef ONLINE
    fprintf(stderr, "%.10fs\n", (clock() - Strat) / CLOCKS_PER_SEC);
    #endif // ONLINE
}
signed main()
{
    fast();
    init();
    cin>>s;
    int n = s.size();
    s = " " + s;
    build(1,1,n);
    int q;
    cin>>q;
    while(q--)
    {
        char type;
        cin>>type;
        if(type == '-')
        {
            int pos; cin>>pos;
            int x = Find(1,1,n,pos);
            up(1,1,n,x);
        }
        else
        {
            int u,v;cin>>u>>v;
            int l = Find(1,1,n,u);
            int r = Find(1,1,n,v);
            cout << get(1,1,n,l,r).sum << "\n";
        }
    }
}
