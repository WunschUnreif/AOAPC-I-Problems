#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

void sub(const char num1[], const char num[], char ans[]) { // assume num1 > num2.
    for(int i = 0; i < 1000; ++i) {
        if(num1[i] != '0') {num1 += i; break;}
    }
    for(int i = 0; i < 1000; ++i) {
        if(num[i] != '0') {num += i; break;}
    }
    char result[1000], num2[1000];
    memset(result, 0, sizeof(result));
    int len1 = strlen(num1), len2 = strlen(num);
    for(int i = 0; i < len1 - len2; ++i) num2[i] = '0';
    strcpy(num2 + (len1 - len2), num);
    int jiewei = 0;
    int resUse = 0;
    len2 = len1;
    for(int i = len2 - 1; i >= 0; --i) {
        int s = (num1[i] - '0') - (num2[i] - '0') - jiewei + 10;
        result[resUse++] = s % 10;
        jiewei = 1 - s / 10;
    }

    int use = 0;
    bool start = false;
    for(int i = resUse; i >= 0; --i) {
        if(result[i]) start = true;
        if(start) ans[use++] = result[i] + '0';
    }
    if(!start) ans[use++] = '0';
    ans[use] = 0;
}

bool greaterOrEqu(char num1[], char num2[]) {
    for(int i = 0; i < 1000; ++i) {
        if(num1[i] != '0') {num1 += i; break;}
    }
    for(int i = 0; i < 1000; ++i) {
        if(num2[i] != '0') {num2 += i; break;}
    }
    int len1 = strlen(num1), len2 = strlen(num2);
    if(len1 > len2) return true;
    if(len1 < len2) return false;
    for(int i = 0; i < len1; ++i) {
        if(num1[i] > num2[i]) return true;
        if(num1[i] < num2[i]) return false;
    }
    return true;
}

void div(char num1[], char num2[], bool doDiv) {
    char ans[1000];
    int use = 0;
    memset(ans, 0, sizeof(ans));
    int len1 = strlen(num1), len2 = strlen(num2);
    for(int pos = len2; pos <= len1; pos++) {
        //cout << num1 << endl;
        char charPos = num1[pos];
        num1[pos] = 0;
        while(greaterOrEqu(num1, num2)) {
            sub(num1, num2, num1);
            ans[use]++;
        }
        int len = strlen(num1);
        if(pos - len)
            for(int i = 0; i < len; ++i) num1[pos - 1 - i] = num1[pos - 1 - i - (pos - len)];
        for(int i = 0; i < pos - len; ++i) num1[i] = '0';
        num1[pos] = charPos;
        use++;
    }
    if(doDiv) {
        bool start = false;
        for(int i = 0; i < use; ++i) {
            if(ans[i]) start = true;
            if(start) cout << (int)ans[i];
        }
        if(!start) cout << '0';
    }
    else {
        bool start = false;
        use = strlen(num1);
        for(int i = 0; i < use; ++i) {
            if(num1[i] != '0') start = true;
            if(start) cout << num1[i];
        }
        if(!start) cout << '0';
    }
    cout << endl;
}

int main() {
    char n1[1000], n2[1000], op;
    while(cin >> n1 >> op >> n2) {
        if(op == '/') div(n1, n2, true);
        else div(n1, n2, false);
    }
    return 0;
}
