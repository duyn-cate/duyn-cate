#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 10;
const int INF = numeric_limits<int>::min();
int a[N], f[N];
namespace Segment_tree
{
    int t[N * 4];
    void up(int id, int l, int r, int pos, int val)
    {
        if(pos < l || r < pos) return;
        if(l == r)
        {
            t[id] =val;
            return;
        }
        int m = l + r >> 1;
        up(id << 1, l, m, pos, val);
        up(id << 1 | 1, m + 1, r, pos, val);
        t[id] = max(t[id << 1], t[id << 1 | 1]);
    }
    int get(int id, int l, int r,int u, int v)
    {
        if(v < l || r < u) return INF;
        if(u <= l && r <= v)
        {
            return t[id];
        }
        int m = l + r >> 1;
        return max(get(id << 1, l, m, u, v), get(id << 1 | 1, m + 1, r, u, v));
    }
}
using namespace Segment_tree;

signed main()
{
    int n, k; cin>>n>>k;
    for(int i = 1; i<= n ; i++)
    {
        cin>>a[i];
    }
    for(int i = n; i > 0 ; i--)
    {
        int res = get(1,1,n,min(i + 1, n), min(i + k, n));
//        cout << res << endl;
        up(1,1,n,i,max(0LL,res + a[i]));
    }
    cout << t[1] << endl;
}
