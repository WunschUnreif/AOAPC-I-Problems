#include <iostream>
#include <cstdio>
#include <cctype>
using namespace std;

void show(int num, char c) {
    while(num--) {
        printf("%c", c);
    }
}

int main() {
    char ch;
    int currNum = 0;
    while((ch = getchar()) != EOF) {
        if(isdigit(ch)) {
            currNum += ch - '0';
        } else if(ch == 'b') {
            show(currNum, ' ');
            currNum = 0;
        } else if(ch == '!' || ch == '\n') {
            printf("\n");
        } else {
            show(currNum, ch);
            currNum = 0;
        }
    }
    return 0;
}
