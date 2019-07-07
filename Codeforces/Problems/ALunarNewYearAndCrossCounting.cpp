#include <iostream>

class ALunarNewYearAndCrossCounting {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n;
		char m[600][600];
		in >> n;
		for (int i = 0; i < n; i++){
		    for (int j = 0; j < n; j++){
		        in >> m[i][j];
		    }
		}
		int ans = 0;
		for (int i = 1; i < n; i++){
		    for (int j = 1; j < n; j++){
		        if(m[i][j] == 'X' && m[i+1][j-1] == 'X' && m[i+1][j+1] == 'X' && m[i-1][j-1] == 'X' && m[i-1][j+1] == 'X')
		        	ans ++;
		    }
		}
		out << ans;
	}
};