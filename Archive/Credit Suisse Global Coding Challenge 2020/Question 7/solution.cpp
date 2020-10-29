#include <bits/stdc++.h>

using namespace std;
string findSuspiciousUserId(int numOfQuestions, vector<vector<int>> questionAndAnswerVecOfVec) {
  set<int> q[10000], a[10000];
  set<int> c;
  set<int> d;
  set<int> n;
  int cnt[10000];
  memset(cnt, 0, sizeof(cnt));
  for (int i = 0; i < questionAndAnswerVecOfVec.size(); i++) {
    vector<int> v = questionAndAnswerVecOfVec[i];
    for (int i = 1; i < v.size(); i++) {
      q[v[0]].insert(v[i]);
      a[v[i]].insert(v[0]);
      c.insert(v[0]);
      c.insert(v[i]);
    }
  }
  // for (int i : c) {
  //   cout << i << ": ";
  //   for (int a : q[i]) {
  //     cout << a << " ";
  //   }
  //   cout << "\n";
  // }
  for (int i : c) {
    for (int a : q[i]) {
      if (q[a].find(i) != q[a].end()) {
        d.insert(a);
        d.insert(i);
        n.insert(a);
        n.insert(i);
      }
    }
  }
  // for (int i : n) {
  //   cout << i << "\n";
  // }
  while (n.size() > 0) {
    set<int> tmp;
    for (int i : n) {
      for (int q : a[i]) {
        if (d.find(q) != d.end()) {
          continue;
        }
        cnt[q]++;
        if (cnt[q] >= 2) {
          d.insert(q);
          tmp.insert(q);
        }
      }
    }
    n = tmp;
  }
  string ans = "";
  for (int i : d) {
    if (ans == "") {
      ans += to_string(i);
    } else {
      ans += "," + to_string(i);
    }
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
  string firstLine;
  getline(cin, firstLine);

  int numOfQuestions = strtol(firstLine.c_str(), NULL, 10);
  ;

  string questionAndAnswerStr;
  getline(cin, questionAndAnswerStr);

  vector<vector<int>> questionAndAnswerVecOfVec;
  vector<string> questionAndAnswerVecByComma = split(questionAndAnswerStr, ',');

  for (vector<string>::const_iterator i = questionAndAnswerVecByComma.begin();
       i != questionAndAnswerVecByComma.end(); ++i) {
    vector<int> bankerPreferenceVecByAnd = splitStringToInt(*i, ' ');
    questionAndAnswerVecOfVec.push_back(bankerPreferenceVecByAnd);
  }

  string result = findSuspiciousUserId(numOfQuestions, questionAndAnswerVecOfVec);

  // Do not remove below line
  cout << result << "\n";
  // Do not print anything after this line

  return 0;
}