/*
	Manacher Algorithm
	Encuentra el substring palindromo mas largo
	Complejidad: O(n)
*/
#include <bits/stdc++.h>
using namespace std;
char A[100010], B[200020];
int n, m;
int L[200020];
int manacher(){
	int center = 0, rightend = 0;
	L[0] = 0;
	for(int i = 1; i < m; i++){
		if(i < rightend){
			L[i] = min(rightend - i, L[2*center - i]);
		}
		while(B[i + L[i] + 1] == B[i - L[i] - 1]) L[i]++;
		if(i + L[i] > rightend){
			rightend = i + L[i];
			center = i;
		}
	}
	int lps = 0;
	for(int i=0; i<m; i++) lps = max(lps, L[i]);
	return lps;
}
int main(){
	scanf("%d", &n);
	scanf("%s", A);
	m = 0;
	B[m++] = '$';
	B[m++] = '#';
	for(int i=0; i<n; i++){
		B[m++] = A[i];
		B[m++] = '#';
	}
	B[m++] = '@';
	B[m] = '\0';
	printf("%d\n", manacher());
	return 0;
}