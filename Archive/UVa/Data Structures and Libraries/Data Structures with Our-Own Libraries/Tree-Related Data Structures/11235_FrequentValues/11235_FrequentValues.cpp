#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <string.h>
#include <vector>
#include <map>
#define MAXN (int)10e5+9
using namespace std;

typedef vector<int> vi;


class SegmentTree {
private: vi st, A;
    int n;
    int left(int p) { return p << 1; }
    int right(int p) { return (p << 1) + 1; }

    void build(int p, int l, int r) {
        if (l == r)
            st[p] = l;
        else {
            build(left(p), l, (l+r)/2);
            build(right(p), (l+r)/2 + 1, r);
            int p1 = st[left(p)], p2 = st[right(p)];
            st[p] = (A[p1] >= A[p2]) ? p1 : p2;
        }
    }

    int rmq(int p, int l, int r, int i, int j) {
        if (i > r || j < l) return -1;
        if (l >= i && r <= j) return st[p];

        int p1 = rmq(left(p), l, (l+r)/2, i, j);
        int p2 = rmq(right(p), (l+r)/2 + 1, r, i, j);

        if (p1 == -1) return p2;
        if (p2 == -1) return p1; 
        return (A[p1] >= A[p2]) ? p1 : p2;
    }

public:
    SegmentTree(const vi &_A, int _n) {
        A = _A; n = _n;
        st.assign(4*n, 0);
        build(1, 0, n-1); 
    }

    int rmq(int i, int j) { return rmq(1, 0, n-1, i, j); }
};

vi numbers(MAXN, 0), frq(MAXN, 0);
int n, q;
map<int, int> freq, start;

int main()
{
    //freopen("in", "r", stdin);
    while(scanf("%d %d", &n, &q), n){
        start.clear();
        freq.clear();
        for (int i = 0; i < n; i++){
            scanf("%d", &numbers[i]);
            freq[numbers[i]]++;
            if (freq[numbers[i]] == 1)
                start[numbers[i]] = i;
        }
        for (int i = 0; i < n; i++) {
            int aux = freq[numbers[i]];
            frq[i] = freq[numbers[i]];
        }
        SegmentTree st(frq, n);
        int a, b, ans, cnt1, cnt2, cnt3;
        for (int i = 0; i < q; i++){
            scanf("%d %d", &a, &b);
            a--;
            b--;
            if (numbers[a] == numbers[b])
                ans = b - a + 1;
            else {
                cnt1 = freq[numbers[a]] + start[numbers[a]] - a;
                cnt2 = b - start[numbers[b]] + 1;
                cnt3 = st.rmq(start[numbers[a]]+freq[numbers[a]], start[numbers[b]]-1);
                ans = max(max(cnt1, cnt2), (cnt3 == -1) ? -1 : frq[cnt3]);
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}

