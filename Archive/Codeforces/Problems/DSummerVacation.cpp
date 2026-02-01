#include "../library/lib.hpp"
#include <iostream>
using namespace std;

const int N = 1e5 + 10;

int n, m;
priority_queue<int> available;
vector<int> job[N];

class DSummerVacation {
public:
	void solve(std::istream& in, std::ostream& out) {
		in >> n >> m;

		for (int i = 0; i < n; i++) {
			int a, b;
			in >> a >> b;
			job[a].push_back(b);
		}

		int ans = 0;
		for (int i = m - 1; i >= 0; i--) {
			for (int x : job[m - i])
				available.push(x);
			if (!available.empty()) {
				int p = available.top();
				ans += p;
				available.pop();
			}
		}
		out << ans;
	}
};