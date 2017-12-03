#include <bits/stdc++.h>
#define MOD 1000000007
#define LL long long
using namespace std;
int n, k;
int sum(int a, int b){
	int x = a + b;
	if(x < 0) x = (x + MOD)%MOD;
	if(x >= MOD) x -= MOD;
	return x;
}
int mul(int a, int b){
	if(a<0) a+=MOD;
	if(b<0) b+=MOD;
	LL x = (LL)a*(LL)b;
	if(x>=MOD) x%=MOD;
	return (int)x;
}
int fpow(int a, int e){
	int x = 1, y = a;
	while(e){
		if(e & 1) x = mul(x,y);
		y = mul(y,y);
		e>>=1;
	}
	return x;
}
int P[1000010];
int main(){
	scanf("%d %d", &n, &k);
	int v = n;
	P[0] = 0;
	for(int i=1; i<=k+1; i++){
		P[i] = sum(P[i-1], fpow(i,k));
	}
	if(n<=k+1){
		printf("%d\n", P[n]);
		return 0;
	}
	/*		 k+1
	Li(n) =  mul   (n - j + 1)
			j = 0    (i - j)
			j!= i
	*/
	int num = 1;
	int dem = 1;
	for(int i=0, j = 0; i<=k+1; i++, j--){
		num = mul(num, sum(n,-i));
		if(j) dem = mul(dem, j);
	} 
	int answer = 0;

	for(int i=0, j = -k-1; i<=k+1; i++, j++){
		if(j==0) j++;
		int inv = sum(n,-i);
		int A = mul(num, fpow(inv, MOD-2));
		int B = mul(A, fpow(dem, MOD-2));
		dem = mul(dem, fpow(j, MOD-2));
		dem = mul(dem, i+1);
		answer = sum(answer, mul(P[i], B));
	}
	printf("%d\n", answer);
	return 0;
}