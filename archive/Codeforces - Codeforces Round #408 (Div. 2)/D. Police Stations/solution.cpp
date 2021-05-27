#include <iostream>
#include <queue>
#include <vector>

const int MAXA = 300001;
using namespace std;

int n, k , d, ans;
vector<vector<pair<int,int>>> adj_list;
bool visited[MAXA], check[MAXA], police[MAXA];
queue<pair<int,int>> q;

void BFS(){
	while(!q.empty()){
		int u = q.front().first;
		int b4 = q.front().second;
		q.pop();
		if(visited[u]) continue;
		visited[u] = 1;
		for(int i = 0; i < adj_list[u].size(); i ++ ){
			int v = adj_list[u][i].first;
			if (v == b4) continue;
			int edge = adj_list[u][i].second;
			if ( visited[v] ) {
				check[edge] = 1;
			}
			else q.push(make_pair(v,u));
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	//freopen("in.in","r",stdin);
	cin >> n >> k >> d;
	adj_list.assign(n + 1, vector<pair<int,int>>());
	for(int i = 1; i <= k; i ++){
		int temp;
		cin >> temp;
		q.push(make_pair(temp,0));
	}
	for(int i = 1; i < n; i ++){
		int u, v;
		cin >> u >> v;
		adj_list[u].push_back(make_pair(v,i));
		adj_list[v].push_back(make_pair(u,i));
	}
	BFS();
	ans = 0;
	for(int i = 1; i < n ; i ++){
		if(check[i]) ans++;
	}
	cout << ans << endl;;
	for(int i = 1; i < n ; i ++){
		if(check[i]) cout << i << " ";
	}	
}