#include "bits/stdc++.h"
using namespace std;

string TextFileToString(string filename) {
    ostringstream dosString(ios::out | ios::binary); // *** binary
    ifstream inFile(filename.c_str());

    string line;
    while (getline(inFile, line))
        dosString << line << "\r\n";

    return dosString.str();
}

bool tokenChecker(string ex, string ac) {
    ex.erase(remove(ex.begin(), ex.end(), '\n'), ex.end());
    ex.erase(remove(ex.begin(), ex.end(), ' '), ex.end());
    ac.erase(remove(ac.begin(), ac.end(), '\n'), ac.end());
    ac.erase(remove(ac.begin(), ac.end(), ' '), ac.end());
    return ex == ac;
}

bool doubleCompare(double ex, double ac, double esp) {
    double minv = min(ex * (1.0 - esp), ex * (1.0 + esp));
    double maxv = max(ex * (1.0 - esp), ex * (1.0 + esp));
    return ac + 1E-15 >= minv && ac <= maxv + 1E-15;
}

pair<bool, double> doubleChecker(string expected, string actual, double e) {
    vector<double> tokenEx, tokenAc;
    stringstream ex(expected), ac(actual);
    string intermediate;
    double tmp;
    while (ex >> tmp)
        tokenEx.push_back(tmp);
    while (ac >> tmp)
        tokenAc.push_back(tmp);
    if (tokenEx.size() != tokenAc.size())
        return {0, 0};
    double maxDiff = 0.0;
    for (int i = 0; i < tokenEx.size(); i++) {
        bool ch = doubleCompare(tokenEx[i], tokenAc[i], e);
        if (!ch)
            return {0, 0};
        maxDiff = max(maxDiff, abs(tokenEx[i] - tokenAc[i]));
    }
    return {1, maxDiff};
}

bool check(stringstream &in, stringstream &out) { return true; }

int main(int argc, char *argv[]) {
    if (argc == 4) {
        if (string(argv[2]) == "") {
            stringstream in, out;
            in << TextFileToString(string(argv[1]));
            out << TextFileToString(string(argv[3]));
            if (check(in, out))
                cout << "OK\n";
            else
                cout << "WA\n";
        } else {
            stringstream in, ex, ac;
            in << TextFileToString(string(argv[1]));
            ex << TextFileToString(string(argv[2]));
            ac << TextFileToString(string(argv[3]));
            if (tokenChecker(ex.str(), ac.str()))
                cout << "OK\n";
            else
                cout << "WA\n";
        }
    }

    if (argc == 5) {
        stringstream in;
        in << TextFileToString(string(argv[1]));
        double e = stod(string(argv[4]));
        if (string(argv[2]) == "") {
            stringstream out;
            out << TextFileToString(string(argv[3]));
            if (check(in, out))
                cout << "OK\n";
            else
                cout << "WA\n";
        } else {
            stringstream ex, ac;
            ex << TextFileToString(string(argv[2]));
            ac << TextFileToString(string(argv[3]));
            pair<bool, double> res = doubleChecker(ex.str(), ac.str(), e);
            if (res.first)
                cout << "OK\nMaximal Different is " << res.second << "\n";
            else
                cout << "WA\n";
        }
    }
}