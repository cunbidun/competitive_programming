#include "genlib.hpp"
#include "testlib.h"

using namespace std;

typedef long long ll;

void writeTest(int test) {
  startTest(test);
  int T = 1;
  cout << T << '\n';
  while (T--) {
    int N = rnd.next(2, 10);
    cout << N << '\n';
    gen_tree(N);
    set<array<int, 2>> s;
    for (int i = 0; i < 7; i++) {
      int u = rnd.next(1, N - 1);
      int v = rnd.next(u + 1, N);
      s.insert({u, v});
    }
    cout << s.size() << '\n';
    for (auto [u, v] : s) {
      cout << u << ' ' << v << '\n';
    }
    cout << '\n';
  }

  char number_str[10];
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
