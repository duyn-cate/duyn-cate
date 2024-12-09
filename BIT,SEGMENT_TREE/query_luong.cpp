#include <bits/stdc++.h>

using namespace std;
using T = tuple<char, int, int>;

class Fenwick_tree
{
private:
    int n;
    vector<int> bit;
public:
    Fenwick_tree(int size)
    {
        this->n = size;
        bit.assign(n + 1, 0);
    }
    void up(int x, int val)
    {
        for(; x <= n; x += (x & -x))
            bit[x] += val;
    }
    int get(int x)
    {
        int sum = 0;
        for(; x > 0; x -= (x & -x))
            sum += bit[x];
        return sum;
    }
    int query(int x, int y)
    {
        return get(y) - get(x - 1);
    }
};
const int N = 2e5 + 10;
int a[N];
signed main()
{
    int n,q; cin>>n>>q;
    vector<T> queris;
    vector<int> val;
    for(int i = 1; i <= n ; i++)
    {
        cin>>a[i];
        val.push_back(a[i]);
    }
    for(int i = 1; i <= q;i++)
    {
        char type;
        int u, v;
        cin>>type>>u>>v;
        if(type == '?') val.push_back(u);
        val.push_back(v);
        queris.push_back(make_tuple(type, u, v));
    }
    sort(val.begin(), val.end());
    val.resize(unique(val.begin(), val.end()) - val.begin());
    auto func = [&](int x)
    {
        return (lower_bound(val.begin(), val.end(), x) - val.begin() + 1);
    };
    Fenwick_tree fen(val.size());
    for(int i = 1; i <= n ; i++)
    {
        a[i] = func(a[i]);
        fen.up(a[i],1);
    }
    for(auto [type, x, y] : queris)
    {
        if(type == '?')
        {
            x = func(x);
            y = func(y);
            cout << fen.query(x,y) << endl;
        }
        else
        {
            y = func(y);
            fen.up(a[x], -1);
            a[x] = y;
            fen.up(a[x], 1);
        }
    }
}
