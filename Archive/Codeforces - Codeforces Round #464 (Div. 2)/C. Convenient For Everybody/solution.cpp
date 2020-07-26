#include <iostream>
#include <cstdio>
#include <algorithm>
#define BASE 1000000007
#define ll long long
#define MAXA 100002
using namespace std;

int n, start, finish, ans;
int a[MAXA], s[MAXA];
int check[MAXA];
int main(){
     //freopen("inp.inp","r",stdin);
     cin >> n;
     for (int i = 1; i <= n ; i++){
          cin >> a[i];
          s[i] = s[i-1] + a[i];
     }
     cin >> start >> finish;
     int range = finish-start;
     ans = 0;
     for(int i = 1; i <= n; i++){
          if (i + range - 1 <= n) {
               if (ans <= s[i + range - 1] - s[i-1]){              
                    ans = s[i + range - 1] - s[i-1];
               }
          }else{
               int temp = (i + range - 1 ) % n;
               if (ans <= (s[n] - s[i-1] + s[temp] )  ){
                    ans = s[n] - s[i-1] + s[temp];
               }
          }
     }
    // cout << ans << endl;
     for(int i = 1; i <=n ; i++ ){
             if (i + range - 1 <= n) {
               if (ans == (s[i + range - 1] - s[i-1])){
                    check[i] = 1;
               }
          }else{
               int temp = (i + range - 1 ) % n;
               if (ans == (s[n] - s[i-1] + s[temp] ) ){
                    check[i] = 1;
               }
          }
     }
    // cout << ans << endl;
     int Ans = n;
     for(int i = 1 ; i <= n ; i ++){
          if (check[i]){
               int temp = start - (i - 1);
               if (temp <= 0) temp += n;
               Ans = min(Ans,temp);
          }
     }
     cout << Ans;
}