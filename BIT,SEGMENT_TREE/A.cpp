#include <bits/stdc++.h>
#ifndef ONLINE
clockid_t Strat = clock();
#endif // ONLINE
using namespace std;
const int N = 2e5 + 10;
using T = tuple<int, int, int>;
int a[N];
void fast()
{
    cin.tie(0)->sync_with_stdio(0);
    #ifndef ONLINE
    fprintf(stderr, "%.10fs\n", (clock() - Strat)/ CLOCKS_PER_SEC);
    #endif // ONLINE
}
struct Node
{
    int l ,r , idx;
};
class Fenwick_tree
{
private:
    int n;
    vector<int> bit;
public:
    Fenwick_tree (int _n)
    {
        this->n = _n;
        bit.assign(n + 1,0);
    }
    void up(int x, int val)
    {
        for(int i=  x ; i <=n ; i+= (i & -i))
        {
            bit[i] += val;
        }
    }
    int get(int x)
    {
        int sum = 0;
        for(int i = x; i > 0 ; i-=(i & -i))
        {
            sum += bit[i];
        }
        return sum;
    }
    int query(int l, int r)
    {
        return get(r) - get(l - 1);
    }
};
signed main()
{
    fast();
    int n,q; cin>>n>>q;
    for(int i = 1 ; i <=n ; i++)
        cin>>a[i];
    vector<Node> queris;
    for(int i = 0 ; i < q ; i++)
    {
        int l, r;
        cin>>l>>r;
        queris.push_back({l,r,i});
    }
    sort(queris.begin(), queris.end(), [](Node a,Node b)->bool{
         return a.r < b.r;
         });
    map<int, int> mp;
    Fenwick_tree fen(n);
    vector<int> v(q);
    int cnt = 0;
    for(int i = 0 ; i < q ; i++)
    {
        while(cnt < queris[i].r)
        {
            cnt++;
            if(mp[a[cnt]] != 0)
            {
                fen.up(mp[a[cnt]], -1);
            }
            mp[a[cnt]] = cnt;
            fen.up(cnt, 1);
        }
        v[queris[i].idx] = fen.query(queris[i].l, queris[i].r);
    }
    for(int i = 0; i < q; i++)
    {
        cout << v[i] << endl;
    }
}
