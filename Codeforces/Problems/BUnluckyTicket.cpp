#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class BUnluckyTicket {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n;
		string s;
		in >> n >> s;
		vector<int> n1, n2;
		REP(i,n)
		    n1.pb(s[i]-'0');
		FOR(i,n,2*n-1)
		    n2.pb(s[i]-'0');
		sort(n1.begin(), n1.end());
		sort(n2.begin(), n2.end());
		int i = 0;
		bool first = true;
		bool bigger, smaller;
		bigger = smaller = 0;
		while(i < n){
		    if (first){
		        if (n1[0] > n2[0])
		            bigger = true;
		        else if (n1[0] < n2[0])
		            smaller = true;
		        else{
		            out << "NO";
		            return;
		        }
		        first = false;
		    }
		    else if (bigger){
		        if (n1[i] <= n2[i]){
		            out << "NO";
		            return;
		        }
		    }
		    else if (smaller){
		        if (n1[i] >= n2[i]){
		            out << "NO";
		            return;
		        }
		    }
		    i++;
		}
		out << "YES";
	}
};