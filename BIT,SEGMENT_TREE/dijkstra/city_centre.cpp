#include <bits/stdc++.h>
#define int int64_t
using namespace std;
using T = pair<int, int>;
const int N = 3e5 + 10;
const int INF = 1e9;
vector<T> adj[N];
void dijkstra(int s,vector<int> &dist, vector<int> &dp)
{
    priority_queue<T, vector<T>, greater<T>> pq;
    pq.push({0,s});
    dist[s] = 0;
    dp[s] = 1;
    while(!pq.empty())
    {
        auto [par,u] = pq.top(); pq.pop();
        if(par > dist[u]) continue;
        for(auto [v,w] :adj[u])
        {
            if(dist[v] == dist[u] + w) dp[v] += dp[u];
            if(dist[v] > dist[u] + w)
            {
                dp[v] = dp[u];
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}
signed main()
{
    int n,m;
    cin>>n>>m;
    for(int i = 0;  i < m ; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    vector<int> dist1(N, INF),dist2(N, INF), dp1(N, 0), dp2(N ,0);
    dijkstra(1,dist1, dp1);
    dijkstra(n, dist2, dp2);
    vector<int> res;
    for(int i = 2; i < n ; i++)
    {
        if(!(dp1[i] * dp2[i] == dp1[n] && dist1[i] + dist2[i] == dist1[n]))
            res.push_back(i);
    }
    if(res.empty())
    {
        cout << 0 << endl;
        return 0;
    }
    cout << res.size() << endl;
    for(auto it : res) cout << it << endl;
}


