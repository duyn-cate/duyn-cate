// dung thuat toan floy
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll N = 401;
ll e[N][N], dist[N][N];
const ll INF = 1e9;
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i = 0 ; i < m ; i++)
    {
        int u,v;
        cin>>u>>v;
        e[u][v] = e[v][u] = 1;

    }
    if(e[1][n])
    {
        for(int i = 1 ; i<= n ; i++)
        {
            for(int j = 1 ; j <=n ; j++)
            {
                if(e[i][j] == 1)
                    e[i][j] = 0;
                else e[i][j] =1;

            }
        }
    }
    for(int i= 1 ; i <= n ; i++)
    {
        for(int j = 1 ; j <= n ; j++)
        {
            if(i == j)
                dist[i][j] = 0;
            else if(e[i][j] == 0) dist[i][j] = INF;
            else dist[i][j] = 1;
        }
    }
    for(int k = 1 ; k <= n ; k++)
    {
        for(int i = 1 ; i <=n ; i++)
        {
            for(int j = 1 ; j <= n ; j++)
            {
                dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
            }
        }
    }
    if(dist[1][n] == INF)
    {
        cout << -1 << endl;
    }
    else cout << dist[1][n] << endl;
}
