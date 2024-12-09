#include <bits/stdc++.h>

using namespace std;

class Fenwick_tree
{
private :
    int n;
    vector<vector<int>> bit;
public:
    Fenwick_tree (int size)
    {
        this->n = size;
        bit.assign(n + 5, vector<int> (n + 5, 0));
    }
    void up(int x, int y, int val)
    {
        for(int i = x; i <= n; i +=(i & -i))
        {
            for(int j = y; j <= n; j += (j & -j))
            {
                bit[i][j] += val;
            }
        }
    }
    int get(int x, int y)
    {
        int sum = 0;
        for(int i = x ; i > 0 ; i -=(i & -i))
        {
            for(int j = y; j > 0; j -= (j & -j))
            {
                sum += bit[i][j];
            }
        }
        return sum;
    }
    int query(int x1, int y1, int x2, int y2)
    {
        return (get(x2, y2) - get(x2, y1 - 1) - get(x1 - 1, y2) + get(x1 - 1, y1 - 1));
    }
};
const int N = 1001;
char a[N][N];
signed main()
{
    int n,q; cin>>n>>q;
    Fenwick_tree fen(n + 1);

    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = 1; j <= n ; j++)
        {
            cin>>a[i][j];
        }
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j= 1; j <= n; j++)
        {
            if(a[i][j] == '*')
            {
                fen.up(i,j,1);
//                fen.up(j,i,1);
            }
        }
    }
    while(q--)
    {
        int x1, y1, x2,y2;
        cin>>x1>>y1>>x2>>y2;
        cout << fen.query(x1,y1,x2,y2) << endl;
    }
}
