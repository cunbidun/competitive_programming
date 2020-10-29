#include <bits/stdc++.h>

using namespace std;

int findMaxProfit(int numOfPredictedDays, vector<int> predictedSharePrices) {
  int n = predictedSharePrices.size();
  if (n < 2) {
    return -1;
  }
  int mx[n + 1];
  mx[n - 1] = predictedSharePrices[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    mx[i] = max(predictedSharePrices[i], mx[i + 1]);
  }
  int ans = 0;
  for (int i = 0; i < n - 1; i++) {
    ans = max(ans, mx[i + 1] - predictedSharePrices[i]);
  }
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
  int numOfPredictedDays = firstLineVec[0];
  vector<int> predictedSharePrices(firstLineVec.begin() + 1, firstLineVec.end());

  int result = findMaxProfit(numOfPredictedDays, predictedSharePrices);

  // Do not remove this line
  cout << result << "\n";
  // Do not print anything after this line

  return 0;
}