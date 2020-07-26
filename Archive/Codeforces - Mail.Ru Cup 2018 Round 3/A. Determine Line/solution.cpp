#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>

#define ll long long
#define pb push_back    

const int INF = 1e9 + 7;
const int MAXA = 5e3 + 10;
const int MOD = 1e9 + 7;

using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, int> II;
typedef vector<int> vi;
typedef vector<ii> vii;

int n, Max;
int check[105];
int main() {
    //freopen("in.in", "r", stdin);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int temp;
        cin >> temp;
        for(int j = 1; j <= temp; j++) {
            int line;
            cin >> line;
            check[line]++;
            Max = max(Max, check[line]);
        }
    }
    for(int i = 1; i <= 100; i++) if(check[i] == Max) cout << i << " ";
    return 0;
}