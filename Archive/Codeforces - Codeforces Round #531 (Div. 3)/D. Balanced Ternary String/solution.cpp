#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define F first
#define S second
#define rf(i,a,b) for(int (i) = (a); (i) <= (b); (i)++)
#define rb(i,b,a) for(int (i) = (b); (i) >= (a); (i)--)
#define watch(x) cout << (#x) << " = " << (x) << endl
#define test(t) int(testCnt) = 0; int(t); cin >> (t); while(t -- && ++testCnt) 

const int INF = 2e9 + 7;
const int MAXA = 1e5 + 10;
const ll MOD = (ll) 1e9 + 7;
const ll INFLL = 9e18 + 7;

typedef pair<int, int> ii;
typedef pair<ii, int> II;
typedef vector<int> vi;
typedef vector<ii> vii;

int n, c0, c1, c2;
string s;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        //freopen("in.in", "r", stdin);
    #endif
    cin >> n >> s;
    s = 'x' + s;
    rf(i, 1, n) {
    	if(s[i] == '0') c0++;
    	if(s[i] == '1') c1++;
    	if(s[i] == '2') c2++;
    }
   	int n0 = n/3 - c0;
   	int n1 = n/3 - c1;
   	int n2 = n/3 - c2;
   	
   	if(n0 > 0) {
   		rf(i, 1, n) {
   			if(!n0) break;
   			if(s[i] == '1' && n1 < 0) {
   				s[i] = '0';
   				n1 ++;
   				n0 --;
   			}
   			if(s[i] == '2' && n2 < 0) {
   				s[i] = '0';
   				n2 ++;
   				n0 --;
   			}
   		}
   	}

   	if(n2 > 0) {
   		rb(i, n, 1) {
   			if(!n2) break;
   			if(s[i] == '1' && n1 < 0) {
   				s[i] = '2';
   				n1 ++;
   				n2 --;
   			}
   			if(s[i] == '0' && n0 < 0) {
   				s[i] = '2';
   				n0 ++;
   				n2 --;
   			}
   		}
   	}

   	if(n2 <= 0)
	   	if(n1 > 0) {
	   		rf(i, 1, n) {
	   			if(!n1) break;
	   			if(s[i] == '2' && n2 < 0) {
	   				s[i] = '1';
	   				n2 ++;
	   				n1 --;
	   			}
	   		}
	   	}

	if(n0 <= 0) {
	   	if(n1 > 0) {
	   		rb(i, n, 1) {
	   			if(!n1) break;
	   			if(s[i] == '0' && n0 < 0) {
	   				s[i] = '1';
	   				n0 ++;
	   				n1 --;
	   			}
	   		}
	   	}
	}

   	rf(i, 1, n) cout << s[i];
    return 0;
}