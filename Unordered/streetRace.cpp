#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class streetRace {
public:
	void solve(std::istream& in, std::ostream& out) {
        vector<int> A = {5,1,0,2,7,0,6,6,1}, B = {1,0,7,4,2,6,8,3,9}, roots;
        vector<int> g[50005];
        out << "hola" << endl;
        out << to_string(A);
        int k;
        REP(i,A.size()){
            g[A[i]].pb(B[i]);
            g[B[i]].pb(A[i]);
        }
        REP(i, 50003){
            if (g[i].empty())
                continue;
            out << to_string(g[i]);
        }
	}
};