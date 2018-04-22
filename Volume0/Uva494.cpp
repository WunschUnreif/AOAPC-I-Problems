#include <cstdio>
#include <cctype>
using namespace std;

int main() {
    int ans = 0, wordCnt = 0;
    char get;
    bool inWord = false;
    while((get = getchar()) != EOF) {
        if(get == '\n') {
            printf("%d\n", ans);
            ans = 0;
            inWord = false;
            wordCnt = 0;
            continue;
        }
        wordCnt++;
        if(inWord && !isalpha(get)) inWord = false;
        else if(!inWord && isalpha(get)){inWord = true; ans ++;}
    }
    if(wordCnt != 0) printf("%d\n", ans);
    return 0;
}