#include <iostream>
#include <cstdio>
using namespace std;

void print(int a) {
    for(int i = 0; i < a; ++i) {
        for(int j = 0; j <= i; ++j) {
            printf("%d", i+1);
        }
        printf("\n");
    }
    for(int i = a - 1; i > 0; --i) {
        for(int j = 0; j < i; ++j) {
            printf("%d", i);
        }
        printf("\n");
    }
}

void solve(int kase) {
    int a, f;
    cin >> a >> f;
    while(f--) {
        print(a);
        if(kase || f)
            printf("\n");
    }
}

int main() {
    int kase = 0;
    cin >> kase;
    while(kase--) {
        solve(kase);
    }
    return 0;
}