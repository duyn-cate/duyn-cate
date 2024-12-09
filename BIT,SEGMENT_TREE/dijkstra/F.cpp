#include <bits/stdc++.h>

using namespace std;
using T = pair<int,int>;
const int INF = numeric_limits<int>::max();
#ifndef ONLINE
clockid_t Start = clock();
#endif // ONLINE
void fast()
{
    cin.tie(0)->sync_with_stdio(0);
    #ifndef ONLINE
    fprintf(stderr, "%.10fs\n",(double)((clock() - Start) / CLOCKS_PER_SEC));
    #endif // ONLINE
}
int main()
{
    fast();
    int n,m,r,c,X,Y;
    cin>>n>>m>>r>>c>>X>>Y;
    vector<vector<char>> a(n + 1, vector<char> (m + 1));
    for(int i = 1;  i <= n; i++)
    {
        for(int j = 1 ; j <=m; j++)
        {
            cin>>a[i][j];
        }
    }
    vector<T> dir = {{0, 1},{0, -1},{1, 0}, {-1,0}};
    vector<vector<int>> dist(n + 1, vector<int> (m + 1, INF));
    dist[r][c] = 0;
    deque<T>pq;
    pq.push_front({r,c});
    while(!pq.empty())
    {
        auto [x,y] = pq.front(); pq.pop_front();

        for(T it : dir)
        {
            int nx = x + it.first;
            int ny = y + it.second;
            int w = (it == make_pair(0,-1));
            if(nx >= 1 && nx <= n && ny >= 1 && ny <= m && a[nx][ny] == '.')
            {
                if(dist[nx][ny]  > dist[x][y] + w)
                {
                    dist[nx][ny] = dist[x][y] + w;
                    if(w == 0)
                    {
                        pq.push_front({nx,ny});
                    }
                    else pq.push_back({nx,ny});
                }
            }
        }
    }
    int ans = 0;
    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = 1 ; j <= m ; j++)
        {
            if(dist[i][j] != INF)
            {
//                cout << dist[i][j] << " ";
                int L = dist[i][j];
                int R = L + (j - c);
                if(L <= X && R <= Y)
                {
                    ans++;
                }
            }
        }
//        cout << endl;
    }
    cout << ans<<endl;
}
