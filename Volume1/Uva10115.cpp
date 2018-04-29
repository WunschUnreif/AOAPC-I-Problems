#include <iostream>
#include <string>
#include <vector>
using namespace std;

void solve(int n) {
    string _;
    getline(cin, _);
    vector<string> a(n), b(n);
    for(int i = 0; i < n; ++i) {
        getline(cin, a[i]);
        getline(cin, b[i]);
    }
    string toch;
    getline(cin, toch);
    for(int i = 0; i < n; ++i) {
        long pos = string::npos;
        while((pos = toch.find(a[i])) != string::npos) {
            toch = toch.substr(0, pos) + b[i] 
                    + toch.substr(pos + a[i].length(), toch.length() - pos - a[i].length());
        }
    }
    cout << toch << endl;
}

int main() {
    int n;
    while(cin >> n && n) {
        solve(n);
    }
    return 0;
}
