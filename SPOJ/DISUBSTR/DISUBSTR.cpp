#include <bits/stdc++.h>
#define N 1020
using namespace std;

int sa[N];
char str[N];

bool cmp(int a, int b){ return strcmp(str+a, str+b) < 0;}

int main(){
	int t;
	scanf("%d\n", &t);
	while(t--){
		fgets(str, N, stdin);
		int n = strlen(str);
		n = str[n-1] == '\n' ? n-1 : n;
		int total = n * (n+1) / 2;
		for (int i = 0; i < n; i++) 
			sa[i] = i;
		sort(sa, sa+n, cmp);
		int lcps = 0;
		for (int i = 0; i < n-1; i++){
			int j = 0;
			while(str[sa[i]+j] == str[sa[i+1]+j]){
				lcps++;
				j++;
			}
		}
		printf("%d\n", total-lcps);
	}
	return 0;
}