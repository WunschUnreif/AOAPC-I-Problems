#include <iostream>
using namespace std;

void solve(long long a, long long l) {
    int ans = 1;
    while(a != 1 && a <= l) {
        if(a & 1) {
            a = 3 * a + 1;
            if(a <= l) ans++;
        } else {
            a /= 2;
            if(a <= l) ans++;
        }
    }
    cout << ans << endl;
}

int main() {
    int kase = 0;
    long long a, l;
    while(cin >> a >> l && a >= 0 && l >= 0) {
        cout << "Case " << ++kase << ": A = " << a << ", limit = " << l << ", number of terms = ";
        solve(a, l);
    }
    return 0;
}