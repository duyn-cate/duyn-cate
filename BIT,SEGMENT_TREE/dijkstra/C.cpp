#include <bits/stdc++.h>

using namespace std;
using ll =long long;
const ll N = 2e5 + 10;
#define ii pair<ll, ll>
vector <ii> adj[N];
bool visited[N];
int n,m;
ll parent[N];
ll dist[N],dp[N];
void dijkstra()
{
    fill(dist , dist + N - 1, LLONG_MAX);
    memset(parent, -1 , sizeof parent);
    priority_queue <ii, vector<ii> , greater<ii>> pq;
    pq.push({0,1});
    dist[1] = 0;
    ll x = 0;
    while(!pq.empty())
    {
        auto [d,u] = pq.top(); pq.pop();
        if(d > dist[u]) continue;
        for(auto [v,w] : adj[u])
        {
            if(dist[v] > dist[u] + w)
            {
                parent[v] =u;
                dist[v] = dist[u] + w;
                pq.push({dist[v],v});
            }
        }
    }
    // truy vet
    if(dist[n] == LLONG_MAX)
    {
        cout << -1 << endl;
        return;
    }
    vector<int> ans;
    for(int i = n ; i != -1; i = parent[i])
        ans.push_back(i);
    reverse(ans.begin(), ans.end());
    for(auto it : ans) cout << it<< " ";
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>m;
    for(int i = 0 ; i < m ; i++)
    {
        int x,y,w;
        cin>>x>>y>>w;
        adj[x].push_back({y,w});
        adj[y].push_back({x,w});
    }
    dijkstra();
}
