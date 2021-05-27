#include <iostream>
#include <vector>																							
#include <utility>
#include <set>

using namespace std;

const int MAXN = 2e4+5;

vector <set<int>> adj_list;
int n, m, ans;

bool isEven(int u){
	return (adj_list[u].size() % 2 == 0);
}

int main(){
	ios_base::sync_with_stdio(0);
	//freopen("inp.inp","r",stdin);
	int t;
	cin >> t;
	while (t--) {
	    cin >> n >> m;
	    adj_list.clear();
	  	adj_list.assign(n+2, set<int>());
	  	ans = 0;
	    for(int i = 1; i <= m; i++){
	    	int x, y;
	    	cin >> x >> y;
	    	adj_list[x].insert(y);
	    	adj_list[y].insert(x);
	    }
		 for(int i = 1; i <= n; i++){
	    	if(!isEven(i)) {
	    		adj_list[0].insert(i);
	    		adj_list[i].insert(0);
	    	}
	    	else ans++;
	    }
	    cout << ans << endl;
	   	for(int i = 1; i <= n; i++){
	   		while (!adj_list[i].empty()) {
	   		    int v = *adj_list[i].begin();
	   		    adj_list[v].erase(i);
	   		    adj_list[i].erase(v);
	   		    if(i && v) cout << i << " " << v << endl;;
	   		    i = v;
	   		}
	   	}
	}
}