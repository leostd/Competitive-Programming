#include "../library/lib.hpp"
#include <iostream>
using namespace std;
#define N 1001
int arr[N];


class ALittleElephantAndFunction {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n;
		in >> n;
		for(int i = 1; i <= n-1; i++)
			arr[i] = i;
		arr[0] = n;
		REP(i,n)
			out << arr[i] << " ";

	}
};