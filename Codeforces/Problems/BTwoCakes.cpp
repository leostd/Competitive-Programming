#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
typedef long long ll;

class BTwoCakes {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n;
		int a[200005];
		int pos[2][200005];
		in >> n;
		memset(pos, -1, sizeof(pos));
		for (int i = 0; i < 2*n; ++i){
			in >> a[i];
			if (pos[0][a[i]] != -1)
				pos[1][a[i]] = i;
			else
				pos[0][a[i]] = i;
		}
		ll ans = 0;
		for (int i = 0; i < 2; i++){
			int cur = 0;
			int next = 1;
			int target;
			for (int j = 0; j < n; j++){
			    if (pos[0][next] != -1 && pos[1][next] != -1){
			        if (pos[0][next] < pos[1][next]){
			            target = pos[0][next];
			            pos[0][next] = -1;
			        }else{
                        target = pos[1][next];
                        pos[1][next] = -1;
			        }
			    }
			    else{
			        if (pos[0][next] != -1){
			            target = pos[0][next];
			            pos[0][next] = -1;
			        }
			        else {
			            target = pos[1][next];
			            pos[1][next] = -1;
			        }
			    }
			    ans += abs(target - cur);
			    cur = target;
			    next++;
			}
		}
		out << ans;
	}
};