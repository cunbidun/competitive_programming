#include "../libs/genlib.h"
#include "../libs/testlib.h"

using namespace std;

typedef long long ll;

void writeTest(int test) {
  startTest(test);

  vector<int> l = gen_array(10000, (int)2.7e5, (int)3e5, false);
  sort(l.begin(), l.end());
  l.resize(distance(l.begin(), unique(l.begin(), l.end())));
  cout << l.size() << '\n';
  shuffle(l.begin(), l.end());
  for (int i : l) {
    cout << i << ' ';
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
