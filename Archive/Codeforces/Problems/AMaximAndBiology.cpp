#include "../library/lib.hpp"
#include <iostream>
using namespace std;
char l[27];

int mindist(int a, int b){
	int aux = a;
	int a1, a2;
	a1 = a2 = 0;
	while(l[aux] != l[b]){
		aux = (aux+1)%26;
		a1++;
	}
	aux = a;
	while(l[aux] != l[b]){
		aux = (aux - 1 + 'Z')%'Z';
		a2++;
	}
	return min(a1,a2);
}


class AMaximAndBiology {
public:
	void solve(std::istream& in, std::ostream& out) {
		
		for (char i = 'A'; i <= 'Z'; i++)
			l[i-'A'] = i;
		int n;
		string s;
		in >> n >> s;
		int ans = 0x3f3f3f3f;
		REP(i,s.size()-3){
			int aux = 0;
			aux += mindist(s[i]-'A', 0);
			aux += mindist(s[i+1]-'A', 2);
			aux += mindist(s[i+2]-'A', 'T'-'A');
			aux += mindist(s[i+3]-'A', 'G'-'A');
			ans = min(ans, aux);
		}
        out << ans;
	}
};