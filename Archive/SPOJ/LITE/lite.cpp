#include <bits/stdc++.h>
#define left(p) p << 1
#define right(p) (p << 1) + 1
using namespace std;

typedef vector<int> vi;

class SegmentTree {
private:
    int n;
    vi A, st, lazy;
    //inline int left(int p) { return (p << 1); }
    //inline int right(int p) { return (p << 1) + 1; }
    inline int rsq(int p, int l, int r, int i, int j) {
        if (lazy[p] != 0) {
            st[p] = (r - l + 1) - st[p];
            if (l != r) {
                lazy[left(p)] = !lazy[left(p)];
                lazy[right(p)] = !lazy[right(p)];
            }
            lazy[p] = 0; 
        }
        if (r < i || l > j) return 0;
        if (l >= i && r <= j) return st[p];
        int n1 = rsq(left(p), l, (l+r)/2, i, j);
        int n2 = rsq(right(p), (l+r)/2+1, r, i, j);
        return n1 + n2;
    }
   inline void update(int p, int l, int r, int i, int j) {
        if (lazy[p] != 0) {
            st[p] = (r - l + 1) - st[p];
            if (l != r) {
                lazy[left(p)] = !lazy[left(p)];
                lazy[right(p)] = !lazy[right(p)];
            }
            lazy[p] = 0;
        }
        
        if (r < i || l > j || r < l) return;
        if (l >= i && r <= j) {
            st[p] = (r - l + 1) - st[p];
            if (l != r) {
                lazy[left(p)] = !lazy[left(p)];
                lazy[right(p)] = !lazy[right(p)];
            }
            return;
        }
        update(left(p), l, (l+r)/2, i, j);
        update(right(p), (l+r)/2+1, r, i, j);
        st[p] = st[left(p)] + st[right(p)];
    }
public:
    SegmentTree(int _n) {
        n = _n;
        st.assign(4*n, 0);
        lazy.assign(4*n, 0);
    }
    int rsq(int i, int j) { return rsq(1, 0, n-1, i, j); }
    void update(int i, int j) { update(1, 0, n-1, i, j); }
};

int main() {
    //freopen("in", "r", stdin);
    int n, m, a, b, c;
    scanf("%d %d", &n, &m);
    SegmentTree st(n);
    for (int i = 0; i < m; ++i) {
        scanf ("%d %d %d", &a, &b, &c);
        if (a)
            printf("%d\n", st.rsq(b-1, c-1));
        else
            st.update(b-1, c-1);
    }
    return 0;
}