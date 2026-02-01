#include <bits/stdc++.h>
#define left(p) p << 1
#define right(p) (p << 1) + 1 
using namespace std;

typedef vector<int> vi;

int getState(int a, int b) {
    if (b == 3) // to toggle classes 
    {
        if (a == 1)
            return 2;
        if (a == 2)
            return 1;
        if (a == 3)
            return 0;
        if (a == 0)
            return 3;
    }
    else
        return b;
}

int getCount(int a, int i, int j, int v) {
    if (a == 2)
        return 0;
    if (a == 1)
        return j - i + 1;
    if (a == 3)
        return (j - i + 1) - v;
}

class SegmentTree {
private:
    int n;
    vi A, st, lazy;
    //int left(int p) { return p << 1; }
    //int right(int p) { return (p << 1) + 1; }
    void build(int p, int l, int r) {
        if (l == r)
            st[p] = A[l];
        else {
            build(left(p), l, (l+r)/2);
            build(right(p), (l+r)/2 + 1, r);
            int n1 = st[left(p)];
            int n2 = st[right(p)];
            st[p] = n1 + n2;
        }
    }
    int rmq(int p, int l, int r, int i, int j) {
        if (lazy[p]) {
            st[p] = getCount(lazy[p], l, r, st[p]);
            if (l != r) {
                lazy[left(p)] = getState(lazy[left(p)], lazy[p]);
                lazy[right(p)] = getState(lazy[right(p)], lazy[p]);
            }
            lazy[p] = 0;
        }
        if (r < i || l > j) return 0;
        if (l >= i && r <= j) return st[p];
        int mid = (l+r) / 2;
        int n1 = rmq(left(p), l, mid, i, j);
        int n2 = rmq(right(p), mid+1, r, i, j);
        return n1 + n2;
    }
    void update(int p, int l, int r, int i, int j, int v) {
        if (lazy[p]) {
            st[p] = getCount(lazy[p], l, r, st[p]);
            if (l != r) {
                int a = lazy[left(p)];
                int b = lazy[right(p)];
                int c = lazy[p];
                lazy[left(p)] = getState(lazy[left(p)], lazy[p]);
                lazy[right(p)] = getState(lazy[right(p)], lazy[p]);
            }
            lazy[p] = 0;
        }
        if (l > j || r < i) return;
        if (l >= i && r <= j) {
            st[p] = getCount(v, l, r, st[p]);
            if (l != r) {
                lazy[left(p)] = getState(lazy[left(p)], v);
                lazy[right(p)] = getState(lazy[right(p)], v);
            }
            return;
        }
        int mid = (l+r) / 2;
        update(left(p), l, mid, i, j, v);
        update(right(p), mid+1, r, i, j, v);
        st[p] = st[left(p)] + st[right(p)];
    }
public:
    SegmentTree(const vi& _A, int _n) {
        A = _A;
        n = _n;
        st.assign(4*n, 0);
        lazy.assign(4*n, 0);
        build(1, 0, n-1);
    }
    int rmq(int i, int j) { return rmq(1, 0, n-1, i, j); }
    void update(int i, int j, int v) { update(1, 0, n-1, i, j, v); }
};

int main()
{
    //freopen("in", "r", stdin);
    int tc;
    scanf("%d", &tc);
    vi ps((1 << 20) + 2, 0);
    for (int t = 1; t <= tc; ++t) {
        int m; // m sets
        int a, b, sz = 0, qs = 1, q;
        int ch;
        scanf("%d", &m);
        for (int i = 0; i < m; ++i) {
            scanf("%d\n", &a);
            vi aux;
            while(ch = getchar(), ch != '\n') {
                ps[sz++] = (ch == '1') ? 1 : 0;
                aux.push_back((ch == '1') ? 1 : 0);
            }
            for (int j = 1; j < a; ++j) {
                for (int k = 0; k < aux.size(); ++k){
                    ps[sz] = aux[k];
                    sz++;
                }
            }
        }
        // for (int i = 0; i < sz; i++)
        //     printf("%d", ps[i]);
        // printf("\n");
        SegmentTree st(ps, sz);
        printf("Case %d:\n", t);
        scanf("%d\n", &q);
        for (int i = 0; i < q; ++i) {
            ch = getchar();
            scanf("%d %d\n", &a, &b);
            if (ch == 'F')
                st.update(a, b, 1);
            else if (ch == 'E')
                st.update(a, b, 2);
            else if (ch == 'I')
                st.update(a, b, 3);
            else {
                int ans = st.rmq(a, b);
                printf("Q%d: %d\n", qs++, ans);
            }
        // for (int i = 0; i < sz; i++)
        //     printf("%d", ps[i]);
        // printf("\n");
        }
    }
    return 0;
}