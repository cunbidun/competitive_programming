#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>

using namespace std;

int n;
string s;
bool ignore[102];
bool check(char temp){
     if (temp == 'e' ||temp == 'i' ||temp == 'u' ||temp == 'a' ||temp == 'o' ||temp == 'y')
     return 1;
     else return 0;
}
int main(){
     //freopen("inp.inp","r",stdin);
     cin>>n;
     cin>>s;
     for (int i = 0; i <s.length(); i++){
          if(check(s[i])){
               for (int j = i+1 ; j<s.length() ; j++){
                    if (check(s[j])) ignore[j] = 1;
                    else break;
               }
          }
     }
     for (int i = 0; i <s.length(); i++){
          if(!ignore[i]) cout << s[i];
     }
}