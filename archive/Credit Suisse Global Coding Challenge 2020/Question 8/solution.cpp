#include <bits/stdc++.h>

using namespace std;
long long countNumberOfWays(int numOfUnits, int numOfCoinTypes, vector<int> coins) {
  long long f[numOfUnits + 1];
  for (int i = 1; i <= numOfUnits; i++) {
    f[i] = 0;
  }
  f[0] = 1;

  sort(coins.begin(), coins.end());
  // reverse(coins.begin(), coins.end());
  for (int coin : coins) {
    for (int i = coin; i <= numOfUnits; i++) {
      f[i] += f[i - coin];
    }
  }
  return f[numOfUnits];
}

vector<string> split(const string &str, char delim) {
  vector<string> strings;
  size_t start;
  size_t end = 0;
  while ((start = str.find_first_not_of(delim, end)) != string::npos) {
    end = str.find(delim, start);
    strings.push_back(str.substr(start, end - start));
  }
  return strings;
}

vector<int> splitStringToInt(const string &str, char delim) {
  vector<int> strings;
  size_t start;
  size_t end = 0;
  while ((start = str.find_first_not_of(delim, end)) != string::npos) {
    end = str.find(delim, start);
    strings.push_back(stoi(str.substr(start, end - start)));
  }
  return strings;
}

void printVector(vector<int> vec) {
  for (vector<int>::const_iterator i = vec.begin(); i != vec.end(); ++i) {
    cout << *i << ' ';
  }
  cout << endl;
}

void printVector(vector<string> vec) {
  for (vector<string>::const_iterator i = vec.begin(); i != vec.end(); ++i) {
    cout << *i << ' ';
  }
  cout << endl;
}

int main() {
  string firstLine;
  getline(cin, firstLine);

  vector<int> firstLineVec = splitStringToInt(firstLine, ' ');
  int numOfUnits = firstLineVec[0];
  int numOfCoinTypes = firstLineVec[1];

  string coins;
  getline(cin, coins);

  vector<int> coinsVec = splitStringToInt(coins, ' ');

  long long result = countNumberOfWays(numOfUnits, numOfCoinTypes, coinsVec);

  // Do not remove below line
  cout << result << "\n";
  // Do not print anything after this line

  return 0;
}
