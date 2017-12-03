/*
	Persistent Segment Tree
	Ejemplo: Problema DQUERY
	Obtiene la cantidad de elementos distintos en un rango [a,b]
	de un arreglo
*/
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f
#define VI vector<int>
#define pii pair<int,int>
#define matrix vector<VI>
#define LL long long
#define MOD 1000000007
#define ULL unsigned long long
#define uedge(g,a,b) g[a].pb(b), g[b].pb(a)
#define dedge(g,a,b) g[a].pb(b)
using namespace std;
class node{
public:
	node* left, *right;
	int sum;
	node(){
		left = right = NULL;
		sum = 0;
	}
	node(int s, node* L, node* R){
		left = L; right = R; sum = s;
	}
};
int A[1000010];
int n, k, q;
node* PST[1000010];
priority_queue<int,vector<int>,greater<int> > F[1000010];
int freq[1000010];
node* E;
void insert(node* B, node* &T, int li, int ls ,int p, int v){
	if(p >= li && p <= ls){
		if(li == ls){
			T = new node(v, E, E);
		}else{
			int mid = (li + ls) >> 1;
			T = new node(0, E, E);
			insert(B->left, T->left, li, mid, p, v);
			insert(B->right, T->right, mid+1, ls, p, v);
			T->sum = T->left->sum + T->right->sum;
		}
	}else T = B;
}
int query(node* T, int li, int ls, int i, int j){
	if(!T) return 0;
	if(i > ls || j < li) return 0;

	if(li >= i && ls <= j) return T->sum;
	int mid = (li + ls)/2;
	int left = query(T->left, li, mid, i, j);
	int right = query(T->right, mid+1, ls, i, j);
	return left + right;
}
void traverse(node* T, int li, int ls){
	if(li == ls){
		return;
	}
	if(T->left) traverse(T->left, li, (li+ls)>>1);
	if(T->right) traverse(T->right, ((li+ls)>>1) + 1, ls);
}
int main(){
	E = new node(0, NULL, NULL);
	E->left = E; E->right = E;
	scanf("%d", &n); k = 1;
	for(int i = 0; i < n; i++) scanf("%d", &A[i]);
	for(int i = 0; i < n; i++){
		freq[A[i]]++;
		F[A[i]].push(i);
		insert((i == 0) ? (E) : (PST[i-1]), PST[i], 0, n-1, i, 1);
		if(freq[A[i]] > k){
			int f = F[A[i]].top(); F[A[i]].pop();
			insert(PST[i], PST[i], 0, n-1, f, 0);
		}
	}
	scanf("%d", &q);
	int x, y, l, r, last = 0;
	for(int i = 0; i < q; i++){
		scanf("%d %d", &l, &r);
		printf("%d\n", last = query(PST[r-1], 0, n-1, l-1, r-1));
	}
	return 0;
}