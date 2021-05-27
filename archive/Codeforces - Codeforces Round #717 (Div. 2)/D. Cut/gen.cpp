#include "../../Script/genlib.h"
#include "../../Script/testlib.h"
#include <vector>

using namespace std;

typedef long long ll;

void writeTest(int test) {
  startTest(test);
  int n = rnd.next(1, 10);
  int q = rnd.next(1, 10);
  cout << n << ' ' << q << '\n';
  gen_array(n, 1, 20);
  cout << '\n';
  while (q--) {
    int l = rnd.next(1, n);
    int r = rnd.next(l, n);
    cout << l << ' ' << r << '\n';
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
