#include <iostream>
#include <cstdio>
#include <algorithm>
#define MAXA 2071
using namespace std;

int n, ans;
int main(){
     //freopen("inp.inp","r",stdin);
     cin  >> n;
     for (int i = 1; i <= n ; i++ ){
          if (n % i == 0)
               ans++;
     }
     cout << ans - 1;
}