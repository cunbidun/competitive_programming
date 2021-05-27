#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int MAXN = 305;

int n, k, level[MAXN], par[MAXN][12], order[MAXN], used[MAXN][MAXN];
vi adj_list[MAXN], ans;
bool False = 0;

void dfs(int u, int last){
	for(int i = 0; i < adj_list[u].size(); i++){
		int v = adj_list[u][i];
		if(v != last){
			par[v][0] = u;
			level[v] = level[u] + 1;
			dfs(v,u);
		}
	}
}
int lca(int x, int y){
	if (level[x] < level[y]) swap(x,y);
	for(int i = 10; i >= 0; i--){
		if(level[par[x][i]] >= level[y]) x = par[x][i];
	}
	if(x == y) return x;
	for(int i = 10; i >= 0; i--)
		if(par[x][i] != par[y][i]) {
			x = par[x][i];
			y = par[y][i];
	}
	return par[x][0];
}
int dis(int x, int y){
	int z = lca(x,y);
	return abs(level[x]-level[z])+abs(level[z]-level[y]);
}
void Find(int x, int target){
	while (x != target) {	
		ans.push_back(x);
		//cout << x << " " << par[x][0] << endl;
		used[x][par[x][0]]++;
		used[par[x][0]][x]++;
		if(used[x][par[x][0]] > 2 || used[par[x][0]][x] > 2){
			False = 1;
			break;
		}
		x = par[x][0];
	}
	ans.push_back(target);
}

int main(){
	ios_base::sync_with_stdio(0);
	//freopen("inp.inp","r",stdin);
	cin >> n;
	for(int i = 1; i < n; i++){
		int x, y;
		cin >> x >> y;
		adj_list[x].push_back(y);
		adj_list[y].push_back(x);	
	}
	for(int i = 2; i <= n; i++)
		if (adj_list[i].size() == 1) k ++;
	for(int i = 1; i <= k; i++){
		cin >> order[i];
	}
	level[1] = 1;
	par[1][0] = 1;
	dfs(1,1);
	for(int j = 1; j <= 9; j++)
		for(int i = 1; i <= n; i++)
			par[i][j] = par[par[i][j-1]][j-1];
	Find(order[1],1);
	for(int i = 2; i <= k; i++){
		int x = lca(order[i], order[i-1]);
		Find(order[i-1], x);
		Find(order[i],x);
		if(False){
			cout << "-1";
			return 0;
		}
	}
	Find(order[k],1);
	if(False){
		cout << "-1";
		return 0;
	}
	// for(int i = 0; i < ans.size(); i++){
	// 	cout << ans[i] << " ";
	// }
	// cout << endl;
	int curr;
	int pos = 1;
	for(int i = level[order[1]] - 1; i >=0; i--) cout << ans[i] << " ";

	for(int i = level[order[1]] ; i < ans.size(); ){
		if(pos == k){
			for(int j = i+1; j < ans.size(); j++) cout << ans[j] << " ";
			break;
		}
		curr = dis(order[pos], lca(order[pos],order[pos+1]));
		// cout << curr << endl;
		// cout << i+1 <<" "<<i + curr  << endl;
		for(int j = i+1; j <= i + curr; j++) cout << ans[j] << " ";
		i = i + curr + 1;
		
		curr = 	dis(order[pos+1], lca(order[pos],order[pos+1]));
		// cout << curr << endl;
		// cout << i <<" "<< i+curr - 1 << endl;
		for(int j = i+curr - 1; j >= i; j--) cout << ans[j] << " ";
		i = i + curr + 1;
		//cout << i << endl;
		pos ++;
		
	}
	return 0;
}