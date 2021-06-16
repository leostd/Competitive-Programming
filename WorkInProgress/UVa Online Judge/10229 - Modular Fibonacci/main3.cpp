#include <stdio.h>
#include <time.h>
#define LL long long
using namespace std;
class matrix{
public:
	LL m[2][2];
	matrix(LL d = 0){
		m[0][1] = m[1][0] = 0;
		m[0][0] = m[1][1] = d;
	}
};
LL mod;
matrix mmul(matrix& a, matrix& b){
	matrix c;
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 2; j++){
			for(int k = 0; k < 2; k++){
				(c.m[i][j] += a.m[i][k] * b.m[k][j]) %= mod;

			}
		}
	}
	return c;
}
matrix eye;
LL f(int n){
	matrix y;
	y.m[0][1] = y.m[1][0] = y.m[1][1] = 1;
	matrix x = eye;
	while(n){
		if(n&1) x = mmul(x, y);
		y = mmul(y,y);
		n >>= 1;
	}
	return x.m[0][1];
}
int main(){
    time_t start, end;

    time(&start);
	eye = matrix(1);
	int n, m;
	while(scanf("%d %d", &n, &m) != EOF){
		mod = (1<<m);
		printf("%lld\n", f(n));
	}
    time(&end);
    double exec_time = double(end-start);
    printf("Time taken by the program: %lf seconds", exec_time);
}