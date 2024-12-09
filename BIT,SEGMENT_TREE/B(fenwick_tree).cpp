#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE
clockid_t Start = clock();
#endif // ONLINE
void fast()
{
    #ifndef ONLINE
    fprintf(stderr,"%.10fs\n",(double)(clock() - Start)/ CLOCKS_PER_SEC);
    #endif // ONLINE
}
class Fenwick_tree
{
private:
    int n; vector <int> bit;
public:
    Fenwick_tree(int n)
    {
        this->n = n;
        bit.assign(n + 1, 0);
    }
    void up(int x, int val)
    {
        for(int i = x; i <= n; i+=(i & -i))
            bit[i] += val;
    }
    int sum(int x)
    {
        int ans = 0;
        for(int i = x; i > 0 ; i -= (i & -i))
            ans += bit[i];
        return ans;
    }
    int query(int l, int r)
    {
        return sum(r) - sum(l - 1);
    }
};
signed main()
{
    fast();
    cin.tie(0)->sync_with_stdio(0);
    int n,q; cin>>n>>q;
    vector<int> v(n + 1);
    for(int i = 1 ; i <=n ; i++)
    {
       cin>>v[i];
    }
    using T = tuple<char, int, int>;
    vector<int> vals;
    vector<T> query;
    for(int i = 1 ; i <=n ; i++)
    {
        vals.push_back(v[i]);
    }
    for(int i = 1 ; i <= q; i++)
    {
        char type;
        int u,v;
        cin>>type>> u>>v;
        if(type == '?') vals.push_back(u);
        vals.push_back(v);
        query.push_back({type, u,v});
    }
    sort(vals.begin(), vals.end());
    vals.resize(unique(vals.begin(), vals.end()) - vals.begin());

    auto func = [&](int x)
    {
        return (int)(lower_bound(vals.begin(), vals.end(), x) - vals.begin() + 1);
    };
    Fenwick_tree a(vals.size());
    for(int i = 1; i <= n ; i++)
    {
        v[i] = func(v[i]);
        a.up(v[i], 1);
    }
    for(auto [type, x,y] : query)
    {
        if(type == '?')
        {
            x = func(x);
            y = func(y);
            if(x > y) swap(x,y);
            cout << a.query(x,y) << "\n";
        }
        else
        {
            y = func(y);
            a.up(v[x], -1);
            v[x] = y;
            a.up(v[x], 1);
        }
    }
}
