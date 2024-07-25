
/*code: Truong Nguyen Duy
tep nay chi toan ly thuyet khong chay duoc*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
/*  phuong phap de quy
    DPT: 2^n         */
ll C(ll n, ll k)
{
    if(n == 0 || k == 0) return 1;
    return C(n  -1 , k  -1) + C(n - 1,  k);
}
/*  de quy co nho
    DPT: n * k;     */
ll F[1000][1000];
memset(F , -1 , sizeof(F) );
ll C(ll n , ll  k)
{
    if(n == 0 || k == 0 ) return 1;
    if(F[n][k] != -1) return F[n][k];
    F[n][k] = C(n - 1, k) + C(n - 1, k - 1);
    return F[n][k];
}
// con cach ma tran nhu chi den 100 khong nhac den day nhe
// su dung cong thuc
// toi uu nhat day roi day
const ll maxn = 2e6 + 1;
const ll mod = 1e9  +7;
int64_t F[maxn];
int64_t g[maxn];// nghich dao modulo cua F[i]
int64_t binpow(int64_t a ,int64_t b)
{
    if(b == 0) return 1;
    int64_t tmp = binpow(a , b / 2);
    if( b & 1) return tmp * tmp;
    else return tmp * tmp * a;
}
F[0] = 1;
for(int i =1 ; i < maxn ; i++)
{
    F[i] = (F[i - 1] * i) % mod;
}
g[maxn - 1] = binpow(F[maxn - 1] , mod - 2);
for(int i = maxn - 2 ;  i >= 0 ; i++)
{
    g[i] = (g[i + 1] * (i + 1)) % mod;
}
int64_t C( int n , int k)
{
    return F[n] * binpow(F[k] , mod - 2) % mod * binpow(F[n-k] , mod - 2) % mod;
}
