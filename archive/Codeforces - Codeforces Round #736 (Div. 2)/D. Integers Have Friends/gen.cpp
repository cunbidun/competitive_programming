#include "../libs/genlib.h"
#include "../libs/testlib.h"

using namespace std;

typedef long long ll;

void writeTest(int test) {
  startTest(test);

  int T = 100;
  cout << T << '\n';
  while (T--) {
    int N = rnd.next(10, 20);
    vector<int> a = gen_array(N, 1, 15, 0);
    sort(a.begin(), a.end());
    a.resize(distance(a.begin(), unique(a.begin(), a.end())));
    cout << a.size() << '\n';
    shuffle(a.begin(), a.end());
    for (int i : a) {
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
