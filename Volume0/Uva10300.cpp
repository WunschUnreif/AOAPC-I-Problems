#include <iostream>
using namespace std;

bool first = true;
void solve() {
    unsigned long long n;
    cin >> n;
    unsigned long long ans = 0;
    while(n--) {
        unsigned long long a, b, c;
        cin >> a >> b >> c;
        ans += b == 0 ? 0 : a * c; //If b = 0, then the money is 0.
    }
    cout << ans << endl;
}
int main() {
    int kase;
    cin >> kase;
    while(kase--) {
        solve();
    }
    return 0;
}