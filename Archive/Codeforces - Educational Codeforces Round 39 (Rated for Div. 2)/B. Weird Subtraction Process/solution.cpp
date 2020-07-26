#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>

#define ll long long
#define MAXA 2071
using namespace std;

ll a,b;
ll process(ll a, ll b){
    int pos;
    for(int i = 1; i <= 63;i++){
        if (pow(2,i) > b/a) break;
        pos = i;
    }
    b -= a*(floor(pow(2,pos)));
    return b;
}
int main(){
    //freopen("inp.inp","r",stdin);
    cin >> a >> b;
    while (a && b) {
        if(a >= 2*b) a = process(b,a);
        else if(b >= 2*a) b = process(a,b);
        else if (a < 2*b && b < 2*a) {cout << a << " " <<b; return 0;}        
    }
    cout << a << " " << b << endl;
}