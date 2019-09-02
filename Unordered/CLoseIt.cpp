#include "../library/lib.hpp"
#include <iostream>
using namespace std;

struct nums {
	int fours, eights, fifteens, sixteens, twentythrees, fortytwos;
};
const int MAXN = 500002;
int a[MAXN];
int fours[MAXN], eights[MAXN], fifteens[MAXN], sixteens[MAXN], twentythrees[MAXN], fortytwos[MAXN];

class CLoseIt {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n;
		in >> n;
		memset(fours, 0, sizeof(fours));
		memset(eights, 0, sizeof(eights));
		memset(fifteens, 0, sizeof(fifteens));
		memset(sixteens, 0, sizeof(sixteens));
		memset(twentythrees, 0, sizeof(twentythrees));
		memset(fortytwos, 0, sizeof(fortytwos));
		for (int i = 0; i < n; i++){
			in >> a[i];
			if (a[i] == 4)
			    fours[i]++;
			else if (a[i] == 8 && i > 0 && fours[i-1] > eights[i])
				eights[i]++, fours[i]--;
			else if (a[i] == 15 && i > 0 && eights[i-1] > fifteens[i])
				fifteens[i]++, eights[i]--;
			else if (a[i] == 16 && i > 0 && fifteens[i-1] > sixteens[i])
				sixteens[i]++, fifteens[i]--;
			else if (a[i] == 23 && i > 0 && sixteens[i-1] > twentythrees[i])
				twentythrees[i]++, sixteens[i]--;
			else if (a[i] == 42 && i > 0 && twentythrees[i-1] > fortytwos[i])
				fortytwos[i]++, twentythrees[i]--;
			if (i > 0){
			    fours[i] += fours[i-1];
				eights[i] += eights[i-1];
				fifteens[i] += fifteens[i-1];
				sixteens[i] += sixteens[i-1];
				twentythrees[i] += twentythrees[i-1];
				fortytwos[i] += fortytwos[i-1];
			}
		}
		int mn = fortytwos[n-1];
		int ans = n - (mn*6);
		out << ans;


	}
};