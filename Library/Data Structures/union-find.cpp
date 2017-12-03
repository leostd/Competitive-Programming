#include <bits/stdc++.h>
using namespace std;

class UF{
public:
    int components;
    int P[505];
    UF(int n){
        components = n;
        for (int i = 0; i < n; i++)
            P[i] = i;
    }
    int Find(int x)
    {
        if (x != P[x])
            return P[x] = Find(P[x]);
        return x;
    }
    int Union(int x, int y)
    {
        int xroot, yroot;
        xroot = Find(x);
        yroot = Find(y);
        if (xroot != yroot)
        {
            components--;
            P[yroot] = xroot;
        }
    }
};

int main(){
	UF uf(10);
	uf.Union(1, 2);
	uf.Union(3, 4);
	uf.Union(5, 6);
	uf.Union(7, 8);
	uf.Union(9, 0);
	printf("%d\n", uf.components);
	return 0;
}