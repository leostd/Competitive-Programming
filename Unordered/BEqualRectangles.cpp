#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class BEqualRectangles {
public:
	void solve(std::istream& in, std::ostream& out) {
		int q;
		in >> q;
		while(q--){
			map<int,int> m, p;
			vector<int> ns;
			int x;
			int n;
			in >> n;
			for (int i = 0; i < 4*n;i++)
				in >> x, m[x]++;
			
			bool valid = true;
			for (auto it = m.begin(); it != m.end(); ++it){
				if (it->snd % 2){
					valid = false;
					break;
				}
				while(it->snd > 0)
					ns.pb(it->fst), it->snd-=2;
			}
			sort(ns.begin(), ns.end());

			bool flag = false;
			int l = 0, r = ns.size()-1;
			while(l < r){
				p[ns[l]*ns[r]]++;
				if (p[ns[l]*ns[r]] == n)
					flag = true;
				l++;r--;
			}


			out << (flag && valid ? "YES\n" : "NO\n");

		}

	}
};