/**
 * solution file should read from stdin and print to stdout
 */
#include <iostream>
#include <string>

using namespace std;
int main() {
  string A, B;
  cin >> A >> B;
  auto compute = [](string &A, string &B) -> int {
    int a = atoi(A.c_str());
    int b = atoi(B.c_str());
    int s = a + b;
    int d = 0;
    while (s > 0) {
      d += s % 10;
      s /= 10;
    }
    return d;
  };
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  int mn = compute(A, B);
  string ans_a = A, ans_b = B;
  do {
    do {
      int d = compute(A, B);
      if (d < mn) {
        mn = d;
        ans_a = A;
        ans_b = B;
      }
    } while (next_permutation(B.begin(), B.end()));
  } while (next_permutation(A.begin(), A.end()));
  cout << ans_a << '\n' << ans_b;
}
