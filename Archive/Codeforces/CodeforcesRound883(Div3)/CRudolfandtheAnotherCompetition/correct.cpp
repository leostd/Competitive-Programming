#include <bits/stdc++.h>
#include <unordered_set>
#include <string.h>
#define ll long long
#define Fast_Warak ios_base::sync_with_stdio(false); cin.tie(NULL);
#define loop(n) for(ll i=0 ; i<n ; i++)
#define rloop(n) for(ll i=n-1 ; i>=0 ; i--)
#define lp(start, end) for(ll i=start ; i<=end ; i++)
#define rlp(start, end) for(ll i=start ; i>=end ; i--)
#define b_e(v) v.begin(), v.end()
const ll max_ele = 1e18;
 
using namespace std;
 
void file(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}
 
bool cmp(pair<ll, ll> &a, pair<ll, ll> &b){
    if(a.first>b.first)return true;
    else if(a.first==b.first&&a.second<b.second)return true;
    return false;
}
 
int main()
{
    //file();
    Fast_Warak
    int t_case=1; cin >> t_case;
    while(t_case--) {
        ll n, m, h; cin >> n >> m >> h;
        vector<pair<ll, ll>> arr(n);
        ll p1, c1;
        loop(n){
            vector<ll> v(m);
            for(int j=0; j<m; j++){
                cin>>v[j];
            }
            ll p=0; ll c=0; ll t=0;
            sort(b_e(v));
            for(int j=0; j<m; j++){
                t+=v[j];
                if(t<=h)p+=(t);
                else break;
                c++;
            }
            arr[i].first=c; arr[i].second=p;
            if(i==0)p1=p, c1=c;
        }
        sort(b_e(arr), cmp);
        bool flag=false;
        loop(n){
            //cout << arr[i].first << " " << arr[i].second << "\n";
            if(arr[i].first==c1&&arr[i].second==p1){cout << i+1 << "\n"; break;}
        }
    }
    return 0;
}
