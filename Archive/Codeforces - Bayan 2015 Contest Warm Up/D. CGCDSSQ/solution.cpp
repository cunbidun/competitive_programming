#include<stdio.h>
#define M1 100200
#define MAX 300200
#define MM 100000
#include<map>
#define ll long long
using namespace std;
int M[M1][20];
int lg[M1];
int a[M1];
ll ans[MAX];
int x[MAX];
map<int,int> mp;
int c[MAX];
int n;
int q;
void swap(int &a,int &b){
    int tmp = a;
    a = b;
    b = tmp;
}
int gcd(int a,int b){
    if( b > a ) swap(a,b);
    while( a%b!=0 ){
        int r = a%b;
        a = b;
        b = r;
    }
    return b;
}
void setup(){
    for(int i=1;i<=n;i++) M[i][0] = a[i];
    for(int j=1;(1<<j)<=n;j++)
        for(int i=1;i+(1<<j)-1<=n;i++)
            M[i][j]=gcd(M[i][j-1],M[i+(1<<(j-1))][j-1]);
    for(int i=1;i<=MM;i++){
        int pos = 0;
        while( (1<<pos) <= i) pos++;
        lg[i] = pos-1;
    }
}
int rmq(int u,int v){
    int k = lg[v-u+1];
    return gcd(M[u][k],M[v-(1<<k)+1][k]);
}
void read(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int curr = 0;
    scanf("%d",&q);
    for(int i=1;i<=q;i++){
        scanf("%d",&x[i]);
        if(mp.find(x[i])==mp.end()){
            curr++;
            mp[x[i]] = curr;
        }
        c[i] = mp[x[i]];
    }
}
int find(int x,int pos){
    int lo = x;
    int hi = n;
    while(lo<hi){
        int mid = (lo+hi)/2;
        if(rmq(x,mid)<pos) hi = mid;
        else lo = mid+1;
    }
    return lo;
}
void solve(){
    for(int i=1;i<=n;i++){
        int pos = i;
        while(1){
            int curr = rmq(i,pos);
            if(rmq(i,pos) == rmq(i,n)){
                if(mp.find(curr)!=mp.end()) ans[mp[curr]]+=1ll*(n-pos+1);
                break;
            }
            int next = find(i,curr);
            if(mp.find(curr)!=mp.end()) ans[mp[curr]]+=1ll*(next-pos);
            pos = next;
        }
    }
    for(int i=1;i<=q;i++) printf("%I64d\n",ans[c[i]]);
}
main(){
//  freopen("test.inp","r",stdin);
    read();
    setup();
    solve();
}