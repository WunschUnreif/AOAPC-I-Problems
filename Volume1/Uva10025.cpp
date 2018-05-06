#include <iostream>
using namespace std;

void solve() {
    int k; cin >> k;
    k = k > 0 ? k : -k;
    int n = 0, i = 1;
    while(n += i) {
        if(n == k) break;
        if(n > k && (n - k) % 2 == 0) break;
        i++;
    }
    cout << i << endl;
}

int main() {
    int kase;
    cin >> kase;
    while(kase--) {
        solve();
        if(kase) cout << endl;
    }
    return 0;
}