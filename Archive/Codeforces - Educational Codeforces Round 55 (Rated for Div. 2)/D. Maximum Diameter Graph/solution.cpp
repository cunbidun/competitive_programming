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

int n, sum = 0;
ii a[MAXA];

int main() {
    //freopen("in.in", "r", stdin);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i].first;
        if(a[i].first != 1) sum += a[i].first - 2;
        a[i].second = i;
    }

    sort(a + 1, a + n + 1);
    // for(int i = 1; i <= n; i++) cout << a[i].first << " "; 
    //     cout << endl;
    int pos = 0;
    for(int i = 1; i <= n; i++) {
        if(a[i].first != 1) {
            pos = i - 2;
            break;
        }
        else pos = i;
    }
    if(pos - 1 > sum) {
        cout << "NO";
        return 0;
    }

    if(pos <= 1) {
        cout << "YES" << " " << n - 1 << endl;
        cout << n - 1 << endl;
        for(int i = 2; i < n; i++) {
            cout << a[i].second << " " << a[i + 1].second << endl;
            a[i].first --;
            a[i + 1].first --;
        }
        cout << a[n].second << " " << a[1].second << endl;
        return 0;
    }
    

  
    cout << "YES" << " " << n - pos << endl;
    cout << n - 1 << endl;

    for(int i = pos + 1; i < n; i++) {
        cout << a[i].second << " " << a[i + 1].second << endl;
        a[i].first --;
        a[i + 1].first --;
    }
    cout << a[n].second << " " << a[pos].second << endl;
    a[n].first --; a[pos].first --;
    int cur = n;
    for(int i = 1; i <= pos - 1; i++) {
        if(a[cur].first) {
            cout << a[cur].second << " " << a[i].second << endl;
            a[cur].first --;
        }
        else {
            cur--;
            cout << a[cur].second << " " << a[i].second << endl;
            a[cur].first --;
        }
    }
    return 0;
}