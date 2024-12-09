#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 3e5 + 10;
const int M = 1e6 + 10;
int n,q;
int a[N], d[M];
#ifndef ONLINE
clockid_t Strat = clock();
#endif // ONLINe
const int INF  = numeric_limits<int>::min();
namespace Segment_tree
{
    int t1[N * 4];
    pair<int,int> t2[N * 4];
    void up(int id , int l, int r, int pos, int val)
    {
        if(pos < l || r < pos) return;
        if(l == r)
        {
            t2[id] = make_pair(val, pos);
            t1[id] = val;
            return;
        }
        int m = (l + r) >> 1;
        up(id << 1,l, m, pos, val);
        up(id << 1 | 1, m + 1, r, pos, val);
        t2[id] = max(t2[id << 1], t2[id << 1 | 1]);
        t1[id] = t1[id << 1] + t1[id << 1 | 1];
    }
    pair<int, int> get_id(int id, int l ,int r, int u, int v)
    {
        if(v < l || r < u) return make_pair(0,0);
        if(u <= l && r <=v)
        {
            return t2[id];
        }
        int m = l + r >> 1;
        return max(get_id(id << 1,l ,m, u, v), get_id(id << 1 | 1, m + 1, r, u, v));
    }
    int get_sum(int id, int l, int r, int u, int v)
    {
        if(v < l  || r < u) return 0;
        if(u <= l & r <= v)
            return t1[id];
        int m = (l + r) >> 1;
        return (get_sum(id << 1, l, m, u, v) + get_sum(id << 1 | 1, m + 1, r, u, v));
    }
};
using namespace Segment_tree;
void fast()
{
    cin.tie(0)->sync_with_stdio(0);
    #ifndef ONLINE
    fprintf(stderr,"%.10fs\n",(clock() - Strat)/ CLOCKS_PER_SEC);
    #endif // ONLINE
}
signed main()
{
    fast();
    for(int i = 1 ; i < M ; i++)
    {
        for(int j = i; j < M ; j+=i)
            d[j]++;
    }
    cin>>n>>q;
    for(int i = 1 ; i <=n ; i++)
    {
        cin>>a[i];
        up(1,1,n,i,a[i]);
    }
    while(q--)
    {
        int type, l,r;
        cin>>type>>l>>r;
        if(type == 1)
        {
            vector<pair<int,int>> save;
            while(true)
            {
                auto [v, id] = get_id(1,1,n,l,r);
                if(v <= 2) break;
                up(1,1,n,id,INF);
                save.emplace_back(v, id);
            }
            for(auto [v,id] : save)
            {
                up(1,1,n,id, d[v]);
            }
        }
        else cout << get_sum(1,1,n,l,r) << "\n";
    }

}
