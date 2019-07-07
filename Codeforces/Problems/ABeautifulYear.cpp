#include "../library/lib.hpp"
#include <iostream>
using namespace std;



class ABeautifulYear {
public:
	bool check(int y){
		set<int> s;
		while(y > 0){
			if (s.count(y%10) == 0)
				s.insert(y%10);
			else
				return false;
			y /= 10;
		}
		return true;
	}
	void solve(std::istream& in, std::ostream& out) {
		int y;
		in >> y;
		y++;
		while(y > 0){
			if (check(y)){
				out << y;
				return;
			}
			y++;
		}

	}
};