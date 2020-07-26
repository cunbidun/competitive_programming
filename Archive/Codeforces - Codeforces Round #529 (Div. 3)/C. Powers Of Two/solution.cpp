#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>
#include <ctime>
    
#define ll long long
#define pb push_back    
#define watch(x) cout << (#x) << " = " << (x) << endl
    
const int INF = 2e9 + 7;
const int MAXA = 1e5 + 10;
const int MOD = 1e9 + 7;
    
using namespace std;
    
typedef pair<int, int> ii;
typedef pair<int, ll> il;
typedef pair<ii, int> II;
typedef vector<int> vi;
typedef vector<ii> vii;

bool check(int x) {
    return (x & (x - 1)) == 0;
}    
int n,k;
vi numList;                   
int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(NULL); 
    clock_t clk = clock();
    cin >> n >> k;
    if(k > n) {
        cout << "NO";
        return 0;
    }    
    if(k == 1 && !check(n)) {
        cout << "NO";
        return 0;
    }
    for(int i = 0; (1 << i) <= n; i++) {
        //cout << (n & (1 << i)) << endl;
        if((n & (1 << i)) ) {
            numList.push_back(i);
        } 
    }
    sort(numList.begin(), numList.end());
    // for(int i = 0; i < numList.size(); i++) {
    //     cout << (1 << numList[i]) << " ";
    // } cout << endl
    k -= numList.size();
    if(k < 0) {
        cout << "NO"; 
        return 0;
    }
    cout << "YES" << endl;
    int curr = 0;
    while(k) {
        if(k >= (1 << numList[curr])) {
            for(int i = 1; i <= (1 << numList[curr]); i++) {
                cout << 1 << " ";    
            }
            //cout << endl;
            k -= (1 << numList[curr]) - 1;
            numList[curr] = -1;
            curr ++;
        }   
        else {

            while(numList[curr] > 0) {
                if(k == 0) break;
                k --;
                numList[curr] --;
                numList.push_back(numList[curr]);
            }
            curr++;
        }
    }
   
    for(int i = 0; i < numList.size(); i++) {
        if(numList[i] != -1)
        cout << (1 << numList[i]) << " ";
    }
    cout << endl;
    cerr << "Time (in ms): " << double(clock() - clk) * 1000.0 / CLOCKS_PER_SEC << '\n';
    return 0;
}