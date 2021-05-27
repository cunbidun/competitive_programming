#include <iostream>
#include <algorithm>
#include <set>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <functional> 
#include <queue>
#include <string>

using namespace std;

#define ll long long
#define INF 1000000007

const int MAXA = 2e5+5;

typedef pair<int, int> ii;
typedef pair<ii, int> II;
typedef vector<int> vi;
typedef vector<ii> vii;

int n, m, k, S;
int a[MAXA];
int ch[MAXA], Ans[MAXA];

int main() {
    // /freopen("in.in","r",stdin);
    cin >> n >> S;
    if(S% n == 0)
    cout << S / n;
    else cout << S/n+1;
    return 0;
}