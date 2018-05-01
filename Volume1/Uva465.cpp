#include <iostream>
#include <cstdio>
#include <cstring>
#include <sstream>
using namespace std;

bool overflow(char num[]) {
    char maxI[] = "2147483647";
    if(strlen(num) > strlen(maxI)) return true;
    if(strlen(num) < strlen(maxI)) return false;
    for(int i = 0; i < 10; ++i) {
        if(num[i] > maxI[i]) return true;
        if(num[i] < maxI[i]) return false;
    }
    return false;
}

void add(char * num1, char* num2, char* s) {
    char sum[300];
    memset(sum, 0, sizeof(sum));
    int u = 0;
    for(int i = strlen(num2) - 1; i >= 0; --i) {
        sum[u++] = num2[i] - '0';
    }
    int len = strlen(num1);
    int jinwei = 0;
    for(int i = len - 1; i >= 0; --i) {
        int j = len - i - 1;
        int currSum = sum[j] + (num1[i] - '0') + jinwei;
        sum[j] = currSum % 10;
        jinwei = currSum / 10;
    }
    if(jinwei) {
        int m = len;
        while(sum[m] == 9) {
            sum[m] = 0;
            m++;
        }
        sum[m] += 1;
    }
    int use = 0;
    bool start = false;
    for(int i = 299; i >= 0; --i) {
        if(sum[i]) start = true;
        if(start) s[use++] = sum[i] + '0';
    }
    s[use] = 0;
}

void mul(char* num1, char* num2, char* sum) {
    char product[300];
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
    int use = 0;
    bool start = false;
    for(int i = 299; i >= 0; --i) {
        if(product[i] != 0) start = true;
        if(start) sum[use++] = product[i] + '0';
    }
    sum[use] = 0;
}

int main() {
    string s;
    char num1[300], num2[300], sum[300], op;
    char _1[300], _2[300];
    int u1 = 0, u2 = 0;
    while(getline(cin, s)) {
        stringstream ss(s);
        ss >> _1 >> op >> _2;
        u1 = 0;
        u2 = 0;
        bool start = false;
        for(int i = 0; i < strlen(_1); ++i) {
            if(_1[i] != '0') start = true;
            if(start) num1[u1++] = _1[i];
        }
        if(start == false) num1[u1++] = '0';
        num1[u1] = 0;
        start = false;
        for(int i = 0; i < strlen(_2); ++i) {
            if(_2[i] != '0') start = true;
            if(start) num2[u2++] = _2[i];
        }
        if(start == false) num2[u2++] = '0';
        num2[u2] = 0;
        cout << s << endl;
        if(overflow(num1)) cout << "first number too big" << endl;
        if(overflow(num2)) cout << "second number too big" << endl;
        if(op == '+') add(num1, num2, sum);
        else if(op == '*') mul(num1, num2, sum);
        if(overflow(sum)) cout << "result too big" << endl;
    }
    return 0;
}
