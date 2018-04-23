#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char s[5][110];
char line2[110];

void solve() {
    int strCnt = 0;
    char ch;
    int use = 0;
    while((ch = getchar()) != '\n') {
        if(ch == '<' || ch == '>') {
            s[strCnt][use] = 0;
            use = 0;
            strCnt++;
        } else s[strCnt][use++] = ch;
    }
    s[strCnt][use] = 0;
    //cout << s[0] << s[1] << s[2] << s[3] << s[4] << endl;
    for(int i = 0; i < 5; ++i) {
        printf("%s", s[i]);
    }
    printf("\n");
    use = 0;
    while((ch = getchar()) != '.') printf("%c", ch);
    printf("%s%s%s%s\n", s[3], s[2], s[1], s[4]);
    while((ch = getchar()) && ch != '\n' && ch != EOF);
}

int main() {
    int pairs;
    scanf("%d", &pairs);
    while(getchar() != '\n');
    while(pairs--) {
        solve();
    }
    return 0;
}