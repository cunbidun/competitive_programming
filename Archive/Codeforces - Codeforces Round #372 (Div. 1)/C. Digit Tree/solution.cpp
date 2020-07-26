#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstring>
#include <map>

using namespace std;

const int MAXN = 1e5+5;
#define ll long long
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;

ll n, M;
ll root, Index, modInverse;
ll numChild[MAXN], level[MAXN], part[MAXN], up[MAXN], down[MAXN];
bool checked[MAXN], isprime[MAXN];
vector<vii> adj_list;
vi primeList, currNode;
ll result;

ll powmod(ll a, ll b){
    ll r = 1;
    while (b) {
        if(b&1) r = (r*a) % M;
        a = (a*a) % M;
        b >>= 1;
    }
    return r;
}


void sieve(){
    memset(isprime, 1, sizeof(isprime));
    isprime[1] = 0;
    for(ll i = 2; i < MAXN; i++){
        if(!isprime[i]) continue;   
        primeList.push_back(i);
        for(ll j = i*2; j < MAXN; j += i){
            isprime[j] = 0;
        }
    }
}

ll phi(ll x){
    ll ans = x;
    for(ll i = 0; primeList[i]*primeList[i] <= x; i++){
        ll p = primeList[i];
        if(x % p == 0){
            ans = (ans/p * (p-1) );
            while (x % p == 0) {
                 x /= p;
            }
        }
    }
    if (x > 1)
        ans = (ans/x * (x-1));
    return ans;
}

    void dfs(ll u, ll last){
    currNode.push_back(u);
    numChild[u] = 1;
    for(ll i = 0; i < adj_list[u].size(); i ++){
        ll v = adj_list[u][i].first;
        if(v != last && !checked[v]){
            dfs(v,u);
            numChild[u] += numChild[v];
        }
    }
}
 
ll getCentroid(ll u, ll last, ll currNum){
    for(ll i = 0; i < adj_list[u].size(); i ++){
        ll v = adj_list[u][i].first;
        if(v != last && !checked[v] && numChild[v] * 2 > currNum){
            return getCentroid(v, u, currNum);
        }
    }
    checked[u] = 1;
    return u;
}

ll getCentroid(ll u){
    dfs(u,u);
    return getCentroid(u,u,currNode.size());
}

ll preprocess(ll u, ll last, ll core){

    if(last == core){
        part[u] = Index;
        Index += 1;
    }

    else if (last != -1){
        part[u] = part[last];
    }   

    for(ll i = 0; i < adj_list[u].size(); i ++){
        ll v = adj_list[u][i].first;
        ll w = adj_list[u][i].second;
        if(v != last && !checked[v]){
            level[v] = level[u] + 1;
            down[v] = (down[u]*10 + w) % M;
            up[v] = (up[u] + (w * powmod(10, level[v]-1)) % M ) % M; 
            preprocess(v,u, core);
        }
    }
}

ll process(ll root){
    for(ll i = 0; i < currNode.size(); i ++){
        ll u = currNode[i];
        up[u] = 0;
        down[u] = 0;
        level[u] = 0;
    }

    ll ans = 0;
    Index = 1;

    preprocess(root, -1, root);
    // for(ll i = 0; i < currNode.size(); i ++){
    //     ll u = currNode[i];
    //     cout << u <<": " << up[u] << " " << down[u] << " " << level[u] << " " << part[u] << endl;
    // }
    map<ll,ll> totalUp;
    map<ll,ll> subtree[Index];
    totalUp[0] ++;
    for(ll i = 0; i < currNode.size(); i ++){
        ll u = currNode[i];
        if(u == root) continue;
        totalUp[up[u]] ++;
        subtree[part[u]][up[u]] ++;
    }
    for(ll i = 0; i < currNode.size(); i ++){
        ll u = currNode[i];
        if(u == root) {
            ans += (totalUp[0]-1);
            continue;
        }
        ll d = down[u];
        ll mod = powmod(modInverse,level[u]);
        ll val = ((-d) % M + M) % M;
        mod = (mod * val) % M;
        //if (down[u] % M == 0)
        //cout << u <<": "<< "mod: " << mod << endl;
        ans += (totalUp[mod] - subtree[part[u]][mod]);
    }
    //cout << "ans: " << ans << endl;
    return ans;
}

void solve(ll u){
    ll root;
    currNode.clear();
    root = getCentroid(u);
    //cout << "root" << " " << root << endl;
    // for(ll i = 0; i < currNode.size(); i ++){
    //     ll u = currNode[i];
    //     cout << u << " ";
    // }
    // cout << endl;
    result += process(root);
    //cout << "result: " << result << endl;
    for(ll i = 0; i < adj_list[root].size(); i ++){
        ll v = adj_list[root][i].first;
        if(checked[v]) continue;
        solve(v);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    //freopen("inp.inp","r",stdin);
    cin >> n >> M;
    adj_list.assign(n+1, vii());
    sieve();
    modInverse = powmod(10, phi(M) - 1 );
    //cout << modInverse << endl;
    for(ll i = 1; i < n; i ++){
        ll u, v, w;
        cin >> u >> v >> w;
        u ++; v ++;
        adj_list[u].push_back(make_pair(v,w));
        adj_list[v].push_back(make_pair(u,w));
    }
    solve(1);
    cout << result << endl;
    return (0);
}