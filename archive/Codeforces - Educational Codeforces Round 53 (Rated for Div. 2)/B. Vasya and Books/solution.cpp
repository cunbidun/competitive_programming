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

int n, m;
int a[MAXA],b[MAXA];
bool check[MAXA]; 
int main() {
    //freopen("in.in","r",stdin);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    int cnt = 1;
    int cur = 1;
    for(int i = 1; i <= n; ){
        if(a[i] == b[cur]){
           // cout << i << " " << cur << endl;
            cout << cnt << " ";
            cur ++;
           // cout << i << " " << cur << " "<<b[cur]<<endl;
            while(check[b[cur]]){
                cout << 0 << " ";
                cur++;
            }
            cnt = 1;
            i++;
            //cout << "i:" <<i << " "<<cur<< endl;
        }
        else {
            cnt ++;
            check[a[i]] = 1;
            //cout << "i:" <<i << endl;
            i++;
        }
    }

    return 0;   
}