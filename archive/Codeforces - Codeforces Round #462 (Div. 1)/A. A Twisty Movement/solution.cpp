#include <iostream>
#include <cstdio>
#include <algorithm>
#define MAXA 2071
using namespace std;

int n, ans;
int a[MAXA];
int f[MAXA][MAXA][3],r_f[MAXA][MAXA][3];

int main(){
     //freopen("inp.inp","r",stdin);
     cin >> n;
     f[1][0][0] = 0;
     f[1][0][1] = 0;
     f[1][0][2] = 0;
     for (int i = 1; i <= n; i++) cin >> a[i];
     for (int i = 1; i <= n; i++){
          if (a[i] == 1){
               f[i][i][0] = 1;
               f[i][i][1] = 0;
               f[i][i][2] = 0;
          }
          else if (a[i] == 2){
               f[i][i][0] = 0;
               f[i][i][1] = 0;
               f[i][i][2] = 1;
          }
     }

     for (int i = 1; i <= n-1; i++){
          for (int j = i + 1; j <= n; j++){ 
               if (a[j] == 1){
                    f[i][j][0] = f[i][j-1][0] + 1; 
                    f[i][j][1] = f[i][j-1][1];  
                    f[i][j][2] = f[i][j-1][2];
               }
               else {
                    f[i][j][0] = f[i][j-1][0];
                    if (f[i][j-1][1] || f[i][j-1][0])
                         f[i][j][1] = max(f[i][j-1][1],f[i][j-1][0]) + 1; 
                    else f[i][j][1] = f[i][j-1][1];
                    f[i][j][2] = f[i][j-1][2] + 1;
               }
          }
     }

     for (int i = 1; i <= n; i++){
          if (a[i] == 1){
               r_f[i][i][0] = 1;
               r_f[i][i][1] = 0;
               r_f[i][i][2] = 0;
          }
          else if (a[i] == 2){
               r_f[i][i][0] = 0;
               r_f[i][i][1] = 0;
               r_f[i][i][2] = 1;
          }
     }

     for (int i = n; i > 1; i--)
          for (int j = i - 1; j >= 1; j--){
               if (a[j] == 1){
                    r_f[i][j][0] = r_f[i][j+1][0] + 1;  
                    r_f[i][j][1] = r_f[i][j+1][1];  
                    r_f[i][j][2] = r_f[i][j+1][2];
               }
               else if (a[j] == 2){
                    r_f[i][j][0] = r_f[i][j+1][0];
                    if (r_f[i][j+1][1] || r_f[i][j+1][0])
                         r_f[i][j][1] = max(r_f[i][j+1][1],r_f[i][j+1][0]) + 1; 
                    else r_f[i][j][1] = r_f[i][j+1][1];
                    r_f[i][j][2] = r_f[i][j+1][2] + 1;
               }
          }
     ans = 0;
     for (int i = 1; i <= n ; i++)
          for (int j = i ; j <= n; j++){
               ans = max (ans, f[1][i-1][0] + r_f[j][i][0] + f[j+1][n][0]);
               ans = max (ans, f[1][i-1][0] + r_f[j][i][0] + f[j+1][n][1]);
               ans = max (ans, f[1][i-1][0] + r_f[j][i][0] + f[j+1][n][2]);
               ans = max (ans, f[1][i-1][0] + r_f[j][i][1] + f[j+1][n][2]);
               ans = max (ans, f[1][i-1][0] + r_f[j][i][2] + f[j+1][n][2]);          
               ans = max (ans, f[1][i-1][1] + r_f[j][i][2] + f[j+1][n][2]);
               ans = max (ans, f[1][i-1][2] + r_f[j][i][2] + f[j+1][n][2]);
          }
     cout << ans;
}