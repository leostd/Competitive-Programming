#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class ACinemaLine {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n, x;
		queue<int> q;
		in >> n;
		REP(i, n){
			in >> x;
			q.push(x);
		}
		int change_50, change_25;
		change_50 = change_25 = 0;
		while(!q.empty()){
			int b = q.front();
			q.pop();
			if (b == 25)
				change_25++;
			else if (b == 50){
				if (change_25 < 1){
					out << "NO";
					return;
				}
				else
					change_25--, change_50++;
			}
			else if (b == 100){
				if ((change_50 < 1 || change_25 < 1) && (change_25 < 3)){
					out << "NO";
					return;
				} 
				else if(change_50 > 0 && change_25 > 0)
					change_25--, change_50--;
				else
					change_25 -= 3;
			}
		}
		out << "YES";

	}
};