#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>

#define ll long long
#define INF 1000000000000000000
using namespace std;

ll n, m, a[52], b[52], M, pos;

int main(){
    //freopen("inp.inp","r",stdin);
    cin >> n >> m;
    for(int i = 1; i <= n ; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= m ; i++){
        cin >> b[i];
    }
    M = -INF;
    
    for(int i = 1; i <= n ; i++){
        for(int j = 1; j <= m; j++){
            //cout << a[i]*b[j] << endl;
            if(a[i] * b[j] > M){
                M = a[i] * b[j];
                pos = i;
            }
        }
    }
    M = -INF;
    
    for(int i = 1; i <= n ; i++){
        if (i == pos) continue;
        for(int j = 1; j <= m; j++){
            if(a[i] * b[j] > M){
                M = a[i] * b[j];
        
            }
        }
    }
    cout << M;
}