#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int h0, n, p = 1;
    while(cin >> h0 >> n && h0 && n) {
        p = 1;
        if(h0 == 1 && n == 1) {cout << "0 1" << endl; continue;}
        while(p) if(fabs(pow(h0, 1/(double)p) - 1 - pow(n, 1 / (double)p)) < 1e-9) break; else p++;
        int N = pow(n, 1 / (double)p) + 0.5;
        int ans1 = 1, ans2 = h0, currN = N;
        for(int i = 0; i < p; ++i) {
            h0 /= 1 + N;
            ans1 += currN;
            ans2 += currN * h0;
            currN *= N;
        }
        cout << ans1 - n << " " << ans2 << endl;
    }
    return 0;
}