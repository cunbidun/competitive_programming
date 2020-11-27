#include <bits/stdc++.h>
#include <nlohmann/json.hpp>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

using namespace std;
using json = nlohmann::json;

int main(int argc, char *argv[]) {
  chdir(argv[1]);
  ifstream in("config.json");
  json j;
  in >> j;
  mkdir("TestCase", 0777);
  chdir("TestCase");
  for (json test : j["tests"]) {
    if (test["active"]) {
      if (test["input"] != nullptr) {
        ofstream inf(to_string(test["index"]) + ".in");
        inf << test["input"].get<string>();
      }
      if (test["output"] != nullptr) {
        ofstream ouf(to_string(test["index"]) + ".out");
        ouf << test["output"].get<string>();
        ouf.close();
      }
    }
  }
}
