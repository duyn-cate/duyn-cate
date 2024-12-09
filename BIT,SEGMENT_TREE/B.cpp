#include <bits/stdc++.h>


using namespace std;
const int N = 2e5 + 10;
int a[N];
#ifndef ONLINE
clockid_t Start = clock();
#endif // ONLINE
void fast()
{
    cin.tie(0)->sync_with_stdio(0);
    #ifndef ONLINE
    fprintf(stderr,"%.10fs\n",(double)(clock() - Start)/ CLOCKS_PER_SEC);
    #endif // ONLINE
}
template<typename T>
struct Segment_tree
{
    int n;
    vector<int> f;
    set<int> se[N];
    T mege(T x, T y)
    {
        return (x + y);
    }
    Segment_tree (int x)
    {
        this->n = x;
        f.resize(4 * n + 1);
        //a.resize(n + 1);
    }
    void build(int id, int l, int r)
    {
        if(l == r)
        {
            f[id] = a[l];
            se[id].insert(a[l]);
            return;
        }
        int m = (l + r) / 2;
        build(id << 1, l , m);
        build(id << 1 | 1, m + 1, r);
        f[id] = mege(f[id << 1], f[id << 1 | 1]);
        se[id << 1].insert(f[id]);
        se[id << 1 | 1].insert(f[id]);
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
        if(l == r)
        {
            T cnt = 0;
            for(set<int>::iterator it = se.lower_bound(u); it != se.upper_bound(v); it++)
            {
                cnt++;
            }
            return cnt;
        }
        int m = (l + r) / 2;
        return mege(get(id << 1, l, m,u,v), get(id << 1 | 1, m + 1, r,u,v));
    }
};
signed main()
{

    fast();
    int n,q;
    cin>>n>>q;
    Segment_tree<int> seg(n);
    for(int i = 1; i <= n ; i++)
    {
        cin>>a[i];
    }
    seg.build(1,1,n);
    while(q--)
    {
        char type;
        cin>>type;
        if(type == '!')
        {
            int pos, val;
            cin>>pos>>val;
            seg.up(1,1,n,pos,val);
        }
        else
        {
            int u,v;
            cin>>u>>v;
            cout << seg.get(1,1,n,u,v) << endl;
        }
    }
}


