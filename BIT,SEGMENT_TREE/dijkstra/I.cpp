// thuat toan floy 1 chieu
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 1e9;
using T = pair<int, int>;
signed main()
{
    string a, b;
    cin>>a>>b;
    vector<vector<int>> dist(26 ,vector<int> (26, INF));
    int n; cin>>n;
    for(int i = 0 ; i < n ; i++)
    {
        char x,y;
        cin>>x>>y;
        int w;
        cin>>w;
        dist[x - 'a'][y - 'a'] = min(dist[x - 'a'][y - 'a'],w);// gan node cho gia tri w
    }
    int lenght = a.size();
    if(a.size() != b.size())
    {
        cout << -1 << endl; // neu legnhta != lenghtb in ra -1
        return 0;
    }
    for(int i = 0 ; i < 26; i++) dist[i][i] = 0; // khoi tao gia tri ban dau hai node trung nhau
    // thuat toan floy : dist[i][j] = min(dist[i][j], dist[i][k],dist[k][j])
    for(int k = 0 ; k < 26; k++)
    {
        for(int i = 0;  i < 26; i++)
        {
            for(int j = 0 ;j  < 26 ; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    int ans = 0;
    string s = "";
    for(int i = 0 ; i < lenght ; i++)
    {
        // neu a[i] == b[i] thi bo qua
        if(a[i] == b[i])
        {
            s += a[i];
            continue;
        }
        char c = 'A';
        int cnt = INF;
        for(int j =0 ; j < 26; j++)
        {
            // tim ky tu thu i nho nhat giua hai duong di
            if(cnt > (dist[a[i] - 'a'][j] + dist[b[i] - 'a'][j]))
            {
                cnt = dist[a[i] - 'a'][j] + dist[b[i] - 'a'][j];
                c = char(j + 'a');
            }
        }
        if(cnt == INF)
        {
            cout << -1 << endl;
            return 0;
        }
        ans += cnt;
        s += c;
    }
    // in ra ket qua
    cout << ans << endl;
    cout << s << endl;
}
