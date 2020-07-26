#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std; 

const int MAXN = 2e5+2;

typedef vector<int> vi;

vector<vi> adj_list;
int n, ans = 0, best;
int dsu[MAXN], level[MAXN], s[MAXN], e[MAXN], depth[MAXN];
bool status[MAXN];

int findSet(int x){
    return (dsu[x] == x) ? x : (dsu[x] = findSet(dsu[x])); 
}
bool isSameSet(int x, int y){ return findSet(x) == findSet(y);}
void mergeSet(int x, int y){
	if(!isSameSet(x,y)){
		x = findSet(x), y = findSet(y);
		if(depth[x] > depth[y]) dsu[y] = x;
		else{
			dsu[x] = y;
			if(depth[x] == depth[y]) depth[y] ++;
		}
	}
}

int cal(int u, int last){
	for(int i = 0; i < adj_list[u].size(); i++){
		int v = adj_list[u][i];
		if(v != last){
			level[v] = level[u] + 1;
			if (level[v] > ans){
				ans = level[v];
				best = v;
			}
			cal(v,u);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	//freopen("inp.inp","r",stdin);
	cin >> n;
	adj_list.assign(n+2, vi());
	for(int i = 1; i <= n; i ++) { 
		dsu[i] = i;
		depth[i] = 0;
		cin >> status[i];
	}
	for(int i = 1; i <= n - 1; i ++) {
		cin >> s[i] >> e[i];
		if(status[s[i]] == status[e[i]]) {
			mergeSet(s[i], e[i]);
		}
	}
	for(int i = 1; i <= n - 1; i ++) {
		int x = s[i], y = e[i];
		if(status[x] != status[y]) {
		//cout << findSet(x) << " " << findSet(y) << endl;
		adj_list[findSet(x)].push_back(findSet(y));
		adj_list[findSet(y)].push_back(findSet(x));
		}
	}
	ans = 0;
	cal(findSet(1),findSet(1));
	//cout << best << " ";
	for(int i = 1; i <= n; i ++){
		level[i] = 0;
	}
	level[best] = 1;
	ans = 0;
	cal(best, best);
	//cout << best << endl;
	cout << ans / 2;
	return 0;
}