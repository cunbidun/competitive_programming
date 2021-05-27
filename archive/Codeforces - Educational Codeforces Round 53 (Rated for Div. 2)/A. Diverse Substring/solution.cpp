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
string S;
int a[MAXA]; 
int main() {
    //freopen("in.in","r",stdin);
    cin >> n >> S;
    for(int i = 1; i < n; i++) {
        if(S[i] != S[i-1] ) {
            cout << "YES" << endl;
            cout << S[i-1] << S[i];
            return 0;
        }
    }
    cout << "NO";
    return 0;   
}