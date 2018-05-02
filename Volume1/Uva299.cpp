#include <iostream>
using namespace std;

void solve() {
    int length, number[60];
    cin >> length;
    for(int i = 0; i < length; ++i) cin >> number[i];
    int ans = 0;
    for(int i = 0; i < length - 1; ++i) {
        for(int j = 0; j < length - i - 1; ++j) {
            if(number[j] > number[j + 1]) {
                ans++;
                int t = number[j];
                number[j] = number[j + 1];
                number[j + 1] = t;
            }
        }
    }
    cout << "Optimal train swapping takes " << ans << " swaps." << endl;
}

int main() {
    int n;
    cin >> n;
    while(n--) solve();
    return 0;
}