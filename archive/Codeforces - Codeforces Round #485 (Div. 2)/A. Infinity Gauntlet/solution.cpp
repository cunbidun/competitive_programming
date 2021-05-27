#include<iostream>
#include<vector>
#include<string>

using namespace std;

int n, check[8];
string s; 
int main(){
    //freopen("in.in","r",stdin);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> s;
        if(s[0] == 'p') check[1] = 1;
        if(s[0] == 'g') check[2] = 1;
        if(s[0] == 'b') check[3] = 1;
        if(s[0] == 'o') check[4] = 1;
        if(s[0] == 'r') check[5] = 1;
        if(s[0] == 'y') check[6] = 1;
    }
    cout << 6 - n << endl;
    for(int i = 1; i <= 6; i++){
       if(check[i]) continue;
       else{
           if(i == 1) cout << "Power" << endl;
           if(i == 2) cout << "Time" << endl;
           if(i == 3) cout << "Space" << endl;
           if(i == 4) cout << "Soul" << endl;
           if(i == 5) cout << "Reality" << endl;
           if(i == 6) cout << "Mind" << endl;
       }
    }
    return 0;
}