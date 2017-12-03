/*
	Algoritmo de Mo
	Permite responder ciertas queries por rango en O(sqrt(n)) 
	ALGORITMO OFFLINE!!!
	Ejemplo: query(a,b) = numeros distintos en el rango [a,b] de un arreglo
*/
#include <bits/stdc++.h>
#define LL long long
#define INF 0x3f3f3f3f
#define VI vector<int>
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define matrix vector<VI>
using namespace std;
int n, q;
int A[100010];
int SQ;
class query{
public:
	int l, r, id;
	query(){}
	query(int a, int b, int c){
		l = a; r = b; id = c;
	}
	bool operator<(const query& other) const{
		if(l/SQ != other.l/SQ) return l/SQ < other.l/SQ;
		return r<other.r;
	}
};
query Q[100010];
int ANS[100010];
int app[1000010];
int total = 0;
void add(int x){
	if(app[A[x]]==0) total++;
	app[A[x]]++;
}
void rmv(int x){
	if(app[A[x]]==1) total--;
	app[A[x]]--;
}
int main(){
	scanf("%d", &n);
	memset(app, 0, sizeof(app));
	for(int i=0; i<n; i++){
		scanf("%d", &A[i]);
	}
	SQ = (int)sqrt(n);
	scanf("%d", &q);
	for(int i=0; i<q; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		x--; y--;
		Q[i] = query(x,y,i);
	}
	sort(Q, Q+q);
	int L = 0, R = -1;
	total = 0;
	for(int i=0; i<q; i++){
		while(R < Q[i].r) add(++R);
		while(R > Q[i].r) rmv(R--);
		while(L < Q[i].l) rmv(L++);
		while(L > Q[i].l) add(--L);
		ANS[Q[i].id] = total;
	}
	for(int i=0; i<q; i++) printf("%d\n", ANS[i]);
	return 0;
}
