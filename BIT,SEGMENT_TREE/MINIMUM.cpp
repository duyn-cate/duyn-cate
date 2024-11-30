#include<bits/stdc++.h>

using namespace std;

template<typename T>
struct Segment_tree
{
    int n;
    vector<int> f,lazy;
    Segment_tree (int n)
    {
        this->n = n;
        f.resize(4 * n + 5);
        lazy.resize(4 * n + 5, 0);
    }
    void pown(int id, int l, int r)
    {
        if(lazy[id] != 0)
        {
            f[id << 1] += lazy[id];
            f[id << 1 | 1] += lazy[id];

            lazy[id << 1] += lazy[id];
            lazy[id << 1 | 1] += lazy[id];
            lazy[id] = 0;
        }
    }
    void up(int id, int l ,int r, int pos, T val)
    {
        if(pos < l || pos > r) return;
        if(l == r)
        {
            f[id] += val;
            lazy[id] += val;
            return;
        }
        int m = (l + r) / 2;
        pown(id, l,r);
        up(id << 1, l, m, pos, val);
        up(id << 1 | 1, m + 1, r, pos, val);
        f[id] = min(f[id << 1] , f[id << 1 | 1]);
    }
    T get(int id, int l ,int r, int u, int v)
    {
        if(v < l || r < u) return (T) 1e9;
        if(u <= l && r <= v)
        {
            return f[id];
        }
        int m = (l + r) / 2;
        pown(id, l, r);
        return min(get(id << 1, l , m, u, v), get(id << 1 | 1, m + 1, r, u, v));
    }
};
signed main()
{
    int n,q;
    cin>>n>>q;
    Segment_tree<int> seg(n);
    for(int i = 1 ; i <=n ; i++)
    {
        int val;
        cin>>val;
        seg.up(1,1,n,i,val);
    }
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        cout << seg.get(1,1,n,l,r) << "\n";
    }
}
