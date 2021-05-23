#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  struct e {
    int i, sa, ea, sb, eb;
  };
  vector<e> E;
  for (int i = 0; i < N; i++) {
    int sa, ea, sb, eb;
    cin >> sa >> ea >> sb >> eb;
    E.push_back({i, sa, ea, sb, eb});
  }
  vector<array<int, 3>> event;
  for (int i = 0; i < (int)E.size(); i++) {
    e e = E[i];
    event.push_back({e.sa, i, 1});
    event.push_back({e.ea + 1, i, -1});
  }
  sort(event.begin(), event.end(), [](auto A, auto B) {
    if (A[0] != B[0]) {
      return A[0] < B[0];
    }
    return A[2] < B[2];
  });
  multiset<int> sb;
  multiset<int> eb;
  for (int i = 0; i < (int)event.size(); i++) {
    int idx = event[i][1];
    if (event[i][2] == 1) {
      if (sb.size() != 0) {
        int mx = *sb.rbegin();
        int mn = *eb.begin();
        if (E[idx].sb > mn || E[idx].eb < mx) {
          cout << "NO\n";
          return 0;
        }
      }
      sb.insert(E[idx].sb);
      eb.insert(E[idx].eb);
    } else {
      auto it = sb.find(E[idx].sb);
      sb.erase(it);
      it = eb.find(E[idx].eb);
      eb.erase(it);
    }
  }

  event.clear();
  for (int i = 0; i < (int)E.size(); i++) {
    e e = E[i];
    event.push_back({e.sb, i, 1});
    event.push_back({e.eb + 1, i, -1});
  }
  sort(event.begin(), event.end(), [](auto A, auto B) {
    if (A[0] != B[0]) {
      return A[0] < B[0];
    }
    return A[2] < B[2];
  });
  multiset<int> sa;
  multiset<int> ea;
  for (int i = 0; i < (int)event.size(); i++) {
    int idx = event[i][1];
    if (event[i][2] == 1) {
      if (sa.size() != 0) {
        int mx = *sa.rbegin();
        int mn = *ea.begin();
        if (E[idx].sa > mn || E[idx].ea < mx) {
          cout << "NO\n";
          return 0;
        }
      }
      sa.insert(E[idx].sa);
      ea.insert(E[idx].ea);
    } else {
      auto it = sa.find(E[idx].sa);
      sa.erase(it);
      it = ea.find(E[idx].ea);
      ea.erase(it);
    }
  }
  cout << "YES\n";
}
