// code : Truong Nguyen Duy
// my code and solution
#include <bits/stdc++.h>

using namespace std;
const int N = 2e5 + 10;
// khoi tao gia tri
int h[N], r[N],n,M;
namespace Segment_tree
{
    int t[N * 4];
    //xay dung cay khach san
    void build(int id, int l, int r)
    {
        if(l == r)
        {
            t[id] = h[l];
            return;
        }
        int m = l + r >> 1;
        build(id << 1, l, m);
        build(id << 1 | 1, m + 1, r);

        t[id] = max(t[id << 1], t[id << 1 | 1]);
    }
    // tim kiem index vi tri khach san thoa man ne khong tra ve -1;
    int Find(int id, int l, int r, int pos)
    {
        if(t[id] < pos) return -1;
        if(l == r)
        {
            return l;
        }
        int m = l + r >> 1;
        int L = Find(id << 1, l , m, pos);
        if(L != -1) return L;
        return Find(id << 1 | 1, m + 1, r, pos);
    }
    void up(int id, int l, int r,int pos, int val)
    {
        if(pos < l || pos > r) return;
        if(l == r)
        {
            t[id] = val;
            return;
        }
        int m = l + r >> 1;
        up(id << 1, l, m, pos, val);
        up(id << 1 | 1, m + 1, r, pos, val);

        t[id] = max(t[id << 1], t[id << 1 | 1]);
    }
}
using namespace Segment_tree;
int main()
{
    cin>>n>>M;
    for(int i = 1 ; i <= n ; i++)
    {
        cin>>h[i];
    }
    for(int i = 1; i <= M; i++)
    {
        cin>>r[i];
    }
    build(1,1,n);
    for(int i = 1; i <= M ; i++)
    {
        int idx = Find(1,1,n,r[i]);
        if(idx == -1)
        {
            cout << 0 << " ";
        }
        else
        {
            cout << idx << " ";
            h[idx] -= r[i];
            up(1,1,n,idx, h[idx]);
        }
    }
}
