#include <bits/stdc++.h>

using namespace std;

int findMaxProfit(int numOfPredictedTimes, vector<int> predictedSharePrices) {
  int ans = 0;
  int p = 0;
  int n = predictedSharePrices.size();
  int last = predictedSharePrices[0];
  for (int i = 1; i < n; i++) {
    if (predictedSharePrices[i] < predictedSharePrices[i - 1]) {
      ans += predictedSharePrices[i - 1] - last;
      last = predictedSharePrices[i];
    }
  }
  ans += predictedSharePrices[n - 1] - last;
  return ans;
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

int main() {
  string firstLine;
  getline(cin, firstLine);

  vector<int> firstLineVec = splitStringToInt(firstLine, ' ');
  int numOfPredictedTimes = firstLineVec[0];
  vector<int> predictedSharePrices(firstLineVec.begin() + 1, firstLineVec.end());

  int result = findMaxProfit(numOfPredictedTimes, predictedSharePrices);

  // Do not remove below line
  cout << result << "\n";
  // Do not print anything after this line

  return 0;
}