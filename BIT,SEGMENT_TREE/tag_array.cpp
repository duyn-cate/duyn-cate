#include <bits/stdc++.h>

using namespace std;
const int N = 2e5 + 10;
int a[N];
namespace Segment_tree
{
    int t[N];

}
int main()
{
    freopen("out.txt", "r", stdin);

    int n, q;
    cin>>n>>q;
    for(int i = 1; i <= n ; i++) cin>>a[i];

    vector<int> prefix(n + 1, 0);

    for(int i = 1; i <= n ; i++)
    {
        prefix[i] = prefix[i - 1];
        if(a[i - 1] < a[i])
        {
            prefix[i] += (a[i] - a[i - 1]);
        }
    }
    while(q--)
    {
        int l, r; cin>>l>>r;
        cout << prefix[r] - prefix[l] << endl;
    }
}
