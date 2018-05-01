#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

void mul(char* num1, char* num2, char* sum) { // "10" * "10" -> "100"
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
    char num[1000];
    int pos = 0;
    char s[10];
    int n;
    while(cin >> s >> n) {
        int use = 0;
        int lenS = strlen(s);
        bool dot = false;
        pos = 0;
        for(int i = 0; i < lenS; ++i) {
            if(dot) pos++;
            if(s[i] == '.') dot = true;
            else num[use++] = s[i];
        }
        num[use] = 0;
        pos *= n;
        char result[1000];
        strcpy(result, num);
        --n;
        while(n--) {
            mul(result, num, result);
        }
        int len = strlen(result);
        for(int i = strlen(result) - 1; i >= 0; --i) {
            if(result[i] != '0') {
                result[i + 1] = 0;
                break;
            }
        }
        if(len >= pos) {
            int i;
            for(i = 0; i < len - pos; ++i) cout << result[i];
            cout << '.' << result + i << endl;
        } else {
            cout << '.';
            for(int i = 0; i < pos - len; ++i) cout << '0';
            cout << result << endl;
        }
    }
    return 0;
}