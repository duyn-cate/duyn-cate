/// code : Truong_Nguyen_Duy 
/// code and solution
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 10;
const int mod = 1e9 + 7;

int a[N];

struct node {
    int sum, check_lazy, lazyA, lazyB, lazyC;
    node() : sum(0), lazyA(0), lazyB(1), lazyC(0), check_lazy(false) {}
};

namespace SegmentTree
{
    node t[N * 4];
    int bpow(int a, int b)
    {
        int res = 1;
        while (b)
        {
            if (b & 1) res = res * a % mod;
            a = a * a % mod;
            b >>= 1;
        }
        return res;
    }
    void down(int id, int l, int r)
    {
        // lazy cho truy van 3
        if(t[id].check_lazy)
        {
            t[id].sum = (1LL * t[id].lazyC * (r - l + 1)) % mod;

            if(l != r)
            {
                t[id << 1].check_lazy = t[id << 1 | 1].check_lazy = true;
                t[id << 1].lazyA = t[id << 1 | 1].lazyA = 0;
                t[id << 1].lazyB = t[id << 1 | 1].lazyB = 1;
                t[id << 1].lazyC = t[id << 1 | 1].lazyC = t[id].lazyC;
            }
            t[id].check_lazy = false;
            t[id].lazyC = 0;
        }
        // lazy cho truy van 1 va 2
        if(t[id].lazyA != 0 || t[id].lazyB != 1)
        {
            /*
            cap nhat lazy cho ca ba truy van nhu sau : 
            Neu A != 0 && B == 1:
                sum = sum + x (voi x = (r - l + 1));
            Neu A == 0 && B != 1
                sum = sum * x (voi x = x * i (i : l->r));
            */
            t[id].sum = (t[id].sum * t[id].lazyB % mod + t[id].lazyA * (r - l + 1) % mod) % mod;
            if(l != r)
            {
                t[id << 1].lazyB = (t[id << 1].lazyB * t[id].lazyB % mod) % mod;
                t[id << 1 | 1].lazyB = (t[id << 1 | 1].lazyB * t[id].lazyB % mod) % mod;

                t[id << 1].lazyA = (t[id << 1].lazyA * t[id].lazyB % mod + t[id].lazyA) % mod;
                t[id << 1 | 1].lazyA = (t[id << 1 | 1].lazyA * t[id].lazyB % mod + t[id].lazyA) % mod;
            }
            t[id].lazyA = 0;
            t[id].lazyB = 1;
        }
    }
    // truy van loai 1 va 2
    void up(int id, int l, int r, int u, int v, int A, int B)
    {
        down(id, l, r);
        if(v < l | r < u) return;
        if(u <= l && r <= v)
        {
            t[id].lazyA = A;
            t[id].lazyB = B;
            down(id, l, r);
            return;
        }
        int m = l + r >> 1;
        up(id << 1, l, m, u, v, A, B);
        up(id << 1 | 1, m + 1, r, u, v, A, B);
        t[id].sum = (t[id << 1].sum + t[id << 1 | 1].sum) % mod;
    }
    // truy van loai 3
    void up1(int id, int l, int r, int u, int v, int val)
    {
        down(id, l, r);
        if(v < l || r < u) return;
        if(u <= l && r <= v)
        {
            t[id].check_lazy = true;
            t[id].lazyC = val;
            down(id, l, r);
            return;
        }
        int m = l + r >> 1;
        up1(id << 1, l , m, u, v, val);
        up1(id << 1 | 1, m + 1, r, u, v, val);
        t[id].sum = (t[id << 1].sum + t[id << 1 | 1].sum) % mod;
    }
    // tinh ham tong
    int get(int id, int l, int r, int u, int v)
    {
        down(id, l, r);
        if(v < l || r < u) return 0;
        if( u <= l && r <= v)
        {
            return t[id].sum;
        }
        int m = l + r >> 1;
        down(id, l, r);
        return (get(id << 1, l, m, u, v) + get(id << 1 | 1, m + 1, r, u, v)) % mod;
    }
}

using namespace SegmentTree;

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    // gia tri ban dau deu la tong cac a[i] lan
    for(int i = 1 ; i <= n ; i++)
    {
        up(1,1,n,i,i,a[i],1);
    }
    //  tra loi truy van
    while (m--)
    {
        int type, l, r;
        cin >> type >> l >> r;
        if(type == 1)
        {
            int x; cin>>x;
            up(1,1,n,l,r,x,1);
        }
        else if(type == 2)
        {
            int x; cin>>x;
            up(1,1,n,l,r,0,x);
        }
        else if(type == 3)
        {
            int x; cin>>x;
            up1(1,1,n,l,r,x);
        }
        else
        {
            cout << get(1, 1, n, l, r) << "\n";
        }
    }

    return 0;
}
