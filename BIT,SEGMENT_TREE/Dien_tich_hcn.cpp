#include <bits/stdc++.h>


using namespace std;
struct node
{
    int x, y1, y2, val;

    bool operator <(node &a)
    {
        return x < a.x;
    }
};
const int  N = 3e5 + 10;
namespace Segment_tree
{
     int t[N * 4], lazy[N * 4];
     void down(int id, int l, int r)
     {
         if(lazy[id] != 0)
         {
             int m = l + r >> 1;
             t[id] += r - l  + 1;
             lazy[id << 1] += lazy[id] *  (m - l + 1);
             lazy[id << 1 | 1] += lazy[id] * (r - m);

             lazy[id] = 0;
         }
     }
     void up(int id, int l, int r, int u, int v, int val)
     {
         down(id, l, r);
         if(v < l || r < u) return;
         if(u <= l && r <= v)
         {
             lazy[id] += val * (r - l + 1);
             down(id, l, r);
             return;
         }
         int m = l + r >> 1;
//         down(id, l, r);
         up(id << 1, l , m, u, v, val);
         up(id << 1 | 1, m + 1, r, u, v, val);

         t[id] = t[id << 1] + t[id << 1 | 1];
     }
}
using namespace Segment_tree;
vector<node> adj;
int main()
{
    int n;
    cin>>n;

    for(int i = 1 ; i <= n; i++)
    {
        int x1, x2,y1,y2;
        cin>>x1>>y1>>x2>>y2;
        adj.push_back({x1,y1,y2,1});
        adj.push_back({x2,y1,y2,-1});
    }
    sort(adj.begin(), adj.end());
    int ans = 0;
    for(int i = 1; i < n; i++)
    {
        int y1 = adj[i].y1, y2 = adj[i].y2;
        int val = adj[i].val;
        up(1,0,N, y1, y2 - 1, val);
        ans += (adj[i + 1].x - adj[i].x) * t[1];
    }
    cout << ans << endl;
}
