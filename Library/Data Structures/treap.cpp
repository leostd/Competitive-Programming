/*
	Implicit Treap
	Arbol que cumple con las propiedades del Heap y del BST
	BST en las keys, Heap en las prioridades
	Usando prioridades aleatorias, es muy poco probable que no quede balanceado
	Caso de ejemplo:
		RMQ en un arreglo dinamico
		Input: Q queries qi
		qi = 0, a,b: Imprimir el elemento minimo en el rango a,b
		qi = 1, a,b: Invertir los elementos del rango a,b
		qi = 2, a,b: Insertar un nuevo elemento b en la posicion a del arreglo
		qi = 3, a: 	 Eliminar el elemento en la posicion a
	Complejidad: Query O(log n)* 
*/
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
int n, q;
class treap{
public:
	int key, prior, sz, dir, value;
	treap* left, *right;
	bool rev;
	int minimum;
	treap(){ left = NULL; right = NULL; sz = 0; dir = 0;}
	treap(int _key, int _prior, int _value){
		key = _key; prior = _prior; value = _value; dir = 0;
		left = NULL; right = NULL;
		rev = false; sz = 1;
		minimum = value;
	}	
};
int getSize(treap* t){
	if(!t) return 0;
	return t->sz;
}
void push(treap* &t){
	if(t && t->rev){
		swap(t->left, t->right);
		if(t->left) t->left->rev ^= true;
		if(t->right) t->right->rev ^= true;
		t->rev = false;
	}
}
void upd(treap* &t){
	if(!t) return;
	t->minimum = t->value;
	t->sz = 1;
	if(t->left){
		t->minimum = min(t->minimum, t->left->minimum);
		t->sz += getSize(t->left);
	}
	if(t->right){
		t->minimum = min(t->minimum, t->right->minimum);
		t->sz += getSize(t->right);
	}
}
void split(treap* t, int key, treap* &L, treap* &R, int add){
	push(t);
	if(t==NULL){
		L = NULL; R = NULL;
	}else{
		int imp_key = getSize(t->left) + add;
		if(key <= imp_key){
			split(t->left, key, L, t->left, add);
			R = t;
		}else{
			split(t->right, key, t->right, R, imp_key + 1);
			L = t;
		}
		upd(t);
	}
}
void merge(treap* &t, treap* L, treap* R){
	push(L);
	push(R);
	if(!L || !R){
		t = L ? L : R;
		upd(t);
	}else{
		if(L->prior > R->prior){
			merge(L->right, L->right, R);
			t = L;
		}else{
			merge(R->left, L, R->left);
			t = R;
		}
		upd(t);
	}
}
void insert(treap* &t, int key, treap* &ins, int add){
	if(!t){
		t = ins;
	}else if(ins->prior > t->prior){
		split(t, key, ins->left, ins->right, add);
		t = ins;
	}else{
		int imp_key = add + getSize(t->left);
		if(key <= imp_key) insert(t->left, key, ins, add);
		else insert(t->right, key, ins, imp_key + 1);
	}
	upd(t);
}
void erase(treap* &t, int key, int add){
	if(!t) return;
	int imp_key = getSize(t->left) + add;
	if(imp_key == key) merge(t, t->left, t->right);
	else if(key <= imp_key) erase(t->left, key, add);
	else erase(t->right, key, imp_key + 1);
}
void query(treap* &t, int qi, int l, int r){
	if(qi == 2){
		int p = rand();
		treap* ins = new treap(l, p, r);
		insert(t, l, ins, 0);
	}else if(qi == 3){
		erase(t, l, 0);
	}else{
		treap *a, *b, *c;
		split(t, l, a, b, 0);
		split(b, r-l+1, b, c, 0);
		if(qi==0) printf("%d\n", b->minimum);
		else if(qi==1) b->rev ^= true;
		merge(t, a, b);
		merge(t, t, c);
	}
}
int main(){
	srand(time(NULL));
	treap* root = NULL;
	int q;
	scanf("%d", &q);
	while(q--){
		int qi, a, b = 0;
		scanf("%d %d", &qi, &a);
		if(qi != 3) scanf("%d", &b);
		query(root, qi, a, b);
	}
}