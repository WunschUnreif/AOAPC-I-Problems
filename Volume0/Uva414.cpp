#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

void solve(int n) {
    int num[20];
    int maxNum = -100;
    memset(num, 0, sizeof(num));
    for(int i = 0; i < n; ++i) {
        string s;
        getline(cin, s);
        //cout << s << endl;
        for(auto c: s) {
            if(c == 'X')num[i]++;
        }
        if(num[i] > maxNum)maxNum = num[i];
    }
    int ans = 0;
    for(int i = 0; i < n; ++i) {
        ans += maxNum - num[i];
    }
    cout << ans << endl;
}

int main() {
    int n;
    while(cin >> n && n) {
        string _;
        getline(cin, _);
        solve(n);
    }
    return 0;
}