#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 10;
map<int, int> pos[N];
set<int> st;
bool visited[N];

void dfs(int u)
{
    visited[u] = true;
    vector<int> vt;
    for(auto &v : st)
    {
        if(visited[v] || pos[u][v]) continue;
        vt.emplace_back(v);
    }
    for(auto &it : vt)
    {
        st.erase(it);
    }
    for(auto it : vt)
    {
        dfs(it);
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i = 1 ; i <= m ; i++)
    {
        int u,v;
        cin>>u>>v;
        pos[u][v] = true;
        pos[v][u] = true;
    }
    for(int i = 1 ; i <= n ; i++)
    {
        st.insert(i);
    }
    int ans = 0;
    for(int i = 1 ; i <= n ; i++)
    {
        if(visited[i]) continue;
        ans ++;
        dfs(i);
    }
    cout << ans - 1 << endl;
}
