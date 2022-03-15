#include "genlib.hpp"
#include "testlib.h"

using namespace std;

typedef long long ll;

void writeTest(int test) {
  startTest(test);

  int preN = 10;
  vector<int> a = gen_array(preN, 1, 10, false);
  set<int> s(a.begin(), a.end());
  int Q = 10;
  cout << s.size() << ' ' << Q << '\n';
  for (int i : s) {
    cout <<  i << ' ';
  }
  cout << '\n';
  while (Q--) {
    cout << rnd.next(1, 10) << '\n';
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
