#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<int> arr(N + 1);
  for (int i = 1; i <= N; i++) {
    for (int j = i * 2; j <= N; j += i) {
      arr[j] = max(arr[j], i);
    }
  }
  sort(arr.begin(), arr.end());
  for (int i = 2; i <= N; i++) {
    cout << arr[i] << ' ';
  }
  cout << '\n';
}
