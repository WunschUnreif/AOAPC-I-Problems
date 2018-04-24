#include <iostream>
#include <cstring>
#include <cstdio>
#include <cctype>
using namespace std;

char line[200];

void solve() {
    double P = -1, U = -1, I = -1;
    bool p = true, u = true, i = true;
    char *pstr = line;
    for(int i = 0; i < 2; ++i) {
        while(*pstr && *pstr != '=') pstr++;
        if(*pstr == 0) break;
        double number;
        sscanf(pstr + 1, "%lf", &number);
        //cout << "\tT" << number << endl;
        for(char * p = pstr + 1; *p != 0; p++) {
            if(isdigit(*p) || *p == '.') continue;
            if(*p == 'm') number /= 1000;
            else if(*p == 'k') number *= 1000;
            else if(*p == 'M') number *= 1000000;
            else break;
        }
        switch(*(pstr-1)) {
            case 'P': P = number; p = false; break;
            case 'U': U = number; u = false; break;
            case 'I': I = number; i = false; break;
        }
        pstr++;
    }
    if(p) {
        printf("P=%.2fW\n", U*I);
    } else if(u) {
        printf("U=%.2fV\n", P/I);
    } else if(i) {
        printf("I=%.2fA\n", P/U);
    }
}

int main() {
    int kase;
    cin >> kase;
    while(getchar() != '\n');
    for(int i = 0; i < kase; ++i) {
        cin.getline(line, 200);
        printf("Problem #%d\n", i + 1);
        solve();
        printf("\n");
    }
    return 0;
}
