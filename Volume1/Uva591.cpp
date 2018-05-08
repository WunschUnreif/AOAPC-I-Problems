#include <iostream>
using namespace std;

int heights[60];
int kase = 0;

bool solve() {
    int n, sum = 0;
    cin >> n;
    if(!n) return false;
    cout << "Set #" << ++kase << endl;
    for(int i = 0; i < n; ++i) {
        cin >> heights[i];
        sum += heights[i];
    }
    sum /= n;
    int ans = 0;
    for(int i = 0; i < n; ++i) {
        if(heights[i] > sum) ans += heights[i] - sum;
    }
    cout << "The minimum number of moves is " << ans << '.' << endl << endl;
    return true;
}

int main() {
    while(solve());
    return 0;
}