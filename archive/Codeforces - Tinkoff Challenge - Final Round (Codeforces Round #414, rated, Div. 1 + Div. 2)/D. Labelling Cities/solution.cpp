#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int MAXN = 3e5+2;

ii edge[MAXN];
vi adjList[MAXN];
int n,m,dsu[MAXN],level[MAXN], label[MAXN], ans[MAXN];
bool visited[MAXN];
pair<vi, int> adj_list[MAXN];

int findSet(int x){ 
	return (dsu[x] == x) ? x : (dsu[x] = findSet(dsu[x]));
}
bool isSameSet(int x, int y){
	return (findSet(x) == findSet(y));
}
bool mergeSet(int x, int y){
	if(!isSameSet(x,y)){
		x = findSet(x), y = findSet(y);
		if(level[x] > level[y]) dsu[y] = x;
		else{
			dsu[x] = y;
			if(level[x] == level[y]) level[y]++;
		}
	}
}

bool check(int u, int last){
	visited[u] = 1;
	for(int i = 0; i < adjList[u].size();i++){
		int v = adjList[u][i];
		if (v == last) continue;
		if(visited[v]) return 0;
		check(v,u);
	}
	return 1;
}

int main(){
	ios_base::sync_with_stdio(0);
	//freopen("inp.inp","r",stdin);
	cin >> n >> m;

	for(int i = 1; i <= m; i++){
		cin >> edge[i].first >> edge[i].second;
		adj_list[edge[i].first].first.push_back(edge[i].second);
		adj_list[edge[i].second].first.push_back(edge[i].first);
	}

	for(int i = 1; i <= n; i++){
		adj_list[i].first.push_back(i);
		adj_list[i].second = i;
		sort(adj_list[i].first.begin(), adj_list[i].first.end());
	}
	sort(adj_list+1, adj_list+n+1);
	
	// for(int i = 1; i <= n; i++){
	// 	for(int j = 0; j < adj_list[i].first.size(); j++){
	// 		cout << adj_list[i].first[j] << " ";
	// 	}
	// 	cout << endl;
	// } cout << endl;

	int cnt = 1;
	for(int i = 1; i <= n; i++){
		if(i == 1) label[adj_list[i].second] = cnt;
		else {
			if(adj_list[i].first == adj_list[i-1].first) label[adj_list[i].second] = cnt;
			else label[adj_list[i].second] = ++cnt;
		}
	}
	if(cnt == 1){
		cout << "YES" << endl;
		for(int i = 1; i <= n; i++)
			cout << 1 << " ";
		return 0;
	}

	// for(int i = 1; i <= n; i++){
	// 	cout << label[i] << endl;
	// }

	for(int i = 1; i <= cnt; i++){
		level[i] = 0;
		dsu[i] = i;
	}

	for(int i = 1; i <= m; i++) {
		int u = edge[i].first, v = edge[i].second;
		int x = label[u], y = label[v];
		if(x != y && !isSameSet(x, y)){
			//cout << x << " " << y << endl;
			adjList[x].push_back(y);
			adjList[y].push_back(x);
			mergeSet(x, y);
		}
	}
	//cout << endl;
	for(int i = 1; i <= cnt; i++){
		if(adjList[i].size() > 2){
			cout << "NO";
			return 0;
		}
	}

	// for(int i = 1; i <= cnt; i++){
	// 	cout << i << ": ";
	// 	for(int j = 0; j < adjList[i].size(); j++){
	// 		cout << adjList[i][j] << " ";
	// 	}
	// 	cout << endl;
	// } cout << endl;

	if(check(1,1)){
		int i;
		for(i = 1; i <= cnt; i++){
			if(adjList[i].size() == 1) break;
		}
		ans[i] = 1;
		int j = adjList[i][0];
		int last = i;
		
		while (adjList[j].size() > 1) {
			ans[j] = ans[last] + 1;
			if(adjList[j][0] != last) {
				last = j;
				j = adjList[j][0];
			}
			else {
				last = j;
				j = adjList[j][1];
			}
		}
		ans[j] = ans[last] + 1;
		cout << "YES" << endl;
		for(int k = 1; k <= n; k++){
			cout << ans[label[k]] << " ";
		}
	}	
	else 
		cout << "NO";

	return 0;
}