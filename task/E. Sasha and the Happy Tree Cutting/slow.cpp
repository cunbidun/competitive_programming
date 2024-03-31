#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=1e5+5,M=1<<20,inf=1e9;
int T,n,m,f[M],E[N],len=0;vector<int>G[N];
void dfs(int u,int fa){for(auto v:G[u])if(v!=fa)dfs(v,u),E[u]^=E[v];}
void sol(){
	cin>>n;
	for(int i=1;i<=n;++i)G[i].clear(),E[i]=0;
	for(int i=1,u,v;i<n;++i)cin>>u>>v,G[u].pb(v),G[v].pb(u);
	cin>>m;for(int i=0,u,v;i<m;++i)cin>>u>>v,E[u]^=(1<<i),E[v]^=(1<<i);
	dfs(1,0);sort(E,E+n+1);len=unique(E,E+n+1)-E;
	for(int i=1;i<(1<<m);++i)f[i]=inf;f[0]=0;
	for(int s=0;s<(1<<m);++s)if(f[s]!=inf)for(int i=1;i<=len;++i)f[s|E[i]]=min(f[s|E[i]],f[s]+1);
	cout<<f[(1<<m)-1]<<endl;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cin>>T;while(T--)sol();
}
