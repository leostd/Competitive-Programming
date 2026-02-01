#include <bits/stdc++.h>
#define int long long
using namespace std;

int calc(int a, int b) {
  if (a > b)
    swap(a, b);
  return a * 3 + (b - a) * 2 - 1;
}

signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  ///
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    if (n - k + 1 < k)
      k = n - k + 1;
    int a = 0, b = 0;
    int ta = k - 1;
    int tb = n - k;
    while (true) {
      if (a < ta && b < tb && calc(a + 1, b + 1) <= m) {
        ++a, ++b;
        continue;
      }
      if (b < tb && calc(a, b + 1) <= m) {
        ++b;
        continue;
      }
      break;
    }
    cout << a + b + 1 << '\n';
  }
}
