#include<bits/stdc++.h>
using namespace std;
#define st first
#define nd second
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll,int> li;
typedef pair<ll,ii> lii;
typedef pair<ii,ii> iiii;
typedef pair<ii, int> iii;
typedef pair<int, char> ic;
typedef pair<double, int> di;
const int N = 1e6;
ll a[N+5], s[N+5];
bool nonpr[N+5];
int n;
vector<ll> pr;
ll tmp;
 
void eratos() {
    nonpr[0] = nonpr[1] = true;
 
    for (int i = 2; i <= N; i++)
        if (!nonpr[i]) {
            for (int j = i + i; j <= N; j += i) {
                nonpr[j] = true;
            }
            if(s[n]%i==0) {
                //cout<<s[n]<<' '<<i<<endl;
                pr.push_back(i);
                while(tmp%i==0) tmp/=i;
            }
        }
 
    if(tmp > 1) pr.push_back(tmp);
 
}
 
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
 
    cin>>n;
    for(int i = 1; i <= n; i++) {
        cin>>a[i];
        s[i] = s[i-1] + a[i];
    }
 
    ll ans = 1e18;
    tmp = s[n];
    eratos();
 
    for(int i = 0; i < pr.size(); i++) {
        ll k = pr[i];
        //if(s[1] == 253404) cout<<k<<"ditme"<<endl;
        ll tmp = 0;
        for(int j = 1; j <= n; j++) {
            tmp = tmp + min(s[j]%k, k - s[j]%k);
        }
 
        ans = min(ans, tmp);
    }
 
    if(ans == 1e18) cout<<-1<<endl;
    else cout<<ans<<endl;
 
 
}
