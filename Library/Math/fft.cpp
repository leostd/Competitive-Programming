/*
	FFT - Fast Fourier Transform

	Permite obtener la convolución F[n] = sum(i = 0 : n) G[i]*H[n-i]
	en O(n log n)

	Ejemplo: Solución al problema MUL de Spoj
*/
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string.h>
#define EPS 0.5
using namespace std;
const double PI = acos(-1.0);
 
struct Complex
{
    double real, image;
    Complex(double _real, double _image)
    {
        real = _real;
        image = _image;
    }
    Complex(){}
};
 
Complex operator + (const Complex &c1, const Complex &c2)
{
    return Complex(c1.real + c2.real, c1.image + c2.image);
}
 
Complex operator - (const Complex &c1, const Complex &c2)
{
    return Complex(c1.real - c2.real, c1.image - c2.image);
}
 
Complex operator * (const Complex &c1, const Complex &c2)
{
    return Complex(c1.real*c2.real - c1.image*c2.image, c1.real*c2.image + c1.image*c2.real);
}
 
int rev(int id, int len)
{
    int ret = 0;
    for(int i = 0; (1 << i) < len; i++)
    {
        ret <<= 1;
        if(id & (1 << i)) ret |= 1;
    }
    return ret;
}
 
Complex A[1 << 19];
void FFT(Complex *a, int len, int DFT)
{
    for(int i = 0; i < len; i++)
        A[rev(i, len)] = a[i];
    for(int s = 1; (1 << s) <= len; s++)
    {
        int m = (1 << s);
        Complex wm = Complex(cos(DFT*2*PI/m), sin(DFT*2*PI/m));
        for(int k = 0; k < len; k += m)
        {
            Complex w = Complex(1, 0);
            for(int j = 0; j < (m >> 1); j++)
            {
                Complex t = w*A[k + j + (m >> 1)];
                Complex u = A[k + j];
                A[k + j] = u + t;
                A[k + j + (m >> 1)] = u - t;
                w = w*wm;
            }
        }
    }
    if(DFT == -1) for(int i = 0; i < len; i++) A[i].real /= len, A[i].image /= len;
    for(int i = 0; i < len; i++) a[i] = A[i];
    return;
}
char numA[20010], numB[20010];
int n, m, N;
int T[30];
Complex f[100010], g[100010], h[100010];
int answer[100010];
int main(){
	int cases;
	scanf("%d", &cases);
	while(cases--){
	
		for(int i=0; i<=20; i++) T[i] = (1<<i);
		while(scanf("%s %s", numA, numB)!=-1){
			N= strlen(numA), m = strlen(numB);
			n =  N + m;
			for(int i=0; i<=20; i++){
				if(T[i]>=n){
					n = T[i];
					break;
				}
			}
			for(int i=0; i<=n; i++) f[i] = g[i] = h[i] = Complex(0.0,0.0);
			for(int i=0; i<N; i++) g[i] = Complex((numA[N-i-1]-'0'), 0.0);
			for(int i=0; i<m; i++) h[i] = Complex((numB[m-i-1]-'0'), 0.0);
			FFT(g, n, 1);
			FFT(h, n, 1);
			for(int i=0; i<n; i++) f[i] = g[i]*h[i];
			FFT(f, n, -1);
			n = N + m;
			memset(answer, 0, sizeof(answer));
			for(int i=0; i<n; i++) answer[i] = (int)floor(f[i].real + 0.5);
 
			int ac = 0;
			for(int i=0; i<n; i++){
				answer[i] += ac;
				ac = answer[i]/10;
				answer[i] %=10;
			}
			if(ac) answer[n++] = ac;
			while(n>0 && answer[n-1]==0) n--;
			if(n==0 && answer[0]==0) printf("0");
			else for(int i=n-1; i>=0; i--) printf("%d", answer[i]);
			printf("\n");
		}
	}
	return 0;
}