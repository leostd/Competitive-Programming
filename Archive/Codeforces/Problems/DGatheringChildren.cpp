#include "../library/lib.hpp"
#include <iostream>
using namespace std;

vector<int> l, r;

int closer_L (int idx){
	auto it = lower_bound(l.begin(), l.end(), idx);
	return *(it);
}

int closer_R (int idx){
	auto it = lower_bound(r.rbegin(), r.rend(), idx, greater<int>());
	return *(it);
}

int mmult(int a, int b){
    return ((a%2) * (b%2))%2;
}

int mpow(int a, int b){
    if (b == 0)
        return 1;
    else if (b % 2 == 0)
        return mpow(mmult(a, a), b/2)%2;
    else
        return mmult(mpow(a, b-1), a);
}

class DGatheringChildren {
public:
	void solve(std::istream& in, std::ostream& out) {
		string s;
		int maxstep = 0;
		in >> s;
        vector<int> squares(s.size(), 1);
		for (int i = 0; i < s.size(); i++)
			if (s[i] == 'L')
				l.pb(i);
			else
				r.pb(i);

        for(int i = 0; i < s.size(); i++){
            if (s[i] == 'L'){
                int closer_r = closer_R(i);
                squares[i]--;
                closer_r++;
                int lastpos = closer_r;
                int diff = i - closer_r;
                lastpos += ((maxstep%2) - (diff%2))%2;
                squares[lastpos]++;
            }else {
                int closer_l = closer_L(i);
                squares[i]--;
                closer_l--;
                int diff = closer_l - i;
                int lastpos = closer_l;
                lastpos += diff%2;
                squares[lastpos]++;
            }
        }
        for (int i = 0; i < squares.size(); i++)
            out << squares[i] << " ";
        l.clear();
        r.clear();
	}
};