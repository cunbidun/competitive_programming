#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <queue>

using namespace std;
#define ll long long
#define INF 1000000007

const int MAXA = 1e2+5;

typedef pair<int, int> ii;
typedef pair<ii, int> II;
typedef vector<int> vi;
typedef vector<ii> vii;

int n, k;
int a[MAXA];
int ans = 0;
int cnt[MAXA];
int Count = 0;
int Diff = 0;
int main() {
   // freopen("in.in","r",stdin);
    cin >> n >> k;
   
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(!cnt[a[i]]) Diff++;
   		cnt[a[i]] ++;		
    }
    for(int i = 1; i <= 100; i++){
    	if(cnt[a[i]] % k == 0) {
    		Count = max(Count, (cnt[a[i]] / k) );
    		continue;
    	}
    	Count = max(Count, (cnt[a[i]] / k) + 1);
    }
   // cout << Count << endl;
    cout << Count * k * Diff - n;
    return 0;   
}