#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class BTPrimes {
public:
	void solve(std::istream& in, std::ostream& out) {
		ll x;
		int n;
		in >> n;
		Sieve s(1000001);
		vector<ll> primes = s.get_primes();
		set<ll> tprimes;
		REP(i, primes.size())
			tprimes.insert(sqr(primes[i]));
		REP(i,n) {
			in >> x;
			if (tprimes.count(x))
				out << "YES\n";
			else
				out << "NO\n";
		}

	}
};