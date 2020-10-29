#include <bits/stdc++.h>

using namespace std;
int calculateMinimumSession(int numOfBankers, int numOfParticipants,
                            vector<vector<int>> bankersPreferences,
                            vector<vector<int>> participantsPreferences) {
  int ans = 0;
  set<int> cnt_b[numOfBankers + 1];
  set<int> cnt_p[numOfParticipants + 1];
  for (int i = 0; i < bankersPreferences.size(); i++) {
    vector<int> b = bankersPreferences[i];
    for (int p : b) {
      cnt_p[p].insert(i + 1);
      cnt_b[i + 1].insert(p);
    }
  }

  for (int i = 0; i < participantsPreferences.size(); i++) {
    vector<int> p = participantsPreferences[i];
    for (int b : p) {
      cnt_b[b].insert(i + 1);
      cnt_p[i + 1].insert(b);
    }
  }

  for (int i = 1; i <= numOfBankers; i++) {
    ans = max(ans, (int)cnt_b[i].size());
  }

  for (int i = 1; i <= numOfParticipants; i++) {
    ans = max(ans, (int)cnt_p[i].size());
  }
  return ans;
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
  int numOfBankers, numOfParticipants;
  vector<vector<int>> bankersPreferences, participantsPreferences;

  cin >> numOfBankers;

  string bankersPreferencesStr;
  cin >> bankersPreferencesStr;
  vector<string> bankersPreferencesVecByComma = split(bankersPreferencesStr, ',');

  for (vector<string>::const_iterator i = bankersPreferencesVecByComma.begin();
       i != bankersPreferencesVecByComma.end(); ++i) {
    vector<int> bankerPreferenceVecByAnd = splitStringToInt(*i, '&');
    bankersPreferences.push_back(bankerPreferenceVecByAnd);
  }

  string participantsPreferencesStr;
  cin >> numOfParticipants;
  cin >> participantsPreferencesStr;
  vector<string> participantsPreferencesVecByComma = split(participantsPreferencesStr, ',');

  for (vector<string>::const_iterator i = participantsPreferencesVecByComma.begin();
       i != participantsPreferencesVecByComma.end(); ++i) {
    vector<int> participantPreferenceVecByAnd = splitStringToInt(*i, '&');
    participantsPreferences.push_back(participantPreferenceVecByAnd);
  }

  int result = calculateMinimumSession(numOfBankers, numOfParticipants, bankersPreferences,
                                       participantsPreferences);

  // Do not remove below line
  cout << result << "\n";
  // Do not print anything after this line

  return 0;
}