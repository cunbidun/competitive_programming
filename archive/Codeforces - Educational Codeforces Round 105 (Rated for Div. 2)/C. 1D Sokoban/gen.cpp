#include "../../Script/genlib.h"
#include "../../Script/testlib.h"
#include <vector>

using namespace std;

typedef long long ll;

void writeTest(int test) {
  startTest(test);

  int t = 1;
  cout << t << '\n';
  while (t--) {
    int n = rnd.next(1, 5);
    int m = rnd.next(1, 5);
    vector<int> arr = gen_array(n, 1, 10, false);
    sort(arr.begin(), arr.end());
    arr.erase(unique(arr.begin(), arr.end()), arr.end());

    vector<int> pos = gen_array(m, 1, 10, false);
    sort(pos.begin(), pos.end());
    pos.erase(unique(pos.begin(), pos.end()), pos.end());

    cout << arr.size() << ' ' << pos.size() << '\n';
    for (int i : arr) {
      cout << i << ' ';
    }
    cout << '\n';
    for (int i : pos) {
      cout << i << ' ';
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
