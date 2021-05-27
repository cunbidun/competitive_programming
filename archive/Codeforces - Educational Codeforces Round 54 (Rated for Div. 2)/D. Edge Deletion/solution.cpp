#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <queue>
#define ll long long

using namespace std;

#define MAXA 300005
const ll INF = 1000000007;

typedef pair<ll, ll> ii;
typedef pair<ll, ii> II;
typedef vector<ll> vi;
typedef vector<ii> vii;

ll n, m, k, dis[MAXA], canDel = 0;
vii EdgeList;
vector<II> adjList[MAXA];
vii G[MAXA];
bool track[MAXA];
vi ans;
ll num = 1;
void dfs(ll u, ll p) {
    for(ll i = 0; i < G[u].size(); i++) {
        ll v = G[u][i].first;
        ll id = G[u][i].second;
        if(v != p) {
            //cout << u << " " << v << endl;
            if(num >= k + 1) {
                return;
            } 
            num ++;
            //cout << num << " " << id << endl;
            ans.push_back(id);
            dfs(v,u);     
        }   
    }
}

int main() {
    //freopen("in.in","r",stdin);
    cin >> n >> m >> k;
    EdgeList.push_back(ii(0,0));
    for(ll i = 1; i <= m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        adjList[u].push_back(II(v,ii(w,i)));
        adjList[v].push_back(II(u,ii(w,i)));
        EdgeList.push_back(ii(u,v));
    }
    memset(dis, INF, sizeof(dis));
    dis[1] = 0;
    priority_queue<II, vector<II>, greater<II>> pq;
    pq.push(II(0,ii(1,-1)));
    while(!pq.empty()){
        II front = pq.top(); pq.pop();
        ll w = front. first;
        ll u = front. second. first;
        ll id = front. second. second;
        if(dis[u] < w) {
            //cout << u << " " << w << " " << id << endl;  
            track[id] = 0;
            continue;
        }
        for(ll i = 0; i < adjList[u].size(); i++) {
            ll v = adjList[u][i].first;
            ll d = adjList[u][i].second.first;
            ll id = adjList[u][i].second.second;
            if(d + w < dis[v]) {
                track[id] = 1;
                //cout << v << " " << d << " " << id << endl;  
                dis[v] = w + d;
                pq.push(II(dis[v],ii(v,id)));
            }
        }
    }
    for(ll i = 1; i <= m; i++) {
        if(track[i] == 0) {
            canDel ++;
        } 
        else{
            ll u = EdgeList[i].first;
            ll v = EdgeList[i].second;
            G[u].push_back(ii(v,i));
            G[v].push_back(ii(u,i));
        }
    }
    if(m - k <= canDel) {
        cout << m - canDel << endl; 
        for(ll i = 1; i <= m; i++){
            if(track[i]) cout << i << " ";
        }
        return 0;
    }
    //for(ll i = 1; i <= m; i++){
    //     if(track[i]) cout << i << " ";
    // }
    // cout << endl;
    //cout << canDel << endl;
    dfs(1,1);
    cout << ans.size() << endl;
    for(ll i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}