#include "../library/lib.hpp"
#include <iostream>
using namespace std;

int dist(const vector<int> &a, const vector<int> &b){
    double ans = 0;
    for (int i = 0; i < a.size(); i++){
        ans += sqr(a[i]-b[i]);
    }
    return sqrt(ans) == trunc(sqrt(ans));
}

class BGoodDistance {
public:
	void solve(std::istream& in, std::ostream& out) {
	    int n, d;
	    in >> n >> d;
	    vector<vector<int>> x;
	    vector<int> a;
	    int m;
	    for (int i = 0; i < n; i++){
	        a.clear();
	        for (int j = 0; j < d; j++){
	            in >> m;
	            a.pb(m);
	        }
	        x.pb(a);
	    }
	    int ans = 0;
	    for (int i = 0; i < n; i++){
	        for (int j = i+1; j < n; j++){
	            ans += dist(x[i], x[j]);
	        }
	    }
        out << ans;
	}
};