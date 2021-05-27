#include "../../Script/genlib.h"
#include "../../Script/testlib.h"
#include <vector>

using namespace std;

typedef long long ll;

void writeTest(int test) {
  startTest(test);

  char number_str[10];
  int n = rnd.next(2, 10);
  cout << n << '\n';
  int m = rnd.next(0, n/2);
  set<int> a;
  while(a.size() < m) {
    a.insert(rnd.next(0, n - 1));
  }
  vector<int> r(n);
  for (int i : a) {
    r[i] = 1;
  }
  for (int i : r) {
    cout << i << ' ';
  }
  cout << '\n';
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
