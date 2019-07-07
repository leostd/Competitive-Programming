#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class DEqualizeThemAll {
public:
	void solve(std::istream& in, std::ostream& out) {
		map<int,int> cnt;
		map<int,vector<int>> pos;
		int x, n, nx=-111, mx=0;
		in >> n;
		vector<int> a;
		REP(i,n){
            in >> x, a.pb(x), cnt[x]++;
            if (cnt[x] > mx){
                mx = cnt[x];
                nx = x;
            }
            pos[x].pb(i);
		}
		out << (n - cnt[nx]) << "\n";
        queue<int> q;
        REP(i,pos[nx].size())
            q.push(pos[nx][i]);
        while(!q.empty()){
            int i, ii, cur;
            cur = q.front();
            q.pop();
            i = cur-1;
            ii = cur+1;
            if (i >= 0){
                if (a[i] != nx){
                    if (a[i] < nx){
                        out << 1 << " " << i+1 << " " << cur+1 << " ";
                        a[i] = nx;
                    }
                    else{
                        out << 2 << " " << i+1 << " " << cur+1 << " ";
                        a[i] = nx;
                    }
                    out << "\n";
                    q.push(i);
                }
            }
            if (ii < n){
                if (a[ii] != nx){
                    if (a[ii] < nx){
                        out << 1 << " " << ii+1 << " " << cur+1 << " ";
                        a[ii] = nx;
                    }else{
                        out << 2 << " " << ii+1 << " " << cur+1 << " ";
                        a[ii] = nx;
                    }
                    out << "\n";
                    q.push(ii);
                }
            }

        }
	}
};