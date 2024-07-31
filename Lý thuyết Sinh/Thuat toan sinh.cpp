#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
using ll = long long;
// sinh to hop chap k cua n
int n , k , X[10001],ok = 1;
void ktao()
{
    for(int i = 1 ; i <= k ; i ++)
    {
        cin>>X[i];
    }
}
void sinh()
{
    int i = k;
    while(i >= 1 && X[i] == n - k  + i)
    {
        i--;
    }
    if(i == 0)
    {
        ok = 0;
    }
    else
    {
        X[i]++;
        for(int j = i +1 ; j <= k ; j++)
        {
            X[j] = X[j-1] + 1;
        }
    }
}
// sinh hoan vi
void ktao()
{
    for(int i = 1 ; i <= n ; i ++)
    {
        cin>>X[i];
    }
}
void sinh()
{
    int i = n-1;
    while(i >= 1 && X[i]> X[i + 1])
    {
        i--;
    }
    if(i == 0)
    {
        ok = 0;

        //reverse(X + 1, X + n + 1) : neu mang cho la cau hinh cuoi cung
    }
    else
    {
        int j = n;
        while(X[i] > X[j]) j--;
        swap(X[i],X[[j]);
        reverse(X + i + 1, X + n + 1);
    }
}
// sinh nhi phan
void ktao()
{
    for(int i = 1 ; i <= n ; i ++)
    {
        X[i] = 0
    }
}
void sinh()
{
    int i = n;
    while(i >= 1 && X[i] == 1)
    {
        X[i] = 0;
        i--;
    }
    if(i != 0)
    {
        X[i] = 0;
    }
    else ok = 0;
}
// sinh phan hoach
int main() {
    cin>>n>>k;
    ktao();
    int i = k;
    while(i >= 1 && X[i] == n - k  + i)
    {
        i--;
    }
    if(i == 0)
    {
        for(int j = 1 ; j <=k ; j++)
            X[j]--;
    }
    else
    {
        X[i]++;
        for(int j = i +1 ; j <= k ; j++)
        {
            X[j] = X[j-1] + 1;
        }
    }
    for(int i = 1 ; i <=k ; i++) cout<<X[i]<<" ";
}
