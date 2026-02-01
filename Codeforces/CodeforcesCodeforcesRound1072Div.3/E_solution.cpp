#include <bits/stdc++.h>

using namespace std;

vector<int> parent;
vector<int> rnk;
vector<int> sz;

void make_set(int v) {
  parent[v] = v;
  rnk[v] = 0;
  sz[v] = 1;
}

int find_set(int v) {
  if (v == parent[v])
    return v;
  return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
  a = find_set(a);
  b = find_set(b);
  if (a != b) {
    if (rnk[a] < rnk[b])
      swap(a, b);
    parent[b] = a;
    if (rnk[a] == rnk[b])
      ++rnk[a];
    sz[a] += sz[b];
  }
}

long long cnt(int x) {
  x = find_set(x);
  return (long long)sz[x] * (sz[x] - 1) / 2;
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    map<int, vector<int>> m;
    int pr;
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      if (i > 0)
        m[abs(a - pr)].push_back(i);
      pr = a;
    }

    parent.resize(n);
    rnk.resize(n);
    sz.resize(n);
    for (int i = 0; i < n; i++)
      make_set(i);

    vector<long long> ans;
    long long cur = 0;
    for (int i = n - 1; i > 0; i--) {
      for (auto y : m[i]) {
        cur -= cnt(y);
        cur -= cnt(y - 1);
        union_sets(y, y - 1);
        cur += cnt(y);
      }
      ans.push_back(cur);
    }

    reverse(ans.begin(), ans.end());
    for (auto x : ans)
      cout << x << ' ';
    cout << '\n';

    parent.clear();
    rnk.clear();
    sz.clear();
  }

  return 0;
}
