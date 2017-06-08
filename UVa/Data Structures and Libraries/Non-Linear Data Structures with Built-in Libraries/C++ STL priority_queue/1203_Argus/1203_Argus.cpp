#include <string>
#include <iostream>
#include <sstream>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;

typedef pair<int, int> ii;

int main()
{
    //freopen("in", "r", stdin);
    string line;
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    unordered_map<int, int> ump;
    ump.reserve(1001);
    int cnum, val;
    while(getline(cin, line)){
        if (line == "#")
            break;
        else{
            stringstream sstr(line);
            sstr >> line >> cnum >> val;
            pq.push(ii(val, cnum));
            ump[cnum] = val;
        }
    }
    int n;
    ii ans;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        ans = pq.top();
        printf("%d\n", ans.second);
        pq.pop();
        ans.first += ump[ans.second];
        pq.push(ans);
    }
    return 0;
}