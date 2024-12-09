#include <bits/stdc++.h>

using namespace std;
#define int long long
using T = tuple<int,int,int>;
using L = pair<int, int>;
const int N = 2e5 + 10;
const int INF = 1e9;
int dx[] = {0, 1,-1, 0, 1, 1,-1,-1};
int dy[] = {1, 0, 0,-1,-1, 1, 1,-1};
//bool check(int i, int j, int x1, int y1)
//{
//    return (i > 0 && i <= x1 && j > 0 && j <= y1);
//}
signed main()
{
    int x0,y0,x1,y1;
    cin>>x0>>y0>>x1>>y1;
    set<L>mp;
    int n;
    cin>>n;
//    mp[make_pair(x0,y0)] = true;
    for(int i = 0 ; i< n; i++)
    {
       int x,y,r;
       cin>>r>>x>>y;
       for(int j = x ; j <=y ; j++)
       {
           mp.insert(make_pair(r,j));
       }
    }
    map<L, int> dist;
//    memset(dist , INF, sizeof dist);
    queue<L> pq;
    pq.emplace(x0, y0);
    dist[make_pair(x0, y0)] = 0;
    while(!pq.empty())
    {
        auto [x,y] = pq.front();
        pq.pop();
//        if(x == x1 && y == y1) break;
        for(int i = 0 ; i < 8; i++)
        {
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            if(mp.find({new_x, new_y}) == mp.end() || dist.count({new_x, new_y})) continue;
            dist[make_pair(new_x,new_y)] = dist[make_pair(x,y)] + 1;
            pq.emplace(new_x, new_y);
        }
//        cout << x << " " << y << endl;
    }
    if(!dist.count(make_pair(x1,y1)))
    {
        cout<< -1 <<endl;
    }
    else
    {
        cout << dist[make_pair(x1,y1)] << endl;
    }
}
