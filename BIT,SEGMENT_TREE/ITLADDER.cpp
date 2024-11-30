#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 10;
const int mod = 1e9 + 7;
struct node
{
    int sum, lazyA, lazyB;
    node() = default;
    node(int x, int y, int z) : sum(x), lazyA(y), lazyB(z) {}

};
namespace Segment_tree
{
    node t[N * 4];
    // lazy segment tree
    void down(int id, int l, int r)
    {
        if(t[id].lazyA || t[id].lazyB)
        {
            int m = l + r >> 1;
            // tinh do dai doan l... r
            int len = r - l + 1;
            // tinh tong tu l...r = 1 + 2 + 3 + ... + r = len * (len - 1) / 2
            t[id].sum = (t[id].sum + 1LL * t[id].lazyA * (len * (len - 1) / 2) % mod + 1LL * t[id].lazyB * len) % mod;
            if(l != r)
            {
                t[id << 1].lazyA = (t[id << 1].lazyA + t[id].lazyA) % mod;
                t[id << 1 | 1].lazyA = (t[id << 1 | 1].lazyA + t[id].lazyA) % mod;

                t[id << 1].lazyB = (t[id << 1].lazyB + t[id].lazyB) % mod;
                // right : cap nhat  doan ve tu l...m
                t[id << 1 | 1].lazyB = (t[id << 1 | 1].lazyB + t[id].lazyB + 1LL * t[id].lazyA * (m - l + 1) % mod ) % mod;


            }
            t[id].lazyA = 0;
            t[id].lazyB = 0;
        }
    }
    void up(int id ,int l, int r, int u, int v, int A, int B)
    {
        down(id, l, r);
        if(v < l || r < u) return;
        if(u <= l && r <= v)
        {
            t[id].lazyA += A % mod;
            t[id].lazyA %= mod;
            // t[id].lazyB = B + A * (i - l) cong thuc cua bai toan
            t[id].lazyB += (B + A * (l - u + mod) % mod) % mod;
            t[id].lazyB %=  mod;
            down(id, l, r);
            return;
        }
        int m = l + r >> 1;
//        down(id, l ,r);
        up(id << 1, l, m, u, v, A, B);
        up(id << 1 | 1, m + 1, r, u, v, A, B);
        t[id].sum = (t[id << 1].sum + t[id << 1 | 1].sum ) % mod;
    }
    int get(int id, int l, int r, int u, int v)
    {
        down(id, l, r);
        if(v < l || r < u) return 0;
        if(u <= l && r <= v)
        {
            return t[id].sum;
        }
        int m = l + r >> 1;

        return (get(id << 1, l, m, u, v) + get(id << 1 | 1, m + 1, r, u, v)) % mod;
    }
}
using namespace Segment_tree;
signed main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin>>n>>q;
    up(1,1,n,1,n,0,0);
    while(q--)
    {
        int type, v, u;
        cin>>type>>u>>v;
        if(type == 1)
        {
            int A,B;
            cin>>A>>B;
            up(1,1,n,u,v,A, B);
        }
        else cout << get(1,1,n,u,v) << "\n";
    }
}

