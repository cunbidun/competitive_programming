#include <array>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<int> a(N + 1);
  vector<int> p(N + 1);
  for (int i = 1; i <= N; i++) {
    cin >> a[i];
    p[a[i]] = i;
  }
  for (int i = 1; i <= N; i++) {
  }
}
