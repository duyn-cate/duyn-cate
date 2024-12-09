#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 10;
int p[N];
template<typename T>
struct Segment_tree
{
    vector<int> t;
    vector<int> a;
    Segment_tree (int n)
    {
        a.resize(n + 10, 0);
        t.resize(4 * n + 10, 0);
    }
    T mege(T a, T b)
    {
        return min(a, b);
    }
    void build(int id , int l, int r)
    {
        if(l == r)
        {
            t[id] = a[l];
            return;
        }
        int m = l + r >> 1;
        build(id << 1, l, m);
        build(id << 1 | 1, m + 1, r);

        t[id] = mege(t[id << 1], t[id << 1 | 1]);
    }
    void up(int id, int l, int r, int pos, T val)
    {
        if(pos < l || pos > r)
            return;
        if(l == r)
        {
            t[id] = val;
            return;
        }
        int m = l + r >> 1;
        up(id << 1, l, m, pos, val);
        up(id << 1 | 1, m + 1, r, pos ,val);

        t[id] = mege(t[id << 1], t[id << 1 | 1]);
    }
    T get(int id, int l, int r, int u, int v)
    {
        if(v < l || r < u) return numeric_limits<T>::max();
        if(u <=l && r <= v)
        {
            return t[id];
        }
        int m = l + r >> 1;
        return mege(get(id << 1, l, m, u, v), get(id << 1 | 1, m + 1, r, u, v));
    }
};

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0)->sync_with_stdio(0);

    int n,q;
    cin>>n>>q;
    for(int i = 1; i <= n ; i++)
    {
        cin>>p[i];
    }
    Segment_tree<int> segU(n);
    Segment_tree <int> segD(n);
    for(int i = 1; i <= n ; i++)
    {
        segD.a[i] = p[i] + i;
        segU.a[i] = p[i] - i;
    }
    segD.build(1,1,n);
    segU.build(1,1,n);

    while(q--)
    {
        int type; cin>>type;
        if(type == 1)
        {
            int pos, val;
            cin>>pos>> val;
            segD.up(1,1,n,pos, val + pos);
            segU.up(1,1,n,pos, val - pos);
        }
        else
        {
            int k; cin>>k;
            int cnt = segU.get(1,1,n,1,k) + k;
            int cnt1 = segD.get(1,1,n,k,n) - k;
            cout << min(cnt, cnt1) << endl;
        }
    }
}
