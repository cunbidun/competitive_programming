#include "bits/stdc++.h"
using namespace std;

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
        // if (string(argv[2]) == "") {
        //     stringstream in, out;
        //     in << string(argv[1]);
        //     out << string(argv[3]);
        //     if (check(in, out))
        //         cout << "OK\n";
        //     else
        //         cout << "WA\n";
        // } else {
        stringstream in, ex, ac;
        in << string(argv[1]);
        ex << string(argv[2]);
        ac << string(argv[3]);
        string ans;
        ac >> ans;
        if (ans == "NO") {
            cout << "OK\nNo output";
            return 0;
        }
        int n, p;
        in >> n;
        in >> n >> p;
        vector<int> v(n + 1);
        vector<int> c(n + 1);
        int s = 0;
        for (int i = 1; i <= n; i++) {
            in >> v[i];
            ac >> c[i];
            s += v[i] * c[i];
        }
        if (s < p) {
            cout << "WA\nNot enough to buy ticket";
            return 0;
        }
        if(s == p) {
            cout << "WA\nJust enough";
            return 0;
        }
        for (int i = 1; i <= n; i++)
            if (c[i] > 0) {
                if (s - v[i] >= p) {
                    cout << "WA\nSet is not correct\n";
                    return 0;
                }
            }
        cout << "OK\n";
    }

    if (argc == 5) {
        stringstream in;
        in << string(argv[1]);
        double e = stod(string(argv[4]));
        if (string(argv[2]) == "") {
            stringstream out;
            out << string(argv[3]);
            if (check(in, out))
                cout << "OK\n";
            else
                cout << "WA\n";
        } else {
            stringstream ex, ac;
            ex << string(argv[2]);
            ac << string(argv[3]);
            pair<bool, double> res = doubleChecker(ex.str(), ac.str(), e);
            if (res.first)
                cout << "OK\nMaximal Different is " << res.second << "\n";
            else
                cout << "WA\n";
        }
    }
}