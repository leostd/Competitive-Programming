#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class AHotelier {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n;
		in >> n;
		char lr;
		int rms[10];
		memset(rms, 0, sizeof(rms));
		for (int i = 0; i < n; i++){
			in >> lr;
			if (isdigit(lr)){
				rms[lr - '0'] = 0;
			}else {
				if (lr == 'R'){
					for (int i = 9; i >= 0; i--)
						if (rms[i] == 0){
							rms[i] = 1;
							break;
						}
							
				}else {
					for (int i = 0; i < 10; i++)
						if (rms[i] == 0){
							rms[i] = 1;
							break;
						}
							
				}
			}
		}
		for(int i = 0; i < 10; i++)
			out << rms[i];
		out << "\n";

	}
};