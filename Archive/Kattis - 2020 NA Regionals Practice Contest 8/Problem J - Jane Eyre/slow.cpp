/*input
2 2 592
"Pride and Predjudice" 432
"Don Quixote" 863
1000000000 "Great Gatsby" 218
1082 "Crime and Punishment" 545
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define PI 3.14159265

typedef pair<string, int> ii;
typedef pair<int, pair<string, int>> iii;
const int N = 1e6;
const int mod = 1e9 + 7; 

int n, m, k;
priority_queue<ii, vector<ii>, greater<ii>> pq;
priority_queue<iii, vector<iii>, greater<iii>> presents;

void solve() {
    long long res = 0;
    while(!pq.empty()){
        while(!presents.empty() && presents.top().first <= res){
            pq.push(presents.top().second);
            presents.pop();
        }
        res = res + 1ll * pq.top().second;
        if(pq.top().first == "Jane Eyre") break;
        pq.pop();
    }
    cout << res;
}

void resolveUnread(string& s){
    int idx = 1;
    string title = "";
    while(s[idx] != '\"'){
        title += s[idx++];
    } 
    while(!isdigit(s[idx])) idx++;
    int pages = stoi(s.substr(idx));
    pq.push({title, pages});
}

void resolvePresent(string& s){
    int idx = 0;
    string t = "";
    while(isdigit(s[idx])) t += s[idx++];
    idx += 2;
    string title = "";
    while(s[idx] != '\"'){
        title += s[idx++];
    } 
    while(!isdigit(s[idx])) idx++;
    int pages = stoi(s.substr(idx));
    presents.push({stoi(t), make_pair(title, pages)});
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    cin.ignore();
    for(int i = 1; i <= n; i++){
        string s;
        getline(cin, s);
        resolveUnread(s);
    }
    pq.push({"Jane Eyre", k});

    for(int i = 1; i <= m; i++){
        string s;
        getline(cin, s);
        resolvePresent(s);
    }
    // while(!presents.empty()){
    //     cout << presents.top().first << " " << presents.top().second.second << endl;
    //     presents.pop();
    // }
    solve();
    return 0; 
}
