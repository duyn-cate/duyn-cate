// dijkstra N^2
#include <bits/stdc++.h>

using namespace std;
using T = pair<int, int>;
using L = tuple<int, int, int>;
const int INF = 1e9;
int n,m;
int Node(int x,int a,int b)
{
    return (((x|a) ^ a)|b);
}
void so()
{
    cin>>n>>m;
    string s;
    cin>>s;
    vector<vector<T>> adj(1<< n);
    for(int i = 0 ; i  < m ; i++)
    {
        int w;
        cin>>w;
        string a,b;
        cin>>a>>b;
        int ans = stoi(a,0,2); // swap bit to Num co so 2 ^ n
        int res = stoi(b,0 ,2);
        for(int x = 0 ; x < (1 << n);x++)
        {
             adj[x].emplace_back(Node(x,ans,res), w);
        }
    }
    // duyet theo thuat toan dijkstra N ^ 2
    vector<int> dist(1 << n, INF);
    vector<bool> del(1 << n, false);
    dist[stoi(s,0, 2)] = 0;
    while(true)
    {
        int ans = INF;
        int  u = -1;
        //Find Node chua duoc toi uu
        for(int i = 0 ; i <(1 << n); i++)
        {
            if(del[i]) continue;// if Node da duoc toi uu thi continue
            if(dist[i] < ans)
            {
                ans = dist[i];
                u = i;
            }
        }
        if(u == -1) break;
        del[u] = true; // xoa di Node da toi uu
        for(auto [v,w] : adj[u])
        {
            if(dist[v] > dist[u] + w)
                dist[v] = dist[u] + w; // tim duong di ngan nhat
        }

    }
    cout << (dist[0] == INF ? -1 : dist[0])<< "\n";
}
signed main()
{
    int t; cin>>t;
    while(t--)
    so();
}
