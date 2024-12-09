#include <bits/stdc++.h>
using namespace std;
using T = pair<int, int>;
const int N =101;
const int INF = 1e9;
vector<T> adj[N];
signed main()
{
    int n,m;
    cin>>n>>m;
    vector<int> res;
    for(int i = 0 ; i < m ; i++)
    {
        int x; cin>>x;
        res.push_back(x);
    }
    vector<vector<int>> dist(n + 1,vector<int> (n + 1,INF));
    for(int u = 1 ; u <= n ; u++)
    {
        for(int v = 1 ; v <= n ; v++)
        {
            int w; cin>>w;
            dist[u][v] =min(dist[u][v],w);
        }
    }
    for(int k = 1; k <= n ; k++)
    {
        for(int i = 1 ; i <= n ; i++)
        {
            for(int j = 1 ; j <= n ; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    int ans = 0;
    for(int i = 0 ; i < m - 1; i++)
    {
        if(dist[res[i]][res[i + 1]] == INF)
        {
            cout << -1 <<  endl;
            return 0;
        }
        ans += dist[res[i]][res[i + 1]];
    }
    cout << ans << endl;
}
