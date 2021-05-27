#include<bits/stdc++.h>
#define maxi 505
using namespace std;
typedef long long ll;

int d; 
int main() {
     //freopen("in.in","r",stdin);
     int t;
     cin >> t;
     while(t--){
          cin >> d;
          if(d*d - 4*d < 0) {
               cout << "N" << endl; 
               continue;
          }
          cout << "Y ";
          double delta = sqrt(d*d - 4*d);
          double a = (d+delta)/2;
          if(a < 0) a = (d-delta)/2;
          if(a < 0) {
               cout << "N" << endl; 
               continue;
          }
          cout << setprecision(9) << fixed << a << " " << d - a << endl; 
    }
    return 0;
}