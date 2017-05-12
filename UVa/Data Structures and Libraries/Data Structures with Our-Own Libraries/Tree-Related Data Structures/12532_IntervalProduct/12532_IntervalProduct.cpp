#include <bits/stdc++.h>
#define MAXN 10e5+5
using namespace std;

typedef vector<int> vi;

class SegmentTree {
private:
    int n;
    vi A, st;
    int left(int p) { return (p << 1); }
    int right(int p) { return (p << 1) + 1; }
    void build(int p, int l, int r) {
        if (l == r)
            st[p] = A[l];
        else{
            build(left(p), l, (l+r)/2);
            build(right(p), (l+r)/2 + 1, r);
            int p1 = st[left(p)];
            int p2 = st[right(p)];
            st[p] = p1*p2;
        }
    }
    int rmq(int p, int l, int r, int i, int j) {
        if (i > r || j < l) return 1;
        if (l >= i && r <= j) return st[p];
        int n1 = rmq(left(p), l, (l+r)/2, i, j);
        int n2 = rmq(right(p), (l+r)/2 +1, r, i, j);
        return n1 * n2;
    }
    void update(int p, int l, int r, int idx, int v) {
        if (l > r || l > idx || r < idx) return;
        if (l == r) {
            st[p] = v;
            return;
        }
        update(left(p), l, (l+r)/2, idx, v);
        update(right(p), (l+r)/2+1, r, idx, v);
        st[p] = st[left(p)] * st[right(p)];
    }
public:
    SegmentTree(const vi& _A, int _n) {
        A = _A;
        n = _n;
        st.assign(4*n, 0);
        build(1, 0, n-1);
    }
    int rmq(int i, int j) { return rmq(1, 0, n-1, i, j); }
    void update(int idx, int v) { update(1, 0, n-1, idx, v); }
};

int main()
{
    //freopen("in", "r", stdin);
    int k, n;
    vi ns(MAXN, 0);
    while(scanf("%d %d", &n, &k) != EOF) {
        string ans = "";
        for (int i = 0; i < n; ++i){
            scanf("%d", &ns[i]);
            if (ns[i] != 0)
                ns[i] = (ns[i] > 0) ? 1 : -1;
        }
        scanf("\n");
        SegmentTree st(ns, n);
        char ch;
        int a, b;
        for (int i = 0; i < k; ++i) {
            ch=getchar();
            scanf("%d %d\n", &a, &b);
            if (ch == 'P') {
                int r = st.rmq(a-1, b-1);
                if (r == 0)
                    ans.push_back('0');
                else
                    ans.push_back((r > 0) ? '+' : '-');
            }
            else
            {
                if (b == 0)
                    st.update(a-1, b);
                else
                    st.update(a-1, (b > 0) ? 1 : -1);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}