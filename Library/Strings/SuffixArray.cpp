// Naive implementation of Suffix Array
// Time Complexity: O(n^2logn)
#include <bits/stdc++.h>
#define N 1010
using namespace std;

char str[N];
int sa[N];

bool cmp(int a, int b) { return strcmp(str+a, str+b) < 0; } // O(n)

int main(){
	int n = (int)strlen(gets(str));
	for (int i = 0; i < n; i++)
		sa[i] = i;
	sort(sa, sa+n, cmp); // O(nlogn)
	for(int i = 0; i < n; i++)
		printf("%2d\t%s\n", sa[i], str+sa[i]);
	return 0;
}