#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define VI vector<int>
#define LL long long
#define pb push_back
#define pii pair<LL,LL>
#define mp make_pair
using namespace std;
string A, B;
int main(){
	cin>>A>>B;
	string R = A;
	string key = B + A;
	for(int i = 0; i < (int)A.length(); i++){
		if(i<(int)B.length()) A[i] = ((int)(A[i]-'A') - (int)(key[i]-'A') + 26)%26 + 'A';
		else{
			int a = A[i]-'A';
			int b = A[i-(int)B.length()]-'A';
			int d = a - b;
			d = (d + 26)%26;
			A[i] = d+'A';
		}
	}
	printf("%s\n", A.c_str());
	return 0;
}