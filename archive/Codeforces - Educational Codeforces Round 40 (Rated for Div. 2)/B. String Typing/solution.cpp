#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>

#define ll long long
#define MAXA 2071
using namespace std;

int n,pos,ans;
string s,curr;
int main(){
    ///freopen("inp.inp","r",stdin);
    cin >> n >> s;
    ans = 0;
    pos = -1;
    for(int i = 0; i < s.length() / 2 ; i++){
        curr += s[i];
        string temp;
        for(int j = i+1; j <= 2*i + 1; j++){
            temp += s[j];
        }
        if (curr == temp) pos = i; 
    }
    if(pos == -1) {cout << n; return(0);}
    cout << (pos+1)+1+n-2*(pos+1);
}