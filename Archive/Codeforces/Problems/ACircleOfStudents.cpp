#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class ACircleOfStudents {
public:
	void solve(std::istream& in, std::ostream& out) {
		int q;
		in >> q;
		while(q--){
			int n;
			vector<int> s;
			int x;

			in >> n;
			for (int i = 0; i < n; i++)
				in >> x, s.pb(x);

			bool flag1 = true;
			for(int i = 0; i < s.size()-1; i++){
				int next = (s[i] + 1) % n;
				next = (next == 0 ? n : next);
				if (next != s[i+1]){
					flag1 = false;
					break;
				}
			}

			bool flag2 = true;
			for (int i = 0; i < s.size()-1; i++){
				int next = ((s[i]%n) - 1 + n) %n;
				next = (next == 0? n: next);
				if (next != s[i+1]){
					flag2 = false;
					break;
				}
			}

			out << (flag1 || flag2 ? "YES\n": "NO\n");
		}

	}
};