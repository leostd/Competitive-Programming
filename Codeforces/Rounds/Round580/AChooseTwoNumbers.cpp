#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class AChooseTwoNumbers {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n, m;
		
		
		in >> n;
		int a[101];
		for (int i = 0; i < n; i++)
			in >> a[i];
		
		in >> m;
		int b[101];
		for (int i = 0; i < m; i++)
			in >> b[i];
		
		sort(a, a+n);
		sort(b, b+m);
		
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				if (!binary_search(a, a+n, a[i]+b[j]) && !binary_search(b, b+m, a[i]+b[j])){
					out << a[i] << " " << b[j] << "\n";
					return;
				}
			}
			
		}

	}
};