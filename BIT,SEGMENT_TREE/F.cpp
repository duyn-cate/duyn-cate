#include <bits/stdc++.h>

using namespace std;
const int N = 2e5 + 10;
int p[N];
template<typename T>
struct Segment_tree
{
    int n;
    vector<int> f,a;
    T mege(T x, T y)
    {
        return min(x,y);
    }
    Segment_tree (int x)
    {
        this->n = x;
        f.resize(4 * n + 1);
        a.resize(n + 1);
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
        f[id] = mege(f[id << 1], f[id << 1 | 1]);
    }
    void up(int id, int l, int r, int pos, T val)
    {
        if(pos < l || pos > r) return;
        if(l == r)
        {
            f[id] = val;
            return;
        }
        int m = (l + r) /  2;
        up(id << 1, l, m, pos, val);
        up(id << 1 | 1, m + 1, r, pos, val);
        f[id] = mege(f[id << 1], f[id << 1 | 1]);
    }
    T get(int id, int l, int r, int u, int v)
    {
        if(v < l || r < u) return (T) numeric_limits<T>::max();
        if(u <= l && r <= v)
        {
            return f[id];
        }
        int m = (l + r) / 2;
        return mege(get(id << 1, l, m,u,v), get(id << 1 | 1, m + 1, r,u,v));
    }
};
signed main()
{
    int n,q;
    cin>>n>>q;
    Segment_tree<int> segU(n);
    Segment_tree<int> segD(n);
    for(int i = 1; i <= n ; i++)
    {
        cin>>p[i];
        segU.a[i] = p[i] + i;
        segD.a[i] = p[i] - i;
    }
    segD.build(1,1,n);
    segU.build(1,1,n);
    while(q--)
    {
        int type;
        cin>>type;
        if(type == 1)
        {
            int pos, val;
            cin>>pos>>val;
            segU.up(1,1,n,pos,val + pos);
            segD.up(1,1,n,pos,val - pos);
        }
        else
        {
            int k;
            cin>>k;
            int ans = segD.get(1,1,n,1,k) + k;
            int res = segU.get(1,1,n,k, n) - k;

            cout << min(ans , res) << endl;

        }
    }
}
