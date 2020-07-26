#include <iostream>
#include <algorithm>
#include <set>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <functional> 
#include <queue>

using namespace std;

int n;
long long m,a[200010],last;
int main() {
    //freopen("in.in","r",stdin);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++) {
        cout << (a[i] + last)/m << " ";
        last = (a[i] + last)%m;
    }
    return 0;
}