#include <iostream>
#include <string>
#include <vector>
using namespace std;

void solve(int k, int e) {
    vector<string> key(k), excuse(e), _excuse(e);
    vector<int> count(e, 0);
    int maxCount = 0;
    for(int i = 0; i < k; ++i) {
        cin >> key[i];
    }
    string _; getline(cin, _);
    for(int i = 0; i < e; ++i) {
        getline(cin, excuse[i]);
        _excuse[i] = excuse[i];
        string now;
        for(int j = 0; j < excuse[i].length(); ++j) {
            if(isalpha(excuse[i][j])) now += tolower(excuse[i][j]);
            else {
                for(int n = 0; n < k; ++n) {
                    if(now == key[n]) count[i]++;
                }
                if(count[i] > maxCount) maxCount = count[i];
                now.clear();
            }
        }
        if(now.length() > 0) {
            for(int n = 0; n < k; ++n) {
                    if(now == key[n]) count[i]++;
                }
                if(count[i] > maxCount) maxCount = count[i];
                now.clear();
        }
    }
    for(int i = 0; i < e; ++i) {
        if(count[i] == maxCount) cout << _excuse[i] << endl;
    }
}

int main() {
    int k, e, kase = 0;
    bool first = true;
    while(cin >> k >> e) {
        //if(!first) cout << endl;
        cout << "Excuse Set #" << ++kase << endl;
        solve(k, e);
        cout << endl;
        //first = false;
    }
    return 0;
}

