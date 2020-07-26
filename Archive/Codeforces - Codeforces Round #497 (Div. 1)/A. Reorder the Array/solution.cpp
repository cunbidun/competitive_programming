#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

const int MAXA = 1e5+5;
int n, a[MAXA], ans;
vector<int> List;
int main(){
    ios_base::sync_with_stdio(0);
    //freopen("in.txt","r",stdin);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        List.push_back(a[i]);
    }
    sort(List.begin(), List.end());
    // for(int i = 1; i <= n; i++){
    //     cout << a[i] << " ";
    // }
    // cout << endl;
    // for(int i = 1; i <= n; i++){
    //     cout << List[i-1] << " ";
    // }
    // cout << endl;
    // vector<int>::iterator up;
    // up = upper_bound(List.begin(), List.end(), 2);
    // cout << up - List.begin() << endl;
    for(int i = 1; i <= n; i++){
        vector<int>::iterator up;
        up = upper_bound(List.begin(), List.end(), a[i]);
        if(up != List.end()) {
            //cout << a[i] << " " << List[up-List.begin()] << endl;
            ans++;
            List.erase(up);
        }
    }   
    cout << ans;
    return 0;
}
// 5 6 2 23 32 x 25 x