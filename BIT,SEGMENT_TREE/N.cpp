#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 10;
string s; int n,m;
template<typename T>
struct Segment_tree
{
    int n;
    vector<int> f, lazy;
    Segment_tree (int _n)
    {
        this->n = _n;
        f.resize(4 * n + 1, 0);
        lazy.resize(4 * n + 1, -1);
    }
    void down(int id, int l, int r)
    {
        if(lazy[id] != -1)
        {
            int m = (l + r) >> 1;
            // update node con
            f[id << 1] = lazy[id] * (m - l + 1);
            f[id << 1 | 1] = lazy[id] * (r - m);
            // update cay lazy
            lazy[id << 1] = lazy[id];
            lazy[id << 1 | 1] = lazy[id];
            lazy[id] = -1;
        }
    }
    void up(int id, int l , int r, int u,int v, T val)
    {
        if(v < l || r < u) return;
        if(u <= l && r <= v)
        {
            f[id] = val * (r - l + 1);
            lazy[id] = val;
            return;
        }
        int m = ( l + r) >> 1;
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
        int m = (l + r) >> 1;
        down(id, l ,r);
        T get1 = get(id << 1, l ,m, u, v);
        T get2 = get(id << 1 | 1, m + 1, r, u, v);
        return (T)(get1 + get2);
    }
};
signed main()
{
    int q;
    cin>>n>>q>>s;
    int n = s.size();
    s = " " + s;
    vector<Segment_tree<int>> seg(26, (n));
    for(int i = 1; i <=n ; i++)
    {
        seg[s[i] - 'a'].up(1,1,n,i,i,1);
    }
    while(q--)
    {
        int type, l, r;
        cin>>l>>r>> type;
        int cur = 0;
        for(int c = 0 ; c < 26; c++)
        {
            int cnt = seg[c].get(1,1,n,l,r);
            seg[c].up(1,1,n,l,r,0);
            if(type)
            {
                seg[c].up(1,1,n,l + cur, l + cur + cnt - 1, 1);
            }
            else
            {
                seg[c].up(1,1,n,r - cur - cnt + 1, r - cur, 1);
            }
            cur += cnt;
        }
    }
    for(int i = 1; i <= n; i++)
    {
        for(int c = 0; c < 26 ; c++)
        {
            if(seg[c].get(1,1,n,i,i))
            {
                cout << char(c + 'a');
                break;
            }
        }
    }
}
