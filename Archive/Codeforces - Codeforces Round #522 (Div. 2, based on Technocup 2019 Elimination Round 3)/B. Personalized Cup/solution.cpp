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
string S;
int main() {
    //freopen("in.in","r",stdin);
    cin >> S;
    if(S.length() <= 20) {
        cout << 1 << " " << S.length() << endl;
        cout << S;
        return 0;
    }

    for(int i = 2; i <= 5; i ++) {
       if((S.length() / i) >= 20) {
            if(S.length()!=20 *i)continue;
        }
        if((S.length()%i) == 0) {
            //cout << S.length() << " " << i << endl;
            //cout << "% case" << endl;
            cout << i << " " << S.length()/i << endl;
            for(int j = 0; j < S.length(); j++) {
                cout << S[j];
                if((j+1) % (S.length()/i) == 0) cout << endl;
            }
            return 0;
        }
        int remain = i - S.length() % i;
        //cout << S.length() << endl;
        cout << i << " " << S.length()/i + 1<< endl;
        int cnt = 0;
        int J = 0;
        for(int j = 0; j < S.length();) {
            if(remain>0 && j % (S.length()/i) == 0) {
                cout << "*";
                int k;
                for(k = j; k < j+S.length()/i; k++) {
                    cout << S[k];
                }
                j = k;
                remain --;
                if(remain)
                cout << endl;
                cnt ++;
                
            }
            // if(remain == 0) {
            //     cout << cnt*(S.length()/i) << endl;
            // }

            if(remain == 0 ){
                if(( (j+cnt) % (S.length()/i + 1)) == 0 )
                    cout << endl;
                cout << S[j];  
                j++;
            }
        }
        return 0;
    } 
    return 0;   
}