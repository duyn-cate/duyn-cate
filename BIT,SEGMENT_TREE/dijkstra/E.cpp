#include <bits/stdc++.h>
#define int long long
using namespace std;
using T = tuple<int, int, int , int>;
vector<pair<int, int>> dirs = {{1, 0},{0, 1},{-1, 0},{0, -1}};
const int N = 1001;
char a[N][N];
int dist[N][N][4];
int n,m,k;
const int INF = 1e9;
signed main()
{
    cin>>n>>m>>k;
    for(int i = 1; i <= n ; i++)
    {
        for(int j = 1; j <= m; j++)
            cin>>a[i][j];
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m ; j++)
        {
            for(int x = 0; x < 4 ; x++)
            {
                dist[i][j][x] = INF;
            }
        }
    }
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    deque<T> pq;
    for(int i = 0 ; i < 4; i++)
    {
        dist[x1][y1][i] = 0;
        pq.push_front({x1,y1,0,i});
    }
    auto check = [&](int i,int j)->bool
    {
        return(i >= 1 && i <= n && j >= 1 && j <= m && a[i][j] == '.');
    };
    while(!pq.empty())
    {
        auto [x,y, d, lst] = pq.front(); pq.pop_front();
        for(int i = 0; i < 4; i++)
        {
            int nx = x + dirs[i].first;
            int ny = y + dirs[i].second;
            if(nx >= 1 && ny >= 1 && nx <= n && ny <= m && a[nx][ny] != '#')
            {
                int w = (d == 0 || i != lst);
                if(dist[nx][ny][i] > dist[x][y][lst] + w)
                {
                    dist[nx][ny][i] = dist[x][y][lst] + w;
                    if(w == 1)
                    {
                        pq.push_back({nx,ny, 1 % k, i});
                    }
                    else
                    {
                        pq.push_front({nx, ny, (d + 1) % k, i});
                    }
    //                    cout << nx << " " << ny << " " << dist[nx][ny] << endl;
                }
            }
        }
    }
    int ans = INF;
    for(int i = 0 ; i < 4 ; i++)
    {
        ans = min(ans, dist[x2][y2][i]);
    }
    cout << (ans == INF ? -1 : ans) << endl;
    return 0;
//    cout << dist[x2][y2] << endl;
}

