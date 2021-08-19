#include "../libs/genlib.h"
#include "../libs/testlib.h"

using namespace std;

typedef long long ll;

void writeTest(int test) {
  startTest(test);

  int N = rnd.next(1, 10);
  int R = rnd.next(1, min(5000, N * N));
  set<array<int, 2>> p;
  for (int i = 0; i < R; i++) {
    p.insert({rnd.next(1, N), rnd.next(1, N)});
  }
  cout << N << ' ' << p.size() << '\n';
  for (auto [a, b] : p) {
    cout << a << ' ' << b << '\n';
  }
  cout << '\n';

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
