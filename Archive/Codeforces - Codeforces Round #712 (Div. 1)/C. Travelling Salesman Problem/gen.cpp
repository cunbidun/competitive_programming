#include "../../Script/genlib.h"
#include "../../Script/testlib.h"
#include <vector>

using namespace std;

typedef long long ll;

void writeTest(int test) {
  startTest(test);
  int n = rnd.next(5, 5);
  cout << n << '\n';
  while (n--) {
    cout << rnd.next(0, 5) << ' ' << rnd.next(0, 5) << '\n';
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
