#include "../library/lib.hpp"

class BHungrySequence {
public:
	void solve(std::istream& in, std::ostream& out) {
        vector<int> v;
        v.pb(1); v.pb(2); v.pb(3); v.pb(4); v.pb(5); v.pb(6);
        FenwickTree bit(v);
        REP(i, v.size())
            out << bit.get_sum(i) << endl;
	}
};