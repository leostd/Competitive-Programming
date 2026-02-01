#include <bits/stdc++.h>
#define N 1000000
using namespace std;

typedef long long int lli;

int sum[N];
int primes[N];
bitset<N> prime;
int t;
int k = 0;
lli num;

void setPrimes(){
    sum[1] = 1;
    prime.set();
    for (int i = 2; i <= N; ++i)
    {
        if (prime[i])
        {
            for (int j = 2*i; j <= N; j += i)
                prime[j] = false;
            sum[i] = 1;
            primes[k++] = i;
        }
    }
}

bool isPrime(lli NM) {                 
  if (NM <= N) return prime[NM];
  for (int i = 0; i < k; i++)
    if (NM % primes[i] == 0) return false;
  return true;                    
}   

int findProperDivisors(lli n)
{
    if (n == 0)
        return 0;
    if (isPrime(n))
        return 0;
    if (n < N && sum[n]!= -1)
        return sum[n];
    lli ans = 0;
    for (int i = 2; i <= sqrt(n); ++i)
    {
        if (n % i == 0)
        {
            if (n/i != i)
                ans += (n/i) + findProperDivisors(n/i) + i + findProperDivisors(i) ;
            else
                ans += i + findProperDivisors(i);
            break;
        }        
    }
    if (n < N)
        return sum[n] = ans;
    else 
        return ans;
}
int main()
{
    scanf("%d", &t);
    setPrimes();
    memset(sum, -1, sizeof(sum));
    while(t--)
    {
        scanf("%lli", &num);
        int ans = findProperDivisors(num)+1;
        if (ans == num)
            printf("perfect");
        else if (ans < num)
            printf("deficient");
        else
            printf("abundant");
        printf("\n",k); 
    }
    return 0;
}