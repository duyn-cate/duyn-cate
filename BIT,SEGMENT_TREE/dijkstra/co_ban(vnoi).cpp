#include <bits/stdc++.h>

using namespace std;
const int INF = 1e9;
using T = pair<int, int>;
const int N = 101;
vector<T> adj[N];
void dijkstra(int s,int t, int type)
{
    vector<int> dist(N, INF);
    vector<int> parent(N, -1);
    priority_queue<T, vector<T>, greater<T>> pq;
    pq.push({0,s});
    dist[s] = 0;
    int ans = 0;
    while(!pq.empty())
    {
        auto [par,u] = pq.top(); pq.pop();
        ans += par;
        if(par > dist[u]) continue;
        for(auto [v,w] : adj[u])
        {
            if(dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.emplace(dist[v], v);
            }
        }
    }
    if(type == 0)
    {
        if(dist[t] == INF)
        {
            cout << -1 << endl;
            return;
        }
        cout << dist[t] << endl;
    }
    else
    {
        if(dist[t] == INF)
        {
            cout << -1 << endl;
            return;
        }
        vector<int> res;
        for(int i = t; i != -1; i = parent[i])
            res.push_back(i);
        cout << res.size()<<" ";
        reverse(res.begin(), res.end());
        for(auto it: res) cout << it << " ";
        cout << endl;
    }
}
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    for(int i = 0 ; i < m ; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    while(k--)
    {
        int type, s,t;
        cin>>type>>s>>t;
        dijkstra(s,t,type);
    }
}
