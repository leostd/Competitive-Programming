#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class BApplemanAndCardGame {
public:
	void solve(std::istream& in, std::ostream& out) {
		ll n,k;
		string s;
		in >> n >> k >> s;

		map<char, ll> m;
		vector<ll> st;
		pii x;
		REP(i,n)
		    m[s[i]]++;
		for(auto it = m.begin(); it != m.end(); ++it)
		    st.pb(it->snd);
		sort(st.begin(), st.end());
		ll ans = 0;
		int i = st.size()-1;
		while(k > 0){
		    ll y = st[i];
		    if (y >= k){
		        ans += k*k;
		    }else{
		        ans += y*y;
		    }
		    i--;
		    k -= y;
		}
		out << ans;

	}
};