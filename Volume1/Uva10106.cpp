#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

bool solve() {
    char num1[300], num2[300], product[500];
    if(!(cin >> num1 >> num2)) return false;
    memset(product, 0, sizeof(product));
    int len1 = strlen(num1), len2 = strlen(num2);
    for(int i = len1 - 1; i >= 0; --i) {
        int startPos = len1 - 1 - i;
        for(int j = len2 - 1; j >= 0; --j) {
            int currPro = (num1[i] - '0') * (num2[j] - '0');
            for(int k = startPos; currPro != 0 ; ++k) {
                int s = product[k] + currPro % 10;
                product[k] = s % 10;
                currPro = currPro / 10 + s / 10;
            }
            startPos++;
        }
    }
    bool start = false;
    for(int i = 499; i >= 0; --i) {
        if(product[i] != 0) start = true;
        if(start) cout << (int)product[i];
    }
    if(!start) cout << 0;
    cout << endl;
    return true;
}

int main() {
    while(solve());
    return 0;
}
