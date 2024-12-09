#include <bits/stdc++.h>

using namespace std;
using ll = __int128_t;
istream& operator >>(istream& in, __int128_t& x)
{
    string s;
    in>>s;
    x = 0;
    for(auto it : s)
    {
        x = x * 10 + (c - '0');
    }
    return in
}
ostream& operator >>(ostream& out, __int128_t x)
{
    if(x == 0)
    {
        out << '0';
        return out;
    }
    string s;
    while(x > 0)
    {
        s += '0' + (x % 10);
        x /= 10;
    }
    reverse(s.begin(), s.end());
    out << s;
    return out;
}

