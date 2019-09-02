#include "../library/lib.hpp"
#include <iostream>
using namespace std;

bool cmp(const pii &a, const pii &b){
	if (a.snd < b.snd)
		return true;
	else if (a.snd == b.snd){
		return a.fst < b.fst;
	}
	return false;

}

class OrigamiPunchout {
public:
	void solve(std::istream& in, std::ostream& out) {
	    int n, cs=1;
	    in >> n;
	    while(n--){
	        int w,h,f,p;
	        in >> w >> h >> f >> p;
	        vector<char> folds;
	        vector<pii> punches;
	        char ch;
	        pii punch;
	        REP(i, f)
	            in >> ch, folds.pb(ch);
	        REP(i, p)
	            in >> punch.snd >> punch.fst, punches.pb(punch);
	        REP(i,f){
	            int nw=w, nh=h;
	            if (folds[i] == 'T' || folds[i] == 'B')
	                nh *= 2;
	            else
	                nw *= 2;
	            REP(j,p){
	                if (folds[i] == 'T'){
	                    punches.pb(mp(h-punches[j].fst-1, punches[j].snd));
	                    punches[j].fst += h;
	                }
	                else if (folds[i] == 'B'){
	                    punches.pb(mp(h + abs(h-punches[j]. fst)-1, punches[j].snd));
	                }
	                else if (folds[i] == 'R'){
	                    punches.pb(mp(punches[j].fst,w + w - punches[j].snd-1));
	                }else if (folds[i] == 'L'){
	                    punches.pb(mp(punches[j].fst,  w - punches[j].snd-1));
	                    punches[j].snd += w;
	                }
	            }
	            w = nw, h=nh, p *= 2;
	        }
	        sort(punches.begin(), punches.end(), cmp);
	        out << "Case #" << cs++ << ":\n";
	        REP(i, punches.size()){
	        	out << punches[i].snd << " " << punches[i].fst << "\n";
	        }
	    }

	}
};