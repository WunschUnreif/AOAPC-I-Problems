#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

char vowel[] = "AUEOI";
char conso[] = "JSBKTCLDMVNWFXGPYHQZR";

void solve() {
    int length;
    cin >> length;
    int vCount = 0, cCount = 0;
    char  *vp = vowel, *cp = conso;
    vector<char> vUse, cUse;
    for(int i = 0; i < length; ++i) {
        if(i % 2 == 0) {
            vCount++;
            vUse.push_back(*vp);
            if(vCount == 21) {
                vp++;
                vCount = 0;
            }
        } else {
            cCount++;
            cUse.push_back(*cp);
            if(cCount == 5) {
                cp++;
                cCount = 0;
            }
        }
    }
    sort(vUse.begin(), vUse.end());
    sort(cUse.begin(), cUse.end());
    auto vIt = vUse.begin(), cIt = cUse.begin();
    for(int i = 0; i < length; ++i) {
        if(i % 2 == 0) {
            cout << *vIt++;
        } else {
            cout << *cIt++;
        }
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cout << "Case " << i + 1 << ": ";
        solve();
    }
}
