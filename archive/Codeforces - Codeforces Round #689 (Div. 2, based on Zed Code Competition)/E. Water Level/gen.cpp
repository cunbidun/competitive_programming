#include "../../Script/genlib.h"
#include "../../Script/testlib.h"
#include <vector>

using namespace std;

typedef long long ll;

void writeTest(int test) {
  startTest(test);

  int l, k, r, t, x, y;
  l = rnd.next(1, 10000);
  r = rnd.next(l, 10000);
  k = rnd.next(l, r);
  t = rnd.next(1, 10000);
  x = rnd.next(1, 10000);
  y = rnd.next(1, 10000);
  cout << k << ' ' << l << ' ' << r << ' ';
  cout << t << ' ' << x << ' ' << y << '\n';
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
