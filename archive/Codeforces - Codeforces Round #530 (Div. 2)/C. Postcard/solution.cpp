#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define F first
#define rf(i,a,b) for(int (i) = (a); (i) <= (b); (i)++)
#define rb(i,b,a) for(int (i) = (b); (i) >= (a); (i)--)
#define watch(x) cout << (#x) << " = " << (x) << endl
#define test(t) int(testCnt) = 0; int(t); cin >> (t); while(t -- && ++testCnt)

const int INF = 2e9 + 7;
const int MAXA = 3e2 + 10;
const ll MOD = (ll) 1e9 + 7;
const ll INFLL = 9e18 + 7;

typedef pair<int, int> ii;
typedef pair<ii, int> II;
typedef vector<int> vi;
typedef vector<ii> vii;

string S;
int n, k, cntQ, cntS;
vector<char> charList;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
      // freopen("in.in", "r", stdin);
    #endif
    cin >> S;
    //cout << S << endl;
    int n = S.length();
    S = '%' + S ;
    cin  >> k;
    charList.pb('%');
    rf(i,1,n) {
        if(S[i] == '*') {
            cntS ++;
            cntQ ++;
        }
        else if(S[i] == '?') {
            cntQ ++;
        }
        else charList.pb(S[i]);
    }

    //rf(i, 1, charList.size() - 1) cout << charList[i];cout << endl;
    if(n - 2 * (cntQ) > k) return cout << "Impossible", 0;
    if(charList.size() - 1>= k) {
        int cnt = charList.size() - k - 1;
        rf(i, 1, n) {
            if((S[i + 1] == '*' || S[i + 1] == '?') && cnt) {
                i ++;
                cnt --;
            }
            else if(S[i] != '*' && S[i] != '?') cout << S[i];
        }
        return 0;
    }
    if(charList.size() - 1 < k && cntS == 0) return cout << "Impossible", 0;

    charList.clear();
    charList.pb('%');
    bool ok = 0;
    rf(i,1,n) {
        if(S[i] == '?') continue;
        if(S[i] == '*'  && !ok) {
            charList.pb(S[i]);
            ok = 1;
        }
        else if(S[i] != '*')charList.pb(S[i]);
    }
    charList.pb('%');
    //rf(i, 1, charList.size() - 2) cout << charList[i];cout << endl;
    rf(i, 1, charList.size() - 2) {
        if(charList[i] == '*') {
            int needed = k - (i - 1) - (charList.size() - 2 - i);
            while(needed > 0) {
                cout << charList[i - 1];
                needed --;
            }
        }
        else cout << charList[i];
    }

    return 0;
}