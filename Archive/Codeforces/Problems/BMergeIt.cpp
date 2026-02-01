#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class BMergeIt {
public:
	void solve(std::istream& in, std::ostream& out) {
		ll a[102], t, n;
		in >> t;
		for (int i = 0; i < t; i++){
			in >> n;
            int ans = 0;
            ll ones, twos;
            ones = twos = 0;
			for (int j = 0; j < n; j++){
                in >> a[j];
                if (a[j] % 3 == 0)
                    ans++;
                else if (a[j] % 3 == 1)
                	ones++;
                else if (a[j] % 3 == 2)
                	twos++;
			}
			ll aux = min(ones, twos);
			ones -= aux;
			twos -= aux;
			ans += aux;
			while(twos > 0 && ones > 0){
				ans++;
				ones--;
				twos--;
			}
			while(twos >= 3){
				ans++;
				twos -= 3;
			}
			while(ones >= 3){
				ans++;
				ones -= 3;
			}
			out << ans << "\n";
		}

	}
};