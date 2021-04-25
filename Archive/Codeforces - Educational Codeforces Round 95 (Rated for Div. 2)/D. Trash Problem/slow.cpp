#include<bits/stdc++.h>
using namespace std;
#define st first
#define nd second
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
ll p[100005];
set <ll> pos;
multiset <ll> dis;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
 
    int n,q; cin>>n>>q;
    for(int i = 1; i <= n; i++) {
        cin>>p[i];
        pos.insert(p[i]);
    }
    sort(p+1, p + 1 + n);
    for(int i = 2; i <= n; i++) {
        dis.insert(p[i] - p[i-1]);
    }
    ll ans = *pos.rbegin() - *pos.begin() - *dis.rbegin();
    cout<<ans<<endl;
    
    while(q--) {
        bool t; ll x;
        cin>>t>>x;
 
        if(t) {
            std::set<ll>::iterator lower, upper;
            lower = pos.lower_bound(x);
            upper = pos.upper_bound(x);
 
            if(upper == pos.end()) {
                if(pos.size() > 0) dis.insert(x - *pos.rbegin());
            }
            else if(pos.size() == 0 || *lower == *pos.begin()) {
                if(pos.size() > 0) dis.insert(*lower - x);
            }
            else {
                if(upper != pos.end()) dis.insert(*upper - x);
                --lower;
                dis.insert(x - *lower);
                ll tmp = *upper - *lower;
                std::set<ll>::iterator cak;
                cak = dis.find(tmp);
                if(cak!=dis.end()) dis.erase(cak);
                
            }
            pos.insert(x);

        }
        else {
           
            pos.erase(x);
            std::set<ll>::iterator lower, upper;
            lower = pos.lower_bound(x);
            upper = pos.upper_bound(x);

            if(upper == pos.end()) {
                if(pos.size() > 0) {
                    ll tmp = x - *(pos.rbegin());
                    std::set<ll>::iterator cak;
                    cak = dis.find(tmp);
                    if(cak!=dis.end()) dis.erase(cak);
                }
            }
            else if(pos.size() == 0 || x < *pos.begin()) {
                if(pos.size() > 0) {
                    ll tmp = *pos.begin() - x;
                    std::set<ll>::iterator cak;
                    cak = dis.find(tmp);
                    if(cak!=dis.end()) dis.erase(cak);
                }
            }
            else {
                std::set<ll>::iterator cak;
                cak = dis.find(*upper - x);
                if(cak!=dis.end()) dis.erase(cak);
            
                --lower;
                cak = dis.find(x - *lower);
                if(cak!=dis.end()){
                    dis.erase(cak);
                }

                dis.insert(*upper - *lower);
            }
            
        }
        //cout<<*pos.rbegin()<<' '<<*pos.begin()<<' '<<*dis.rbegin()<<endl;
        if(pos.size() <= 2) cout<<0<<endl;
        else {
            ll ans = *pos.rbegin()-*pos.begin()-*dis.rbegin();
            cout<<ans<<endl;
        }
 
 
    }
 
}
