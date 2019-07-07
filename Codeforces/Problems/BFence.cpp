#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class BFence {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n, k;
		in >> n >> k;
		vector<int> a;
		int x;
		REP(i, n)
			in >> x, a.pb(x);
		int ms = 0x3f3f3f3f, mi = n+19;
		deque<int> dq;
		int sum = 0;
		bool first = true;
		REP(i, n-k+1){
			if (first){
				for (int j = 0; j < k; j++){
					dq.push_back(a[i+j]);
					sum += a[i+j];
				}
				first = false;
			}
			else {
				sum -= dq.front();
				dq.pop_front();
				dq.push_back(a[i+k-1]);
				sum += a[i+k-1];
			}
			if (dq.size() == k && sum < ms){
				ms = sum;
				mi = i+1;
			}
		}
		out << mi;
		
	}
};