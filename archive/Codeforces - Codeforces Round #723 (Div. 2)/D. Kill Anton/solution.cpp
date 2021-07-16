#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  map<char, int> mp;
  mp['A'] = 0;
  mp['N'] = 1;
  mp['T'] = 2;
  mp['O'] = 3;
  vector<char> id{'A', 'N', 'T', 'O'};
  while (T--) {
    string S;
    cin >> S;
    int N = (int)S.size();
    vector<int> cnt(4);
    for (int i = 0; i < N; i++) {
      cnt[mp[S[i]]]++;
    }
    vector<int> tmp{0, 1, 2, 3};
    vector<int> ans;
    long long mx = -1;
    do {
      long long res = 0;
      vector<int> c = cnt;
      for (int i = 0; i < (int)S.size(); i++) {
        long long tot = 0;
        for (int j = 0; j < 4; j++) {
          if (mp[S[i]] == tmp[j]) {
            break;
          }
          tot += c[tmp[j]];
        }
        res += tot;
        c[mp[S[i]]]--;
      }
      if (res > mx) {
        mx = res;
        ans = tmp;
      }
    } while (next_permutation(tmp.begin(), tmp.end()));
    for (int i : ans) {
      while (cnt[i]--) {
        cout << id[i];
      }
    }
    cout << '\n';
  }
}
