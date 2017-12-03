#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f
#define VI vector<int>
#define pii pair<int,int>
#define matrix vector<VI>
#define LL long long
#define MOD 1000000007
#define ULL unsigned long long
#define uedge(g,a,b) g[a].pb(b), g[b].pb(a)
#define dedge(g,a,b) g[a].pb(b)
using namespace std;
class trie{
public:
	vector<int> out;
	bool word;
	int mark;
	trie* child[2];
	trie* fail;
	trie(){
		child[0] = NULL; child[1] = NULL; fail = NULL; word = false; mark = -1;
	}
};
trie* root;
void insert(trie* cur, string& W, int pos, int& id){
	if(pos == (int)W.length()){
		cur->word = true;
		cur->out.pb(id);
		return;
	}
	if(!cur->child[W[pos]-'0']) cur->child[W[pos]-'0'] = new trie();
	insert(cur->child[W[pos]-'0'], W, pos+1, id);
}
 
void automata(){
	queue<trie*> q;
	if(root->child[0]){
		q.push(root->child[0]);
		root->child[0]->fail = root;
	}else root->child[0] = root;
 
	if(root->child[1]){
		q.push(root->child[1]);
		root->child[1]->fail = root;
	}else root->child[1] = root;
 
 
	trie* cur, *v, *c; 
	while(!q.empty()){
		cur = q.front(); q.pop();
		for(int i = 0; i < 2; i++){
			if(!cur->child[i]) continue;
			c = cur->child[i];
			v = cur->fail;
			while(!v->child[i]) v = v->fail;
			c->fail = v->child[i];
			q.push(c);
			for(int j = 0; j <(int)c->fail->out.size(); j++){
				c->out.pb(c->fail->out[j]);
				//printf("%d\n", c->fail->out[j]);
			}
		}
	}
}
vector<string> S;
int mark[300010];
int search(char W[], int it){
	trie* cur = root;
	int pos = 0;
	int len = strlen(W);
	while(true){
		if(cur->mark != it){
			cur->mark = it;
			for(int i = 0; i <(int)cur->out.size(); i++){
				mark[cur->out[i]] = it;
				//printf("%d\n", cur->out[i]);
			}
		}
		if(pos >= len) break;
		if(!cur->child[W[pos]-'0']) cur = cur->fail;
		else{
			cur = cur->child[W[pos]-'0'];
			pos++;
		}
	}
	int ans = 0;
	for(; mark[ans] == it; ans++);
	return (int)S[ans].length();
}
char P[100010];
int main(){
	int n = 17;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < (1<<(i+1)); j++){
			S.pb(string(i+1,'0'));
			for(int k = 0; k < i+1; k++){
				if(j & (1<<k)) S[(int)S.size()-1][i-k] = '1';
			}
		}
	}
	root = new trie();
	for(int i = 0; i < (int)S.size(); i++){
		insert(root, S[i], 0, i);
		//printf("%s\n", S[i].c_str());
	}
	automata();
	int t;
	scanf("%d", &t);
	int iter = 1;
	while(t--){
		scanf("%s", P);
		printf("%d\n", search(P, iter++));
	}
	return 0;
} 