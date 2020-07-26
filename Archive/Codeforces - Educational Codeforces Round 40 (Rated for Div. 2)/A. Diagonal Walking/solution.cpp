#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>

#define ll long long
#define MAXA 2071
using namespace std;

int n,ans;
string s;
int main(){
   // freopen("inp.inp","r",stdin);
    cin >> n >> s;
    ans = 0;
    for(int i = 0; i < s.length() - 1 ; i++){
        if (s[i] == 'U' && s[i+1] == 'R') {
            ans++;
            i++;
        }
        else if (s[i] == 'R' && s[i+1] == 'U') {
            ans++;
            i++;
        }
    }
    cout << s.length()-ans;
}