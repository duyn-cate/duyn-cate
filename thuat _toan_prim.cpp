// thuat toan prim: chon ra 1 diem bat dau
// 47p xem tiep tim duong di ngan nhat
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll maxn = 1e5 + 1;
typedef pair<ll , ll > ii;
struct node
{
    int x,y,w;
};
vector<node> dscanh;
int n,m;
bool visited[maxn];
vector<ii> adj[maxn];
void nhap()
{
    cin>>n>>m;
    for(int i = 0 ; i< m ; i++){
        int x,y,w;
        cin>>x>>y>>w;
        adj[x].push_back({y,w});
        adj[y].push_back({x,w});
    }
}
void prim(int s){
    priority_queue< ii , vector<ii> , greater<ii>> Q;
    visited[s] = true;
    for(auto t : adj[s])
    {
        if(!visited[t.first])
        {
            Q.push({t.second , t.first});
        }
    }
    ll d= 0 ;
    int dem = 0;
    while(!Q.empty())
    {
        if(dem == n-1) break;
        ii e = Q.top(); Q.pop();
        // first : la trong so, second : la dinh
        if(!visited[e.second])
        {
            dem++;
            visited[e.second] = true;
            d += e.first;
            for(auto it : adj[e.second])
            {
                if(!visited[it.first])
                {
                    Q.push({it.second, it.first});
                }
            }
        }
    }
    if(dem != n-1) cout << "IMPOSSIBLE";
    else cout << d;
}
signed main()
{
    ios_base::sync_with_stdio();
    cin.tie(NULL);
    cout.tie(NULL);
    nhap();
    prim(1);
}
