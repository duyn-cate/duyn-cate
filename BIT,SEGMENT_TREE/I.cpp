    #include <bits/stdc++.h>

    using namespace std;
    string s;
    const int N = 2e5 + 10;
    struct node
    {
        int cnt1, cnt0, cnt;
        node() = default;
        node(int a)
        {
            cnt = 0;
            cnt1 = (a == 1);
            cnt0 = (a == 0);
        }
    };
    int a[N];
    namespace Segment_tree
    {
        node t[N * 4];
        node operator +(const node &l, const node &r)
        {
            node res = node();

            res.cnt1 = l.cnt1 + r.cnt1 - min(l.cnt0, r.cnt1);
            res.cnt0 = l.cnt0 + r.cnt0 - min(l.cnt0, r.cnt1);
            res.cnt = l.cnt + r.cnt + min(l.cnt0, r.cnt1);
            return res;
        }
        void build(int id, int l, int r)
        {

            if(l == r)
            {
                t[id] = node(a[l]);
                return;
            }
            int m = l + r >> 1;
            build(id << 1, l ,m);
            build(id << 1 | 1, m + 1, r);
            t[id] = t[id << 1] + t[id << 1 | 1];
        }
        void up(int id, int l, int r, int pos, int val)
        {
            if(pos < l || pos > r) return;
            if(l == r && r == pos)
            {
                t[id] = node(val);
                return;
            }
            int m = l + r >> 1;
            up(id << 1, l ,m, pos, val);
            up(id << 1 | 1, m + 1, r, pos, val);

            t[id] = t[id << 1] + t[id << 1 | 1];
        }
        node get(int id, int l, int r, int u, int v)
        {
            if(v < l || r < u) return node();
            if(u <= l && r <= v)
            {
                return t[id];
            }
            int m = l + r >> 1;
            node L = get(id << 1, l, m, u, v);
            node R = get(id << 1 | 1, m + 1, r, u, v);

            return (L + R);
        }
    }
    using namespace Segment_tree;

    signed main()
    {
        cin>>s;
        int n = s.size();
        for(int i = 1;  i <= n ; i++)
            a[i] = (s[i - 1] - '0');
        build(1,1,n);
        int q;
        cin>>q;
        while(q--)
        {
            int type;
            cin>>type;
            if(type == 1)
            {
                int pos; cin>>pos;
                a[pos] = a[pos] ^ 1;
                up(1,1,n,pos,a[pos]);
            }
            else
            {
                int u, v;
                cin>>u>>v;
                int cntx = get(1,1,n,u,v).cnt;
                int len = v - u + 1;
                cout << (len - cntx * 2) << "\n";
            }
        }
    }
