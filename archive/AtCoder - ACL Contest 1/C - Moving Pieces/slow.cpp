// LUOGU_RID: 102106630
#include <array>
#include <assert.h>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
using namespace std;
const int K = 55,N = 2555,M = 2e6+5;
int e[M],ne[M],w[M],flow[M],maxflow[M];
int h[N],vis[N],dis[N],cur[N],idx,ans,st = N-2,ed = N-1,n,m,vis2[N]; 
char arr[K][K];
 
int get(int x,int y)
{
	return x * 50 + y;
}
 
void add(int a,int b,int c,int f)
{
	e[idx] = b;
	ne[idx] = h[a];
	w[idx] = c;
	maxflow[idx] = f;
	h[a] = idx++;
	e[idx] = a;
	ne[idx] = h[b];
	w[idx] = -c;
	//maxflow[idx] = 0;
	h[b] = idx++;
}
 
bool spfa()
{
	memset(vis,0,sizeof(vis));
	memset(dis,-0x3f,sizeof(dis));
	dis[st] = 0,vis[st] = 1;
	for(int i=1;i<N;i++)
		cur[i] = h[i];
	queue<int> q;
	q.push(st);
	while(!q.empty())
	{
		int x = q.front();
		q.pop();
		vis[x] = 0;
		for(int i=h[x];~i;i = ne[i])
		{
			int j = e[i];
			if(flow[i] < maxflow[i] && dis[x] + w[i] > dis[j])
			{
				dis[j] = dis[x] + w[i];//最长路 
				if(!vis[j])
				{
					q.push(j);
					vis[j] = 1;
				}
			}
		}
	}
	return dis[ed] > -0x3f3f3f3f/2;
}
 
int DFS(int u,int a)
{
	if(u == ed || !a)	return a;
	int x = 0,f;
	vis[u] = 1;
	for(;~cur[u];cur[u] = ne[cur[u]])
	{
		int j = e[cur[u]];
		if((!vis[j]) && dis[j] == dis[u] + w[cur[u]] && (f = DFS(e[cur[u]],min(a,maxflow[cur[u]] - flow[cur[u]]))))
		{
			x += f;
			flow[cur[u]] += f;
			flow[cur[u]^1] -= f;
			a -= f;
			ans += w[cur[u]] * f;
		}
		if(!a)	break;
	}
	vis[u] = 0;
	return x;
}
 
int main()
{
	memset(h,-1,sizeof(h));
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		scanf("%s",arr[i]+1);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(arr[i][j] == '#')	continue;
			if(j < m)	add(get(i,j),get(i,j+1),1,1e9);
			if(i < n)	add(get(i,j),get(i+1,j),1,1e9);
			if(arr[i][j] == 'o')	add(st,get(i,j),0,1);
			add(get(i,j),ed,0,1);
		}
	}
	while(spfa())
		DFS(st,1e9);
	cout<<ans<<endl;
 }
