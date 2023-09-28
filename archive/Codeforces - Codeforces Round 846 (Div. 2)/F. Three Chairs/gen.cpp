#include "genlib.hpp"
#include "testlib.h"

using namespace std;

typedef long long ll;

void writeTest(int test) {
  startTest(test);

  int tmp = rnd.next(50);
  auto a = gen_array(tmp, 1, 1000, false);
  set<int> s;
  for (int i : a) {
    s.insert(i);
  }
  cout << s.size() << '\n';
  for (int i : s) {
    cout << i << ' ';
  }
  cout << '\n';
  char number_str[10];
  snprintf(number_str, 10, "%d", test);
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
