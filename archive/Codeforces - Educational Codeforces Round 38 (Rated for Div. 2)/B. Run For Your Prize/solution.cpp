#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int n, player1, player2;
int a[100001];
bool check = 0;
int main(){
  //   freopen("inp.inp","r",stdin);
     cin >> n;
     for (int i = 1; i <= n; i++){
          cin >> a[i]; 
          if (a[i] <= 500000) player1 = a[i] - 1;
          else if (!check){
               check = 1;
               player2 = 1e6 - a[i];
          }
     }
     cout << max(player2, player1);
}