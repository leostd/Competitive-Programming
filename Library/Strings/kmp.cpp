/*
	KMP (Knuth-Morris-Pratt)
	Busca las ocurrencias de un string P en un string H
	Complejidad O(|P|+|H|)
*/
#include <bits/stdc++.h>
using namespace std;
int T[100010];
void build_table(string& P){
	int i = 0, j = -1; T[0] = -1;
	int n = (int)P.length();
	while(i < n){
		while(j >= 0 && P[i] != P[j]) j = T[j];
		i++; j++;
		T[i] = j;
	}
}
void search(string& H, string& P){
	int n = (int)H.length(), m = (int)P.length();
	int i = 0, j = 0;
	while(i < n){
		while(j >= 0 && H[i] != P[j]) j = T[j];
		i++; j++;
		if(j == m){
			printf("%d\n", i - m + 1);
			if(j - 1 >= 0) i--, j = T[j-1];
		}
	}
}