#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll N = 1e6 + 1;
int F[N] , g[N];
const ll mod = 1e9 + 7;
ll binpow( int a , int b)
{
    ll ans = 1;
    while(b)
    {
        if(b & 1)
        {
            ans = (1LL * ans * a) % mod;
        }
        a = (1LL * a * a) % mod;
        b >>= 1;
    }
    return ans;
}
void so()
{
    F[0] = 1;
    for(int i = 1; i < N ; i++)
    {
        F[i] = (1LL * F[i - 1] * i) % mod;
    }
    g[N - 1] = binpow(F[N - 1], mod - 2);
    for(int i = N - 2;  i >= 0; i--)
    {
        g[i] = (1LL * g[i + 1] * ( i + 1)) % mod;
    }
}
ll C(ll n , ll k)
{
    if(n < k) return 0;
    return ((1LL * F[n] * g[n - k]) % mod * g[k]) % mod;
}
int main()
{
    cin.tie()->sync_with_stdio(0);
     ll n; cin>>n;
     so();
    for(int i = 1 ; i <= n ; i++)
    {
        cout << C(n,i) << endl;

    }
}

