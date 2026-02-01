#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class DCandyBoxEasyVersion {
public:
	void solve(std::istream& in, std::ostream& out) {
		int q;
		const int MAXN = 200005;
		in >> q;
		while(q--){
			int n;
			int a[MAXN];
			map<int, int> qnt;
			vector<int> v;
			in >> n;
			for (int i = 0 ; i < n; i++)
				in >> a[i], qnt[a[i]]++;
			for(auto it = qnt.begin(); it != qnt.end(); it++)
				v.pb(it->snd);
			sort(v.begin(), v.end(), greater<int>());
			ll ans = 0;
			int prev = -1;
			bool first = true;
			for (int i = 0; i < v.size(); i++){
				if (first){
					ans+= v[i];
					prev = v[i];
					first = false;
				}else if((prev - 1) >= v[i]){
					ans+= v[i];
					prev = v[i];
				}else if ((prev-1) > 0 && (prev-1) < v[i]){
					ans += prev-1;
					prev--;
				}
			}
			out << ans << "\n";
		}

	}
};