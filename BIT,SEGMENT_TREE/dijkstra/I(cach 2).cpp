#include <bits/stdc++.h>

using namespace std;
#define int int64_t
const int INF = 1e9;
const int N = 26;
using T = pair<int, int>;
vector<T> adj[N];
vector<int> dijkstra(int a)
{
    vector<int> dist(N, INF);
    priority_queue<T, vector<T>,greater<T>> pq;
    pq.push({0, a});
    dist[a] = 0;
    while(!pq.empty())
    {
        auto [par, u] = pq.top(); pq.pop();
        if(par > dist[u]) continue;
        for(auto [v,w]: adj[u])
        {
            if(dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}
signed main()
{
    string a,b; cin>>a>>b;
    int m; cin>>m;
    for(int i = 0 ; i < m ; i++)
    {
        char x,y; cin>>x>>y;
        int w; cin>>w;
        adj[x - 'a'].push_back({y - 'a', w});
        //adj[y - 'a'].push_back({x - 'a', w});
    }
    int n = a.size();
    if(n != b.size())
    {
        cout << -1 << endl;
        return 0;
    }
    int ans = 0;
    string res = "";
    for(int i = 0 ; i < n ; i++)
    {
        int u = a[i] - 'a';
        int v = b[i] - 'a';
        vector<int> distU = dijkstra(u);
        vector<int> distV = dijkstra(v);
        int cost = INF;
        char char_s = '@';
        for(int c = 0; c < 26; c++)
        {
            int cnt = distU[c] + distV[c];
//            if(distU[c] != INF && distV[c] != INF)
//            cout <<char(c + 'a')<< " "<< distU[c] << " " << distV[c] << " " <<  cost << endl;
            if(cnt < cost)
            {
                cost = cnt;
                char_s = char(c + 'a');
            }
        }
//            cout << endl;
        if(cost == INF)
        {
            cout << -1 << endl;
            return 0;
        }
        ans += cost;
        res += char_s;
    }
    cout << ans << endl;
    cout << res << endl;
}

