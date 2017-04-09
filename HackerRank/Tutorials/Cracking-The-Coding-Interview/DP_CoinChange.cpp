#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

typedef long long ll;
ll memo[55][255];

ll make_change(vector<int> coins, ll money) {
	for (int i = 1; i < coins.size(); i++) {
		for (int j = 1; j <= money; j++)
		{
			if (j - coins[i] >= 0)
				memo[i][j] = memo[i - 1][j] + memo[i][j - coins[i]];
			else
				memo[i][j] = memo[i - 1][j];
		}
	}
	return memo[coins.size() - 1][money];
}

int main() {
	int n;
	int m;
	cin >> n >> m;
	vector<int> coins(m);
	for (int i = 0; i <= n + 1; i++) {
		memo[0][i] = 0; // no way to give change for money > 0
		if (i <= m)
			memo[i][0] = 1; // only 1 way to give change for money == 0
	}

	for (int coins_i = 0;coins_i < m;coins_i++) {
		cin >> coins[coins_i];
	}
	coins.push_back(0);
	sort(coins.begin(), coins.end());
	cout << make_change(coins, n) << endl;
	return 0;
}
