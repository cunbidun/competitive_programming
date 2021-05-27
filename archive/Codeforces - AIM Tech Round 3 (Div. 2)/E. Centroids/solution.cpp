#include <iostream>																			
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 4e5+5;

vector<int> adj_list[MAXN];
int n, root;
int numChild[MAXN], parent[MAXN], part[MAXN], heaviest[MAXN];
bool OK[MAXN];

void pre_dfs(int u, int last){
	numChild[u] = 1;
	for(int i = 0; i < adj_list[u].size(); i++){
		int v = adj_list[u][i];
		if(v != last){
			part[v] = part[u];
			pre_dfs(v,u);
			numChild[u] += numChild[v];
		}
	}
}

int find(int u, int last){
	for(int i = 0; i < adj_list[u].size(); i++){
		int v = adj_list[u][i];
		if(v != last && numChild[v]*2 > n){
			return find(v,u);
		}
	}
	return u;
}

void dfs(int u, int last){
	numChild[u] = 1;
	if (parent[u] == root) part[u] = u;
	for(int i = 0; i < adj_list[u].size(); i++){
		int v = adj_list[u][i];
		if(v != last){
			parent[v] = u;
			part[v] = part[u];
			dfs(v,u);
			numChild[u] += numChild[v];
		}
	}
}

void cal(int u, int last){
	int curr = 1;
	for(int i = 0; i < adj_list[u].size(); i++){
		int v = adj_list[u][i];
		if(v != last){
			cal(v,u);
			if(numChild[v] >= curr){
				heaviest[u] = v;
				curr = numChild[v]; 
			}
		}
	}
}
bool checkNode(int u, int skip){
	if ((numChild[root] - numChild[skip]) <= n/2 ) 
			return 1;

	if(skip == heaviest[root]){
		for(int i = 0; i < adj_list[root].size(); i ++){
			int v = adj_list[root][i];
			if(v != skip){
				if( (numChild[root] - numChild[v] - numChild[u])<= n/2) return 1;
			}
		}
	}
	else{	
		if((numChild[root] - numChild[heaviest[root]] - numChild[u])<= n/2) 
			return 1;
	}
	
	return 0;
}

int main() {
	ios_base::sync_with_stdio(0);
	//freopen("inp.inp","r",stdin);
	cin >> n;
	for(int i = 1; i <= n; i ++) OK[i] = 1;
	for(int i = 1; i < n; i ++){
		int x, y;
		cin >> x >> y;
		adj_list[x].push_back(y); 
		adj_list[y].push_back(x);
	}
	pre_dfs(1,1);
	root = find(1,1);
	for(int i = 1; i <= n; i ++) numChild[i] = 0;
	OK[root] = 1;
	parent[root] = root;
	part[root] = root;
	dfs(root, root);
	cal(root, root);
	for(int i = 1; i <= n; i ++) {
		if(numChild[i] == 1) heaviest[i] = i;
		//cout << heaviest[i] <<" "; cout << endl;
	}
	for(int i = 1; i <= n; i++){
		if(i == root) continue;
		if(n - numChild[i] > n/2){
			OK[i] = checkNode(i,part[i]);
		}
	}
	for(int i = 1; i <= n; i++) {
		cout << OK[i] << " ";
	}
	return 0;
}