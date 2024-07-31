#include <bits/stdc++.h>
using namespace std;

int n,a[10001],dem, ok = 1;

void ktao()
{
    dem  = 1;
    a[1] = n;
}
void sinh()
{
    int i = dem;
    while(i >=1 && a[i] == 1)
    {
        i--;
    }
    if(i == 0)
        ok = 0;
    else
    {
        a[i] --;
        int d = dem  - i + 1;
        int q = d / a[i], r = d % a[i];

        dem  = i;

        for(int j = 1 ; j <= q ; j ++)
        {
            dem++;
            a[dem] = a[i];
        }
        if(r != 0)
        {
            dem++;
            a[dem] = r;
        }
    }
}
int main()
{
    cin>>n;
    ktao();jk
    while(ok == 1)
    {
        for(int i = 1 ; i <= dem ; i++)
            cout << a[i] << " ";
        cout << endl;
        sinh();
    }
}
