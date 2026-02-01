#include <bits/stdc++.h>
using namespace std;

typedef pair<string, string> ss;
map<ss, int> scoreboard;
ss black, white;
queue<string> q;
queue<ss> winners;
string name, goals;
int max_goals = 0;

int main() {
	int n, aux;
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		cin >> name;
		q.push(name);
	}
	white.first = q.front();
	q.pop();
	black.first = q.front();
	q.pop();
	white.second = q.front();
	q.pop();
	black.second = q.front();
	q.pop();
	cin.ignore();
	getline(cin, goals);
	scoreboard[white] = 0;
	scoreboard[black] = 0;
	for(int i = 0; i < goals.size(); i++){
		if (goals[i] == 'W'){
			q.push(black.second);
			black.second = black.first;
			black.first = q.front();
			q.pop();
			swap(white.first, white.second);
			scoreboard[white]++;
			aux = scoreboard[white];
			if (aux > max_goals){
				queue<ss> c;
				swap(winners, c);
				winners.push(white);
				max_goals = aux;
			}
			else if (aux == max_goals){
				winners.push(white);
			}
			scoreboard[black] = 0;
		}
		else{
			q.push(white.second);
			white.second = white.first;
			white.first = q.front();
			q.pop();
			swap(black.first, black.second);
			scoreboard[black]++;
			aux = scoreboard[black];
			if (aux > max_goals) {
				queue<ss> c;
				swap(winners, c);
				winners.push(black);
				max_goals = aux;
			}
			else if (aux == max_goals){
				winners.push(black);
			}
			scoreboard[white] = 0;
		}
	}
	while(!winners.empty()){
		ss a = winners.front();
		winners.pop();
		cout << a.first << " " << a.second << "\n";
	}
	printf("%d", max_goals);
	return 0;
}