#include <bits/stdc++.h>

using namespace std;
using T = pair<int, int>;
const int INF = 1e9;
const int N = 501;
vector<vector<int>> dist(N , vector<int> (N, INF));
vector<bool> x(N, false);
int main()
{
    int n; cin>>n;
    int m = 0;
    for(int i = 0 ; i < n ; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        dist[u][v] = min(dist[u][v], w);
        dist[v][u] = min(dist[v][u], w);
        m = max(m,u);
        m = max(m ,v);
    }
    for(int i = 1 ; i <= m ; i++) dist[i][i]=0;
    for(int k = 1 ; k <= m; k++)
    {
        for(int i = 1 ; i <= m ;i++)
        {
            for(int j = 1 ; j <=m ; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    vector<int> res;
    for(int k = 0 ; k < n ; k++)
    {
        int ans = 0;
        for(int i = 1 ; i <= m ; i++)
        {
            for(int j = 1 ; j <= m ; j++)
            {
                if(x[i] || x[j] || dist[i][j] == INF) continue;
                ans += dist[i][j];
//                cout << i << " " << j << " " << dist[i][j]<< endl;
            }
        }
        res.push_back(ans);
        int id;
        cin>>id;
        x[id] = true;
    }
    for(auto it: res)
        cout <<  it << " ";
}
