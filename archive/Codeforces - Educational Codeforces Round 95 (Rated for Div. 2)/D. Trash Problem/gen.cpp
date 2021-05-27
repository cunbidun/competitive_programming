#include "../../Script/genlib.h"
#include "../../Script/testlib.h"
#include <vector>

using namespace std;

typedef long long ll;

void writeTest(int test) {
  startTest(test);

  char number_str[10];
  int n, q;
  n = rnd.next(5, 5);
  q = rnd.next(5, 5);
  cout << n << ' ' << q << '\n';
  set<int> v;
  for (int i = 1; i <= n; i++) {
    cout << i * i << ' ';
    v.insert(i * i);
  }
  cout << '\n';
  while (q--) {
    int x = rnd.next(1, n);
    if (v.find(x * x) == v.end()) {
      cout << 1 << ' ' << x * x << '\n';
      v.insert(x * x);
    } else {
      cout << 0 << ' ' << x * x << '\n';
      v.erase(x * x);
    }
  }
  sprintf(number_str, "%d", test);
  std::rename(number_str, ('S' + to_string(test) + ".in").c_str());
}

int main(int argc, char *argv[]) {
  registerGen(argc, argv, 1);
  int NUM_TEST = opt<int>(2);
  for (int i = 0; i < NUM_TEST; i++) {
    writeTest(i);
  }
  return 0;
}
