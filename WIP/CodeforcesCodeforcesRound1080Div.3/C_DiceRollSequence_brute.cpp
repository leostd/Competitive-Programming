// Brute-force / reference solution for Dice Roll Sequence (CF 2195 C).
// Compile and run: same I/O as main solution. Use with gen to compare.

/*
  PATTERN: Sequence DP with small alphabet and adjacent-pair constraint
  - Positions 0..n-1, value at each position in alphabet [1..K] (here K=6).
  - Constraint: only certain (prev, cur) pairs are allowed.
  - Cost: minimize number of positions we "change" (or any per-position cost).

  Structure:
    1. valid(u, v)  — whether u at i-1 and v at i is allowed.
    2. dp[i][v] = min over valid u of ( dp[i-1][u] + cost(i, v) ).
    3. Base: dp[0][v] = cost(0, v) for each v.
    4. Answer: min_v dp[n-1][v].

  Space: O(n * K). Time: O(n * K^2). Often reducible to O(n * K) with prefix/suffix mins.
*/

#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)

static const int INF = 1e9;

bool valid_pair(int u, int v) {
  return u != v && u + v != 7;
}

int solve_brute(const vector<int>& a) {
  int n = (int)a.size();
  if (n <= 1) return 0;

  // dp[i][v] = min number of changes to make a[0..i] valid with a[i] = v (v in 1..6)
  vector<array<int, 7>> dp(n);
  forn(i, n) forn(v, 7) dp[i][v] = INF;

  for (int v = 1; v <= 6; v++)
    dp[0][v] = (v != a[0] ? 1 : 0);

  for (int i = 1; i < n; i++) {
    for (int v = 1; v <= 6; v++) {
      int cost = (v != a[i] ? 1 : 0);
      for (int u = 1; u <= 6; u++) {
        if (!valid_pair(u, v)) continue;
        dp[i][v] = min(dp[i][v], dp[i - 1][u] + cost);
      }
    }
  }

  int ans = INF;
  for (int v = 1; v <= 6; v++)
    ans = min(ans, dp[n - 1][v]);
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    forn(i, n) cin >> a[i];
    cout << solve_brute(a) << '\n';
  }
  return 0;
}
