#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int MAXN = 2e5+5;

int n, result = 0, lab[MAXN];
vii adj_list[MAXN];
vector<vi> ans; 

void dfs(int u, int last, int skip){
	int curr;
	if(skip != 1) curr = 1;
		else curr = 2;
	//cout << u << " " << skip << endl;
	for(int i = 0; i < adj_list[u].size(); i++){
		int v = adj_list[u][i].first;
		int num = adj_list[u][i].second;
		if(v != last){
		//	cout << u << " " << v <<" "<<num<<" "<< curr << endl;
			if (curr == skip) curr++;
			ans[curr].push_back(num);
			lab[num] = curr;
			curr++; if (curr == skip) curr++;
		}
	}
	for(int i = 0; i < adj_list[u].size(); i++){
		int v = adj_list[u][i].first;
		int num = adj_list[u][i].second;
		if(v != last){
			if(adj_list[v].size() > 1) {
				dfs(v,u,lab[num]);
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	//freopen("inp.inp","r",stdin);
	cin >> n;
	for(int i = 1; i < n; i++){
		int x, y;
		cin >> x >> y;
		adj_list[x].push_back(make_pair(y,i));
		adj_list[y].push_back(make_pair(x,i));
		result = max(result, (int)adj_list[x].size());
		result = max(result, (int)adj_list[y].size());
	}
	ans.assign(result+2,vi());
	dfs(1,1,0);
	cout << result <<endl;
	for(int i = 1; i <= result; i++){
		cout << ans[i].size() << " ";
		for(int j = 0; j < ans[i].size(); j++){
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}

	
	 
	return 0;
}