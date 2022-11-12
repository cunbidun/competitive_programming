#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, X, Y;
  cin >> N >> X >> Y;
  if (Y < X)
    return cout << "Second\n", 0;
  for (int i = 0; i < N; ++i) {
    int x;
    cin >> x;
    if ((x % (X + Y)) >= X)
      return cout << "First\n", 0;
  }
  cout << "Second\n";
}
