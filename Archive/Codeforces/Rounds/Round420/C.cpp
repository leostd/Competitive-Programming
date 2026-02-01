#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, d;
	char o[50];
	scanf("%d", &n);
	int acum = 0;
	int counter = 1;
	bool flag = false;
	set<int> pq;
	for (int i = 0; i < 2*n; i++) {
		scanf("%s", o);
		if (strcmp(o, "add") == 0){
			scanf("%d", &d);
			if (d == counter) {
				flag = true;
			}
			if (!pq.empty() && *pq.begin() < d && flag) acum++;
			pq.insert(d);
		}
		else{
			pq.erase(pq.begin());
			counter++;
			flag = pq.find(counter) != pq.end();
		}
	}
	printf("%d\n", acum);
	return 0;
}