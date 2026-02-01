#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class ACardsWithNumbers {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n, x;
		in >> n;
		map<int, vector<int>> idx;
		RE(i,2*n)
			in >> x, idx[x].pb(i);
		for(auto it = idx.begin(); it != idx.end(); it++){
			if (it->second.size() % 2 != 0){
				out << -1;
				return;
			}
		}
		for(auto it = idx.begin(); it != idx.end(); ++it){
			for(int i = 0; i < it->second.size(); i+=2){
				out << it->second[i] << " " << it->second[i+1] << "\n";
			}
		}
	}
};