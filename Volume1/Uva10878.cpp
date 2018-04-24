#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main() {
    char ch, out = 0;
    int w = 128;
    while(getchar() != '|');
    while((ch = getchar())) {
        if(ch == '.') continue;
        if(ch == '|') {
            while((ch=getchar()) && ch != '|' && ch != '_'){}
            printf("%c", out);
            out = 0;
            w = 128;
            if(ch == '_') break;
            continue;
        }
        if(ch == 'o') {
            out += w;
        }
        w >>= 1;
    }
    return 0;
}