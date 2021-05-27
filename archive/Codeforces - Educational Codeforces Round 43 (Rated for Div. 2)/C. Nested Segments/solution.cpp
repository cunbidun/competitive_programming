#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <queue>


using namespace std;
#define ll long long

#define MAXA 300020
const int INF = 1000000007;

typedef pair<int, int> ii;
typedef pair<ii, int> II;
typedef vector<int> vi;
typedef vector<ii> vii;

int n, m;
II a[MAXA]; 
ii b[MAXA];
int main() {
    //freopen("in.in","r",stdin);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i].first.second >> a[i].first.first;
        a[i].second = i;
        b[i].first = a[i].first.second;
        b[i].second = i;
    }
    sort(b+1, b+n+1);
    for(int i = 2; i <= n; i++) {
         if(b[i].first == b[i-1].first){
            if(a[b[i].second].first.first <= a[b[i-1].second].first.first)
            cout << (b[i].second) << " " << b[i-1].second << endl;
        else 
            cout << (b[i-1].second) << " " << b[i].second << endl;
            return 0;
        }
    }
    int Max = 1;
    sort(a+1,a+n+1);
    for(int i = 2; i <= n; i++) {
        if(a[i].first.first == a[i-1].first.first){
            if(a[i].first.second >= a[i-1].first.second)
                cout << (a[i].second) << " " << a[i-1].second << endl;
            else 
                cout << (a[i-1].second) << " " << a[i].second << endl;
            return 0;   
        }
        if(a[i].first.second <= a[Max].first.second){
            cout << a[Max].second << " " << (a[i].second) << endl;
            return 0;
        }
        if(a[i].first.second > a[Max].first.second) {
            Max = i;
        }
    }
    cout << -1 <<" " << -1;
    return 0;   
}