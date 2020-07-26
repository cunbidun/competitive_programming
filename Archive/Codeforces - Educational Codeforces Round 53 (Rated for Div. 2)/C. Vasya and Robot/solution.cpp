#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <queue>


using namespace std;
#define ll long long

#define MAXA 200020
const int INF = 1000000007;

typedef pair<int, int> ii;
typedef pair<ii, int> II;
typedef vector<int> vi;
typedef vector<ii> vii;

int n, tarx, tary;
string S;
int a[MAXA];
bool check(int temp){
    //cout << temp << endl;
    int x = 0, y = 0, cx = tarx, cy = tary;
    for(int i = n-1; i >= temp; i--) {
        if(S[i] == 'U') cy--;
        if(S[i] == 'D') cy++;
        if(S[i] == 'L') cx++;
        if(S[i] == 'R') cx--;
    }
    if(abs(cx - x) + abs(cy - y) <= temp) {
            return 1;
    }
    for(int i = 0; i < n - temp ; i++) {
       
        if(S[i] == 'U') y++;
        if(S[i] == 'D') y--;
        if(S[i] == 'L') x--;
        if(S[i] == 'R') x++; 

        if(S[temp+i] == 'U') cy++;
        if(S[temp+i] == 'D') cy--;
        if(S[temp+i] == 'L') cx--;
        if(S[temp+i] == 'R') cx++;

        if(abs(cx - x) + abs(cy - y) <= temp) {
            //cout << i+1 << " " << temp + i<<endl;
            return 1;
        }
    }
    return 0;
}
int main() {
   // freopen("in.in","r",stdin);
    cin >> n >>S;
    cin >> tarx >> tary;
    if((abs(tarx) + abs(tary) > n) || (((abs(tarx) + abs(tary))%2) != (n%2))) {
        cout << -1;
        return 0;
    }
    int l = 0, h = n;

    while (l != h){
        int m = (l + h) / 2;
        if (check(m)) {
           h = m; 
        }
        else l = m + 1;
    }
    cout << l;
    return 0;   
}