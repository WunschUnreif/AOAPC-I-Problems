#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    char get;
    while((get = getchar()) != EOF) {
        if(get == '\n') printf("\n");
        else {
            printf("%c", get - 7);
        }
    }
    return 0;
}