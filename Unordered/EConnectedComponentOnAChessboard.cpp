#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class EConnectedComponentOnAChessboard {
public:
	void solve(std::istream& in, std::ostream& out) {
		int q;
		in >> q;
		while(q--){
			int b,w;
			in >> b >> w;
			pii s, cur;
			vector<pii> ans;
			if (b > w){
				s = pii(2,2);
				ans.pb(s);
				for(int i = 3; i <= 2*w; i++){
					ans.pb(pii(2, i));
				}
				assert(ans.size() >= w);
				int bs = w-1;
				int sz = ans.size();
				for (int i = 0; i < sz; i+=2){
					cur = ans[i];
					ans.pb(pii(1, cur.snd));
					ans.pb(pii(3, cur.snd));
					bs += 2;
				}
				ans.pb(pii(2, 1));
				ans.pb(pii(2, 2*w+1));
				bs+=2;
				if (bs >= b){
					out << "YES\n";
					REP(i, w+b)
						out << ans[i].first << " " << ans[i].snd << "\n";
				}else{
					out << "NO\n";
				}
			} else {
				s = pii(2, 3);
				ans.pb(s);
				for(int i = 1; i < 2*b; i++){
					ans.pb(pii(2, 3+i));
				}
				assert(ans.size() >= b);
				int ws = b-1;
				int sz = ans.size();
				for (int i = 0; i < sz; i+=2){
					cur = ans[i];
					ans.pb(pii(1, cur.snd));
					ans.pb(pii(3, cur.snd));
					ws += 2;
				}
				ans.pb(pii(2,2));
				ans.pb(pii(2, 3 + (2*(b-1) + 1)));
				ws+=2;
				if (ws >= w){
					out << "YES\n";
					REP(i, w+b)
						out << ans[i].first << " " << ans[i].snd << "\n";
				}else{
					out << "NO\n";
				}
			}
			
		}
	}
};