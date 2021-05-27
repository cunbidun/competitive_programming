#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>

#define ll long long
#define pb push_back    

const int INF = 1e9 + 7;
const int MAXA = 1e5 + 10;
const int MOD = 1e9 + 7;

using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, int> II;
typedef vector<int> vi;
typedef vector<ii> vii;

int n;
int num[MAXA];
vi adjList[MAXA];

void dfs(int u, int l) {
    if(adjList[u].size() == 1 && u != 1) {
        num[u] = 1;
        return;
    }
    for(int i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if(v != l) {
            dfs(v,u);
            num[u] += num[v];
        }
    }
}

int main() {
    //freopen("in.in", "r", stdin);
    cin >> n;
    if(n == 1) {
        cout << 1;
        return 0;
    }
    for(int i = 2; i <= n; i++) {
        int temp;
        cin >> temp;
        adjList[temp].pb(i);
        adjList[i].pb(temp);
    }
    dfs(1,1);
    sort(num + 1, num + n + 1);
    for(int i = 1; i <= n; i++) {
        cout << num[i] << " ";
    }
    return 0;
}