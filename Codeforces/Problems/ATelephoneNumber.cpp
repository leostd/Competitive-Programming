#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class ATelephoneNumber {
public:
	void solve(std::istream& in, std::ostream& out) {
		int t;
		in >> t;
		while(t--){
			string x, n;
			in >> x >> n;
			bool flag = false;
			for (int i = 0; i < n.size(); i++){
				if (n[i] =='8'){
					if ((n.size() - i) >= 11){
						out << "YES\n", flag = true;
					}else{
						out << "NO\n", flag = true;
					}
					break;
				}
			}
			if (!flag)
				out << "NO\n";
		}

	}
};