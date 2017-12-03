/*
	Función Z
	A partir de un String S,
	Z[i] = Longitud del substring mas largo S[i...] que también
	es un prefijo de S
	Complejidad O(|S|)
*/
#include <bits/stdc++.h>
using namespace std;
int Z[100010];
void zFunction(string& S){
	int L = 0, R = 0, n = (int)S.length();
	Z[0] = 0;
	for(int i = 1; i < n; i++){
		if(i > R){
			L = R = i;
			while(R < n && S[R-L] == S[R]) R++;
			Z[i] = R-L; R--;
		}else{
			int k = i - L;
			Z[i] = Z[k];
			if(Z[k] >= R - i + 1){
				L = i;
				while(R < n && S[R-L] == S[R]) R++;
				Z[i] = R - L; R--;
			}	
		}
	}
}
int main(){
	string S;
	cin>>S;
	zFunction(S);
	for(int i = 0; i < S.length(); i++) printf("%d ", Z[i]);
	printf("\n");
}