#include <bits/stdc++.h>

using namespace std;

struct node
{
    int l,r, idx;
};
class Fenwick_tree
{
private :
    int n;
    vector<int> bit;
public:
    Fenwick_tree (int x)
    {
        this->n = x;
        bit.assign(n + 10, 0);
    }
    void up(int x, int val)
    {
        for(; x <= n ; x +=(x & -x))
            bit[x] += val;
    }
    int get(int x)
    {
        int sum = 0;
        for(; x > 0; x -=(x & -x))
        {
            sum += bit[x];
        }
        return sum;
    }
    int query(int l, int r)
    {
        return get(r) - get(l - 1);
    }
};
const int N = 2e5 + 10;
int a[N];
signed main()
{
    int n,q;
    cin>>n>>q;
    for(int i = 1 ; i <= n ; i++)
        cin>>a[i];
    vector<node> queris;
    for(int i = 0 ; i < q; i++)
    {
        int l, r;
        cin>> l>>r;
        queris.push_back({l,r,i});
    }
    sort(queris.begin(), queris.end(), [](node a, node b)->bool
         {
             return a.r < b.r;
         });
    int cnt = 0;
    Fenwick_tree fen(n);
    vector<int> res(q);
    map<int, int> mp;
    for(int i = 0 ; i < q; i++)
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
        res[queris[i].idx] = fen.query(queris[i].l, queris[i].r);
    }
    for(auto it : res)
        cout << it  << endl;
}
