#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	while(n--){
		int b, sg, sb, x, y;
		scanf("%d", &b, &sg, &sb);
		multiset<int, greater<int>> blues, greens, auxb, auxg;
		for (int i = 0; i < sg; i++)
		{
			scanf("%d", &x);
			greens.insert(x);
		}
		for (int i = 0; i < sb; i++)
		{
			scanf("%d", &x);
			blues.insert(x);
		}
		while(1){
			if (greens.empty() && blues.empty()){
				printf("green and blue died\n");
				break;
			}
			else if(greens.empty()){
				printf("blue wins\n");
				for (auto it = blues.begin(); it != blues.end(); ++it)
					printf("%d\n", *it);
				break;
			}
			else if(blues.empty()){
				printf("green wins\n");
				for (auto it = greens.begin(); it != greens.end(); ++it)
					printf("%d\n", *it);
				break;
			}
			auxb.clear();
			auxg.clear();
			int mins = min(min((int)blues.size(), (int)greens.size()), b);
			for (int i = 0; i < mins; i++){
				sb = *(blues.begin());
				sg = *(greens.begin());
				if (sb != sg){
					if (sb > sg)
					{
						sb -= sg;
						auxb.insert(sb);
					}
					else{
						sg -= sb;
						auxg.insert(sg);
					}
				}
				greens.erase(greens.begin());
				blues.erase(blues.begin());
			}
			for (auto it = auxb.begin(); it != auxb.end(); ++it){
				blues.insert(*it);
			}
			for (auto it = auxg.begin(); it != auxg.end(); ++it){
				greens.insert(*it);
			}
		}
	}
	return 0;
}