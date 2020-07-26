#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 1e5+1;

typedef vector<int> vi;

int n, root, nodeCount;
vector<vi> adj_list, centroidTree;
int numChild[MAXN], level[MAXN];
bool checked[MAXN];

void dfs(int u, int last){
    nodeCount ++ ;
    numChild[u] = 1;
    for(int i = 0; i < adj_list[u].size(); i++){
        int v = adj_list[u][i];
        if(v != last && !checked[v]){
            dfs(v,u);
            numChild[u] += numChild[v];
        }
    }
}

int getCentroid(int u, int last, int currNum){
    //cout << u << endl;
    for(int i = 0; i < adj_list[u].size(); i++){
        int v = adj_list[u][i];
        if(v != last && !checked[v] && numChild[v]*2 > currNum){
            return getCentroid(v,u,currNum);
            break;
        }
    }
    checked[u] = 1;
    return u;
}

int getCentroid(int u){
    nodeCount = 0;
    dfs(u,u);
    return getCentroid(u,u,nodeCount);
}

int decomposeTree(int u){
    int centroid;
    if(u == root) centroid = root;
    else centroid = getCentroid(u);
    for(int i = 0; i < adj_list[centroid].size(); i ++){
        int v = adj_list[centroid][i];
        if(!checked[v]){
            int next = decomposeTree(v);
            centroidTree[centroid].push_back(next);
        }
    }
    return centroid;
}

void dfsCentroid(int u){
    for (int i = 0; i < centroidTree[u].size(); i++){
        int v = centroidTree[u][i];
        level[v] = level[u] + 1;
        dfsCentroid(v);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    //freopen("inp.inp","r",stdin);
    cin >> n;
    adj_list.assign(n+1, vi());
    centroidTree.assign(n+1, vi());
    for(int i = 1; i < n; i ++){
        int x, y;
        cin >> x >> y;
        adj_list[x].push_back(y);
        adj_list[y].push_back(x);
    }
    
    root = getCentroid(1);
    decomposeTree(root);

    level[root] = 1;
    dfsCentroid(root);
    for(int i = 1; i <= n; i ++){
        cout << (char)('A' + (level[i] - 1)) << " ";
    }
}