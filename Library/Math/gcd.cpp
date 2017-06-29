#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef set<ll> si;

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}

ll lcm(ll a, ll b) {
	return (a*b) / gcd(a, b);
}


si divisors(ll n){
	si d;
	for(ll p = 1; p*p <= n; ++p){
		if (n % p == 0){
			if (n/p != p)
				d.insert(n/p);
			d.insert(p);
		}
	}
	return d;
}

// Function to find length of period in 1/n
int getPeriod(int n)
{
   // Create a map to store mapping from remainder
   // its position
   map<int, int> mymap;
   map<int, int>::iterator it;
 
   // Initialize remainder and position of remainder
   int rem = 1, i = 1;
 
   // Keep finding remainders till a repeating remainder
   // is found
   while (true)
   {
   		// print the number
        if (mymap.find((10*rem)%n) == mymap.end())
          printf("%d", (10*rem)/n);
      	// Find next remainder
        rem = (10*rem) % n;
        // If remainder exists in mymap, then the difference
        // between current and previous position is length of
        // period
        it = mymap.find(rem);
        if (it != mymap.end())
            return (i - it->second);
 
        // If doesn't exist, then add 'i' to mymap
        mymap[rem] = i;
        i++;
   }
 
   // This code should never be reached
   return -1;
}