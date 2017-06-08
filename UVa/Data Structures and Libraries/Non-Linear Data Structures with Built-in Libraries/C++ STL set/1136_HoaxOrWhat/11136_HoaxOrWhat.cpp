#include <bits/stdc++.h>
using namespace std;

multiset<int> ms;

int main()
{
	int n;
	while(scanf("%d", &n), n){
		ms.clear();
		long long int ans = 0;
		int b, a;
		for (int i = 0; i < n; ++i){
			scanf("%d", &b);
			for (int j = 0; j < b; ++j){
				scanf("%d", &a);
				ms.insert(a);
			}
			if (!ms.empty())
			{
				int n1, n2;
				n1 = *(ms.begin());
				n2 = *(--ms.end());
				ans += n2 - n1;
				ms.erase(ms.begin());
				ms.erase(--ms.end());
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}