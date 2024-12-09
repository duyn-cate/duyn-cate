#include <bits/stdc++.h>
#define int int64_t
using namespace std;
using T = pair<int, int>;
const int INF = 0x3f3f3f3f;
const int N = 3e3 + 10;
int dist[N][N];

signed main()
{
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<int>> adj(n + 1);
    for(int i= 1; i <= m ;i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    map<tuple<int,int,int>, int> mp;
    for(int i = 0; i < k; i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        mp[make_tuple(a,b,c)] = true;
    }
    queue<pair<int, int>> pq;
    memset(dist, 0x3f, sizeof dist);
    for(auto& v : adj[1])
    {
        pq.emplace(1,v);
        dist[1][v] = 1;
    }

    while(!pq.empty())
    {
        auto [x,y] = pq.front();
        pq.pop();
        for(auto& z : adj[y])
        {
            if(dist[y][z] != INF || mp.count(make_tuple(x,y,z)))continue;
            dist[y][z] = dist[x][y] + 1;
            pq.emplace(y,z);
        }
    }
    int ans = INF, c = -1;
    for(int i = 1; i <= n ; i++)
    {
        if(ans > dist[i][n])
        {
            ans = dist[i][n];
            c = i;
        }
    }
    if(ans == INF)
    {
        cout << -1 << endl;
        return 0;
    }
    cout << ans << endl;
    vector<int> res;
    res.push_back(n);
    int y = c, z = n;
    while(ans--)
    {

        res.push_back(y);
        for(int x = 1 ; x<= n ; x++)
        {
            if(dist[x][y] + 1 == dist[y][z])
            {
                z = y;
                y = x;
                break;
            }
        }
    }
    reverse(res.begin(), res.end());
    for(auto it : res )
        cout << it << " ";
}
