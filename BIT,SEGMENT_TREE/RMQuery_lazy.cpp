#include <bits/stdc++.h>

using namespace std;
const int N = 2e5 + 10;
int a[N];
template<typename T>
struct Segment_tree
{
    int n;
    vector<int> f, lazy;
    Segment_tree (int _n)
    {
        this->n = _n;
        f.resize(4 * n + 5);
        lazy.resize(4 * n + 5, 0);
    }
    void build(int id, int l, int r)
    {
        if(l == r)
        {
            f[id] = a[l];
            return;
        }
        int m = (l + r) / 2;
        build(id << 1, l , m);
        build(id << 1 | 1, m + 1, r);
        f[id] = f[id << 1] + f[id >> 1 | 1];
    }
    void down(int id, int l, int r)
    {
        if(lazy[id] != 0)
        {
            int m = (l + r) / 2;
            // update node con
            f[id << 1] += lazy[id] * (m - l + 1);
            f[id << 1 | 1] += lazy[id] * (r - m);
            // update cay lazy
            lazy[id << 1] += lazy[id];
            lazy[id << 1 | 1] += lazy[id];
            lazy[id] = 0;
        }
    }
    void up(int id, int l , int r, int u,int v, T val)
    {
        if(v < l || r < u) return;
        if(u <= l && r <= v)
        {
            f[id] += val * (r - l + 1);
            lazy[id] += val;
            return;
        }
        int m = ( l + r)/  2;
        down(id, l , r);
        up(id << 1, l , m , u, v, val);
        up(id << 1 | 1, m + 1, r, u, v, val);
        f[id] = f[id << 1] + f[id << 1 | 1];
    }
    T get(int id, int l ,int r, int u , int v)
    {
        if(v < l || r < u) return (T) 0;
        if(u <= l && r <= v)
        {
            return f[id];
        }
        int m = (l + r)/  2;
        down(id, l ,r);
        T get1 = get(id << 1, l ,m, u, v);
        T get2 = get(id << 1 | 1, m + 1, r, u, v);
        return (T)(get1 + get2);
    }
};
signed main()
{
    int n,q;
    cin>>n>>q;
    for(int i =1 ; i<= n ; i++)
    {
        cin>>a[i];
    }
    Segment_tree <int> seg(n);
    seg.build(1,1,n);
    while(q--)
    {
        int type;
        cin>>type;
        if(type == 1)
        {
            int u,v, val;
            cin>>u>>v>>val;
            seg.up(1,1,n,u,v,val);
        }
        else
        {
            int u; cin>>u;
            cout << seg.get(1,1,n,u,u) << "\n";
        }
    }
}
