#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 1<<20;
const LL inf = 1e18;
int n,m,c;
LL f[N],t[N],w[N];
vector<pair<int,int> > v[N];
void modify(int L,int R,LL X,int k=1,int l=0,int r=m){
	if(L<=l&&r<=R){
		w[k]+=X;
		t[k]+=X;
		return;
	}
	int h=l+r>>1;
	if(L<=h)
		modify(L,R,X,k<<1,l,h);
	if(h<R)
		modify(L,R,X,k<<1|1,h+1,r);
	t[k]=min(t[k<<1],t[k<<1|1])+w[k];
}
LL query(int L,int R,int k=1,int l=0,int r=m){
	if(L<=l&&r<=R)
		return t[k];
	int h=l+r>>1;
	LL o=inf;
	if(L<=h)
		o=min(o,query(L,R,k<<1,l,h));
	if(h<R)
		o=min(o,query(L,R,k<<1|1,h+1,r));
	return o+w[k];
}
int main()
{
	int i,j,x,y,z;
	LL o;
	scanf("%d%d%d",&n,&m,&c);
	for(i=1;i<=n;i++){
		scanf("%d%d%d",&x,&y,&z);
		v[m-y].push_back(make_pair(x,z));
	}
	f[0]=0;
	for(i=1;i<=m;i++){
		f[i]=f[i-1];
		for(j=0;j<v[i].size();j++){
			x=v[i][j].first;
			y=v[i][j].second;
			f[i]+=y;
			if(x+1<=i-1)
				modify(x+1,i-1,y);
		}
		f[i]=min(f[i],query(0,i-1)+i*c);
		modify(i,i,f[i]-i*c);
	}
	printf("%lld\n",f[m]);
	return 0;
}
