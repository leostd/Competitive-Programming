#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;


class SegmentTree {
private:
    int n;
    vi A, st;
    int left(int p) { return (p << 1); }
    int right(int p) { return (p << 1) + 1; }
    void build(int p, int l, int r) {
        if (l == r) st[p] = l;
        else {
            build(left(p), l, (l+r)/2);
            build(right(p), (l+r)/2 + 1, r);
            int p1 = st[left(p)];
            int p2 = st[right(p)];
            st[p] = (A[p1] <= A[p2]) ? p1 : p2;
        }
    }
    int rmq(int p, int l, int r, int i, int j) {
        if (i > r || j < l) return -1;
        if (l >= i && r <= j) return st[p];
        int p1 = rmq(left(p), l, (l+r)/2, i, j);
        int p2 = rmq(right(p), (l+r)/2 +1, r, i, j);
        if (p1 == -1) return p2;
        if (p2 == -1) return p1;
        return (A[p1] <= A[p2]) ? p1 : p2;
    }
public:
    SegmentTree(const vi &_A, int _n) {
        A = _A;
        n = _n;
        st.assign(4*n, 0);
        build(1, 0, n-1);
    }
    int rmq(int i, int j) { return rmq(1, 0, n-1, i, j); }
};

int main()
{
    //freopen("in", "r", stdin);
    int tc, sc = 1;
    scanf("%d", &tc);
    vi ns(2 << 20, 0);
    while(tc--){
        int n, q, a, b, ans;
        scanf("%d %d", &n, &q);
        for (int i = 0; i < n; ++i)
            scanf("%d", &ns[i]);
        SegmentTree st(ns, n);
        printf("Scenario #%d:\n", sc++);
        for (int i = 0; i < q; ++i) {
            scanf("%d %d", &a, &b);
            ans = st.rmq(a-1, b-1);
            printf("%d\n", ns[ans]);
        }
    }
    return 0;
}