#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class AComparingStrings {
public:
	void solve(std::istream& in, std::ostream& out) {
        string a, b;
        pii aa, bb;
        in >> a >> b;
        int cnt = 0;
        REP(i, a.size()){
            if (cnt == 0 && a[i] != b[i]){
                cnt++;
                aa.first = a[i];
                bb.second = b[i];
            }
            else if (cnt == 1 && a[i] != b[i]){
                cnt++;
                aa.snd = a[i];
                bb.fst = b[i];
            }
            else if(cnt >= 2 && a[i] != b[i]){
                out << "NO";
                return;
            }
        }
        if (aa == bb && a.size() == b.size())
            out << "YES";
        else
            out << "NO";
	}
};