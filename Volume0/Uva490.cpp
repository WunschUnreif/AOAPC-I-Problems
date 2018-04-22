#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char sects[200][200];

int main() {
    memset(sects, ' ', sizeof(sects));
    char ch;
    int maxc = 0;
    int r = 0, c = 0;
    while((ch = getchar()) != EOF) {
        if(ch == '\n') {
            if(c > maxc) maxc = c;
            r++; c = 0;
        }
        else {
            sects[r][c++] = ch;
        }
    }
    if(c > maxc) maxc = c;
    if(c == 0) r--;
    for(int i = 0; i < maxc; ++i) {
        for(int j = r; j >= 0; --j) {
            printf("%c", sects[j][i]);
        }
        printf("\n");
    }
    return 0;
}