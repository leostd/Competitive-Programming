#include <bits/stdc++.h>
#define N 200001
using namespace std;

typedef long long int ll;

ll n, m, k, s, idx, jdx, a, b;
pair<ll, int> t1[N], t2[N], d[N], p[N];
pair<int, int> sol[N];

bool f(int index){
    ll x = d[index].first;
    ll y = p[index].first;
    ll money = s;
    int c = 0;
    int i = 0, j = 0;
    while(i < idx || j < jdx){
        if (i < idx && x*t1[i].first <= y*t2[j].first && money - x*t1[i].first >= 0){
            money -= x*t1[i].first;
            sol[c].first = t1[i].second;
            sol[c].second = d[index].second;
            c++;
            i++;
        }
        else if (j < jdx && y*t2[j].first <= x*t1[i].first && money - y*t2[j].first >= 0){
            money -= y*t2[j].first;
            sol[c].first = t2[j].second;
            sol[c].second = p[index].second;
            c++;
            j++;
        }
        else if(j == jdx && money - x*t1[i].first >= 0){
            money -= x*t1[i].first;
            sol[c].first = t1[i].second;
            sol[c].second = d[index].second;
            c++;
            i++;
        }
        else if(i == idx && money - y*t2[j].first >= 0){
            money -= y*t2[j].first;
            sol[c].first = t2[j].second;
            sol[c].second = p[index].second;
            c++;
            j++;
        }
        else if(j < jdx && money - y*t2[j].first < 0 && i < idx && money - x*t1[i].first < 0)
            break;
        else if (i==idx && j < jdx && money - y*t2[j].first < 0)
            break;
        else if (j == jdx && i < idx && money - x*t1[i].first < 0)
            break;
    }
    return c >= k;
}

int main(){

    cin >> n >> m >> k >> s;
    for (int i = 0; i < n; i++){
        cin >> d[i].first;
        d[i].second = i;
    }
    for (int i = 0; i < n; i++){
        cin >> p[i].first;
        p[i].second = i;
    }
    idx = jdx = 0;
    for (int i = 0; i < m; i++){
        cin >> a >> b;
        if (a == 1){
            t1[idx].second = i;
            t1[idx++].first = b;
        }
        else{
            t2[jdx].second = i;
            t2[jdx++].first = b;
        }

    }
    for (int i = 1; i < n; i++){
        d[i] = min(d[i], d[i-1]);
        p[i] = min(p[i], p[i-1]);
    }
    sort(t1, t1+idx);
    sort(t2, t2+jdx);
    int l = 0, r = n-1, mid;
    while (r - l > 1){
        mid = l + (r-l)/2;
        if (f(mid))
            r = mid;
        else
            l = mid;
    }
    int ans;
    if (f(l))
        ans = l+1;
    else if (f(r))
        ans = r+1;
    else
        ans = -1;
    printf("%d\n", ans);
    if (ans != -1)
    for (int i = 0; i < k; i++)
        printf("%d %d\n", sol[i].first+1, sol[i].second+1);
    return 0;
}
