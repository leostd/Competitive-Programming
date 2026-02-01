#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class BLetter {
public:
	void solve(std::istream& in, std::ostream& out) {
		string a, b;
		map<char, int> ma, mb;
		getline(in, a);
		getline(in, b);
		REP(i,a.size()){
			if (a[i] != ' ' && a[i] != '\n')
				ma[a[i]]++;
		}
		REP(i,b.size()){
			if(b[i] != ' ' && b[i] != '\n')
				mb[b[i]]++;
		}
		for(auto it = mb.begin(); it != mb.end(); ++it){
			if (it->snd > ma[it->fst]){
				out << "NO";
				return;
			}
			else{
				ma[it->fst] -= it->snd;
			}
		}
		out << "YES";
		return;

	}
};