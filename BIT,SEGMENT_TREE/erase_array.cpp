#include <bits/stdc++.h>

using namespace std;
const int N = 2e5 + 10;
int a[N], n,idx[N];
namespace Segment_tree
{
    int t[N * 4];
    void build(int id, int l, int r)
    {
        if(l == r)
        {
            t[id] = 1;
            return;
        }
        int m = l + r >> 1;
        build(id << 1, l ,m);
        build(id << 1 | 1, m + 1, r);

        t[id] = (t[id << 1] +  t[id << 1 | 1]);
    }
    // tim kiem phan tu bang idx
    int Find(int id, int l, int r, int pos)
    {
        if(l == r)
        {
            return l;
        }
        int m = l + r >> 1;
        if(pos <= t[id << 1])
            return Find(id << 1, l, m, pos);
        return Find(id << 1 | 1, m + 1, r, pos - t[id << 1]);
    }
    void up(int id, int l, int r, int pos)
    {
        if(pos < l || pos > r) return;
        if(l == r)
        {
            t[id] = 0;
            return;
        }
        int m = l + r >> 1;
        up(id << 1, l, m, pos);
        up(id << 1 | 1, m + 1, r, pos);

        t[id] = (t[id << 1] + t[id << 1 | 1]);
    }
}
using namespace Segment_tree;

int main()
{
    cin>>n;
    for(int i = 1 ; i <= n; i++)
    {
        cin>>a[i];
    }
    for(int i = 1 ; i <= n ; i++)
    {
        cin>>idx[i];
//        idx[i] += 1;
    }
    build(1,1,n);
    for(int i = 1 ; i <= n ; i++)
    {
        // tim kiem tai vi tri idx
        int pos = Find(1,1,n,idx[i]);
        cout << a[pos] << " ";
        up(1,1,n,pos);
    }
}
