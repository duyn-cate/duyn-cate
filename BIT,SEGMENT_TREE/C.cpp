#include <bits/stdc++.h>
using namespace std;
const int  N = 2e5 + 10;
#define int int64_t
int bit[N][11];
int n,k;
int a[N];
void up(int x, int i, int val)
{
    for(;x  <= n ; x += (x & -x))
    {
        bit[x][i] += val;
    }
}
int get(int x, int i)
{
    int sum = 0;
    for(;x > 0;x -=(x & -x))
        sum += bit[x][i];

    return sum;
}
signed main()
{
    cin>>n>>k;
    for(int i = 1 ; i <=n ; i++)
    {
        cin>>a[i];
    }
    for(int i = 1 ; i <= n; i++)
    {
        up(a[i],1,1);
        for(int j = 2; j <= k + 1; j++)
        {
            // lay phan sau doan (1...a[i] - 1) cua k - 1 + len cho doan a[i] cua k
            int sum = get(a[i] - 1,j - 1);
            up(a[i],j, sum);
        }
    }
    cout << get(n, k +1) << endl;
}
