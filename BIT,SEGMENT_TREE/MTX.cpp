#include <bits/stdc++.h>

using namespace std;
using mtx = vector<vector<int>>;
namespace Matrix
{
    const int mod = 10;
    int bpow(int a, int b)
    {
        int ans = 0;
        while(b)
        {
            if(b & 1) ans = (ans + a) % mod;
            a = (a + a) % mod;
            b>>=1;
        }
        return ans;
    }
    mtx mul(mtx a, mtx b)
    {
        //assert(a[0].size() == b.size());
        int n = a.size();
        int m = b[0].size();
        int p = a[0].size();
        mtx c(n, vector<int>(m));
        for(int i = 0 ; i < n; i++)
        {
            for(int j = 0 ; j < m; j++)
            {
                c[i][j] = 0;
                for(int k = 0 ; k < p; k++)
                {
                    c[i][j] += bpow(a[i][k],b[k][j]) % mod;
                    c[i][j] %= mod;
                }
            }
        }
        return c;
    }
    mtx powmod(mtx a, int b)
    {
        assert(a[0].size() == a.size());
        mtx ans;
        for(int i = 0 ; i < a.size(); i++)
        {
            ans[i][i] = 1;
        }
        while(b)
        {
            if(b & 1) ans = mul(ans, a);
            a = mul(a, a);
            b>>=1;
        }
        return ans;

    }
    bool check(mtx a, mtx b)
    {
        assert(a[0].size() == b.size());
        int n = a.size();
        int m = b[0].size();
        for(int i = 0; i <n ; i++)
        {
            for(int j = 0 ; j < m ;j++)
            {
                if(a[i][j] != b[i][j])
                    return false;
            }
        }
        return true;
    }
};
using namespace Matrix;
char x[1001];
void so()
{
    cin.tie(0)->sync_with_stdio(0);
    int n; cin>>n;
    mtx a(n + 1, vector<int>(n + 1)),b(n + 1, vector<int>(n + 1)), c(n + 1, vector<int>(n + 1));
    for(int i = 0 ; i < n ; i++)
    {
        string s; cin>>s;
        for(int j= 0 ; j < n ; j++)
        {
            a[i][j] = (s[j] - '0');
        }
    }
    for(int i = 0 ; i < n ; i++)
    {
        string s; cin>>s;
        for(int j= 0 ; j < n ; j++)
        {
            b[i][j] = (s[j] - '0');
        }
    }
     for(int i = 0 ; i < n ; i++)
    {
        string s; cin>>s;
        for(int j= 0 ; j < n ; j++)
        {
            c[i][j] = (s[j] - '0');
        }
    }
    for(int j = 0 ;  j < 9; j++)
    {
        mtx r(n + 1, vector<int>(1, 0));
        for(int i  = 0 ; i <n ; i++)
        {
            r[i][0] = (rand() & 1);
        }
        mtx ans = mul(a,mul(b, r));
        mtx res = mul(c,r);
        if(ans != res)
        {
            cout <<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
}
int main()
{
    int t; cin>>t;
    while(t--)
        so();
}
