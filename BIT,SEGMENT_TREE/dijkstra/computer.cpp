#include <bits/stdc++.h>

using namespace std;
using TP = tuple<int, int, double long>;
using T = pair<int, double long>;
using Ta= pair<double long, int>;
const int INF = numeric_limits<int>::max();
const int N = 1001;
vector<T> adj[N];
struct Node
{
    int u, v;
    double long w;
};
void dijkstra(int s, vector<double long> &dist, vector<int > &dp)
{
    priority_queue<Ta, vector<Ta>, greater<Ta>> pq;
    pq.push({0,s});
    dist[s] = 0.0;
    dp[s] = 1;
    while(!pq.empty())
    {
        auto [par,u] = pq.top(); pq.pop();
        if(par > dist[u]) continue;
        for(auto [v,w] : adj[u])
        {
            //cout << u << " " << v << " " << w << endl;
            if(dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v],v});
            }
        }
    }
}
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    vector<double long> dist1(N, INF);
    vector<int> dp1(N, 0), dpN(N, 0);
    vector<Node> cost;
    for(int i = 0 ; i < m ; i++)
    {
        int u,v;
        double long w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
        cost.push_back({u,v,w});
    }

    dijkstra(1,dist1,dp1);
    double long ans = dist1[n];
    sort(cost.begin(), cost.end(),[&](Node a, Node b)->bool{
         if(a.w == b.w)
         {
             return (dist1[a.u] + dist1[a.v] > dist1[b.u] + dist1[b.v]);
         }
         return a.w > b.w;
         });
    for(int i = 0; i < k; i++)
    {
        auto [u,v,w] = cost[i];
        //cout << u << " " << v <<  " " << w << endl;
        adj[u].push_back({v, 1.0 * w / 2});
        adj[v].push_back({u, 1.0 * w / 2});

        vector<double long> dist_new(N , INF);
        dijkstra(1,dist_new, dp1);
        ans = min(ans, dist_new[n]);

        adj[u].pop_back();
        adj[v].pop_back();
    }
    cout << ans  << endl;
}
